#import "NetPrinterSunmiAdapter.h"
#import "sys/utsname.h"
#import "GCDAsyncSocket.h"
#import <AdSupport/AdSupport.h>
#import <ifaddrs.h>
#import <arpa/inet.h>
#import <sys/sockio.h>
#import <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/sysctl.h>
#include <net/if.h>
#include <net/if_dl.h>

#define BROADCAST_IP        @"224.0.0.1"

@interface NetPrinterSunmiAdapter()<GCDAsyncSocketDelegate>
{
    NSString *ipString;
    RCTResponseSenderBlock _successCallback;
    RCTResponseSenderBlock _errorCallback;
}
@property (nonatomic, strong) dispatch_source_t timer; //定时器
@property (nonatomic, strong) GCDAsyncSocket *tcpSocketConnect;
@property (nonatomic, copy)  IPConnectDeviceBlock connectionBlock;

@end

@implementation NetPrinterSunmiAdapter

- (dispatch_queue_t)methodQueue
{
    return dispatch_get_global_queue(DISPATCH_QUEUE_PRIORITY_HIGH, 0);
}


- (void) connectAndSend:(NSString *)host
               withPort:(nonnull NSNumber *)port
           printRawData:(NSString *)text
                success:(RCTResponseSenderBlock)successCallback
                   fail:(RCTResponseSenderBlock)errorCallback {

    @try {
        BOOL isConnectSuccess = [self connectSocketWithIP:host];
        !isConnectSuccess ? [NSException raise:@"Invalid connection" format:@"Can't connect to printer %@", host] : nil;
         _successCallback= successCallback;
         _errorCallback= errorCallback;
        NSData* payload = [NSData dataWithBase64EncodedString:text];
        NSString* hexData = [payload hexadecimalString];
        [self controlDevicePrintingData:hexData];
        [self.tcpSocketConnect disconnectAfterWriting];
    } @catch (NSException *exception) {
        errorCallback(@[exception.reason]);
    }
}


- (BOOL)connectSocketWithIP:(NSString *)ip  {

    return [self.tcpSocketConnect connectToHost:ip onPort:9100 error:nil];
}

#pragma mark - GCDAsyncSocketDelegate

- (void)socket:(GCDAsyncSocket *)sock didConnectToHost:(NSString *)host port:(uint16_t)port {

    NSLog(@"TCP connected to host: %@ port: %d", host, port);

}

- (void)socketDidDisconnect:(GCDAsyncSocket *)sock withError:(nullable NSError *)err {
    NSLog(@"Disconnected from socket with error: %@", err);

      if (err!= nil)
      {
        _errorCallback != nil ? _errorCallback(@[[NSString stringWithFormat:@"Delegate with ERROR"]]) : nil;

    } else {
       _successCallback != nil ? _successCallback(@[[NSString stringWithFormat:@"Successfuly printed"]]) : nil;
    }

    _successCallback = nil;
    _errorCallback = nil;
    [self._tcpSocketConnect setDelegate: nil];
    [self._tcpSocketConnect release];
}

// MARK： 写数据
- (void)controlDevicePrintingData:(NSData *)ipData {
    [self.tcpSocketConnect writeData:ipData withTimeout:10 tag:100];
}

// MARK: 读数据
-(void)readDataFromSocketWithTag: (NSInteger)tag {
    [self.tcpSocketConnect readDataWithTimeout:-1 tag:tag];
}
#pragma mark - Getters
- (GCDAsyncSocket *)tcpSocketConnect {
    if (!_tcpSocketConnect) {
        _tcpSocketConnect = [[GCDAsyncSocket alloc] initWithDelegate:self delegateQueue:methodQueue()];
    }

    return _tcpSocketConnect;
}
