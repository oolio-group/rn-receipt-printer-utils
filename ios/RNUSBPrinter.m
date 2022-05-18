//
//  RNUSBPrinter.m
//
//  Created by Till POS on 14/09/21.
//


#import "RNUSBPrinter.h"

@implementation RNUSBPrinter

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0);
}
RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(connectAndSend:(NSInteger)vendorId
                  withProductID:(NSInteger)productId
                  printRawData:(NSData *)text
                  success:(RCTResponseSenderBlock)successCallback
                  fail:(RCTResponseSenderBlock)errorCallback) {
    // TODO
    errorCallback(@[@"This function is not supported"]);
}
@end

