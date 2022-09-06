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
            NSLog(@"succeed for printer %@ on attempt %i",host,_retryAttempts);
            _retryAttempts = 3;
          }
          @catch (NSException *exception)
          {
             NSLog(@"retry attempt %i, printer %@",_retryAttempts,host);
             if (_retryAttempts>=3)
             {
               @throw exception;
             }
             [printer endTransaction];
             [printer disconnect];
             [printer clearCommandBuffer];
          }
        }
        while(_retryAttempts<3);



    } @catch (NSException *exception) {

          [printer endTransaction];
          [printer disconnect];
          [printer clearCommandBuffer];
          [printer setReceiveEventDelegate:nil];
          errorCallback(@[exception.reason]);
    }
}

- (void) connectAndSendAux:(NSString *)host printRawData:(NSString *)text success:(RCTResponseSenderBlock)successCallback fail:(RCTResponseSenderBlock)errorCallback {
        NSString* target = [NSString stringWithFormat:@"TCP:%@", host];
        int result = EPOS2_SUCCESS;
        result = [printer connect:target timeout:5000];
        if (result != EPOS2_SUCCESS) {
             NSLog(@"failing at connect,attempt %i, printer %@",_retryAttempts,host);
            [NSException raise:@"Invalid connection" format:@"Can't connect to printer %@", host];


        }

       int r = arc4random_uniform(100);

       if(r < 50)
       {
         NSLog(@"failing at sim,attempt %i, printer %@",_retryAttempts,host);
        [NSException raise:@"test fail connection" format:@"sim dropout for %@", host];
       }

        NSData* payload = [NSData dataWithBase64EncodedString:text];
        [printer addCommand:payload];
        result = [printer sendData:5000];
        if (result != EPOS2_SUCCESS) {
             NSLog(@"failing at print,attempt %i, printer %@,result %i", _retryAttempts,host,result);
            [NSException raise:@"Print failed" format:@"Error occurred while printing"];

        }
        NSLog(@"print success for %@, printer obj pointer %p",host,printer);
        _successCallback = successCallback;
        _errorCallback = errorCallback;

}
- (void) onPtrReceive:(Epos2Printer *)printerObj code:(int)code status:(Epos2PrinterStatusInfo *)status printJobId:(NSString *)printJobId
{
    NSString *errMsg = [EpsonUtils makeErrorMessage:status];
    if ([errMsg  isEqual: @""]) {
        _successCallback != nil ? _successCallback(@[[NSString stringWithFormat:@"Successfuly printed"]]) : nil;
    } else {
        _errorCallback != nil ? _errorCallback(@[[NSString stringWithString:errMsg]]) : nil;
    }

    _successCallback = nil;
    _errorCallback = nil;



    [printerObj endTransaction];
    [printerObj clearCommandBuffer];
    [printerObj disconnect];
    [printerObj setReceiveEventDelegate:nil];
    return;
}

@end
