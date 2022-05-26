//
//  BLEPrinterSNBCAdapter.h
//  Pods
//
//  Created by Vankong Veng on 25/5/22.
//
#pragma once
#ifndef BLEPrinterSNBCAdapter_h
#define BLEPrinterSNBCAdapter_h

#if __has_include("RCTBridgeModule.h")
#import "RCTBridgeModule.h"
#else
#import <React/RCTBridgeModule.h>
#endif
#import <CoreBluetooth/CoreBluetooth.h>
#import "POSSDK.h"

@interface BLEPrinterSNBCAdapter : NSObject {
//    NSMutableArray* _printerArray;
    NSObject* m_printer;
}
- (void) connectAndSend:(NSString *)bdAddress printRawData:(NSString *)text success:(RCTResponseSenderBlock)successCallback fail:(RCTResponseSenderBlock)errorCallback;
@end

#endif /* BLEPrinterSNBCAdapter_h */
