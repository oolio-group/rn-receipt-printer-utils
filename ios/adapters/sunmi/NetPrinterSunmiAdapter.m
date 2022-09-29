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
    NSErr1
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

- (void)connectSocketWithIP:(NSString *)ip completeBlock:(IPConnectDeviceBlock)completeBlock {
    self.connectionBlock = completeBlock;
    [self.tcpSocketConnect connectToHost:ip onPort:9100 error:nil];
}

#pragma mark - GCDAsyncSocketDelegate

- (void)socket:(GCDAsyncSocket *)sock didConnectToHost:(NSString *)host port:(uint16_t)port {

    NSLog(@"TCP connected to host: %@ port: %d", host, port);
    if (self.connectionBlock) {
        self.connectionBlock(PRINTER_SUCCESS);
    }
}

- (void)socketDidDisconnect:(GCDAsyncSocket *)sock withError:(nullable NSError *)err {
    NSLog(@"Disconnected from socket with error: %@", err);
    if (self.connectionBlock) {
        err != nil? self.connectionBlock(PRINTER_ILLEGAL) : seld.connectionBlock(PRINTER_DISCONNECT)
    }
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
