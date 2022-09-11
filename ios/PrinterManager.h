#import <Foundation/Foundation.h>
#import "EpsonPrinterSDK.h"


@interface PrinterManager : NSObject

 (instancetype)sharedManager;

 (NSString *)add:(Epos2Printer*)obj;
 (Epos2Printer*)getObject:(NSString *) identifier;
 (void)remove:(NSString *) identifier;
 (void)removeAll;

@end
