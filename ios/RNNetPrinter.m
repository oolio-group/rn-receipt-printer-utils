//
//  RNNetPrinter.m
//
//  Created by Till POS on 14/09/21.
//


#import "RNNetPrinter.h"
#import "adapters/epson/NetPrinterEpsonAdapter.h"
#import "adapters/generic/NetPrinterGenericAdapter.h"
#import "utils/NSDataAdditions.h"
#import "utils/EpsonUtils.h"

@implementation RNNetPrinter

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(connectAndSend:(NSString *)host
                  withPort:(nonnull NSNumber *)port
                  printRawData:(NSString *)text
                  brand:(NSString *)brand
                  success:(RCTResponseSenderBlock)successCallback
                  fail:(RCTResponseSenderBlock)errorCallback) {
    @try {
        if ([brand  isEqual: @"EPSON"]) {
            NetPrinterEpsonAdapter *adapter = [NetPrinterEpsonAdapter alloc];
            [adapter connectAndSend:host withPort:port printRawData:text success:successCallback fail:errorCallback];
        }
        else {
            NetPrinterGenericAdapter *adapter = [NetPrinterGenericAdapter alloc];
            [adapter connectAndSend:host withPort:port printRawData:text success:successCallback fail:errorCallback];
        }
    } @catch (NSException *exception) {
        errorCallback(@[exception.reason]);
    }
}
@end
