//
//  USBPrinterGenericAdapter.m
//
//  Created by Till POS on 14/09/21.
//

#import "USBPrinterGenericAdapter.h"
#import "GenericPrinterSDK.h"

@implementation USBPrinterGenericAdapter

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}

- (void) init:(RCTResponseSenderBlock)successCallback
         fail:(RCTResponseSenderBlock)errorCallback {
    // TODO
    successCallback(@[@"Init successful"]);
}

- (void) getDeviceList:(RCTResponseSenderBlock)successCallback
                  fail:(RCTResponseSenderBlock)errorCallback {
    // TODO
    NSMutableArray *printerArray = [NSMutableArray new];
    successCallback(@[printerArray]);
}

- (void) connectPrinter:(NSInteger)vendorId
          withProductID:(NSInteger)productId
                success:(RCTResponseSenderBlock)successCallback
                   fail:(RCTResponseSenderBlock)errorCallback {
    // TODO
    errorCallback(@[@"This function is not supported"]);
}

- (void) printRawData:(NSString *)text
                 fail:(RCTResponseSenderBlock)errorCallback {
    // TODO
    errorCallback(@[@"This function is not supported"]);
}

- (void) closeConn {
    // TODO
}

@end
