#import <React/RCTBridgeModule.h>
#import "../../utils/NSDataAdditions.h"
#import <Foundation/Foundation.h>

@interface NetPrinterSunmiAdapter : NSObject

- (void) connectAndSend:(NSString *_Nullable)host withPort:(nonnull NSNumber *)port printRawData:(NSString *_Nullable)text success:(RCTResponseSenderBlock _Nullable )successCallback fail:(RCTResponseSenderBlock _Nullable )errorCallback;
@end