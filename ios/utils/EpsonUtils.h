//
//  EpsonUtils.h
//
//  Created by Till POS on 14/09/21.
//

#import "PrinterSDK.h"

@interface EpsonUtils : NSObject
+ (NSString *)makeErrorMessage:(Epos2PrinterStatusInfo *)status;
@end
