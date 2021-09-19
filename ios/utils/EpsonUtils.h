//
//  EpsonUtils.h
//
//  Created by Till POS on 14/09/21.
//

#import "EpsonPrinterSDK.h"

@interface EpsonUtils : NSObject
+ (NSString *)makeErrorMessage:(Epos2PrinterStatusInfo *)status;
@end
