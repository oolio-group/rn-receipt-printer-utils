//
//  RNBLEPrinter.h
//
//  Created by Till POS on 14/09/21.
//

#pragma once
#ifndef RNBLEPrinter_h
#define RNBLEPrinter_h

#if __has_include("RCTBridgeModule.h")
#import "RCTBridgeModule.h"
#else
#import <React/RCTBridgeModule.h>
#endif
#import <CoreBluetooth/CoreBluetooth.h>
#import "PrinterSDK.h"

@interface RNBLEPrinter : NSObject <RCTBridgeModule>{
    Epos2Printer *printer_;
}
@end

#endif /* RNBLEPrinter_h */
