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
}
@property (nonatomic, strong) GCDAsyncUdpSocket      *udpSocketClient;
@property (nonatomic, strong) NSTimer                  *broadcastTimer;
@property (nonatomic, strong) NSMutableArray         *detectedIpArray;
@property (nonatomic, strong) NSThread               *timerThread;
@property (nonatomic, copy) NSDictionary           *connectingRouterDeviceInfo;//当前已连接的路由器设备
@property (nonatomic, copy) NSDictionary           *connectingIPCDeviceInfo;   //当前已连接的IPC设备
@property (nonatomic, copy) void(^resultBlcok)(NSArray *resultDict);
@property (nonatomic, strong) dispatch_source_t timer; //定时器
@property (nonatomic, strong) GCDAsyncSocket *tcpSocketConnect;
@property (nonatomic, copy)  IPConnectDeviceBlock connectionBlock;

@end