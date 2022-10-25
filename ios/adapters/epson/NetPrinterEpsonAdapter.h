//
//  NetPrinterEpsonAdapter.h
//
//  Created by Till POS on 14/09/21.
//

#import <React/RCTBridgeModule.h>
#import "EpsonPrinterSDK.h"
#import "../../utils/NSDataAdditions.h"

@interface NetPrinterEpsonAdapter : NSObject {

}
- (void) connectAndSend:(NSString *_Nullable)host withPort:(nonnull NSNumber *)port printRawData:(NSString *_Nullable)text epsonModel:(int)modelNumber success:(RCTResponseSenderBlock _Nullable )successCallback fail:(RCTResponseSenderBlock _Nullable )errorCallback;
@end
