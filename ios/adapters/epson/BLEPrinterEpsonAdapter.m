//
//  BLEPrinterEpsonAdapter.m
//
//  Created by Till POS on 14/09/21.
//


#import <Foundation/Foundation.h>

#import "BLEPrinterEpsonAdapter.h"
#import "EpsonPrinterSDK.h"
#import "../../utils/NSDataAdditions.h"
#import "../../utils/EpsonUtils.h"

@interface BLEPrinterEpsonAdapter() <Epos2PtrReceiveDelegate>
@end

@implementation BLEPrinterEpsonAdapter {
    RCTResponseSenderBlock _successCallback;
    RCTResponseSenderBlock _errorCallback;
}

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}

- (void) connectAndSend:(NSString *)bdAddress
           printRawData:(NSString *)text
                success:(RCTResponseSenderBlock)successCallback
                   fail:(RCTResponseSenderBlock)errorCallback {
    @try {
        int result = EPOS2_SUCCESS;

        printer = [[Epos2Printer alloc] initWithPrinterSeries:1 lang:EPOS2_MODEL_ANK];
        [printer setReceiveEventDelegate:self];

        NSString* target = [NSString stringWithFormat:@"BT:%@", bdAddress];
        result = [printer connect:target timeout:5000];

        if (result != EPOS2_SUCCESS) {
            [NSException raise:@"Invalid connection" format:@"Can't connect to printer %@", bdAddress];
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

    [printer endTransaction];
    [printer disconnect];
    [printer clearCommandBuffer];
    [printer setReceiveEventDelegate:nil];
    return;
}

@end
