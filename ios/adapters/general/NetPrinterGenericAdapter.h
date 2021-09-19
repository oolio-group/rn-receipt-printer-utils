//
//  NetPrinterGenericAdapter.h
//
//  Created by Till POS on 14/09/21.
//

#import <React/RCTBridgeModule.h>
#import <React/RCTEventEmitter.h>

@interface NetPrinterGenericAdapter : RCTEventEmitter {
    NSString *connected_ip;
    NSString *current_scan_ip;
    NSMutableArray* _printerArray;
    bool is_scanning;
}
- (void) connectAndSend:(NSString *)host withPort:(nonnull NSNumber *)port printRawData:(NSString *)text success:(RCTResponseSenderBlock)successCallback fail:(RCTResponseSenderBlock)errorCallback;
@end
