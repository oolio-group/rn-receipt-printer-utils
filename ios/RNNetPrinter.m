//
//  RNNetPrinter.m
//
//  Created by Till POS on 14/09/21.
//

#import "RNNetPrinter.h"
#import "adapters/epson/NetPrinterEpsonAdapter.h"
#import "adapters/generic/NetPrinterGenericAdapter.h"
#import "utils/EpsonUtils.h"
#import "utils/NSDataAdditions.h"

@implementation RNNetPrinter

- (dispatch_queue_t)methodQueue {
  return dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0);
}

RCT_EXPORT_MODULE()

RCT_EXPORT_METHOD(connectAndSend
                  : (NSString *)host withPort
                  : (nonnull NSNumber *)port printRawData
                  : (NSString *)text brand
                  : (NSString *)brand series
                  : (NSString *)series success
                  : (RCTResponseSenderBlock)successCallback fail
                  : (RCTResponseSenderBlock)errorCallback) {
  @autoreleasepool {
    @try {
      int number;
      if ([series isEqual:@"TM_M30"]) {
        number = 1;
      } else if ([series isEqual:@"TM_M30II"]) {
        number = 21;
      } else if ([series isEqual:@"TM_U220"]) {
        number = 15;
      } else if ([series isEqual:@"TM_T82"]) {
        number = 10;
      } else if ([series isEqual:@"TM_L90"]) {
        number = 17;
      } else {
        number = 1;
      }
      if ([brand isEqual:@"EPSON"]) {
        NetPrinterEpsonAdapter *adapter = [NetPrinterEpsonAdapter alloc];
        [adapter connectAndSend:host
                       withPort:port
                   printRawData:text
                     epsonModel:number
                        success:successCallback
                           fail:errorCallback];
      } else {
        NetPrinterGenericAdapter *adapter = [NetPrinterGenericAdapter alloc];
        [adapter connectAndSend:host
                       withPort:port
                   printRawData:text
                        success:successCallback
                           fail:errorCallback];
      }
    } @catch (NSException *exception) {
      errorCallback(@[ exception.reason ]);
    }
  }
}
@end
