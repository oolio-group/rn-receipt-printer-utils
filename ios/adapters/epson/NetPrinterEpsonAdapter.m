//
//  NetPrinterEpsonAdapter.m
//
//  Created by Till POS on 14/09/21.
//


#import "NetPrinterEpsonAdapter.h"
#import "EpsonPrinterSDK.h"
#import "../../utils/NSDataAdditions.h"
#import "../../utils/EpsonUtils.h"

@interface NetPrinterEpsonAdapter() <Epos2PtrReceiveDelegate>
@end

static NSMutableDictionary *printersByIP;

@implementation NetPrinterEpsonAdapter {
    RCTResponseSenderBlock _successCallback;
    RCTResponseSenderBlock _errorCallback;
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
    @try {
      if(printersByIP == nil)
      {
         printersByIP=[[NSMutableDictionary alloc]init];
      }
    
     Epos2Printer *printer = [printersByIP objectForKey:host];

      if (printer == nil) {
        printer = [[Epos2Printer alloc] initWithPrinterSeries:modelNumber
                                                         lang:EPOS2_MODEL_ANK];
        [printersByIP setObject:printer forKey:host];
      }

       Epos2PrinterStatusInfo* status = [printer getStatus];
    [printer setReceiveEventDelegate:self];
        int result = EPOS2_SUCCESS;
        
        NSString* target = [NSString stringWithFormat:@"TCP:%@", host];
        result = [printer connect:target timeout:5000];

        if (result != EPOS2_SUCCESS && result != EPOS2_ERR_ILLEGAL) {
            [NSException raise:@"Invalid connection" format:@"Can't connect to printer %@", host];
        }

        NSData* payload = [NSData dataWithBase64EncodedString:text];
        [printer addCommand:payload];
        result = [printer sendData:5000];

        if (result != EPOS2_SUCCESS) {
            [NSException raise:@"Print failed" format:@"Error occurred while printing"];
        }

        _successCallback = successCallback;
        _errorCallback = errorCallback;

    } @catch (NSException *exception) {
        errorCallback(@[exception.reason]);
    }
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
    int failResult = [printerObj disconnect];
    while (failResult == EPOS2_ERR_PROCESSING) {
        [NSThread sleepForTimeInterval:0.5];
        failResult = [self netAdapterDisconnect:printer];
    }
    [printerObj clearCommandBuffer];
    [printerObj setReceiveEventDelegate:nil];
    return;
}

@end
