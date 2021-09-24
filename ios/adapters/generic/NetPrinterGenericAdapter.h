//
//  NetPrinterGenericAdapter.h
//
//  Created by Till POS on 14/09/21.
//

#import <React/RCTBridgeModule.h>

@interface NetPrinterGenericAdapter : NSObject {
}
- (void) connectAndSend:(NSString *)host withPort:(nonnull NSNumber *)port printRawData:(NSString *_Nullable)text success:(RCTResponseSenderBlock _Nullable )successCallback fail:(RCTResponseSenderBlock _Nullable )errorCallback;
@end
