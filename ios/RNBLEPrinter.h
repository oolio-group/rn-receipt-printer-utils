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

@interface RNBLEPrinter : NSObject <RCTBridgeModule>{
}
@end

#endif /* RNBLEPrinter_h */
