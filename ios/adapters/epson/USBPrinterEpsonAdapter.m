//
//  USBPrinterEpsonAdapter.h
//  RNThermalReceiptPrinter
//
//  Created by MTT on 06/10/19.
//  Copyright © 2019 Facebook. All rights reserved.
//
#pragma once
#ifndef USBPrinterEpsonAdapter_h
#define USBPrinterEpsonAdapter_h

#if __has_include("RCTBridgeModule.h")
#import "RCTBridgeModule.h"
#else
#import <React/RCTBridgeModule.h>
#endif
#import <CoreBluetooth/CoreBluetooth.h>

@interface USBPrinterEpsonAdapter : NSObject {
    NSMutableArray* _printerArray;
    NSObject* m_printer;
}
@end

#endif /* USBPrinterEpsonAdapter_h */
