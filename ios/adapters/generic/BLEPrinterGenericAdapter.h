//
//  BLEPrinterGenericAdapter.h
//
//  Created by Till POS on 14/09/21.

#pragma once
#ifndef BLEPrinterGenericAdapter_h
#define BLEPrinterGenericAdapter_h

#if __has_include("RCTBridgeModule.h")
#import "RCTBridgeModule.h"
#else
#import <React/RCTBridgeModule.h>
#endif
#import <CoreBluetooth/CoreBluetooth.h>

@interface BLEPrinterGenericAdapter : NSObject {
    NSMutableArray* _printerArray;
    NSObject* m_printer;
}
- (void) connectAndSend:(NSString *)bdAddress printRawData:(NSString *)text success:(RCTResponseSenderBlock)successCallback fail:(RCTResponseSenderBlock)errorCallback;
@end

#endif /* BLEPrinterGenericAdapter_h */
