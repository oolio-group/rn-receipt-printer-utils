//
//  BLEPrinterGenericAdapter.m
//
//  Created by Till POS on 14/09/21.
//

#import <Foundation/Foundation.h>

#import "BLEPrinterGenericAdapter.h"
#import "GenericPrinterSDK.h"
#import "../../utils/NSDataAdditions.h"

@interface ExtendedPrinter : Printer

@property (nonatomic, readwrite) NSString* name;
@property (nonatomic, readwrite) NSString* UUIDString;

@end

@implementation ExtendedPrinter : Printer {
    NSString* _UUIDString;
}
    @synthesize name;
    @synthesize UUIDString = _UUIDString;
    - (void) setUUIDString:(NSString *)value {
        _UUIDString = value;
    }
@end

@implementation BLEPrinterGenericAdapter

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_main_queue();
}

- (void) init:(RCTResponseSenderBlock)successCallback
         fail:(RCTResponseSenderBlock)errorCallback {
    @try {
        _printerArray = [NSMutableArray new];
        m_printer = [[NSObject alloc] init];
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(handleNetPrinterConnectedNotification:) name:@"NetPrinterConnected" object:nil];
        // API MISUSE: <CBCentralManager> can only accept this command while in the powered on state
        [[PrinterSDK defaultPrinterSDK] scanPrintersWithCompletion:^(Printer* printer){}];
        successCallback(@[@"Init successful"]);
    } @catch (NSException *exception) {
        errorCallback(@[@"No bluetooth adapter available"]);
    }
}

- (void) handleNetPrinterConnectedNotification:(NSNotification*)notification
{
    m_printer = nil;
}

- (void) getDeviceList:(RCTResponseSenderBlock)successCallback
                  fail:(RCTResponseSenderBlock)errorCallback {
    @try {
        !_printerArray ? [NSException raise:@"Null pointer exception" format:@"Must call init function first"] : nil;
        [[PrinterSDK defaultPrinterSDK] scanPrintersWithCompletion:^(Printer* printer){
            [_printerArray addObject:printer];
            NSMutableArray *mapped = [NSMutableArray arrayWithCapacity:[_printerArray count]];
            [_printerArray enumerateObjectsUsingBlock:^(id obj, NSUInteger idx, BOOL *stop) {
                NSDictionary *dict = @{ @"device_name" : printer.name, @"inner_mac_address" : printer.UUIDString};
                [mapped addObject:dict];
            }];
            NSMutableArray *uniquearray = (NSMutableArray *)[[NSSet setWithArray:mapped] allObjects];;
            successCallback(@[uniquearray]);
        }];
    } @catch (NSException *exception) {
        errorCallback(@[exception.reason]);
    }
}

- (void) connectPrinter:(NSString *)inner_mac_address
                success:(RCTResponseSenderBlock)successCallback
                   fail:(RCTResponseSenderBlock)errorCallback {
    @try {
        __block BOOL found = NO;
        __block Printer* selectedPrinter = nil;
        [_printerArray enumerateObjectsUsingBlock: ^(id obj, NSUInteger idx, BOOL *stop){
            selectedPrinter = (Printer *)obj;
            if ([inner_mac_address isEqualToString:(selectedPrinter.UUIDString)]) {
                found = YES;
                *stop = YES;
            }
        }];

        if (found) {
            [[PrinterSDK defaultPrinterSDK] connectBT:selectedPrinter];
            [[NSNotificationCenter defaultCenter] postNotificationName:@"BLEPrinterConnected" object:nil];
            m_printer = selectedPrinter;
            successCallback(@[[NSString stringWithFormat:@"Connected to printer %@", selectedPrinter.name]]);
        } else {
            [NSException raise:@"Invalid connection" format:@"connectPrinter: Can't connect to printer %@", inner_mac_address];
        }
    } @catch (NSException *exception) {
        errorCallback(@[exception.reason]);
    }
}

- (void) printRawData:(NSString *)text
                 fail:(RCTResponseSenderBlock)errorCallback {
    @try {
        !m_printer ? [NSException raise:@"Invalid connection" format:@"printRawData: Can't connect to printer"] : nil;

        [[PrinterSDK defaultPrinterSDK] sendHex:text];
    } @catch (NSException *exception) {
        errorCallback(@[exception.reason]);
    }
}

- (void) connectAndSend:(NSString *)bdAddress
           printRawData:(NSString *)text
                success:(RCTResponseSenderBlock)successCallback
                   fail:(RCTResponseSenderBlock)errorCallback {
    @try {
        [[PrinterSDK defaultPrinterSDK] scanPrintersWithCompletion:^(Printer* printer){
            [self->_printerArray addObject:printer];
        }];
        
        __block BOOL found = NO;
        __block Printer* selectedPrinter = nil;

        [_printerArray enumerateObjectsUsingBlock: ^(id obj, NSUInteger idx, BOOL *stop){
            selectedPrinter = (Printer *)obj;
            if ([bdAddress isEqualToString:(selectedPrinter.UUIDString)]) {
                found = YES;
                *stop = YES;
            }
        }];

        ExtendedPrinter* extendedPrinter = (ExtendedPrinter*) [ExtendedPrinter alloc];
        [extendedPrinter setUUIDString:bdAddress];
        [[PrinterSDK defaultPrinterSDK] connectBT:extendedPrinter];
        
        NSData* payload = [NSData dataWithBase64EncodedString:text];
        [[PrinterSDK defaultPrinterSDK] sendHex:[payload hexadecimalString]];
        successCallback(@[[NSString stringWithFormat:@"Successfuly printed"]]);
    } @catch (NSException *exception) {
        errorCallback(@[exception.reason]);
    }
}

- (void) closeConn {
    @try {
        !m_printer ? [NSException raise:@"Invalid connection" format:@"closeConn: Can't connect to printer"] : nil;
        [[PrinterSDK defaultPrinterSDK] disconnect];
        m_printer = nil;
    } @catch (NSException *exception) {
        NSLog(@"%@", exception.reason);
    }
}

@end
