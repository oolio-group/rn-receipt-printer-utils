//
//  BLEPrinterSNBCAdapter.m
//  tillpos-rn-receipt-printer-utils
//
//  Created by Vankong Veng on 25/5/22.
//

#import <Foundation/Foundation.h>
#import "BLEPrinterSNBCAdapter.h"
#import "POSSDK.h"


@interface BLEPrinterSNBCAdapter() //change this
@property (nonatomic) DEVICEHANDLE handle;
@end

@implementation BLEPrinterSNBCAdapter {
    RCTResponseSenderBlock _successCallback;
    RCTResponseSenderBlock _errorCallback;
}

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0);
}

- (void) connectAndSend:(NSString *)bdAddress
           printRawData:(NSString *)text
                success:(RCTResponseSenderBlock)successCallback
                   fail:(RCTResponseSenderBlock)errorCallback {
    @try { //write this

        _handle = Init("POS");
       int result = ERR_SUCCESS;
//       // NSString *tmpStr = [NSString stringWithFormat:@"%s|%s", [tmpArr[1] UTF8String], [tmpArr[2] UTF8String]];
       char *payload = (char *)[text UTF8String];
//        char *selectPrinter = (char *)[tmpStr UTF8String]; //set to specific bluetooth address?
       result = OpenBlueToothPort(_handle, "A0:E6:F8:26:62:38");
       result = SendPortData(_handle, payload, 100, 100);
//
//        _successCallback = successCallback;
//        _errorCallback = errorCallback;
    } @catch (NSException *exception) {
//        errorCallback(@[exception.reason]);
    }
}

@end
