//
//  RNNetPrinter.h
//
//  Created by Till POS on 14/09/21.
//

#import <React/RCTBridgeModule.h>
#import "PrinterSDK.h"
#import "utils/NSDataAdditions.h"

@interface RNNetPrinter : NSObject <RCTBridgeModule>{
    Epos2Printer *printer_;
}

@end
