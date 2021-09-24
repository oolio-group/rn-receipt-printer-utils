//
//  NetPrinterGenericAdapter.m
//
//  Created by Till POS on 14/09/21.
//

#import "NetPrinterGenericAdapter.h"
#import "GenericPrinterSDK.h"
#import "../../utils/NSDataAdditions.h"

@implementation NetPrinterGenericAdapter

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}

- (void) connectAndSend:(NSString *)host
               withPort:(nonnull NSNumber *)port
           printRawData:(NSString *)text
                success:(RCTResponseSenderBlock)successCallback
                   fail:(RCTResponseSenderBlock)errorCallback {
    @try {
        BOOL isConnectSuccess = [[PrinterSDK defaultPrinterSDK] connectIP:host];
        !isConnectSuccess ? [NSException raise:@"Invalid connection" format:@"Can't connect to printer %@", host] : nil;
        NSData* payload = [NSData dataWithBase64EncodedString:text];
        NSString* hexData = [payload hexadecimalString];
        [[PrinterSDK defaultPrinterSDK] sendHex:hexData];
        successCallback(@[[NSString stringWithFormat:@"Sent to printer %@", host]]);
    } @catch (NSException *exception) {
        errorCallback(@[exception.reason]);
    }
}

@end
