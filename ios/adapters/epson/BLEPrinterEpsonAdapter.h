//
//  BLEPrinterEpsonAdapter.h
//
//  Created by Till POS on 14/09/21.
//

#pragma once
#ifndef BLEPrinterEpsonAdapter_h
#define BLEPrinterEpsonAdapter_h

#if __has_include("RCTBridgeModule.h")
#import "RCTBridgeModule.h"
#else
#import <React/RCTBridgeModule.h>
#endif

#import <CoreBluetooth/CoreBluetooth.h>
#import "EpsonPrinterSDK.h"

@interface BLEPrinterEpsonAdapter : NSObject {
    Epos2Printer *printer;
}
- (void) connectAndSend:(NSString *)bdAddress printRawData:(NSString *)text success:(RCTResponseSenderBlock)successCallback fail:(RCTResponseSenderBlock)errorCallback;
@end

#endif /* BLEPrinterEpsonAdapter_h */
