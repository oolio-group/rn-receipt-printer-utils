#import <React/RCTBridgeModule.h>
#import "../../utils/NSDataAdditions.h"
#import <Foundation/Foundation.h>

typedef void (^IPConnectDeviceBlock)(int resCode);

enum ErrorStatus : int {
    PRINTER_SUCCESS = 0,
    PRINTER_PARAM,
    PRINTER_CONNECT,
    PRINTER_TIMEOUT,
    PRINTER_MEMORY,
    PRINTER_ILLEGAL,
    PRINTER_PROCESSING,
    PRINTER_NOT_FOUND,
    PRINTER_IN_USE,
    PRINTER_TYPE_INVALID,
    PRINTER_DISCONNECT,
    PRINTER_ALREADY_OPENED,
    PRINTER_ALREADY_USED,
    PRINTER_BOX_COUNT_OVER,
    PRINTER_BOX_CLIENT_OVER,
    PRINTER_UNSUPPORTED,
    PRINTER_DEVICE_BUSY,
    PRINTER_RECOVERY_FAILURE,
    PRINTER_FAILURE = 255
};

@interface NetPrinterSunmiAdapter : NSObject

- (void) connectAndSend:(NSString *_Nullable)host withPort:(nonnull NSNumber *)port printRawData:(NSString *_Nullable)text success:(RCTResponseSenderBlock _Nullable )successCallback fail:(RCTResponseSenderBlock _Nullable )errorCallback;
@end
