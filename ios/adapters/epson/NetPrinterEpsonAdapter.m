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
- (void) connectAndSendAux:(NSString *_Nullable)host printRawData: (NSString *_Nullable)text success:(RCTResponseSenderBlock _Nullable )successCallback fail:(RCTResponseSenderBlock _Nullable )errorCallback printerObj:(Epos2Printer *)printer;
@end

  NSMutableDictionary *printerDictionary;
@implementation NetPrinterEpsonAdapter {
    RCTResponseSenderBlock _successCallback;
    RCTResponseSenderBlock _errorCallback;
    int _retryAttempts;
    BOOL _finishedAsyncCall;


}

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0);
}

- (void) connectAndSend:(NSString *)host
               withPort:(nonnull NSNumber *)port
           printRawData:(NSString *)text
              epsonModel:(int)modelNumber
                success:(RCTResponseSenderBlock)successCallback
                   fail:(RCTResponseSenderBlock)errorCallback {
        _retryAttempts=0;
    _finishedAsyncCall=NO;
    @synchronized (printerDictionary) {
        if(printerDictionary == nil)
        {



            printerDictionary = [[NSMutableDictionary alloc] init];




        }
    }
    Epos2Printer *printer = [[Epos2Printer alloc] initWithPrinterSeries:modelNumber lang:EPOS2_MODEL_ANK];
    NSString *printerLock;

    @synchronized (printerDictionary) {
        printerLock = [printerDictionary objectForKey:host];


        if (printerLock == nil)
        {
                printerLock= [NSString stringWithFormat:@"%@", host];
                [printerDictionary setObject:printerLock forKey:host];
        }

    }
    @synchronized (printerLock) {
            @try{
                __weak NetPrinterEpsonAdapter *weakSelf = self;
            [printer setReceiveEventDelegate:weakSelf];
            do{
              @try{
                _retryAttempts++;
                  [self connectAndSendAux:host printRawData:text success:successCallback fail:errorCallback printerObj:printer];
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
                 [NSThread sleepForTimeInterval:(3.0f * _retryAttempts)];
              }
            }
            while(_retryAttempts<3);

           long delayInSeconds = 3;
           long startTime = [[NSDate date] timeIntervalSince1970];
           long currTime =  [[NSDate date] timeIntervalSince1970];
           while (!_finishedAsyncCall && startTime + delayInSeconds > currTime) {
                        [NSThread sleepForTimeInterval:0.5];
                        currTime =  [[NSDate date] timeIntervalSince1970];

            }
            if (!_finishedAsyncCall) {
                [NSException raise:@"Print failed" format:@"Delegate Function not called"];
            }
            [printer endTransaction];
            [printer disconnect];
            [printer clearCommandBuffer];
            [printer setReceiveEventDelegate:nil];



        } @catch (NSException *exception) {

              [printer endTransaction];
              int failResult=[printer disconnect];
              [printer clearCommandBuffer];
              [printer setReceiveEventDelegate:nil];
              errorCallback(@[[NSString stringWithFormat:@"%@ and disconnect code %i",exception.reason,failResult]]);
        }
            @finally
            {
                _successCallback=nil;
                _errorCallback=nil;
            }
        }






}

- (void) connectAndSendAux:(NSString *)host printRawData:(NSString *)text success:(RCTResponseSenderBlock)successCallback fail:(RCTResponseSenderBlock)errorCallback printerObj:(Epos2Printer *)printer {
        NSString* target = [NSString stringWithFormat:@"TCP:%@", host];
        int result = EPOS2_SUCCESS;
        result = [printer connect:target timeout:5000];
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

    _finishedAsyncCall=YES;

    if ([errMsg  isEqual: @""]) {
        _successCallback != nil ? _successCallback(@[[NSString stringWithFormat:@"Successfuly printed"]]) : nil;
    } else {
        _errorCallback != nil ? _errorCallback(@[[NSString stringWithFormat:@"Delegate with ERROR and message %@",errMsg]]) : nil;
    }


    return;
}

@end
