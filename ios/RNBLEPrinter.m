//
//  RNBLEPrinter.m
//
//  Created by Till POS on 14/09/21.
//


#import <Foundation/Foundation.h>

#import "RNBLEPrinter.h"
#import "adapters/epson/BLEPrinterEpsonAdapter.h"
#import "adapters/generic/BLEPrinterGenericAdapter.h"
#import "utils/NSDataAdditions.h"
#import "utils/EpsonUtils.h"

@implementation RNBLEPrinter

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0);
}

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(connectAndSend:(NSString *)bdAddress
                  printRawData:(NSString *)text
                  brand:(NSString *)brand
                  series:(NSString *)series
                  success:(RCTResponseSenderBlock)successCallback
                  fail:(RCTResponseSenderBlock)errorCallback) {
    @try {
        int number;
        if ([series isEqual:@"TM_M30"]){
            number = 1;
        }
        else if ([series isEqual:@"TM_M30II"]){
            number = 21;
        }
        else if ([series isEqual:@"TM_U220"]){
            number = 15;
        }
        else if ([series isEqual:@"TM_T82"]){
            number = 10;
        }
        else if ([series isEqual:@"TM_L90"]){
            number = 17;
        }
        else {
            number = 1;
        }
        if ([brand  isEqual: @"EPSON"]) {
            BLEPrinterEpsonAdapter *adapter = [BLEPrinterEpsonAdapter alloc];
            [adapter connectAndSend:bdAddress printRawData:text epsonModel:number success:successCallback fail:errorCallback];
        }
        else {
            BLEPrinterGenericAdapter *adapter = [BLEPrinterGenericAdapter alloc];
            [adapter connectAndSend:bdAddress printRawData:text success:successCallback fail:errorCallback];
        }
    } @catch (NSException *exception) {
        errorCallback(@[exception.reason]);
    }
}

@end
