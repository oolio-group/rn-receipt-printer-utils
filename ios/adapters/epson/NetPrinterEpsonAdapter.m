
//
//  NetPrinterEpsonAdapter.m
//
//  Created by Till POS on 14/09/21.
//

#import "NetPrinterEpsonAdapter.h"
#import "../../utils/EpsonUtils.h"
#import "../../utils/NSDataAdditions.h"
#import "EpsonPrinterSDK.h"
#import <stdlib.h>

@interface NetPrinterEpsonAdapter () <Epos2PtrReceiveDelegate,
                                      Epos2ConnectionDelegate>

@end

static NSMutableDictionary *printersByIP;
static NSLock *connectionAPIlock;
static NSObject *isLogging;

@implementation NetPrinterEpsonAdapter {
  RCTResponseSenderBlock _successCallback;
  RCTResponseSenderBlock _errorCallback;
  int _finishedAsyncCall;
  int _failedConnect;
  Epos2Printer *printer;
}

- (dispatch_queue_t)methodQueue {
  return dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0);
}

- (void)connectAndSend:(NSString *)host
              withPort:(nonnull NSNumber *)port
          printRawData:(NSString *)text
            epsonModel:(int)modelNumber
               success:(RCTResponseSenderBlock)successCallback
                  fail:(RCTResponseSenderBlock)errorCallback {

  _finishedAsyncCall = 0;
  @autoreleasepool {
    @synchronized(isLogging) {
      if (isLogging == nil) {
        int logResult = EPOS2_SUCCESS;

        logResult = [Epos2Log setLogSettings:EPOS2_PERIOD_PERMANENT
                                      output:EPOS2_OUTPUT_STORAGE
                                   ipAddress:nil
                                        port:0
                                     logSize:10
                                    logLevel:EPOS2_LOGLEVEL_LOW];
        if (logResult == EPOS2_SUCCESS) {
          isLogging = [[NSObject alloc] init];
          NSLog(@"STARTED LOGGING");
        }
      }
    }

    if (printersByIP == nil) {
      @synchronized(printersByIP) {
        if (printersByIP == nil) {
          printersByIP = [[NSMutableDictionary alloc] init];
        }
      }
    }

    @synchronized(printersByIP) {
      printer = [printersByIP objectForKey:host];
      if (printer == nil) {
        printer = [[Epos2Printer alloc] initWithPrinterSeries:modelNumber
                                                         lang:EPOS2_MODEL_ANK];

        [printersByIP setObject:printer forKey:host];
      }
    }

    @synchronized(printer) {
      @try {

        NSString *target = [NSString stringWithFormat:@"TCP:%@", host];
        int result = EPOS2_SUCCESS;

        Epos2PrinterStatusInfo *status = [printer getStatus];

        if ([status getConnection] != EPOS2_TRUE) {

          result = [self netAdapterConnect:printer target:target];
          if ((result != EPOS2_SUCCESS)) {

            @synchronized(printersByIP) {
              if (printer == [printersByIP objectForKey:host]) {

                [printersByIP
                    setObject:[[Epos2Printer alloc]
                                  initWithPrinterSeries:modelNumber
                                                   lang:EPOS2_MODEL_ANK]
                       forKey:host];
              }
            }
            [NSException raise:@"Invalid connection"
                        format:@"Can't connect to printer %@, ERROR code: %i",
                               host, result];
          }
        }
        __weak NetPrinterEpsonAdapter *weakSelf = self;
        [printer setReceiveEventDelegate:weakSelf];
        [printer setConnectionEventDelegate:weakSelf];

        NSData *payload = [NSData dataWithBase64EncodedString:text];
        [printer beginTransaction];
        [printer addCommand:payload];
        result = [printer sendData:5000];
        if (result != EPOS2_SUCCESS) {
          [NSException raise:@"Print failed"
                      format:@"Error occurred while printing"];
        }
        _successCallback = successCallback;
        _errorCallback = errorCallback;

        long delayInSeconds = 20;
        long startTime = [[NSDate date] timeIntervalSince1970];
        long currTime = [[NSDate date] timeIntervalSince1970];

        while ((_finishedAsyncCall != 1) &&
               (startTime + delayInSeconds > currTime)) {
          [NSThread sleepForTimeInterval:0.5];
          currTime = [[NSDate date] timeIntervalSince1970];
        }
        if (!_finishedAsyncCall) {
          [NSException raise:@"Print failed"
                      format:@"Delegate Functions not called"];
        } else if (_finishedAsyncCall == 2) {
          [NSException
               raise:@"Print failed"
              format:@"Disconnect Delegate Function called, epos error"];
        } else if ((_finishedAsyncCall == 3) || (_finishedAsyncCall == 4)) {
          while (_finishedAsyncCall == 3) {
            [NSThread sleepForTimeInterval:0.5];
          }
          [NSException raise:@"Print failed"
                      format:@"reconnection event occurred"];
        }

        // Delegate function onPtrReceive doesn't do the disconnecting anymore,
        // do the disconnect here if the delegate function executes
        // successfully. Do the disconnect in the catch if delegate function is
        // not called
        [printer endTransaction];
        int successDisconnectResult = [self netAdapterDisconnect:printer];
        while (successDisconnectResult == EPOS2_ERR_PROCESSING) {
          [NSThread sleepForTimeInterval:0.5];
          successDisconnectResult = [self netAdapterDisconnect:printer];
        }
        NSLog(@"SUCCESS PRINT");

      } @catch (NSException *exception) {

        [printer endTransaction];
        int failResult = [self netAdapterDisconnect:printer];
        while (failResult == EPOS2_ERR_PROCESSING) {
          [NSThread sleepForTimeInterval:0.5];
          failResult = [self netAdapterDisconnect:printer];
        }
        errorCallback(
            @[ [NSString stringWithFormat:@"%@ and disconnect code %i",
                                          exception.reason, failResult] ]);
        NSLog(@"Fail PRINT");
      } @finally {
        _successCallback = nil;
        _errorCallback = nil;
        [printer clearCommandBuffer];
        [printer setReceiveEventDelegate:nil];
        [printer setConnectionEventDelegate:nil];
        printer = nil;
      }
    }
  }
}

