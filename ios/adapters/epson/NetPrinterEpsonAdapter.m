//
//  NetPrinterEpsonAdapter.m
//
//  Created by Till POS on 14/09/21.
//


#import "NetPrinterEpsonAdapter.h"
#import "EpsonPrinterSDK.h"
#import "../../utils/NSDataAdditions.h"
#import "../../utils/EpsonUtils.h"
#import <stdlib.h>

@interface NetPrinterEpsonAdapter() <Epos2PtrReceiveDelegate>
- (void) connectAndSendAux:(NSString *_Nullable)host printRawData: (NSString *_Nullable)text success:(RCTResponseSenderBlock _Nullable )successCallback fail:(RCTResponseSenderBlock _Nullable )errorCallback;
@end

@implementation NetPrinterEpsonAdapter {
    RCTResponseSenderBlock _successCallback;
    RCTResponseSenderBlock _errorCallback;
    int _retryAttempts;
}

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0);
}

- (void) connectAndSend:(NSString *)host
               withPort:(nonnull NSNumber *)port
           printRawData:(NSString *)text
                success:(RCTResponseSenderBlock)successCallback
                   fail:(RCTResponseSenderBlock)errorCallback {
    @try {


        _retryAttempts=0;


        printer = [[Epos2Printer alloc] initWithPrinterSeries:1 lang:EPOS2_MODEL_ANK];
        [printer setReceiveEventDelegate:self];
        do{
          @try{
            _retryAttempts++;
            [self connectAndSendAux:host printRawData:text success:successCallback fail:errorCallback];
            _retryAttempts = 3;
          }
          @catch (NSException *exception)
          {
             if (_retryAttempts>=3)
             {
               @throw exception;
             }
             [printer endTransaction];
             [printer disconnect];
             [printer clearCommandBuffer];
             [NSThread sleepForTimeInterval:3.0f];
          }
        }
        while(_retryAttempts<3);



    } @catch (NSException *exception) {

          [printer endTransaction];
          int failResult=[printer disconnect];
          [printer clearCommandBuffer];
          [printer setReceiveEventDelegate:nil];
          errorCallback(@[[NSString stringWithFormat:@"%@ and disconnect code %i",exception.reason,failResult]]);
    }
}

- (void) connectAndSendAux:(NSString *)host printRawData:(NSString *)text success:(RCTResponseSenderBlock)successCallback fail:(RCTResponseSenderBlock)errorCallback {
        NSString* target = [NSString stringWithFormat:@"TCP:%@", host];
        int result = EPOS2_SUCCESS;
        result = [printer connect:target timeout:(_retryAttempts * 3000)];
        if (result != EPOS2_SUCCESS) {
            [NSException raise:@"Invalid connection" format:@"Can't connect to printer %@, ERROR code: %i", host,result];


        }


        NSData* payload = [NSData dataWithBase64EncodedString:text];
        [printer addCommand:payload];
        result = [printer sendData:5000];
        if (result != EPOS2_SUCCESS) {
            [NSException raise:@"Print failed" format:@"Error occurred while printing"];

        }
        _successCallback = successCallback;
        _errorCallback = errorCallback;

}
- (void) onPtrReceive:(Epos2Printer *)printerObj code:(int)code status:(Epos2PrinterStatusInfo *)status printJobId:(NSString *)printJobId
{
    NSString *errMsg = [EpsonUtils makeErrorMessage:status];
    [printerObj endTransaction];
    [printerObj clearCommandBuffer];
    int result = [printerObj disconnect];
    if ([errMsg  isEqual: @""] && result == EPOS2_SUCCESS) {
        _successCallback != nil ? _successCallback(@[[NSString stringWithFormat:@"Successfuly printed"]]) : nil;
    } else {
        _errorCallback != nil ? _errorCallback(@[[NSString stringWithFormat:@"Delegate with ERROR %i and message %@",result,errMsg]]) : nil;
    }

    _successCallback = nil;
    _errorCallback = nil;

    [printerObj setReceiveEventDelegate:nil];
    return;
}

@end