- (void)onPtrReceive:(Epos2Printer *)printerObj
                code:(int)code
              status:(Epos2PrinterStatusInfo *)status
          printJobId:(NSString *)printJobId {
  NSString *errMsg = [EpsonUtils makeErrorMessage:status];
  NSLog(@"code is %i", code);
  if ([errMsg isEqual:@""] && (code == EPOS2_CODE_SUCCESS)) {
    _successCallback != nil ? _successCallback(@[ [NSString
                                  stringWithFormat:@"Successfuly printed"] ])
                            : nil;
  } else {
    _errorCallback != nil ? _errorCallback(@[
      [NSString
          stringWithFormat:@"Delegate with ERROR and message %@ and code %i",
                           errMsg, code]
    ])
                          : nil;
  }
  _finishedAsyncCall = 1;
  NSLog(@"In Delegate");

  return;
}
- (void)onConnection:(id)deviceObj eventType:(int)eventType {

  if (eventType == EPOS2_EVENT_DISCONNECT) {
    _finishedAsyncCall = 2;
  } else if (eventType == EPOS2_EVENT_RECONNECTING) {
    _finishedAsyncCall = 3;
  } else {
    _finishedAsyncCall = 4;
  }
}

- (int)netAdapterConnect:(Epos2Printer *)printerObj target:(NSString *)target {
  if (connectionAPIlock == nil) {
    @synchronized(connectionAPIlock) {
      if (connectionAPIlock == nil) {
        connectionAPIlock = [[NSLock alloc] init];
      }
    }
  }
  [connectionAPIlock lock];

  int result = [printerObj connect:target timeout:5000];

  [connectionAPIlock unlock];

  return result;
}

- (int)netAdapterDisconnect:(Epos2Printer *)printerObj {
  if (connectionAPIlock == nil) {
    @synchronized(connectionAPIlock) {
      if (connectionAPIlock == nil) {
        connectionAPIlock = [[NSLock alloc] init];
      }
    }
  }
  [connectionAPIlock lock];

  int result = [printerObj disconnect];

  [connectionAPIlock unlock];

  return result;
}

@end
