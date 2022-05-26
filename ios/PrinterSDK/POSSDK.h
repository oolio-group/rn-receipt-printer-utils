////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @file:    POSSDKDLL.h
/// @brief:    Declares the bpladll class
///
///
/// Copyright SNBC Corp. 2019
/// ALL RGIHTS RESERVED.
///
/// @~Chinese
/// @file:    POSSDKDLL.h
/// @brief:
///
///
/// 山东新北洋信息技术有限公司 2019\n
/// 所有权利保留。
////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma once


// 接口函数导出形式定义
#ifndef POSSDKCALL_MODE
#ifdef _WIN32
/// A macro that defines possdkcall mode
#define POSSDKCALL_MODE    __stdcall
#else
#define POSSDKCALL_MODE
#endif
#endif

/**************************************************************************************************************************
 * 宏定义
 ************************************************************************************************************************/
#ifndef POSSDK_DATA_TYPE_DEF

#define POSSDK_DATA_TYPE_DEF

////////////////////////////////////////////////////////////////////////////////////////////////////
/// type of return handle
/// @~English
/// Returns the handle type
///
///
/// @~Chinese
/// 返回句柄类型
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef void*    DEVICEHANDLE;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Success
/// @~Chinese
/// @brief 无IO通讯
////////////////////////////////////////////////////////////////////////////////////////////////////
const int PORT_NONE = 0;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Serial port
/// @~Chinese
/// @brief 串口
////////////////////////////////////////////////////////////////////////////////////////////////////
const int PORT_SERIAL = 1;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief API mode
/// @~Chinese
/// @brief API模式
////////////////////////////////////////////////////////////////////////////////////////////////////
const int PORT_USBDEVICE_API = 2;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief USB class mode
/// @~Chinese
/// @brief USB 类模式
////////////////////////////////////////////////////////////////////////////////////////////////////
const int PORT_USBDEVICE_CLASS = 3;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Net port
/// @~Chinese
/// @brief 网口
////////////////////////////////////////////////////////////////////////////////////////////////////
const int PORT_ETHERNET = 4;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Lpt port
/// @~Chinese
/// @brief 并口
////////////////////////////////////////////////////////////////////////////////////////////////////
const int PORT_LPT = 5;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Print Driver
/// @~Chinese
/// @brief 打印机驱动
////////////////////////////////////////////////////////////////////////////////////////////////////
const int PORT_DRIVER = 6;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Bluetooth
/// @~Chinese
/// @brief 蓝牙
////////////////////////////////////////////////////////////////////////////////////////////////////
const int PORT_BLT = 7;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Bluetooth_MFI
/// @~Chinese
/// @brief 蓝牙MFI
////////////////////////////////////////////////////////////////////////////////////////////////////
const int PORT_BLT_MFI = 8;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Success
/// @~Chinese
/// @brief 成功
////////////////////////////////////////////////////////////////////////////////////////////////////
const int ERR_SUCCESS = 0;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Fail
/// @~Chinese
/// @brief 失败
////////////////////////////////////////////////////////////////////////////////////////////////////
const int ERR_FAIL = -1;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Invalid handle
/// @~Chinese
/// @brief 无效句柄
////////////////////////////////////////////////////////////////////////////////////////////////////
const int ERR_HANDLE = -2;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Invalid parameter
/// @~Chinese
/// @brief 无效参数
////////////////////////////////////////////////////////////////////////////////////////////////////
const int ERR_PARAMATER = -3;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Parameter file error
/// @~Chinese
/// @brief 参数文件错误
////////////////////////////////////////////////////////////////////////////////////////////////////
const int ERR_FILE = -4;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Error reading file or data
/// @~Chinese
/// @brief 读取文件或数据错误
////////////////////////////////////////////////////////////////////////////////////////////////////
const int ERR_READ = -5;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Error in issuing file or data
/// @~Chinese
/// @brief 下发文件或数据错误
////////////////////////////////////////////////////////////////////////////////////////////////////
const int ERR_WRITE = -6;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief This feature is not supported
/// @~Chinese
/// @brief 此功能不支持
////////////////////////////////////////////////////////////////////////////////////////////////////
const int ERR_NOT_SUPPORT = -7;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Bitmap error
/// @~Chinese
/// @brief 位图错误
////////////////////////////////////////////////////////////////////////////////////////////////////
const int ERR_BITMAP_INVAILD = -8;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Dynamic library failed to load
/// @~Chinese
/// @brief 动态库加载失败
////////////////////////////////////////////////////////////////////////////////////////////////////
const int ERR_LOADDLL_FAILURE = -9;
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief Firmware does not support
/// @~Chinese
/// @brief 固件不支持
////////////////////////////////////////////////////////////////////////////////////////////////////
const int ERR_FIRNOSUPPORT = -10;

//在此继续添加错误.........
////////////////////////////////////////////////////////////////////////////////////////////////////
/// @~English
/// @brief An unknown error
/// @~Chinese
/// @brief 未知错误
////////////////////////////////////////////////////////////////////////////////////////////////////
const int ERR_UNKOWN_ERROR = -127;

#endif


/**************************************************************************************************************************
 * 参数设置
 ************************************************************************************************************************/
/// TCP协议
const int     TCP_PROTOCOL = 0;

/// UDP协议
const int     UDP_PROTOCOL = 1;

/// 不广播
const int   NOTBROADCAST = 0;

/// 广播
const int   BROADCAST = 1;


#ifdef __cplusplus
/// .
extern "C"
{
#endif // __cplusplus
    //*****************API function************************************************
    //通讯
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Enumerate device names
    ///
    /// @param [in]    nOperationType Port type, The effective parameters are as follows:
    ///             |Valid value|Meaning|
    ///             |---------|---------|
    ///             | ::PORT_USBDEVICE_CLASS     |USB Class mode|
    ///             | ::PORT_USBDEVICE_API     |USB API mode|
    ///             | ::PORT_SERIAL     |Serial port|
    ///             | ::PORT_ETHERNET     |Network port|
    ///             | ::PORT_DRIVER    |Printer driver|
    ///             | ::PORT_BLT    |Bluetooth|
    ///             | ::PORT_BLT_MFI    |Bluetooth MFI|
    ///             | ::PORT_LPT    |Lpt port|
    /// @param [out] szDeviceNameBuf The buffer of name list each name terminator with \@, This terminator is not used as the name information for the enumeration. It is only used to divide multiple name applications.Such as "BTP-L540@BTP-L520@".
    /// @param [in]     nBufLen        Buffer size must match the name list buffer size.
    /// @param [out] npNumber        The number of name list.
    ///
    /// <b>Sample code\n</b>
    /// See details @ref EG_EnumDeviceInfo
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    ///
    /// @~Chinese
    /// @brief 枚举设备名称
    ///
    /// @param [in]  nOperationType 端口类型，有效参数如下：
    ///             |有效值|含义|
    ///             |---------|---------|
    ///             | ::PORT_USBDEVICE_CLASS     |USB 类模式|
    ///             | ::PORT_USBDEVICE_API     |USB API模式|
    ///             | ::PORT_SERIAL     |串口|
    ///             | ::PORT_ETHERNET     |网口|
    ///             | ::PORT_DRIVER    |打印机驱动|
    ///             | ::PORT_BLT    |蓝牙|
    ///             | ::PORT_BLT_MFI    |蓝牙 MFI|
    ///             | ::PORT_LPT    |并口|
    /// @param [out] szDeviceNameBuf 名称列表缓冲区 每个名称结束符为\@，此结束符不作为枚举的名称信息，只用于划分多个名称应用。如“BTP-L540\@BTP-L520\@”。
    /// @param [in]     nBufLen        缓冲区大小 必须与名称列表缓冲区大小一致。
    /// @param [out] npNumber        名称列表数量。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_EnumDeviceInfo
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    int POSSDKCALL_MODE EnumDeviceInfo(int nOperationType, char *szDeviceNameBuf, int nBufLen, int *npNumber);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Initializes the device
    ///
    /// @param [in]    szDeviceName    Device name, According to the different printer input specific character string.
    ///             Btp-s80 and other receipt printers use "POS", BK series unit printers use "KIOSK", BT series unit printers use "TKIOSK", BTP_M300 and other impact printers use "IMPACT".
    ///
    /// <b>Remark\n</b>
    /// 1.iOS only support POS and IMPACT machine.
    ///
    /// @return
    /// Success：Returns the device handle,this handle is the first parameter of the execution function interface.\n
    /// Fail：\n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    ///
    /// @~Chinese
    /// @brief 初始化设备
    ///
    /// @param [in]    szDeviceName    设备名称,根据不同的打印机输入特定的字符串。
    ///             BTP-S80等收据类打印机使用“POS”,BK系列单元类打印机使用“KIOSK”,BT系列单元类打印机使用“TKIOSK”，BTP_M300等针打打印机使用“IMPACT”。
    ///
    /// <b>备注\n</b>
    /// 1、iOS只支持POS和IMPACT类设备。
    ///
    /// @return
    /// 成功：返回设备句柄，此句柄为执行功能接口的第一个参数。\n
    /// 失败：\n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    DEVICEHANDLE POSSDKCALL_MODE Init(char *szDeviceName);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Open serial port
    ///
    /// @param            hDev            The device handle.
    /// @param [in]    szName            The name of serial port, such as "COM1", "COM2", "COM3", "COM4".
    /// @param            nComBaudrate    The com baud rate. Can be these values:2400,4800,9600,19200,38400,57600,115200etc.
    ///                             The baud rate value is related to the printer port parameters, the maximum should not exceed 256000.
    /// @param            nComDataBits    The com data bits. Valid values are 4,5,6,7,8. The value is related to the printer port parameters.
    /// @param            nComStopBits    The com stop bits.
    ///             |Valid value|Actual value|
    ///             |---------|---------|
    ///             |0     |1|
    ///             |1     |1.5|
    ///             |2     |2|
    /// @param [in]    nComParity      The parity method for the specifies serial port.\n
    ///             |Valid value|Actual value|
    ///             |---------|---------|
    ///             |0     |No checkout|
    ///             |1     |Odd parity|
    ///             |2     |Parity checking|
    ///             |3     |Mark inspection|
    ///             |4     |empty-cell test|
    /// @param [in]    nParam            The flow control mode of the specify serial port.
    ///             |Valid value|Actual value|
    ///             |---------|---------|
    ///             |0     |DTR/DSR|
    ///             |1     |RTS/CTS|
    ///             |2     |XON/XOFF|
    ///             |3     |NULL|
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese.
    ///
    /// @brief 打开串口设备
    ///
    /// @param [in]    hDev            设备句柄。
    /// @param [in]    szName            串口名称，如“COM1”，“COM2”，“COM3”，“COM4”。
    /// @param [in]    nComBaudrate    指定串口的波特率（bps）。 可以为以下值之一：
    ///                             2400，4800，9600，19200，38400，57600，115200等。
    ///                             具体的值与打印机的端口参数有关，不过最大不应超过256000。
    /// @param [in]    nComDataBits    指定串口通讯时的数据位数。有效值为4、5、6、7、8。具体的值与打印机的端口参数有关。
    /// @param [in]    nComStopBits    指定串口通讯时的数据停止位数。
    ///             |有效值|实际值|
    ///             |---------|---------|
    ///             |0     |1|
    ///             |1     |1.5|
    ///             |2     |2|
    /// @param [in]    nComParity      指定串口的奇偶校验方法。\n
    ///             |有效值|实际值|
    ///             |---------|---------|
    ///             |0     |无校验|
    ///             |1     |奇校验|
    ///             |2     |偶校验|
    ///             |3     |标志检验|
    ///             |4     |空格检验|
    /// @param [in]    nParam            指定串口的流控制（握手）方式、或表示通讯方式。
    ///             |有效值|实际值|
    ///             |---------|---------|
    ///             |0     |DTR/DSR|
    ///             |1     |RTS/CTS|
    ///             |2     |XON/XOFF|
    ///             |3     |无|
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE OpenCOMPort(DEVICEHANDLE hDev, char *szName, int nComBaudrate, int nComDataBits, int nComStopBits, int nComParity, int nParam);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Opens lpt port device
    ///
    /// @param [in] hDev      Device handle.
    /// @param [in]    szName    Lpt port name, such as:"LPT1","LPT2","LPT3".
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 打开字节并口设备
    ///
    /// @param [in]    hDev      设备句柄。
    /// @param [in]    szName    字节并口名称，如：“LPT1”,“LPT2”,“LPT3”。
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE OpenLPTPort(DEVICEHANDLE hDev, char *szName);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    ///
    /// @brief Opens USB API mode device
    ///
    /// @param    hDev         Device handle.
    /// @param    nDeviceId    Identifier for the device.Range: must be greater than -1.
    ///
    ///
    /// <b>Remark\n</b>
    /// 1.The identifier can be viewed by "register-HKEY_LOCAL_MACHINE--SOFTWARE--BEIYANG--PRINTERPORT"\n
    /// 2.When nDeviceId equals -1, opens the currently connected device by default.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 打开USB API模式设备
    ///
    /// @param [in]    hDev      设备句柄。
    /// @param [in] nDeviceId    设备内部ID号，范围：必须大于-1。
    ///
    ///
    /// <b>备注\n</b>
    /// 1、内部ID号可通过"注册表-HKEY_LOCAL_MACHINE--SOFTWARE--BEIYANG--PRINTERPORT"查看。\n
    /// 2、此功能nDeviceId等于-1时，默认打开当前已连接的设备。
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE OpenUsbApiPort(DEVICEHANDLE hDev, int nDeviceId);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Opens USB class mode device
    ///
    /// @param [in] hDev    Device handle.
    /// @param [in]    szName              The printer name, it can be viewed by device enumeration interface or computer device and printer page.
    /// @param [in] nIsSplitStatus    Automatic status returns whether to split. When value is 1, the AutoQueryStatus interface is not available.
    ///             |Valid value|Actual value|
    ///             |---------|---------|
    ///             |0     |unsplit|
    ///             |1     |split|
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 打开USB 类模式设备
    ///
    /// @param [in]    hDev      设备句柄。
    /// @param [in]    szName              打印机名称，可通过枚举设备接口查看或者电脑的设备和打印机页面。
    /// @param [in] nIsSplitStatus    自动状态返回是否拆分。当取值为1时，AutoQueryStatus 接口无法使用。
    ///             |有效值|实际值|
    ///             |---------|---------|
    ///             |0     |不拆分|
    ///             |1     |拆分|
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE OpenUsbClassPort(DEVICEHANDLE hDev, char *szName, int nIsSplitStatus);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Opens net port device(by enumeration of device names)
    ///
    /// @param [in]    hDev      Device handle.
    /// @param [in,out]    szName    Enumeration of device names.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    /// @brief 打开网口设备（通过枚举的设备名称）
    ///
    /// @param [in]    hDev      设备句柄。
    /// @param [in]    szName    枚举的设备名称。
    ///
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE OpenNetPortByName(DEVICEHANDLE hDev, char *szName);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Opens net port device(by IP address)
    ///
    /// @param [in] hDev             Device handle.
    /// @param [in]    szNetIP             The IP address of Device, such as:"192.168.1.251".
    /// @param [in] nPort             The port, such as :"9100".
    /// @param [in]    nProtocalType    Type of the protocal, 0:TCP,1:UDP.
    /// @param [in]    nBroadcast       0:Don't broadcast, 1:Broadcast.
    ///
    /// <b>Remark\n</b>
    /// This interface supports JK-E02,JK-E04,JK-E05,JK-W01,JK-W03 network board.\n
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    /// @brief 打开网口设备（通过IP地址）
    ///
    /// @param [in] hDev             设备句柄。
    /// @param [in]    szNetIP             设备IP地址，如：“192.168.1.251”。
    /// @param [in]    nPort             设备端口号，如：“9100”。
    /// @param [in]    nProtocalType    协议类型，0:TCP,1:UDP。
    /// @param [in]    nBroadcast       0:不广播，1;广播。
    ///
    /// <b>备注\n</b>
    /// 此接口支持JK-E02、JK-E04、JK-E05、JK-W01、JK-W03网口板。\n
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE OpenNetPort(DEVICEHANDLE hDev, char *szNetIP, int nPort, int nProtocalType, int nBroadcast);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Opens blue tooth port device(by enumeration of device names)
    ///
    /// @param [in]    hDev      Device handle.
    /// @param [in,] szName    Enumeration of device names.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 打开蓝牙设备（通过枚举的设备名称）
    ///
    /// @param [in]    hDev      设备句柄。
    /// @param [in]    szName    枚举的设备名称。
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE OpenBlueToothPortByName(DEVICEHANDLE hDev, char *szName);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Opens blue tooth port device(by MAC address)
    ///
    /// @param [in]    hDev            Device handle.
    /// @param [in]    szMACAddress    Device MAC address, such as:"00:15:5:81:DF:F4:5B".
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 打开蓝牙设备（通过MAC地址）
    ///
    /// @param [in] hDev             设备句柄。
    /// @param [in]    szMACAddress    设备MAC地址，如：“00:15:81:DF:F4:5B”。
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE OpenBlueToothPort(DEVICEHANDLE hDev, char *szMACAddress);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Opens blue tooth MFI port device(by MAC address)
    ///
    /// @param [in]    hDev            Device handle.
    /// @param [in]    szMACAddress    Device MAC address.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 打开蓝牙设备（通过MAC地址）
    ///
    /// @param [in] hDev             设备句柄。
    /// @param [in] szMACAddress     设备MAC地址。
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE OpenBlueToothPortMFI(DEVICEHANDLE hDev, char *szMACAddress);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Opens printer driver port
    ///
    /// @param [in] hDev      Device handle.
    /// @param [in]    szName    The name of the installed printer name, it same as the device and printer in the control panel,such as:"BTP-S80(U)1".
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 打开打印机驱动端口
    ///
    /// @param [in] hDev     设备句柄。
    /// @param [in]    szName    已经安装的打印机驱动名称，与控制面板中的设备和打印机名称一致，例如："BTP-S80(U)1"。
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE OpenDriverPort(DEVICEHANDLE hDev, char *szName);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Closes open ports
    ///
    /// @param [in] hDev    Device handle.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 关闭已打开的端口
    ///
    /// @param [in] hDev 设备句柄。
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE ClosePort(DEVICEHANDLE hDev);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Sends a port data
    ///
    /// @param [in]    hDev           Port handle.
    /// @param [in]    szData           Data buffer to be sent.
    /// @param [in]    nDataLength    The number of bytes of data to be sent.
    /// @param [out] npReturnLen    The number of bytes actually sent.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 发送数据
    ///
    /// @param [in]    hDev           端口句柄。
    /// @param [in]    szData           将要发送的数据缓冲区。
    /// @param [in]    nDataLength    将要发送的数据的字节数。
    /// @param [out] npReturnLen    实际下发的字节数。
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SendPortData(DEVICEHANDLE hDev, char *szData, int nDataLength, int *npReturnLen);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///  @~English
    /// @brief Reads data from the device to the specified buffer
    ///
    /// @param [in]    hDev           Port handle.
    /// @param [in]    szData           Data buffer to be read.
    /// @param [in] nDataLength    The number of bytes of data to be read.
    /// @param [in]    npReturnLen    The number of bytes actually read.
    ///
    /// <b>Remark\n</b>
    /// 1.The number of bytes read by the USB port must be greater than the number of bytes actually read.\n
    /// 2.Driver port does not support this feature.\n
    /// 3.In the case of reading windows serial port contents, nDataLength can not larger than the data length in the serial port buffer,set nDataLength to 0 to read out all the data in the serial port buffer.\n
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    /// @brief 从设备读取数据到指定的缓冲区
    ///
    /// @param [in]    hDev           端口句柄。
    /// @param [in]    szData           将要读取的数据缓冲区。
    /// @param [in]    nDataLength    将要读取的数据的字节数。
    /// @param [in]    npReturnLen    实际读取的数据的字节数。
    ///
    /// <b>备注\n</b>
    /// 1、USB口的读取字节数必须大于实际读取的字节数。\n
    /// 2、驱动接口不支持此功能。\n
    /// 3、读取Winodws串口内容的情况下，参数nDataLength不能大于串口缓冲区内数据长度，将nDataLength设为0可以把串口缓冲区内所有数据读出。\n
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE ReadPortData(DEVICEHANDLE hDev, char *szData, int nDataLength, int *npReturnLen);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///  @~English
    /// @brief Sets read and write timeout
    ///
    /// @param [in] hDev             Device handle.
    /// @param [in] nWriteTimeout    The write timeout, unit:ms, default setting:5000ms.
    /// @param [in] nReadTimeout     The read timeout, unit:ms, default setting:3000ms.
    ///
    ///  <b>Remark\n</b>
    /// 1.Driver port does not support this feature.\n
    /// 2.The default parameter is -1, set the last read or write data timeout.\n
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    /// ::ERR_NOT_SUPPORT    --@copybrief ::ERR_NOT_SUPPORT \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置读写超时时间
    ///
    /// @param [in] hDev             设备句柄。
    /// @param [in] nWriteTimeout    读数据的超时时间，单位：ms，默认设置为5000ms。
    /// @param [in] nReadTimeout     写数据的超时时间，单位：ms，默认设置为3000ms。
    ///
    ///  <b>备注\n</b>
    /// 1、驱动接口不支持此功能。\n
    /// 2、缺省参数-1，设置上一次的读或写数据超时时间。\n
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    /// ::ERR_NOT_SUPPORT    --@copybrief ::ERR_NOT_SUPPORT \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetPortTimeout(DEVICEHANDLE hDev, int nWriteTimeout, int nReadTimeout);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///  @~English
    /// @brief Gets the read and write timeout
    ///
    /// @param [in] hDev             Device handle.
    /// @param [out] nWriteTimeout    Write data timeout,Unit: ms.
    /// @param [out] nReadTimeout     Read data timeout,Unit: ms.
    ///
    /// @return    A POSSDKCALL_MODE.
    ///
    ///  <b>Remark\n</b>
    /// 1.The driver interface does not support this function.\n
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    /// ::ERR_NOT_SUPPORT    --@copybrief ::ERR_NOT_SUPPORT \n
    ///
    /// @~Chinese
    ///
    /// @brief 获取读写超时时间
    ///
    /// @param [in] hDev             设备句柄。
    /// @param [out] nWriteTimeout      写数据的超时时间，单位：ms。
    /// @param [out] nReadTimeout         读数据的超时时间，单位：ms。
    ///
    ///  <b>备注\n</b>
    /// 1、驱动接口不支持此功能。\n
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    /// ::ERR_NOT_SUPPORT    --@copybrief ::ERR_NOT_SUPPORT \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE GetPortTimeout(DEVICEHANDLE hDev, int *nWriteTimeout, int *nReadTimeout);
    
    // 位图
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///  @~English
    /// @brief Print bitmap
    /// @param [in]    hDev       Device handle.
    /// @param [in]    szFilePath      Points to a null string representing the image path and its file name, or to standard bitmap data. This image only supports 1-bit / 8-bit / 24-bit images.
    /// @param [in]    nStartX    The distance (point/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points.
    /// @param [in]    nStartY    Specifies the distance (point/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed as "-1" when printed in standard mode (line mode).
    /// @param [in]    nType      Printed bitmap effect.
    ///                     Valid values | Meaning
    ///                     -------|---------------------------
    ///                     0      | Grayscale printing (clearest, but with large data volume and slow printing)
    ///                     1      | Dither printing (relatively clear, recommended)
    ///                     2      | Briary printing (the effect is poorer,Monochrome image are recommended) \n
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintBitmapExample
    ///
    /// <b>Remark\n</b>
    /// 1.IMPACT class printers do not support nType 0 or 2.\n
    /// 2.When nType is equal to 1, only partial POS printers that support grayscale printing instructions are supported.\n
    /// 3.Linux only supports JPG, PNG, BMP images.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_FILE    -- @copybrief ::ERR_FILE \n
    /// ::ERR_BITMAP_INVAILD    -- @copybrief ::ERR_BITMAP_INVAILD \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 打印位图
    /// @param [in] hDev       设备句柄。
    /// @param [in] szFilePath      指向以 null 结尾的表示图片路径及其文件名的字符串或标准的位图数据。该图片只支持1位/8位/24位图片。
    /// @param [in] nStartX    指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。
    /// @param [in] nStartY    指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。
    /// @param [in] nType      打印的位图效果。
    ///                     有效值 | 含义
    ///                     -------|---------------------------
    ///                     0      | 灰度打印（最清晰，但数据量大，打印慢）
    ///                     1      | 抖动打印（比较清晰，建议使用）
    ///                     2      | 二值化打印（效果较差，建议单色图片打印使用）  \n
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintBitmapExample
    ///
    /// <b>备注\n</b>
    /// 1、此功能IMPACT类打印机不支持nType等于0或2。\n
    /// 2、此功能nType等于1时，仅部分支持灰度打印指令的POS类打印机支持。\n
    /// 3、Linux仅支持JPG、PNG、BMP格式图片。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_FILE    -- @copybrief ::ERR_FILE \n
    /// ::ERR_BITMAP_INVAILD    -- @copybrief ::ERR_BITMAP_INVAILD \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE PrintBitmap(DEVICEHANDLE hDev, char *szFilePath, int nStartX, int nStartY, int nType);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Print monochrome bitmap (support for enlargement)
    ///
    /// @param [in]    hDev          Device handle.
    /// @param [in]    szFilePath    Points to a null-terminated string representing the image path and its file name, or to standard 1-bit bitmap data. This image only supports 1 bit depth images.
    /// @param [in]    nStartX       The distance (point/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points
    /// @param [in]    nStartY       Specifies the distance (point/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed as "-1" when printed in standard mode (line mode).
    /// @param [in]    nMode          Print mode for bitmaps.
    ///             Valid values|Meaning
    ///           -----------|-------------
    ///             0       | 8 point single density
    ///             1       | 8 point double density
    ///             2       | 24 point sigle density
    ///             3       | 24 point sigle density
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintBitmapExample
    ///
    /// <b>Remark\n</b>
    /// 1.IMPACT printers do not support nMode equals 2 or 3.\n.
    /// 2.Linux only supports JPG, PNG, BMP images.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_FILE    -- @copybrief ::ERR_FILE \n
    /// ::ERR_BITMAP_INVAILD    -- @copybrief ::ERR_BITMAP_INVAILD \n
    ///
    /// @~Chinese
    ///
    /// @brief 打印单色位图（支持放大）
    ///
    /// @param [in] hDev          设备句柄。
    /// @param [in]    szFilePath    指向以 null 结尾的表示图片路径及其文件名的字符串或标准的1位位图数据。该图片只支持1位深度图片。
    /// @param [in] nStartX       指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。
    /// @param [in] nStartY       指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。
    /// @param [in]    nMode          位图的打印模式。
    ///             有效值  | 含义
    ///           -----------|-------------
    ///             0       | 8点单密度
    ///             1       | 8点双密度
    ///             2       | 24点单密度
    ///             3       | 24点双密度
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintBitmapExample
    ///
    /// <b>备注\n</b>
    /// 1、此功能IMPACT类打印机不支持nMode等于2或3。\n
    /// 2、Linux仅支持JPG、PNG、BMP格式图片。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_FILE    -- @copybrief ::ERR_FILE \n
    /// ::ERR_BITMAP_INVAILD    -- @copybrief ::ERR_BITMAP_INVAILD \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE PrintBitmapByMode(DEVICEHANDLE hDev, char *szFilePath, int nStartX, int nStartY, int nMode);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Print TrueType fonts
    ///
    /// @param [in]    hDev           Device handle.
    /// @param [in]    szText           Null-terminated string buffers.
    /// @param [in]    nStartX           The distance (point/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points.
    /// @param [in]    nStartY           Specifies the distance (dot/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed as "-1" when printed in standard mode (line mode).
    /// @param [in]    szFontName     Font name, and valid values are Windows system fonts, such as "song type", "Calibri".
    /// @param [in]    nFontHeight    Font height, effective range is greater than 0, please choose the appropriate font size.
    /// @param [in]    nFontWidth     Font width, effective range is greater than 0, please choose the appropriate font size.
    /// @param [in]    nBold           Bold, 0: no bold; 1: bold.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintTextExample
    ///
    /// <b>Remark\n</b>
    ///    1.This function is not supported by IMPACT printers.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_FILE    --    @copybrief ::ERR_FILE    \n
    ///
    /// @~Chinese
    /// @brief 打印TrueType字体
    ///
    /// @param [in] hDev           设备句柄。
    /// @param [in]    szText           以 null 结尾的字符串缓冲区。
    /// @param [in]    nStartX           指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。
    /// @param [in]    nStartY           指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。
    /// @param [in]    szFontName     字体名称，有效值为Windows系统字体，如"宋体"、"Calibri"。
    /// @param [in]    nFontHeight    字体高度，有效范围为大于0，请根据具体字体选择适合的字号。
    /// @param [in]    nFontWidth     字体宽度，有效范围为大于0，请根据具体字体选择适合的字号。
    /// @param [in]    nBold           加粗，0：不加粗；1：加粗。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintTextExample
    ///
    /// <b>备注\n</b>
    ///    1、此功能IMPACT类打印机不支持。
    ///    2、iOS系统下，nFontWidth参数实际意义为字体大小，nFontHeight参数无实际意义，nBold参数无实际意义，字体名称对应有是否加粗。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_FILE    --    @copybrief ::ERR_FILE    \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE PrintTrueType(DEVICEHANDLE hDev, char *szText, int nStartX, int nStartY, char *szFontName, int nFontHeight, int nFontWidth, int nBold);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Predownload a bitmap to the RAM of the printer and specify the ID number of the bitmap
    ///
    /// @param [in] hDev          Device handle.
    /// @param [in]    szFilePath    Points to a null string representing the image path and its file name, or to standard bitmap data.
    /// @param [in] nImageID      Specifies the ID number of the bitmap to be downloaded. Valid values are 0-7.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_RAMExample
    ///
    /// <b>Remark\n</b>
    ///    1.The bitmap size to be downloaded should not exceed 900 square millimeters (approximately 240 dots by 240 dots).\n
    ///    2.Bitmaps must be monochrome.\n
    ///    3.The available RAM space inside a typical printer is 8K bytes.\n
    ///    4.Bitmap ID number does not require consistent.\n
    ///    5.Bitmaps downloaded into RAM will not be saved after power off.\n
    ///    6.This function, IMPACT printer, is not supported.\n
    ///    7.Linux only supports JPG, PNG, BMP images.\n
    ///    8.Non-monochrome images will be dithered and downloaded.\n
    ///    9.This image only supports 1-bit / 8-bit / 24-bit images.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_FILE    -- @copybrief ::ERR_FILE \n
    /// ::ERR_BITMAP_INVAILD    -- @copybrief ::ERR_BITMAP_INVAILD \n
    ///
    /// @~Chinese
    /// @brief 预下载一幅位图到打印机的 RAM 中，同时指定此位图的 ID 号
    ///
    /// @param [in]    hDev          设备句柄。
    /// @param [in]    szFilePath    指向以 null 结尾的表示图片路径及其文件名的字符串或标准的位图数据。
    /// @param [in]    nImageID      指定将要下载的位图的 ID 号。有效值为0 - 7。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_RAMExample
    ///
    /// <b>备注\n</b>
    ///    1、将要下载的位图大小不能超过 900 平方毫米 (大约为 240点 × 240 点)。\n
    ///    2、位图必须是单色的。\n
    ///    3、一般打印机内部的可用 RAM 空间为 8K 字节。\n
    ///    4、位图的 ID 号不要求是连续的。\n
    ///    5、下载到RAM中的位图在打印机关电后不被保存。\n
    ///    6、此功能IMPACT类打印机不支持。\n
    ///    7、Linux仅支持JPG、PNG、BMP格式图片。\n
    ///    8、非单色位图会进行抖动处理后下载。\n
    ///    9、仅支持1位/8位/24位深图片。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_FILE    -- @copybrief ::ERR_FILE \n
    /// ::ERR_BITMAP_INVAILD    -- @copybrief ::ERR_BITMAP_INVAILD \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE DownloadRAMBitmapByFile(DEVICEHANDLE hDev, char *szFilePath, int nImageID);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Print the bitmap that has been downloaded to RAM
    ///
    /// @param [in]    hDev        Device handle.
    /// @param [in]    nImageID    The ID number of the bitmap downloaded. Valid values are 0-7.
    /// @param [in]    nStartX     The distance (dot/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points.
    /// @param [in]    nStartY     Specifies the distance (dot/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed as "-1" when printed in standard mode (line mode).
    /// @param [in]    nMode       Specifies the print mode for the bitmap. Can be one of the values listed in the following list:
    ///              Valid values | Meaning
    ///             ---------|----------------
    ///             0     | Normal
    ///             1     | Times as wide
    ///             2     | Times as high
    ///             3     | Times as wide and times as high
    ///
    /// <b>The sample code\n</b>
    ///  See details @ref EG_RAMExample
    ///
    /// <b>Remark\n</b>
    /// 1.This function is not supported by IMPACT printers.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 打印已经下载到 RAM 中的位图
    ///
    /// @param [in] hDev        设备句柄。
    /// @param [in] nImageID    下载的位图的 ID 号。有效值为0 - 7。
    /// @param [in] nStartX     指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。
    /// @param [in] nStartY     指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。
    /// @param [in] nMode       指定位图的打印模式。可以为以下列表中所列值之一：
    ///                有效值 | 含义
    ///             ---------|----------------
    ///             0     | 正常
    ///             1     | 倍宽
    ///             2     | 倍高
    ///             3     | 倍宽且倍高
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_RAMExample
    ///
    /// <b>备注\n</b>
    /// 1、此功能IMPACT类打印机不支持。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE PrintRAMBitmap(DEVICEHANDLE hDev, int nImageID, int nStartX, int nStartY, int nMode);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Predownload one or more bitmaps to the printer's Flash
    ///
    /// @param [in]    hDev          Device handle.
    /// @param [in]    szFilePath    Points to an array of strings containing file paths and their names for several bitmaps.
    /// @param [in] nImageID      Specifies the number of bitmaps to be downloaded. The valid range is 1-255.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_FlashExample
    ///
    /// <b>Remark\n</b>
    ///    1.The data size of each bitmap cannot exceed 8K bytes (approximately 256 x 256 points).\n
    ///    2.Non-monochrome images will be dithered and downloaded.\n
    ///    3.The number of images downloaded into Flash is related to the number and order of bitmaps. Bitmaps are downloaded in the same order as file names in the array, and are sequential. For example, the first bitmap number is 1, the second bitmap number is 2, and so on.\n
    ///    4.Each download will clear the bitmap from the last download to Flash.\n
    ///    5.It will not be cleaned when the power is turned off.\n
    ///    6.The amount of Flash available inside a printer depends on the type of printer.\n
    ///    7.The bitmaps downloaded into FLASH are saved after the printer turns off the power.\n
    ///    8.Linux only supports JPG, PNG, BMP images.\n
    ///    9.This image only supports 1-bit / 8-bit / 24-bit images.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_FILE    -- @copybrief ::ERR_FILE \n
    /// ::ERR_BITMAP_INVAILD    -- @copybrief ::ERR_BITMAP_INVAILD \n
    ///
    /// @~Chinese
    /// @brief 预下载一幅或若干幅位图到打印机的 Flash 中
    ///
    /// @param [in] hDev          设备句柄。
    /// @param [in] szFilePath    指向包含若干位图的文件路径及其名称的字符串数组。
    /// @param [in] nImageCount      指定将要下载的位图幅数。有效范围为1-255。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_FlashExample
    ///
    /// <b>备注\n</b>
    ///    1、每幅位图的数据大小不能超过 8K 字节（大约为 256 点 × 256 点）。\n
    ///    2、非单色位图会进行抖动处理后下载。\n
    ///    3、下载到 Flash 中的图片的图号与位图的个数和排列顺序相关。位图的下载顺序和文件名在数组中的顺序一致，是连续的。如：第一个位图的图号为 1，第二个为 2，以此类推。\n
    ///    4、每次下载都会把上次下载到 Flash 中的位图都清除。\n
    ///    5、关电后不会被清除。\n
    ///    6、打印机内部Flash 的可使用空间与具体打印机型号有关。\n
    ///    7、下载到FLASH中的位图在打印机关电后仍然被保存。\n
    ///    8、Linux仅支持JPG、PNG、BMP格式图片。\n
    ///    9、仅支持1位/8位/24位深图片。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_FILE    -- @copybrief ::ERR_FILE \n
    /// ::ERR_BITMAP_INVAILD    -- @copybrief ::ERR_BITMAP_INVAILD \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE DownloadFlashBitmapByFile(DEVICEHANDLE hDev, char *szFilePath[], int nImageCount);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Print the bitmap that has been downloaded into Flash
    ///
    /// @param [in]    hDev        Device handle.
    /// @param [in]    nImageID    Specifies the bitmap ID number. The valid range is 1-255.
    /// @param [in]    nStartX     The distance (dot/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points.
    /// @param [in]    nStartY     Specifies the distance (dot/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed as "-1" when printed in standard mode (line mode).
    /// @param [in]    nMode       Specifies the print mode for the bitmap. Can be one of the values listed in the following list:
    ///                Valid values | Meaning
    ///             ---------|----------------
    ///             0     | Normal
    ///             1     | Times as wide
    ///             2     | Times as high
    ///             3     | Times as wide and times as high
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_FlashExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 打印已经下载到 Flash 中的位图
    ///
    /// @param [in] hDev        设备端口。
    /// @param [in] nImageID    指定位图ID号。有效范围为1-255。
    /// @param [in] nStartX     指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。
    /// @param [in] nStartY     指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。
    /// @param [in] nMode       指定位图的打印模式。可以为以下列表中所列值之一：
    ///                有效值 | 含义
    ///             ---------|----------------
    ///             0     | 正常
    ///             1     | 倍宽
    ///             2     | 倍高
    ///             3     | 倍宽且倍高
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_FlashExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE PrintFlashBitmap(DEVICEHANDLE hDev, int nImageID, int nStartX, int nStartY, int nMode);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Set and print barcode
    ///
    /// @param [in]    hDev                Device handle.
    /// @param [in]    szDataBuffer        Points to a null-terminated string. The range and format allowed per character depends on the specific barcode type.
    /// @param [in] nStartX                The distance (dot/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points.
    /// @param [in]    nStartY                Specifies the distance (dot/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed as "-1" when printed in standard mode (line mode).
    /// @param [in]    nType                Specifies the type of barcode. Can be one of the values listed in the following list:
    ///               Valid values | Meaning
    ///             ---------|----------------
    ///             65     | UPC-A
    ///             66     | UPC-C
    ///             67     | JAN13(EAN13)
    ///             68     | JAN8(EAN8)
    ///             69     | CODE39
    ///             70     | INTERLEAVED 2 OF 5
    ///             71     | CODEBAR
    ///             72     | CODE 93
    ///             73     | CODE 128
    /// @param [in]    nBasicWidth            Specifies the number of base element widths of the bar code. \n ranges from 1 to 6 points.
    /// @param [in]    nHeight                Specifies the height of the bar code (dot/mm). \n valid range is 1-255 points.
    /// @param [in]    nHriFontType        Specify the type of font for HRI (Human Readable Interpretation) characters. Can be one of the following values:
    ///                Valid values | Meaning
    ///             ---------|----------------
    ///             0     | Standard ASCII
    ///             1     | Compression ASCII
    /// @param [in]    nHriFontPosition    Specify the location of the HRI (Human Readable Interpretation) characters. Can be one of the following values:
    ///                Valid values | Meaning
    ///             ---------|----------------
    ///             0     | Don't print
    ///             1     | Print above barcode only
    ///             2     | Print below the barcode only
    ///             3     | Print above and below the barcode
    /// @param [in]    nBytesToPrint       Total number of characters sent to the printer. No more than the length of szDataBuffer valid data.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintBarcodeExample
    ///
    /// <b> Remark\n </b>
    ///    1.In page mode, this function does not print the barcode immediately, until the call function ::PageModePrint.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置并打印条码
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in]    szDataBuffer          指向以 null 结尾的字符串。每个字符允许的范围和格式与具体条码类型有关。
    /// @param [in]    nStartX              指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。
    /// @param [in]    nStartY              指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。
    /// @param [in]    nType                  指定条码的类型。可以为以下列表中所列值之一：
    ///                有效值 | 含义
    ///             ---------|----------------
    ///             65     | UPC-A
    ///             66     | UPC-C
    ///             67     | JAN13(EAN13)
    ///             68     | JAN8(EAN8)
    ///             69     | CODE39
    ///             70     | INTERLEAVED 2 OF 5
    ///             71     | CODEBAR
    ///             72     | CODE 93
    ///             73     | CODE 128
    /// @param [in]    nBasicWidth          指定条码的基本元素宽度点数。\n取值范围 1 - 6 点。
    /// @param [in]    nHeight              指定条码的高度（点/毫米）。\n 有效范围为 1 - 255 点。
    /// @param [in]    nHriFontType          指定 HRI（Human Readable Interpretation）字符的字体类型。可以为以下值之一：
    ///                有效值 | 含义
    ///             ---------|----------------
    ///             0     | 标准ASCII
    ///             1     | 压缩ASCII
    /// @param [in]    nHriFontPosition      指定HRI（Human Readable Interpretation）字符的位置。可以为以下值之一：
    ///                有效值 | 含义
    ///             ---------|----------------
    ///             0     | 不打印
    ///             1     | 只在条码上方打印
    ///             2     | 只在条码下方打印
    ///             3     | 条码上、下方都打印
    /// @param [in]    nBytesToPrint         指定由参数 szDataBuffer指向的字符串长度，即将要发送给打印机的字符总数，不可大于szDataBuffer有效数据长度。具体值与条码类型有关。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintBarcodeExample
    ///
    /// <b> 备注\n </b>
    ///    1、在页模式下，此函数并不立即打印条码，而是一直到调用函数  ::PageModePrint时才打印。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE PrintBarcode(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nType, int nBasicWidth, int nHeight, int nHriFontType, int nHriFontPosition, int nBytesToPrint);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Set and print barcode (simple interface)
    ///
    /// @param [in]    hDev                Device handle.
    /// @param [in]    szDataBuffer        Points to a null-terminated string. The range and format allowed per character depends on the specific barcode type.
    /// @param [in]    nStartX                The distance (dot/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points.
    /// @param [in]    nStartY                Specifies the distance (dot/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed as "-1" when printed in standard mode (line mode).
    /// @param [in]    nType                Specifies the type of barcode. Can be one of the values listed in the following list:
    ///               Valid values | Meaning
    ///             ---------|----------------
    ///             65     | UPC-A
    ///             66     | UPC-C
    ///             67     | JAN13(EAN13)
    ///             68     | JAN8(EAN8)
    ///             69     | CODE39
    ///             70     | INTERLEAVED 2 OF 5
    ///             71     | CODEBAR
    ///             72     | CODE 93
    ///             73     | CODE 128
    /// @param [in]    nWidth                Specifies the width of the barcode (dot/mm).
    /// @param [in]    nHeight                Specifies the height of the bar code (dot/mm). \n Valid range is 1-255 points.
    /// @param [in]    nHriFontPosition    Specify the location of the HRI (Human Readable) characters. Can be one of the following values:
    ///                Valid values | Meaning
    ///             ---------|----------------
    ///             0     | Don't print
    ///             1     | Print above barcode only
    ///             2     | Print below the barcode only
    ///             3     | Print above and below the barcode
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintBarcodeExample
    ///
    /// <b>Remark\n</b>
    ///    1.In page mode, this function does not print the barcode immediately,until the PageModePrint function is called.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置并打印条码（简易接口）
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in]    szDataBuffer          指向以 null 结尾的字符串。每个字符允许的范围和格式与具体条码类型有关。
    /// @param [in]    nStartX              指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。
    /// @param [in]    nStartY              指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。
    /// @param [in]    nType                  指定条码的类型。可以为以下列表中所列值之一：
    ///                有效值 | 含义
    ///             ---------|----------------
    ///             65     | UPC-A
    ///             66     | UPC-C
    ///             67     | JAN13(EAN13)
    ///             68     | JAN8(EAN8)
    ///             69     | CODE39
    ///             70     | INTERLEAVED 2 OF 5
    ///             71     | CODEBAR
    ///             72     | CODE 93
    ///             73     | CODE 128
    /// @param [in]    nWidth              指定条码的宽度（点/毫米）。
    /// @param [in]    nHeight              指定条码的高度（点/毫米）。\n 有效范围为 1 - 255 点。
    /// @param [in]    nHriFontPosition      指定HRI（Human Readable Interpretation）字符的位置。可以为以下值之一：
    ///                有效值 | 含义
    ///             ---------|----------------
    ///             0     | 不打印
    ///             1     | 只在条码上方打印
    ///             2     | 只在条码下方打印
    ///             3     | 条码上、下方都打印
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintBarcodeExample
    ///
    /// <b>备注\n</b>
    ///    1、在页模式下，此函数并不立即打印条码，而是一直到调用函数PageModePrint时才打印。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE PrintBarcodeSimple(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nType, int nWidth, int nHeight, int nHriFontPosition);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Set and print the QR code
    ///
    /// @param [in] hDev             Devcie handle.
    /// @param [in]    szDataBuffer     Points to a null-terminated string.
    /// @param [in]    nStartX             The distance (dot/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points.
    /// @param [in]    nStartY             Specifies the distance (dot/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed as "-1" when printed in standard mode (line mode).
    /// @param [in]    nBasicWidth      Specifies the number of base element widths of the bar code. \n valid range is 1-10 points.
    /// @param [in]    nSymbolType      Symbol type. The effective range of \n is 1-2. \n 1: for primitive type 2: for enhanced type (recommended).
    /// @param [in]    nLanguageMode    The language mode.\n valid range is 0-1. \n 0: for Chinese 1: for Japanese
    /// @param [in]    nErrorCorrect    QR code error correction level. \n valid range is 0-3. \n 0: represents L level, 1 represents M level, 2 represents Q level, 3 represents H level.
    /// @param [in]    nBytesToPrint    Total number of characters sent to the printer. No more than the length of szDataBuffer valid data.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintBarcodeExample
    ///
    /// <b>Remark\n</b>
    ///    1.In page mode, this function does not immediately print the bar code, until the call function PageModePrint to print.\n
    ///    2.This feature is only supported by POS class printers.
    ///    3.Please ensure that the szDataBuffer within the length of the nBytesToPrint parameter is valid data, otherwise it may cause a crash.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_NOT_SUPPORT    -- @copybrief ::ERR_NOT_SUPPORT \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置并打印QR码
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in]    szDataBuffer          指向以 null 结尾的字符串。
    /// @param [in]    nStartX              指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。
    /// @param [in]    nStartY              指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。
    /// @param [in]    nBasicWidth          指定条码的基本元素宽度点数。\n 有效范围为 1 - 10 点。
    /// @param [in]    nSymbolType          符号类型。\n 有效范围为 1 - 2。\n 1:表示原始类型  2: 表示增强类型(推荐使用)。
    /// @param [in]    nLanguageMode          语言模式。\n 有效范围为 0 - 1。\n 0:表示汉字  1: 表示日文。
    /// @param [in]    nErrorCorrect          QR码纠错等级。\n 有效范围为 0 - 3。\n 0：代表L级别  1代表M级别  2代表Q级别  3代表H级别。
    /// @param [in]    nBytesToPrint         指定由参数 szDataBuffer指向的字符串个数，即将要发送给打印机的字符总数。\n 有效范围为 1 - 252且不可大于szDataBuffer有效数据长度。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintBarcodeExample
    ///
    /// <b>备注\n</b>
    ///    1、在页模式下，此函数并不立即打印条码，而是一直到调用函数PageModePrint时才打印。\n
    ///    2、此功能针打类（IMPACT）打印机不支持。\n
    ///    3、请确保nBytesToPrint参数长度内szDataBuffer均为有效数据，否则可能引发崩溃。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_NOT_SUPPORT    -- @copybrief ::ERR_NOT_SUPPORT \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE BarcodePrintQR(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nBasicWidth, int nSymbolType, int nLanguageMode, int nErrorCorrect, int nBytesToPrint);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Set and print the QR code
    ///
    /// @param [in] hDev             Devcie handle.
    /// @param [in]    szDataBuffer     Points to a null-terminated string.
    /// @param [in]    nStartX             The distance (dot/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points.
    /// @param [in]    nStartY             Specifies the distance (dot/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed as "-1" when printed in standard mode (line mode).
    /// @param [in]    nBasicWidth      Specifies the number of base element widths of the bar code. \n valid range is 1-16 points.
    /// @param [in]    nErrorCorrect    QR code error correction level. \n valid range is 0-3. \n 0: represents L level, 1 represents M level, 2 represents Q level, 3 represents H level.
    /// @param [in]    nBytesToPrint    Total number of characters sent to the printer. No more than the length of szDataBuffer valid data.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintBarcodeExample
    ///
    /// <b>Remark\n</b>
    ///    1.In page mode, this function does not immediately print the bar code, until the call function PageModePrint to print.\n
    ///    2.This feature is not supported by the IMPACT class printer.\n
    ///    3.Please ensure that the szDataBuffer within the length of the nBytesToPrint parameter is valid data, otherwise it may cause a crash.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_NOT_SUPPORT    -- @copybrief ::ERR_NOT_SUPPORT \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置并打印QR码
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in]    szDataBuffer          指向以 null 结尾的字符串。
    /// @param [in]    nStartX              指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。
    /// @param [in]    nStartY              指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。
    /// @param [in]    nBasicWidth          指定条码的基本元素宽度点数。\n 有效范围为 1 - 16 点。
    /// @param [in]    nErrorCorrect          QR码纠错等级。\n 有效范围为 0 - 3。\n 0：代表L级别  1代表M级别  2代表Q级别  3代表H级别。
    /// @param [in]    nBytesToPrint         指定由参数 szDataBuffer指向的字符串个数，即将要发送给打印机的字符总数。\n 有效范围为 1 - 7089且不可大于szDataBuffer有效数据长度。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintBarcodeExample
    ///
    /// <b>备注\n</b>
    ///    1、在页模式下，此函数并不立即打印条码，而是一直到调用函数PageModePrint时才打印。\n
    ///    2、此功能仅POS类打印机支持。\n
    ///    3、请确保nBytesToPrint参数长度内szDataBuffer均为有效数据，否则可能引发崩溃。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_NOT_SUPPORT    -- @copybrief ::ERR_NOT_SUPPORT \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    int POSSDKCALL_MODE BarcodePrintQREx(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nBasicWidth, int nErrorCorrect, int nBytesToPrint);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Set and print PDF417
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in]    szDataBuffer          Points to a null-terminated string.
    /// @param [in]    nStartX              The distance (dot/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points.
    /// @param [in]    nStartY              Specifies the distance (dot/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed to "-1" when printed in standard mode (line mode).
    /// @param [in]    nBasicWidth          Specifies the number of base element widths of the bar code. \n valid range is 1-7 points.
    /// @param [in]    nHeight              Specifies the height number of bar code elements. \n effective range is 2-25 points.
    /// @param [in]    nLines              Specifies the number of lines in the barcode. \n valid range is 3-90.
    /// @param [in]    nColumns              Specifies the number of columns of the barcode. \n valid range is 1-30.
    /// @param [in]    nScaleH              Specifies the bar code appearance ratio height. The effective range of \n is 1-10.
    /// @param [in]    nScaleV              Specifies the bar code appearance ratio width. \n valid range is 1-100.
    /// @param [in]    nErrorCorrect          Specify bar code error correction level. \n effective range is 0-8.
    /// @param [in]    nBytesToPrint         Total number of characters sent to the printer. No more than the length of szDataBuffer valid data.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintBarcodeExample
    ///
    /// <b>Remark\n</b>
    ///    1.In page mode, this function does not immediately print the bar code, until the call function PageModePrint to print.\n
    ///    2.This feature is not supported by the IMPACT class printer.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置并打印PDF417码
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in]    szDataBuffer          指向以 null 结尾的字符串。
    /// @param [in]    nStartX              指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。
    /// @param [in]    nStartY              指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。
    /// @param [in]    nBasicWidth          指定条码的基本元素宽度点数。\n 有效范围为 1 - 7 点。
    /// @param [in]    nHeight              指定条码元素高度点数。\n 有效范围为 2 - 25 点。
    /// @param [in]    nLines              指定条码的行数。\n 有效范围为 3 - 90。
    /// @param [in]    nColumns              指定条码的列数。\n 有效范围为 1 - 30。
    /// @param [in]    nScaleH              指定条码外观比高度。\n 有效范围为 1 - 10。
    /// @param [in]    nScaleV              指定条码外观比宽度。\n 有效范围为 1 - 100。
    /// @param [in]    nErrorCorrect          指定条码纠错级别。\n 有效范围为 0 - 8。
    /// @param [in]    nBytesToPrint         指定由参数 szDataBuffer指向的字符串个数，即将要发送给打印机的字符总数，不可大于szDataBuffer有效数据长度。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintBarcodeExample
    ///
    /// <b>备注\n</b>
    ///    1、在页模式下，此函数并不立即打印条码，而是一直到调用函数PageModePrint时才打印。\n
    ///    2、此功能IMPACT类打印机不支持。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE BarcodePrintPDF417(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nBasicWidth, int nHeight, int nLines, int nColumns, int nScaleH, int nScaleV, int nCorrectGrade, int nBytesToPrint);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Set and print PDF417
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in]    szDataBuffer          Points to a null-terminated string.
    /// @param [in]    nStartX              The distance (dot/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points.
    /// @param [in]    nStartY              Specifies the distance (dot/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed to "-1" when printed in standard mode (line mode).
    /// @param [in]    nBasicWidth          Specifies the number of base element widths of the bar code. \n valid range is 1-7 points.
    /// @param [in]    nHeight              Specifies the height number of bar code elements. \n effective range is 2-25 points.
    /// @param [in]    nLines              Specifies the number of lines in the barcode. \n valid range is 3-90.
    /// @param [in]    nColumns              Specifies the number of columns of the barcode. \n valid range is 1-30.
    /// @param [in]    nScaleH              Specifies the bar code appearance ratio height. The effective range of \n is 1-10.
    /// @param [in]    nScaleV              Specifies the bar code appearance ratio width. \n valid range is 1-100.
    /// @param [in]    nErrorCorrect          Specify bar code error correction level. \n effective range is 0-8.
    /// @param [in]    nBytesToPrint         Total number of characters sent to the printer. No more than the length of szDataBuffer valid data.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintBarcodeExample
    ///
    /// <b>Remark\n</b>
    ///    1.In page mode, this function does not immediately print the bar code, until the call function PageModePrint to print.\n
    ///    2.This feature is not supported by the IMPACT class printer.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置并打印PDF417码
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in]    szDataBuffer          指向以 null 结尾的字符串。
    /// @param [in]    nStartX              指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。
    /// @param [in]    nStartY              指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。
    /// @param [in]    nBasicWidth          指定条码的基本元素宽度点数。\n 有效范围为 1 - 7 点。
    /// @param [in]    nHeight              指定条码元素高度点数。\n 有效范围为 2 - 25 点。
    /// @param [in]    nLines              指定条码的行数。\n 有效范围为 3 - 90。
    /// @param [in]    nColumns              指定条码的列数。\n 有效范围为 1 - 30。
    /// @param [in]    nScaleH              指定条码外观比高度。\n 有效范围为 1 - 10。
    /// @param [in]    nScaleV              指定条码外观比宽度。\n 有效范围为 1 - 100。
    /// @param [in]    nErrorCorrect          指定条码纠错级别。\n 有效范围为 0 - 8。
    /// @param [in]    nBytesToPrint         指定由参数 szDataBuffer指向的字符串个数，即将要发送给打印机的字符总数，不可大于szDataBuffer有效数据长度。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintBarcodeExample
    ///
    /// <b>备注\n</b>
    ///    1、使用打印位图的方式打印PDF417码。\n
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////

    int POSSDKCALL_MODE BarcodePrintPDF417Image(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nBasicWidth, int nHeight, int nLines, int nColumns, int nScaleH, int nScaleV, int nCorrectGrade, int nBytesToPrint);

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Set and print PDF417 (simple interface)
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in]    szDataBuffer          Points to a null-terminated string.
    /// @param [in]    nStartX              The distance (dot/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points.
    /// @param [in]    nStartY              Specifies the distance (dot/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed to "-1" when printed in standard mode (line mode).
    /// @param [in]    nWidth              Specifies the width of the bar code (dot/mm).
    /// @param [in]    nHeight              Specifies height of bar code element (dot/mm). \n effective range is 2-25 points.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintBarcodeExample
    ///
    /// <b>Remark\n</b>
    ///    1.In page mode, this function does not immediately print the bar code, until the call function PageModePrint to print.\n
    ///    2.This feature is not supported by the IMPACT class printer.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置并打印PDF417码（简易接口）
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in]    szDataBuffer          指向以 null 结尾的字符串。
    /// @param [in]    nStartX              指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。
    /// @param [in]    nStartY              指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。
    /// @param [in]    nWidth              指定条码的宽度（点/毫米）。
    /// @param [in]    nHeight              指定条码元素高度（点/毫米）。\n 有效范围为 2 - 25 点。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintBarcodeExample
    ///
    /// <b>备注\n</b>
    ///    1、在页模式下，此函数并不立即打印条码，而是一直到调用函数PageModePrint时才打印。\n
    ///    2、此功能IMPACT类打印机不支持。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE BarcodePrintPDF417Simple(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nWidth, int nHeight);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Set up and print the Maxicode barcode
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in]    szDataBuffer          Points to a null-terminated string.
    /// @param [in]    nStartX              The distance (dot/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points.
    /// @param [in]    nStartY              Specifies the distance (dot/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed to "-1" when printed in standard mode (line mode).
    /// @param [in]    nBytesToPrint         Total number of characters sent to the printer. No more than the length of szDataBuffer valid data.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintBarcodeExample
    ///
    /// <b>Remark\n</b>
    ///    1.In page mode, this function does not immediately print the bar code, until the call function PageModePrint to print.\n
    ///    2.This feature is only supported by POS class printers.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_NOT_SUPPORT    -- @copybrief ::ERR_NOT_SUPPORT \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    /// @~Chinese
    ///
    /// @brief 设置并打印Maxicode条码
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in]    szDataBuffer          指向以 null 结尾的字符串。
    /// @param [in]    nStartX              指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。
    /// @param [in]    nStartY              指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。
    /// @param [in]    nBytesToPrint         指定由参数 szDataBuffer指向的字符串个数，即将要发送给打印机的字符总数，不可大于szDataBuffer有效数据长度。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintBarcodeExample
    ///
    /// <b>备注\n</b>
    ///    1、在页模式下，此函数并不立即打印条码，而是一直到调用函数PageModePrint时才打印。\n
    ///    2、此功能仅POS类打印机支持。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_NOT_SUPPORT    -- @copybrief ::ERR_NOT_SUPPORT \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE BarcodePrintMaxicode(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nBytesToPrint);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Set and print the GS1 barcode
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in]    szDataBuffer          Points to a null-terminated string. The range and format allowed per character depends on the specific barcode type.
    /// @param [in]    nStartX              The distance (dot/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points.
    /// @param [in]    nStartY              Specifies the distance (dot/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed to "-1" when printed in standard mode (line mode).
    /// @param [in]    nBarcodeType          Specify barcode GS1 type and character set. \n valid range is 1-7.
    /// @param [in]    nBasicWidth          Specifies the number of base element widths of the bar code. \n effective range is 1-6 points.
    /// @param [in]    nHeight              Specifies the height of the bar code (dot/mm). \n effective range is 2-250 points.
    /// @param [in]    nSegmentNum          Specifies the number of segments in each line of the barcode symbol. \n valid range is 2-20.
    /// @param [in]    nSeparatorHeight      Specifies the number of height points for the delimiter. \n valid range is 1-10 points.
    /// @param [in]    nBasicHeight          Specifies the number of base elements height of the bar code. \n valid range is 1-10 points.
    /// @param [in]    nHRI                  Specify the type of font for HRI (Human Readable Interpretation) characters. The effective range of \n is 1-4.
    /// @param [in]    nAI                  Specifies whether the bar code is applied to AI (application identifier). \n valid range is 0-1. \n 0 means do not apply AI 1 means apply.
    /// @param [in]    nBytesToPrint         Total number of characters sent to the printer. No more than the length of szDataBuffer valid data.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintBarcodeExample
    ///
    /// <b>Remark\n</b>
    ///    1.In page mode, this function does not immediately print the bar code, until the call function PageModePrint to print.\n
    ///    2.This feature is only supported by POS class printers.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_NOT_SUPPORT    -- @copybrief ::ERR_NOT_SUPPORT \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置并打印GS1条码
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in]    szDataBuffer          指向以 null 结尾的字符串。每个字符允许的范围和格式与具体条码类型有关。
    /// @param [in]    nStartX              指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。
    /// @param [in]    nStartY              指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。
    /// @param [in]    nBarcodeType          指定条码GS1类型及字符集。\n 有效范围为 1 - 7。
    /// @param [in]    nBasicWidth          指定条码的基本元素宽度点数。\n 有效范围为 1 - 6 点。
    /// @param [in]    nHeight              指定条码的高度（点/毫米）。\n 有效范围为 2 - 250 点。
    /// @param [in]    nSegmentNum          指定条码每行条码符号的段数。\n 有效范围为 2 - 20。
    /// @param [in]    nSeparatorHeight      指定分隔符的高度点数。\n 有效范围为 1 - 10 点。
    /// @param [in]    nBasicHeight          指定条码的基本元素高度点数。\n 有效范围为 1 - 10 点。
    /// @param [in]    nHRI                  指定 HRI（Human Readable Interpretation）字符的字体类型。\n 有效范围为 1 - 4。
    /// @param [in]    nAI                  指定条码是否应用AI（应用标识符）。\n 有效范围为 0 - 1。\n 0表示不应用AI  1表示应用。
    /// @param [in]    nBytesToPrint         指定由参数 szDataBuffer指向的字符串个数，即将要发送给打印机的字符总数，不可大于szDataBuffer有效数据长度。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintBarcodeExample
    ///
    /// <b>备注\n</b>
    ///    1、在页模式下，此函数并不立即打印条码，而是一直到调用函数PageModePrint时才打印。\n
    ///    2、此功能仅POS类打印机支持。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_NOT_SUPPORT    -- @copybrief ::ERR_NOT_SUPPORT \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE BarcodePrintGS1DataBar(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nBarcodeType, int nBasicWidth, int nHeight, int nSegmentNum, int nSeparatorHeight, int nBasicHeight, int nHRI, int nAI, int nBytesToPrint);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Barcode reserve function
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in] nInstructionName     Reserve parameter 1.
    /// @param [in] nPara1                 Reserve parameter 2.
    /// @param [in] szPara2             Reserve parameter 3.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 条码预留接口
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in] nInstructionName     预留参数1。
    /// @param [in] nPara1                 预留参数2。
    /// @param [in] szPara2             预留参数3。
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE BarcodeReserveFunction(DEVICEHANDLE hDev, int nInstructionsName, int nPara1, char *szPara2);
    
    // 文本
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Feed line
    ///
    /// @param [in] hDev Device handle.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintTextExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 换行
    ///
    /// @param [in] hDev 设备句柄。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintTextExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE FeedLine(DEVICEHANDLE hDev);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief The string data to be printed is sent to the print buffer
    ///
    /// @param [in]    hDev          Device handle\n
    /// @param [in]    szTextData    Points to a null-terminated string buffer.\n
    /// @param [in] nStartX     The distance (dot/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points.\n
    /// @param [in] nStartY     Specifies the distance (dot/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed to "-1" when printed in standard mode (line mode).\n
    ///
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintTextExample
    ///
    /// <b>Remark\n</b>
    /// 1.This function does not immediately print the incoming string, until the FeedLine function is called. However, if the string passed in is already larger than the printable width, the paper is automatically fed and printed.\n
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 将要打印的字符串数据发送到打印缓冲区
    ///
    /// @param [in]    hDev          设备句柄。\n
    /// @param [in]    szTextData    指向以 null 结尾的字符串缓冲区。\n
    /// @param [in] nStartX     指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。\n
    /// @param [in] nStartY     指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。\n
    ///
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintTextExample
    ///
    /// <b>备注\n</b>
    /// 1、此函数并不立即打印传入的字符串，而是一直到调用函数 FeedLine 时才进行实际的进纸并打印的动作。但是，如果传入的字符串已经大于可打印宽度时，那么会自动进纸并打印。\n
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE PrintTextOut(DEVICEHANDLE hDev, char *szTextData, int nStartX, int nStartY);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief The string data to be printed is sent to the print buffer(support for amplification)
    ///
    /// @param [in] hDev            Device handle
    /// @param [in] szTextData      Points to a null-terminated string buffer.
    /// @param [in] nStartX         The distance (dot/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points.
    /// @param [in] nStartY         Specifies the distance (dot/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed to "-1" when printed in standard mode (line mode).
    /// @param [in] nWidthTimes     Horizontal magnification, effective range 1-6.
    /// @param [in] nHeightTimes    Vertical magnification, effective range 1-6.
    /// @param [in] nFontType       Specifies the font type for the character. Can be one of the values listed in the following list:\n
    ///                  Valid values | Meaning
    ///             ---------|----------------
    ///             0     | Standard ASCII
    ///             1     | Compression ASCII
    ///             2     | User-defined characters
    ///             3     | Standard "Song typeface"
    ///
    /// @param [in] nFontStyle      Specifies the font style of the character. Can be one of the values listed in the following list:\n
    ///             Valid values（HEX） | implications
    ///             -----------|--------------------
    ///             0x00     | Normal
    ///             0x08     | Bold
    ///             0x80     | 1 point bold underline
    ///             0x100    | 2 bold underline
    ///             0x200    | Inversion (only valid at the beginning of the line)
    ///             0x400    | Reverse (white text on black background)
    ///             0x800    | Smoothing (for magnification)
    ///             0x1000   | Rotate each character 90 degrees clockwise
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintTextExample
    ///
    /// <b>Remark\n</b>
    ///    1.In the printer, generally, the internal font types are shown in the following table, but different models will be different, please refer to the test sample of the printer.\n
    ///                     The name of the font | Font size (W * H)
    ///                ---------|------------------------
    ///                   Standard ASCII     | 12 * 24 / 13 * 24
    ///                Compressed ASCII     | 9 * 17
    ///                Standard of song typeface     | 24 * 24
    ///                Small song typeface    | 16 * 16
    ///                Small ASCII    | 8 * 16
    ///
    ///    2.If the character style is set to "reverse" or "rotate 90 degrees clockwise," then the "thin underscore" and "thick underscore" functions are disabled.\n
    ///    3.If in Chinese character mode, standard ASCII characters (except partial symbols and symbols under full corners) and Chinese characters can be printed in one call. If in ASCII character mode, only standard ASCII characters and compressed ASCII characters can be printed.\n
    /// 4.This function does not immediately print the incoming string, does not actually feed and print until the FeedLine function is called. However, if the string passed in is already larger than the printable width, the paper is automatically fed and printed.\n
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 将要打印的字符串数据发送到打印缓冲区（支持放大）
    ///
    /// @param [in] hDev            设备句柄。
    /// @param [in] szTextData      指向以 null 结尾的字符串缓冲区。
    /// @param [in] nStartX         指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。
    /// @param [in] nStartY         指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。
    /// @param [in] nWidthTimes     横向放大倍数，有效范围为1-6。
    /// @param [in] nHeightTimes    纵向放大倍数，有效范围为1-6。
    /// @param [in] nFontType       指定字符的字体类型。可以为以下列表中所列值之一:\n
    ///                  有效值 | 含义
    ///             ---------|----------------
    ///             0     | 标准 ASCII
    ///             1     | 压缩 ASCII
    ///             2     | 用户自定义字符
    ///             3     | 标准 “宋体”
    ///
    /// @param [in] nFontStyle      指定字符的字体风格。可以为以下列表中所列值之一:\n
    ///             有效值（HEX） | 含义
    ///             -----------|--------------------
    ///             0x00     | 正常
    ///             0x08     | 加粗
    ///             0x80     | 1点粗的下划线
    ///             0x100    | 2点粗的下划线
    ///             0x200    | 倒置（只在行首有效）
    ///             0x400    | 反显（黑底白字）
    ///             0x800    | 平滑处理（用于放大时）
    ///             0x1000   | 每个字符顺时针旋转 90 度
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintTextExample
    ///
    /// <b>备注\n</b>
    ///    1、在打印机中，一般内部已有字体类型如下表所示，但是不同机型会有所不同，可以参考打印机的测试样张。\n
    ///                     字体名称 | 字体大小（W * H）
    ///                ---------|------------------------
    ///                   Standard ASCII     | 12 * 24 / 13 * 24
    ///                Compressed ASCII     | 9 * 17
    ///                标准宋体     | 24 * 24
    ///                小宋体    | 16 * 16
    ///                小ASCII    | 8 * 16
    ///
    ///    2、如果字符风格设置为“反显”，或“顺时针旋转90度”，那么“细下划线” 和“粗下划线”的功能将无效。\n
    ///    3、如果在汉字字符模式下，则一次调用时，标准ASCII字符（除部分符号和全角下的符号）和汉字可以混合打印；如果在ASCII字符模式下，则只可以打印标准 ASCII 字符和压缩的ASCII字符。\n
    /// 4、此函数并不立即打印传入的字符串，而是一直到调用函数 FeedLine 时才进行实际的进纸并打印的动作。但是，如果传入的字符串已经大于可打印宽度时，那么会自动进纸并打印。\n
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE UniversalTextOut(DEVICEHANDLE hDev, char *szTextData, int nStartX, int nStartY, int nWidthTimes, int nHeightTimes, int nFontType, int nFontStyle);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Sets text line hight
    ///
    /// @param    [in] hDev               Device handle.
    /// @param    [in] nLineHeight    Specifies the high number of rows. The valid range is 0-255.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintTextExample
    ///
    /// <b>Remark\n</b>
    ///    1.If the line height is set to 0, the printer USES the internal default line height, which is 1/6 of an inch. If the print head has a vertical resolution of 180dpi, it is 31 points high.\n
    ///    2.If the line height is set to less than the current character height, the printer USES the current character height to be the line height.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 设置字符的行高
    ///
    /// @param    [in] hDev           设备端口。
    /// @param    [in] nLineHeight    指定行高点数。有效范围为0-255。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintTextExample
    ///
    /// <b>备注\n</b>
    ///    1、如果把行高设置为0，则打印机使用内部的默认行高值，即1 / 6英寸。如果打印头纵向分辨率为180dpi 则相当于 31 点高。\n
    ///    2、如果行高被设置为小于当前的字符高度，则打印机将使用当前字符高度为行高。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetTextLineHight(DEVICEHANDLE hDev, int nLineHeight);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Sets text bold
    ///
    /// @param [in] hDev     Device handle.
    /// @param [in]    nBold    0：no bold；1：bold.
    ///
    /// <b>The sample code\n</b>
    /// Valid values @ref EG_PrintTextExample
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 设置加粗
    ///
    /// @param [in] hDev     设备句柄。
    /// @param [in]    nBold    0：不加粗；1：加粗。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintTextExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetTextBold(DEVICEHANDLE hDev, int nBold);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Sets text double width and height
    ///
    /// @param [in] hDev             Device handle.
    /// @param [in] nWidthEnable     Text double width,0:Cancel double width;1:Choose double width.
    /// @param [in] nHeightEnable    Text double higeht,0:Cancel double higeht;1:Choose double higeht.
    ///
    /// <b>The sample code\n</b>
    /// Valid values @ref EG_PrintTextExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 设置文本倍宽倍高使能
    ///
    /// @param [in] hDev             设备句柄。
    /// @param [in] nWidthEnable     文本倍宽使能，0：取消倍宽；1：选择倍宽。
    /// @param [in] nHeightEnable    文本倍高使能，0：取消倍高；1：选择倍高。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintTextExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetTextDoubleWidthAndHeight(DEVICEHANDLE hDev, int nWidthEnable, int nHeightEnable);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Set the alignment of the printed text (only valid at the beginning of the line in standard mode)
    ///
    /// @param [in] hDev          Device handle.
    /// @param [in]    nAlignment    Alignment. Can be one of the values listed in the following list:\n
    ///              Valid values | Meaning
    ///             ---------|----------------
    ///             0     | Left justified
    ///             1     | In the middle
    ///             2     | Right justified
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintTextExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置文本打印的对齐方式（只在标准模式的行首有效）
    ///
    /// @param [in] hDev          设备句柄。
    /// @param [in]    nAlignment    对齐方式。可以为以下列表中所列值之一:\n
    ///              有效值 | 含义
    ///             ---------|----------------
    ///             0     | 左对齐
    ///             1     | 居中
    ///             2     | 右对齐
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintTextExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetAlignmentMode(DEVICEHANDLE hDev, int nAlignment);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Sets text character space
    ///
    /// @param [in] hDev           Device handle.
    /// @param [in] nLeftSpace     Character left spacing (this parameter should be valid when setting Chinese character spacing). The valid range is 0-255.
    /// @param [in] nRightSpace    Character right spacing. The valid range is 0-255.
    /// @param [in] nMode           Character mode. 0: Chinese character mode; 1: English character mode.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintTextExample
    ///
    /// <b>Remark\n</b>
    /// 1.If the parameter Mode is 0, the parameter nLeftSpace and nRightSpace must both be legal; if the parameter Mode is 1, as long as the parameter nRightSpace is legal, the parameter LeftSpace is ignored.\n
    /// 2.You can only change the character spacing in English or Chinese by calling textSetCharacterSpace once. To change the character spacing in Chinese and English, you need to call the function twice.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置字符间距
    ///
    /// @param [in] hDev           设备句柄。
    /// @param [in] nLeftSpace     字符左间距（设置中文字符间距时，此参数需有效）。有效范围为0-255。
    /// @param [in] nRightSpace    字符右间距。有效范围为0-255。
    /// @param [in] nMode           字符模式。0：中文字符模式；1：英文字符模式。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintTextExample
    ///
    /// <b>备注\n</b>
    /// 1、如果参数Mode为0，参数nLeftSpace和nRightSpace必须同时合法，如果参数Mode为1，只要参数nRightSpace合法便可，此时参数LeftSpace被忽略。\n
    /// 2、调用一次函数textSetCharacterSpace只可以单独更改英文或中文的字符间距，若想更改中英文字符间距需要调用函数两次。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetTextCharacterSpace(DEVICEHANDLE hDev, int nLeftSpace, int nRightSpace, int nMode);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Sets text magnify times
    ///
    /// @param [in] hDev                Device handle.
    /// @param [in] nHorMagnifyTimes    Horizontal magnification, effective range 1-6.
    /// @param [in] nVerMagnifyTimes    Vertical magnification, effective range 1-6.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintTextExample
    ///
    /// <b>Remark\n</b>
    /// 1.In standard mode, vertical is the direction of feed and horizontal is perpendicular to the direction of feed. But when the character is rotated 90 degrees clockwise, it is reversed horizontally and vertically.\n
    /// 2.In page mode, landscape and portrait depend on the direction of the area.\n
    /// 3.All characters are aligned with the bottom line.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置字符大小
    ///
    /// @param [in] hDev                设备句柄。
    /// @param [in] nHorMagnifyTimes    横向放大倍数，有效范围为1-6。
    /// @param [in] nVerMagnifyTimes    纵向放大倍数，有效范围为1-6。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintTextExample
    ///
    /// <b>备注\n</b>
    /// 1、在标准模式下，纵向是进纸方向，横向是垂直于进纸的方向。但是当字符顺时针旋转90°时，横向和纵向颠倒。\n
    /// 2、页模式下，横向和纵向取决于区域的方向。\n
    /// 3、同一行字符的放大倍数不同时，所有的字符以底线对齐。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetTextMagnifyTimes(DEVICEHANDLE hDev, int nHorMagnifyTimes, int nVerMagnifyTimes);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Select the font type for the print character
    ///
    /// @param [in] hDev          Device handle.
    /// @param [in] nFontType       Font Type. Can be one of the values listed in the following list:\n
    ///                  Valid values| Meaning
    ///             ---------|----------------
    ///             0     | Standard ASCII
    ///             1     | Compression ASCII
    ///             2     | User-defined characters
    ///             3     | Standard "Song typeface"
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintTextExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 选择打印字符的字体类型
    ///
    /// @param [in] hDev          设备句柄。
    /// @param [in] nFontType       指定字符的字体类型。可以为以下列表中所列值之一:\n
    ///                  有效值 | 含义
    ///             ---------|----------------
    ///             0     | 标准 ASCII
    ///             1     | 压缩 ASCII
    ///             2     | 用户自定义字符
    ///             3     | 标准 “宋体”
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintTextExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetTextFontType(DEVICEHANDLE hDev, int nFontStyle);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Select whether to print upside down (only valid at the beginning of the line in standard mode)
    ///
    /// @param [in] hDev     Device handle.
    /// @param [in] nMode    Specifies the font type for the character. 0: no upside down printing; 1: inverted printing.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintTextExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    ///
    /// @~Chinese
    /// @brief 选择是否倒置打印（只在标准模式的行首有效）
    ///
    /// @param [in] hDev     设备句柄。
    /// @param [in] nMode    指定字符的字体类型。0：不倒置打印；1：倒置打印。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintTextExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetTextUpsideDownMode(DEVICEHANDLE hDev, int nMode);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Select whether to print reverse or not
    ///
    /// @param [in] hDev     Device handle.
    /// @param [in] nEnable  0: no reverse 1: reverse .
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintTextExample
    ///
    /// <b>Remark\n</b>
    /// 1.In reverse mode, underline mode does not work.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 选择是否反显打印
    ///
    /// @param [in] hDev     设备句柄。
    /// @param [in] nEnable  0：不反显；1：反显。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintTextExample
    ///
    /// <b>备注\n</b>
    /// 1、在反显打印模式选择时，下划线模式不起作用。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetTextOppositeColor(DEVICEHANDLE hDev, int nEnable);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Set underline
    ///
    /// @param [in] hDev     Device handle.
    /// @param [in] nMode    0: no underline is set; 1: one bold underline point; 2: two bold underlined points.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintTextExample
    ///
    /// <b>Remark\n</b>
    /// 1.In reverse mode, underline mode does not work.\n
    /// 2.This feature IMPACT class printers do not support nMode equals 2.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 设置下划线
    ///
    /// @param [in] hDev     设备句柄。
    /// @param [in] nMode    0：不设置下划线；1：一点粗下划线；2：两点粗下划线。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintTextExample
    ///
    /// <b>备注\n</b>
    /// 1、在反显打印模式选择时，下划线模式不起作用。\n
    /// 2、此功能IMPACT类打印机不支持nMode等于2。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetTextUnderline(DEVICEHANDLE hDev, int nMode);
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Sets text color enable
    ///
    /// @param [in] hDev     Device handle.
    /// @param [in] nEnable  0:unable; 1:enable.
    ///
    /// <b>Remark\n</b>
    /// 1.This feature is only supported by POS class printers.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 双色打印使能
    ///
    /// @param [in] hDev     设备句柄。
    /// @param [in] nEnable  0：不使能；1：使能。
    ///
    /// <b>备注\n</b>
    /// 1、此功能仅POS类打印机支持。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetTextColorEnable(DEVICEHANDLE hDev, int nEnable);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Sets the color of the printed characters
    ///
    /// @param [in] hDev     Device handle.
    /// @param [in] nFontColor  0: color 1; 1: color 2.
    ///
    /// <b>Remark\n</b>
    /// 1.This function is only supported by POS printers and IMPACT printers.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 设置打印字符的颜色
    ///
    /// @param [in] hDev     设备句柄。
    /// @param [in] nFontColor  0：颜色1；1：颜色2。
    ///
    /// <b>备注\n</b>
    /// 1、此功能仅POS类打印机和IMPACT类打印机支持。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetTextFontColor(DEVICEHANDLE hDev, int nFontColor);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Sets rotate enable
    ///
    /// @param [in] hDev     Device handle.
    /// @param [in] nEnable  0: cancel the rotation of 90 degrees to print; 1: choose to rotate 90 degrees to print.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_PrintTextExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 顺时针旋转90°使能
    ///
    /// @param [in] hDev     设备句柄。
    /// @param [in] nEnable  0：取消旋转90度打印；1：选择旋转90度打印。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_PrintTextExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetTextRotate(DEVICEHANDLE hDev, int nEnable);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Select the international character set and code page
    ///
    /// @param [in] hDev       Device handle.
    /// @param [in] nCharSet   International character set, valid range see @subpage page_charset_eng.
    /// @param [in] nCodePage  International code page, valid range see @subpage page_codepage_eng.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 选择国际字符集和代码页
    ///
    /// @param [in] hDev       设备句柄。
    /// @param [in] nCharSet   国际字符集，有效范围详见 @subpage page_charset。
    /// @param [in] nCodePage  国际代码页，有效范围详见 @subpage page_codepage。
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetTextCharsetAndCodepage(DEVICEHANDLE hDev, int nCharSet, int nCodePage);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief User-defined characters enable
    ///
    /// @param [in] hDev     Device handle.
    /// @param [in] nEnable  0: cancel user-defined characters; 1: select user-defined characters.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 用户自定义字符使能
    ///
    /// @param [in] hDev     设备句柄。
    /// @param [in] nEnable  0：取消用户自定义字符；1：选择用户自定义字符。
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetTextUserDefinedCharacterEnable(DEVICEHANDLE hDev, int nEnable);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Defines user-defined characters
    ///
    /// @param [in] hDev        Device handle.
    /// @param [in] nStartCode  Start character, valid range of 32-127.
    /// @param [in] nEndCode       Termination character, valid range 32-127.
    /// @param [in] nFontType   Specifies the font type for the character. Can be one of the values listed in the following list:\n
    ///                  Valid values |Meaning
    ///             ---------|----------------
    ///             0     | Standard ASCII
    ///             1     | Compression ASCII
    ///             2     | User-defined characters
    ///             3     | Standard "Song typeface"
    /// @param [in] szChData    Character data.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ///
    /// @~Chinese
    /// @brief 定义用户自定义字符
    ///
    /// @param [in] hDev        设备句柄。
    /// @param [in] nStartCode     起始字符,有效范围为32-127。
    /// @param [in] nEndCode       终止字符,有效范围为32-127。
    /// @param [in] nFontType   指定字符的字体类型。可以为以下列表中所列值之一:\n
    ///                  有效值 | 含义
    ///             ---------|----------------
    ///             0     | 标准 ASCII
    ///             1     | 压缩 ASCII
    ///             2     | 用户自定义字符
    ///             3     | 标准 “宋体”
    /// @param [in] szChData    字符的数据。
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_HANDLE    --    @copybrief    ::ERR_HANDLE \n
    /// ::ERR_LOADDLL_FAILURE    --    @copybrief    ::ERR_LOADDLL_FAILURE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetTextDefineUserDefinedCharacter(DEVICEHANDLE hDev, int nStartCode, int nEndCode, int nFontType, char *szChData);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Text setting reserve function interface
    ///
    /// @param [in]      hDev                Device handle.
    /// @param [in]      nInstructionName    Property index value.
    /// @param [in]      nPara                Property parameters.
    /// @param [in]  szPara                Property parameters.
    ///
    /// @return
    /// ::ERR_NOT_SUPPORT    -- @copybrief ::ERR_NOT_SUPPORT \n
    ///
    /// @~Chinese
    /// @brief 文本设置预留功能接口
    ///
    /// @param [in]      hDev                设备句柄。
    /// @param [in]      nInstructionName    属性索引值。
    /// @param [in]      nPara                属性参数。
    /// @param [in]  szPara                属性参数。
    ///
    /// @return
    /// ::ERR_NOT_SUPPORT    -- @copybrief ::ERR_NOT_SUPPORT \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SetTextUniveral(DEVICEHANDLE hDev, int nInstructionName, int nPara, char *szPara);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Send files to the printer
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in]    szFilePath              The file path to send to the printer.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FILE    -- @copybrief ::ERR_FILE \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 发送文件到打印机
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in]    szFilePath              所要发送到打印机的文件路径。
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FILE    -- @copybrief ::ERR_FILE \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE DownloadFile(DEVICEHANDLE hDev, char *szFilePath);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Set the print mode for the printer
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in]    nPrintMode              Specify the print mode. Can be one of the following values:
    ///                Valid values | Meaning
    ///             ---------|----------------
    ///             0     | Standard mode(Line mode）
    ///             1     | Page mode
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_BasicSetExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置打印机的打印模式
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in]    nPrintMode              指定打印模式。可以为以下值之一：
    ///                有效值 | 含义
    ///             ---------|----------------
    ///             0     | 标准模式（行模式）
    ///             1     | 页模式
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_BasicSetExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE PrintSetMode(DEVICEHANDLE hDev, int nPrintMode);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Set the print area of the page
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in] nStartX             The distance (dot/mm) from the left edge of the starting point in the X (horizontal) direction of the specified area. \n effective range is 0-65535 points.\n
    /// @param [in] nStartY             Specifies the distance (dot/mm) from the starting point in the Y direction (vertical) to the upper boundary. \n effective range is -1-65535 points. \n this parameter only takes effect when printed in page mode, fixed to "-1" when printed in standard mode (line mode).
    /// @param [in]    nWidth              Specifies the width (horizontal) of the print area. \n effective range is 0-65535 points.
    /// @param [in]    nHeight              Specifies the height (vertical) of the print area. \n effective range is 0-65535 points.
    /// @param [in]    nDirection              Specifies the direction (origin position) of the print area. Can be one of the following values:
    ///                Valid values | Meaning
    ///             ---------|----------------
    ///             0     | Top left
    ///             1     | Bottom left
    ///             2     | Bottom riget
    ///             3     | Top right
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_BasicSetExample
    ///
    /// <b>Remark\n</b>
    /// 1.The width of the printable area is different because different printer models have different print head widths (or internal buffer widths). Similarly, the height of the printable area may vary, typically 128 × 8 points, if the values specified by the parameters nWidth and nHeight exceed this limit. Then the printable area is automatically set to the actual printable area.\n
    /// 2.If the width or height of the print area is set to 0, the printer stops processing instructions and treats the data it receives as normal character data.\n
    /// 3.If the starting point of the print area exceeds the printer's printable area, the printer stops processing instructions and treats the data it receives as ordinary character data.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置页面的打印区域
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in] nStartX             指定区域的 X （水平）方向的起始点位置离左边界的距离（点/毫米）。\n 有效范围为 0 - 65535点。
    /// @param [in] nStartY             指定 Y 方向（垂直）的起始点位置离上边界的距离（点/毫米）。\n 有效范围为-1 - 65535点。\n 该参数只有在页模式打印时生效，标准模式(行模式)打印时，固定为"-1"。
    /// @param [in]    nWidth              指定打印区域的宽度（水平方向）。\n 有效范围为 0 - 65535点。
    /// @param [in]    nHeight              指定打印区域的高度（垂直方向）。\n 有效范围为 0 - 65535点。
    /// @param [in]    nDirection              指定打印区域的方向（原点位置）。可以为以下值之一：
    ///                有效值 | 含义
    ///             ---------|----------------
    ///             0     | 左上角
    ///             1     | 左下角
    ///             2     | 右下角
    ///             3     | 右上角
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_BasicSetExample
    ///
    /// <b>备注\n</b>
    /// 1、由于不同的打印机型号有不同的打印头宽度（或内部缓冲区的宽度），所以可打印区域的宽度是不同的。同样，可打印区域的高度也有可能不同，一般大约是 128 × 8 点，如果参数 nWidth 和 nHeight 所指定的值超过此限制。那么可打印区域自动设置为实际的可打印区域。\n
    /// 2、如果打印区域的宽度或高度设置为0，则打印机停止指令的处理，而将随后接受到的数据都当作普通的字符数据。\n
    /// 3、如果打印区域的起始点超出打印机的可打印区域，则打印机停止指令的处理，而将随后接受到的数据都当作普通的字符数据。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE PageModeSetArea(DEVICEHANDLE hDev, int nStartX, int nStartY, int nWidth, int nHeight, int nDirection);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Print the data in the page or label buffer
    ///
    /// @param [in]    hDev                  Device handle.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_BasicSetExample
    ///
    /// <b>Remark\n</b>
    /// 1.If the function succeeds, it enters the paper and prints the ticket, but the page buffer or label buffer contents remain, and you can call this function again to continue printing the ticket in the page buffer or label buffer.\n
    /// 2.You can call the PageModeClearBuffer to clear the page buffer or label buffer.\n
    /// 3.Please refer to PrintSetMode。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 打印页或标签缓冲区中的数据
    ///
    /// @param [in]    hDev                  设备句柄。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_BasicSetExample
    ///
    /// <b>备注\n</b>
    /// 1、如果函数成功，则将进纸并打印票面，但是页缓冲区或标签缓冲区内容还是被保留着，可以再次调用此函数继续打印页缓冲区或标签缓冲区中的票面。\n
    /// 2、可以调用 PageModeClearBuffer 来清除页缓冲区或标签缓冲区中的数据。\n
    /// 3、另请参考 PrintSetMode。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE PageModePrint(DEVICEHANDLE hDev);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Remove ticket and label print buffer data
    ///
    /// @param [in]    hDev                  Device handle.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_BasicSetExample
    ///
    /// <b>Remark\n</b>
    /// 1.If the function succeeds, the current page buffer inside the printer is cleared.\n
    /// 2.Please also refer to PageModePrint, PrintSetMode.\n
    /// 3.This feature is not supported by the IMPACT class printer.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 清除票面和标签的打印缓冲区中的数据
    ///
    /// @param [in]    hDev                  设备句柄。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_BasicSetExample
    ///
    /// <b>备注\n</b>
    /// 1、如果函数成功，则打印机内部的当前页缓冲区被清除。\n
    /// 2、另请参考 PageModePrint，PrintSetMode。\n
    /// 3、此功能IMPACT类打印机不支持。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE PageModeClearBuffer(DEVICEHANDLE hDev);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Feed paper
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in]    nLineNum              Feed paper length. \n effective range 0-255 dots.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    /// @~Chinese
    ///
    /// @brief 走纸一段距离
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in]    nLineNum              走纸长度。\n 有效范围为 0 - 255 点。
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE FeedLineNumber(DEVICEHANDLE hDev, int nLineNum);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Cut paper
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in] nCutMode             Specify Cut paper mode. \n can be one of the following values:
    ///                Valid values | Meaning
    ///             ---------|----------------
    ///             0     | Full cut
    ///             1     | Feed paper and half cut
    ///             2     | Feed paper and full cut
    ///             3     | Half cut
    /// @param [in] nDistance             The number of points that specify the length of the feed. \n valid range is 0-255.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_BasicSetExample
    ///
    /// <b>Remark\n</b>
    /// 1.If 0 (full cut) or 3 (half cut) is selected, the printer will cut the paper immediately after printing, and the parameter nDistance is ignored.\n
    /// 2.If you choose 1 (take a distance and cut in half) or 2 (Feed paper and full cut), then the printer takes the nDistance point and cuts the paper.\n
    /// 3.If the current paper type is black label paper, select 1 (Feed paper and half cut) or 2 (Feed paper and full cut) to position the black label and cut the paper.\n
    /// 4.Please also refer to PrintSetMode.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 切纸
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in] nCutMode             指定切纸模式。\n 可以为以下值之一：
    ///                有效值 | 含义
    ///             ---------|----------------
    ///             0     | 全切
    ///             1     | 走纸一段距离并半切
    ///             2     | 走纸一段距离并全切
    ///             3     | 半切
    /// @param [in] nDistance             指定进纸长度的点数。\n 有效范围为 0 - 255。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_BasicSetExample
    ///
    /// <b>备注\n</b>
    /// 1、如果选择0（全切）或3（半切），则打印机打印完成立刻切纸，参数 nDistance 忽略。\n
    /// 2、如果选择1（走纸一段距离并半切）或2（走纸一段距离并全切），则打印机走纸 nDistance 点，然后切纸。\n
    /// 3、如果当前纸张类型为黑标纸，选择1（走纸一段距离并半切）或2（走纸一段距离并全切）时定位黑标并切纸。\n
    /// 4、另请参考 PrintSetMode。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE CutPaper(DEVICEHANDLE hDev, int nCutMode, int nDistance);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Resets the printer, clears the print buffer of data, clears the character and line height Settings, and returns the print mode to the default mode when powered on
    ///
    /// @param [in]    hDev                  Device handle.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_BasicSetExample
    ///
    /// <b>Remark\n</b>
    /// After the function is successfully executed, then:\n
    /// 1.Receive instructions in the buffer and keep them.\n
    /// 2.Preserve macro definition\n
    /// 3.Save the bitmap in Flash.\n
    /// 4.Save the data in Flash\n
    /// 5.The DIP switch setting is not checked again.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 复位打印机，把打印缓冲区中的数据清除，字符和行高的设置被清除，打印模式被恢复到上电时的缺省模式
    ///
    /// @param [in]    hDev                  设备句柄。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_BasicSetExample
    ///
    /// <b>备注\n</b>
    /// 函数成功执行后，则：\n
    /// 1、接收缓冲区中的指令保留。\n
    /// 2、宏定义保留。\n
    /// 3、Flash 中的位图保留。\n
    /// 4、Flash 中的数据保留。\n
    /// 5、DIP开关的设置不进行再次检测。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE Reset(DEVICEHANDLE hDev);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Send pulses to drawer pin to open the drawer
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in] nID                 Specify the pin of drawer.\n Can be one of the following values:
    ///                Valid values | Meaning
    ///             ---------|----------------
    ///             0     | Drawer connector pin 2
    ///             1     | Drawer connector pin 5
    /// @param [in] nOnTimes             Specifies the holding time for high level pulses sent to the drawer, nOnTimes × 2 ms. \n valid range is 0-255.
    /// @param [in] nOffTimes             Specifies the holding time for low level pulses sent to the drawer, nOnTimes × 2 ms. \n valid range is 0-255.
    ///
    /// <b>Remark\n</b>
    /// 1.If the value of the parameter nOffTimes is less than nOnTimes, the low level pulse sent to the money box remains nOnTimes × 2 milliseconds.\n
    /// 2.Please refer to the relevant materials provided by the money box supplier.\n
    /// 3.This feature is supported only for POS printers and IMPACT printers.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_NOT_SUPPORT    -- @copybrief ::ERR_NOT_SUPPORT \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 往钱箱引脚发送脉冲以打开钱箱
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in] nID                 指定钱箱的引脚。\n 可以为以下值之一：
    ///                有效值 | 含义
    ///             ---------|----------------
    ///             0     | 钱箱连接器引脚2
    ///             1     | 钱箱连接器引脚5
    /// @param [in] nOnTimes             指定往钱箱发送的高电平脉冲保持时间，即 nOnTimes × 2 毫秒。\n 有效范围为 0 - 255。
    /// @param [in] nOffTimes             指定往钱箱发送的低电平脉冲保持时间，即 nOffTimes × 2 毫秒。\n 有效范围为 0 - 255。
    ///
    /// <b>备注\n</b>
    /// 1、如果参数 nOffTimes 的值小于 nOnTimes, 则往钱箱发送的低电平脉冲的保持时间为nOnTimes × 2 毫秒。\n
    /// 2、请参考钱箱供应商提供的相关资料。\n
    /// 3、此功能仅POS类打印机和IMPACT类打印机支持。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_NOT_SUPPORT    -- @copybrief ::ERR_NOT_SUPPORT \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE KickOutDrawer(DEVICEHANDLE hDev, int nID, int nOnTimes, int nOffTimes);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Sets the application unit of the printer
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in] nUnit                 Specifies the application unit of the printer. \n can be one of the following values:
    ///                Valid values | Meaning
    ///             ---------|----------------
    ///             0     | dot
    ///             1     | millimetre
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_BasicSetExample
    ///
    /// <b>Remark\n</b>
    /// 1.The default resolution is 203*203. If the current printer resolution is not 203*203, please first call the MotionUnit interface to set the resolution, and then do other operations.
    ///
    /// @~Chinese
    /// @brief 设置打印机的应用单位
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in] nUnit                 指定打印机的应用单位。\n 可以为以下值之一：
    ///                有效值 | 含义
    ///             ---------|----------------
    ///             0     | 点
    ///             1     | 毫米
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_BasicSetExample
    ///
    /// <b>备注\n</b>
    /// 1、默认的分辨率为203*203，如果当前打印机分辨率非203*203，请先调用MotionUnit接口，设置分辨率，再进行其他操作。\n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    void POSSDKCALL_MODE ApplicationUnit(DEVICEHANDLE hDev, int nUnit);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Set print density
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in] nDensity             Specifies the print concentration of the printer. \n valid range is 1-140. \n print concentration increases with the value.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_BasicSetExample
    ///
    /// <b>Remark\n</b>
    /// 1.The printing density is set by this function, and the printer fails after restart. The printing density after restart is subject to the EEPROM setting of the printer.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置打印浓度
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in] nDensity             指定打印机的打印浓度。\n 有效范围为 1 - 140。\n 打印浓度随数值增大而增加。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_BasicSetExample
    ///
    /// <b>备注\n</b>
    /// 1、通过该函数设置打印浓度，打印机重启后失效，重启后的打印浓度以打印机的EEPROM设置为准。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE PrintDensity(DEVICEHANDLE hDev, int nDensity);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Set the printer's mobile unit (resolution)
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in] nHorizontalMU         Horizontal printer resolution. The effective value of \n is 180, 203 and 300.
    /// @param [in] nVerticalMU         Printer longitudinal resolution. The effective value of \n is 180, 203 and 300.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_BasicSetExample
    ///
    /// <b>Remark\n</b>
    /// 1.Please refer to ::PrintSetMode。\n
    /// 2.The resolution set must be consistent with the actual printer resolution.\n
    /// 3.Set after opening the port。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置打印机的移动单位(分辨率)
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in] nHorizontalMU         打印机横向分辨率。\n 有效值为180、203、300。
    /// @param [in] nVerticalMU         打印机纵向分辨率。\n 有效值为180、203、300。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_BasicSetExample
    ///
    /// <b>备注\n</b>
    /// 1、另请参考 ::PrintSetMode。\n
    /// 2、设置的分辨率必须与打印机实际分辨率一致。\n
    /// 3、在打开端口后设置。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE MotionUnit(DEVICEHANDLE hDev, int nHorizontalMU, int nVerticalMU);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Set the paper type for the printer
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in] nPaperType             Specifies the paper type for the printer. \n can be one of the following values:
    ///                Valid values | Meaning
    ///             ---------|----------------
    ///             0     | Continuous paper
    ///             1     | Black tag label paper
    ///             2     | White tag label paper
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置打印机的纸张类型
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in] nPaperType             指定打印机的纸张类型。\n 可以为以下值之一：
    ///                有效值 | 含义
    ///             ---------|----------------
    ///             0     | 连续纸
    ///             1     | 黑标记标签纸
    ///             2     | 白标记标签纸
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SelectPaperType(DEVICEHANDLE hDev, int nPaperType);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    ///
    /// @brief Set the paper type of the printer (reset to take effect)
    ///
    /// @param [in]    hDev                  Devcice handle.
    /// @param [in] nPaperType             Specifies the paper type of the printer. \n can be one of the following values:
    ///                Valid values | Meaning
    ///             ---------|----------------
    ///             0     | Continuous paper
    ///             1     | Black tag label paper
    ///             2     | White tag label paper
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 设置打印机的纸张类型(复位生效)
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in] nPaperType             指定打印机的纸张类型。\n 可以为以下值之一：
    ///                有效值 | 含义
    ///             ---------|----------------
    ///             0     | 连续纸
    ///             1     | 黑标记标签纸
    ///             2     | 白标记标签纸
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SelectPaperTypeEEP(DEVICEHANDLE hDev, int nPaperType);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Basic Settings reserve interface
    ///
    /// @param [in]    hDev                  Device handle.
    /// @param [in] nInstructionName     Reserve parameter 1.
    /// @param [in] nPara1                 Reserve parameter 2.
    /// @param [in] szPara2             Reserve parameter 3.
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 基本设置预留接口
    ///
    /// @param [in]    hDev                  设备句柄。
    /// @param [in] nInstructionName     预留参数1。
    /// @param [in] nPara1                 预留参数2。
    /// @param [in] szPara2             预留参数3。
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE BasicSetReserveFunction(DEVICEHANDLE hDev, int nInstructionName, int nPara1, char *szPara2);
    
    // 查询
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Real time query of printer status
    /// @param [in]        hDev                 Device handle.
    /// @param [out]    szStatus            Returns a buffer of printer status with a buffer size of 1 byte.
    /// @param [in]        nDataLength            Points to the length of the buffer that returns the status of the printer.
    /// @param [out]    nRealDataLength        Returns the length of the actual printer state.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_QueryExample
    ///
    /// <b>State analysis\n</b>
    /// See details @ref EG_RealTimeStatus
    ///
    /// <b>Remark\n</b>
    /// 1.The printer status corresponds to szStatus returned by different types of printers is different. The specific status is as follows:\n
    /// ① POS-type printing device status analysis see detail @subpage page_realpos_eng .\n
    /// ② KIOSK class printing device status analysis see details @subpage page_realkiosk_eng .\n
    /// ③ TKIOSK class printing device status analysis see details @subpage page_realtkiosk_eng .\n
    /// ④ IMPACT class printing device status analysis see details @subpage page_realimpact_eng .\n
    /// 2.State analysis is applicable to most printers. If the analysis bit does not match the reality, please refer to the programming manual of the relevant model.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    ///
    /// @~Chinese
    /// @brief 实时查询打印机状态
    ///
    /// @param [in]        hDev                 设备句柄。
    /// @param [out]    szStatus            返回打印机状态的缓冲区，缓冲区大小为 1 个字节。
    /// @param [in]        nDataLength            指向返回打印机状态的缓冲区的长度。
    /// @param [out]    nRealDataLength        返回实际打印机状态的长度。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_QueryExample
    ///
    /// <b>状态解析\n</b>
    /// 详见 @ref EG_RealTimeStatus
    ///
    /// <b>备注\n</b>
    /// 1、不同类型的打印机返回的szStatus对应的打印机状态不一样，具体状态解析如下：\n
    /// ① POS类打印设备状态解析详见 @subpage page_realpos 。\n
    /// ② KIOSK类打印设备状态解析详见 @subpage page_realkiosk 。\n
    /// ③ TKIOSK类打印设备状态解析详见 @subpage page_realtkiosk 。\n
    /// ④ IMPACT类打印设备状态解析详见 @subpage page_realimpact 。\n
    /// 2、状态解析适用大部分打印机，若解析位与实际不符，请参考相关机型的编程手册。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE RealTimeQueryStatus(DEVICEHANDLE hDev, char *szStatus, int nDataLength, unsigned long *nRealDataLength);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Non-real-time query of printer status
    ///
    /// @param [in]        hDev                 Device handle.
    /// @param [out]    szStatus            Returns a buffer of printer status with a buffer size of 1 byte.
    /// @param [in]        nDataLength            Points to the length of the buffer that returns the status of the printer.
    /// @param [out]    nRealDataLength        Returns the length of the actual printer state.
    ///
    /// <b>Remark\n</b>
    /// 1.szStatus State analysis
    ///              Hex|Status | Meaning
    ///             --------|-----------|------------
    ///             0x03 | 0 / 1     | Paper feeder has paper / Paper will run out
    ///             0x0C | 0 / 1     | There is paper at the print head / No paper
    ///             0x30 | 0 / 1     | Cashbox connector pin 3 is low (off) / high (on)
    ///
    /// 2.Among them, the POS type printing device and the IMPACT type printing device support the cash box status inquiry, and the KIOSK type printing device and the TKIOSK type printing device do not support the cash box status inquiry.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    ///
    /// @~Chinese
    /// @brief 非实时查询打印机状态
    ///
    /// @param [in]        hDev                 设备句柄。
    /// @param [out]    szStatus            返回打印机状态的缓冲区，缓冲区大小为 1 个字节。
    /// @param [in]        nDataLength            指向返回打印机状态的缓冲区的长度。
    /// @param [out]    nRealDataLength        返回实际打印机状态的长度。
    ///
    /// <b>备注\n</b>
    /// 1、szStatus状态解析
    ///              Hex|Status | Meaning
    ///             --------|-----------|------------
    ///             0x03 | 0 / 1     | 容纸器中有纸 / 纸将用尽
    ///             0x0C | 0 / 1     | 打印头处有纸 / 无纸
    ///             0x30 | 0 / 1     | 钱箱连接器引脚 3 的电平为低（关闭） / 高（打开）
    ///
    /// 2、其中POS类打印设备和IMPACT类打印设备支持钱箱状态查询，KIOSK类打印设备和TKIOSK类打印设备不支持钱箱状态查询。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    ///
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE NonRealTimeQueryStatus(DEVICEHANDLE hDev, char *szStatus, int nDataLength, unsigned long *nRealDataLength);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Automatic status returns query printer status
    ///
    /// @param [in]        hDev                 Device handle.
    /// @param [out]    szStatus            Returns a buffer of printer status with a buffer size of at least 4 bytes.
    /// @param [in]        nDataLength            Points to the length of the buffer that returns the status of the printer.
    /// @param [in]        nEnable        Automatic status return enable
    ///                Valid values | Meaning
    ///             ---------|----------------
    ///             0     | Turn off automatic status return
    ///             1     | Enable automatic status return and read status
    /// @param [out]    nRealDataLength        Returns the length of the actual printer state.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_AutoQueryStatus
    ///
    /// <b>State analysis\n</b>
    /// See details @ref EG_AutoStatus
    ///
    /// <b>Remark\n</b>
    /// 1.The printer status corresponding to szStatus returned by different types of printers is different. The specific status is as follows:\n
    /// ① For automatic state resolution of POS-type printing devices, see  @subpage page_autopos_eng .\n
    /// ② The automatic state resolution of KIOSK printing equipment, see @subpage page_autokiosk_eng .\n
    /// ③ Automatic status analysis of TKIOSK printing devices see @subpage page_autotkiosk_eng .\n
    /// ④ IMPACT class printing device automatic state resolution, see @subpage page_autoimpact_eng .\n
    /// 2.State analysis is applicable to most printers. If the resolution bit does not match the actual one, please refer to the programming manual of the relevant model.
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    ///
    /// @~Chinese
    /// @brief 自动状态返回查询打印机状态
    ///
    /// @param [in]        hDev                 设备句柄。
    /// @param [out]    szStatus            返回打印机状态的缓冲区，缓冲区大小至少为 4 个字节。
    /// @param [in]        nDataLength            指向返回打印机状态的缓冲区的长度。
    /// @param [in]        nEnable        自动状态返回使能
    ///                有效值 | 含义
    ///             ---------|----------------
    ///             0     | 关闭自动状态返回
    ///             1     | 使能自动状态返回并读取状态
    /// @param [out]    nRealDataLength        返回实际打印机状态的长度。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_AutoQueryStatus
    ///
    /// <b>状态解析\n</b>
    /// 详见 @ref EG_AutoStatus
    ///
    /// <b>备注\n</b>
    /// 1、不同类型的打印机返回的szStatus对应的打印机状态不一样，具体状态解析如下：\n
    /// ① POS类打印设备自动状态解析详见 @subpage page_autopos 。\n
    /// ② KIOSK类打印设备自动状态解析详见 @subpage page_autokiosk 。\n
    /// ③ TKIOSK类打印设备自动状态解析详见 @subpage page_autotkiosk 。\n
    /// ④ IMPACT类打印设备自动状态解析详见 @subpage page_autoimpact 。\n
    /// 2、状态解析适用大部分打印机，若解析位与实际不符，请参考相关机型的编程手册。
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE AutoQueryStatus(DEVICEHANDLE hDev, char *szStatus, int nDataLength, int nEnable, unsigned long *nRealDataLength);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Get the firmware version number of the printer
    ///
    /// @param [in]        hDev                 Device handle.
    /// @param [out]    szFirmwareVersion    Returns the buffer of the firmware version number with a buffer size of at least 20 bytes.
    /// @param [in]        nDataLength            Points to the length of the buffer that returns the firmware version number.
    /// @param [out]    nRealDataLength        Returns the length of the actual firmware version number.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_QueryExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    /// @brief 获取打印机的固件版本号
    ///
    /// @param [in]        hDev                 设备句柄。
    /// @param [out]    szFirmwareVersion    返回固件版本号的缓冲区，缓冲区大小至少为 20 个字节。
    /// @param [in]        nDataLength            指向返回固件版本号的缓冲区的长度。
    /// @param [out]    nRealDataLength        返回实际固件版本号的长度。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_QueryExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE FirmwareVersion(DEVICEHANDLE hDev, char *szFirmwareVersion, int nDataLength, unsigned long *nRealDataLength);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Obtain the software version number
    ///
    /// @param [in]        hDev                 Device handle.
    /// @param [out]    szSoftwareVersion    Returns the buffer of the software version number with a buffer size of at least 8 bytes.
    /// @param [in]        nDataLength            The length of the buffer pointing to the returned software version number.
    /// @param [out]    nRealDataLength        Returns the length of the actual software version number.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_QueryExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    ///
    /// @~Chinese
    /// @brief 获取软件版本号
    ///
    /// @param [in]        hDev                 设备句柄。
    /// @param [out]    szSoftwareVersion    返回的软件版本号的缓冲区，缓冲区大小至少为 8 个字节。
    /// @param [in]        nDataLength            指向返回的软件版本号的缓冲区的长度。
    /// @param [out]    nRealDataLength        返回实际的软件版本号的长度。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_QueryExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE SoftwareVersion(DEVICEHANDLE hDev, char *szSoftwareVersion, int nDataLength, unsigned long *nRealDataLength);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Get printer vendor information
    ///
    /// @param [in]        hDev                 Device handle.
    /// @param [out]    szVendorInformation    Returns a buffer of vendor information with a buffer size of at least 4 bytes.
    /// @param [in]        nDataLength            Points to the length of the buffer that returns vendor information.
    /// @param [out]    nRealDataLength        Returns the length of the actual vendor information.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_QueryExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    ///
    /// @brief 获取打印机的厂商信息
    ///
    /// @param [in]        hDev                 设备句柄。
    /// @param [out]    szVendorInformation    返回厂商信息的缓冲区，缓冲区大小至少为 4 个字节。
    /// @param [in]        nDataLength            指向返回厂商信息的缓冲区的长度。
    /// @param [out]    nRealDataLength        返回实际厂商信息的长度。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_QueryExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE VendorInformation(DEVICEHANDLE hDev, char *szVendorInformation, int nDataLength, unsigned long *nRealDataLength);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Get the name of the printer
    ///
    /// @param [in]        hDev                 Device handle
    /// @param [out]    szPrinterName        Returns a buffer of the printer name with a buffer size of at least 4 bytes.
    /// @param [in]        nDataLength            Points to the length of the buffer that returns the printer name.
    /// @param [out]    nRealDataLength        Returns the length of the actual printer name.
    ///
    /// <b>The sample code\n</b>
    /// Valid values @ref EG_QueryExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    /// @brief 获取打印机的名称
    ///
    /// @param [in]        hDev                 设备句柄。
    /// @param [out]    szPrinterName        返回打印机名称的缓冲区，缓冲区大小至少为 4 个字节。
    /// @param [in]        nDataLength            指向返回打印机名称的缓冲区的长度。
    /// @param [out]    nRealDataLength        返回实际打印机名称的长度。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_QueryExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE PrinterName(DEVICEHANDLE hDev, char *szPrinterName, int nDataLength, unsigned long *nRealDataLength);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Get the resolution of the printer
    ///
    /// @param [in]        hDev                 Device handle.
    /// @param [out]    szResolutionRatio    Returns a buffer of the printer name with a buffer size of 2 bytes.\n
    ///                 The first byte represents the horizontal resolution, 0x01 means 203dpi, 0x02 means 180dpi\n
    ///                 The second byte represents the vertical resolution, 0x01 means 203dpi, 0x02 means 180dpi\n
    /// @param [in]        nDataLength            Points to the length of the buffer that returns the resolution of the printer.
    /// @param [out]    nRealDataLength        Returns the length of the actual printer resolution.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_QueryExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_FIRNOSUPPORT    -- @copybrief ::ERR_FIRNOSUPPORT \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    /// @brief 获取打印机的分辨率
    ///
    /// @param [in]        hDev                 设备句柄。
    /// @param [out]    szResolutionRatio    返回打印机名称的缓冲区，缓冲区大小为2个字节。\n
    ///                 第一个字节代表横向分辨率，0x01表示203dpi，0x02表示180dpi\n
    ///                 第二个字节代表纵向分辨率，0x01表示203dpi，0x02表示180dpi\n
    /// @param [in]        nDataLength            指向返回打印机分辨率的缓冲区的长度。
    /// @param [out]    nRealDataLength        返回实际打印机分辨率的长度。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_QueryExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_FIRNOSUPPORT    -- @copybrief ::ERR_FIRNOSUPPORT \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE ResolutionRatio(DEVICEHANDLE hDev, char *szResolutionRatio, int nDataLength, unsigned long *nRealDataLength);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    ///
    /// @~English
    /// @brief Get the hardware serial number of the printer
    ///
    /// @param [in]        hDev                     Device handle
    /// @param [out]    szHardwareSerialNumber    Returns a buffer of the printer hardware serial number with a buffer size of at least 4 bytes.\n
    /// @param [in]        nDataLength                Points to the length of the buffer that returns the serial number of the printer hardware.
    /// @param [out]    nRealDataLength            Returns the length of the actual printer hardware serial number.
    ///
    /// <b>The sample code\n</b>
    /// See details @ref EG_QueryExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ///
    /// @~Chinese
    /// @brief 获取打印机的硬件序列号
    ///
    /// @param [in]        hDev                     设备句柄。
    /// @param [out]    szHardwareSerialNumber    返回打印机硬件序列号的缓冲区，缓冲区大小至少为4个字节。\n
    /// @param [in]        nDataLength                指向返回打印机硬件序列号的缓冲区的长度。
    /// @param [out]    nRealDataLength            返回实际打印机硬件序列号的长度。
    ///
    /// <b>示例代码\n</b>
    /// 详见 @ref EG_QueryExample
    ///
    /// @return
    /// ::ERR_SUCCESS    -- @copybrief ::ERR_SUCCESS \n
    /// ::ERR_PARAMATER    -- @copybrief ::ERR_PARAMATER \n
    /// ::ERR_FAIL    -- @copybrief ::ERR_FAIL \n
    /// ::ERR_LOADDLL_FAILURE    -- @copybrief ::ERR_LOADDLL_FAILURE \n
    /// ::ERR_HANDLE    -- @copybrief ::ERR_HANDLE \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE HardwareSerialNumber(DEVICEHANDLE hDev, char *szHardwareSerialNumber, int nDataLength, unsigned long *nRealDataLength);
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Status query reservation interface
    ///
    /// @param  hDev                 Device handle.
    /// @param  nInstructionsName    Attribute value
    /// @param  nPara                 Function parameter
    /// @param     szPara                 Function parameter
    ///
    /// @return
    /// ::ERR_NOT_SUPPORT    -- @copybrief ::ERR_NOT_SUPPORT \n
    ///
    /// @~Chinese
    /// @brief 状态查询预留接口
    ///
    /// @param  hDev                 设备句柄。
    /// @param  nInstructionsName    属性值。
    /// @param  nPara                 功能参数。
    /// @param     szPara                 功能参数。
    ///
    /// @return
    /// ::ERR_NOT_SUPPORT    -- @copybrief ::ERR_NOT_SUPPORT \n
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE QueryReserveFunction(DEVICEHANDLE hDev, int nInstructionsName, int nPara, char *szPara, unsigned long *nRealDataLength);
    
    // 日志
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    /// @~English
    /// @brief Logging
    /// @param                hDev          The development.
    /// @param [in,out]    szFileName    If non-null, filename of the file.
    /// @param [in,out]    szFilePath    If non-null, full pathname of the file.
    /// @param                nOpen          The open.
    ///
    /// @return    A POSSDKCALL_MODE.
    ///
    /// @~Chinese
    ///
    /// @brief 记录日志
    /// @param                hDev          The development.
    /// @param [in,out]    szFileName    If non-null, filename of the file.
    /// @param [in,out]    szFilePath    If non-null, full pathname of the file.
    /// @param                nOpen          The open.
    ///
    /// @return    A POSSDKCALL_MODE.
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    
    int POSSDKCALL_MODE InstructionsRecord(DEVICEHANDLE hDev, char *szFileName, char *szFilePath, int nOpen);
    
#ifdef __cplusplus
}
#endif

/// 通讯
typedef int (POSSDKCALL_MODE *pSDKGetVersionInfo)(char *szVersionInfo, int nInfoLength, int *npInforTrueLen);
typedef int (POSSDKCALL_MODE *pEnumDeviceInfo1)(int nOperationType, char *szDeviceNameBuf, int nBufLen, int *npNumber);
typedef DEVICEHANDLE(POSSDKCALL_MODE *pInit)(char *szPrinterName);
typedef int (POSSDKCALL_MODE *pOpenCOMPort)(DEVICEHANDLE hDev, char *szName, int nComBaudrate, int nComDataBits, int nComStopBits, int nComParity, int nParam);
typedef int (POSSDKCALL_MODE *pOpenLPTPort)(DEVICEHANDLE hDev, char *szName);
typedef int (POSSDKCALL_MODE *pOpenUsbApiPort)(DEVICEHANDLE hDev, int nDeviceId);
typedef int (POSSDKCALL_MODE *pOpenUsbClassPort)(DEVICEHANDLE hDev, char *szName, int nIsSplitStatus);
typedef int (POSSDKCALL_MODE *pOpenNetPortByName)(DEVICEHANDLE hDev, char *szName);
typedef int (POSSDKCALL_MODE *pOpenNetPort)(DEVICEHANDLE hDev, char *szNetIP, int nPort, int nProtocalType, int nBroadcast);
typedef int (POSSDKCALL_MODE *pOpenBlueToothPortByName)(DEVICEHANDLE hDev, char *szName);
typedef int (POSSDKCALL_MODE *pOpenBlueToothPort)(DEVICEHANDLE hDev, char *szMACAddress);
typedef int (POSSDKCALL_MODE *pOpenBlueToothPortMFI)(DEVICEHANDLE hDev, char *szMACAddress);
typedef int (POSSDKCALL_MODE *pOpenDriverPort)(DEVICEHANDLE hDev, char *szName);
typedef int (POSSDKCALL_MODE *pClosePort11)(DEVICEHANDLE hDev);
typedef int (POSSDKCALL_MODE *pSendPortData)(DEVICEHANDLE hDev, char *szData, int nDataLength, int *npReturnLen);
typedef int (POSSDKCALL_MODE *pReadPortData)(DEVICEHANDLE hDev, char *szData, int nDataLength, int *npReturnLen);
typedef int (POSSDKCALL_MODE *pSetPortTimeout)(DEVICEHANDLE hDev, int nWriteTimeout, int nReadTimeout);
typedef int (POSSDKCALL_MODE *pGetPortTimeout)(DEVICEHANDLE hDev, int *nWriteTimeout, int *nReadTimeout);

/// 位图
typedef int (POSSDKCALL_MODE *pPrintBitmap)(DEVICEHANDLE hDev, char *szFilePath, int nStartX, int nStartY, int nType);
typedef int (POSSDKCALL_MODE *pPrintBitmapByMode)(DEVICEHANDLE hDev, char *szFilePath, int nStartX, int nStartY, int nMode);
typedef int (POSSDKCALL_MODE *pPrintTrueType)(DEVICEHANDLE hDev, char *szText, int nStartX, int nStartY, char *szFontName, int nFontHeight, int nFontWidth, int nBold);
typedef int (POSSDKCALL_MODE *pDownloadRAMBitmapByFile)(DEVICEHANDLE hDev, char *szFilePath, int nImageID);
typedef int (POSSDKCALL_MODE *pPrintRAMBitmap)(DEVICEHANDLE hDev, int nImageID, int nStartX, int nStartY, int nMode);
typedef int (POSSDKCALL_MODE *pDownloadFlashBitmapByFile)(DEVICEHANDLE hDev, char *szFilePath[], int nImageCount);
typedef int (POSSDKCALL_MODE *pPrintFlashBitmap)(DEVICEHANDLE hDev, int nImageID, int nStartX, int nStartY, int nMode);

/// 条码
typedef int (POSSDKCALL_MODE *pPrintBarcode)(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nType, int nBasicWidth, int nHeight, int nHriFontType, int nHriFontPosition, int nBytesToPrint);
typedef int (POSSDKCALL_MODE *pPrintBarcodeSimple)(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nType, int nWidth, int nHeight, int nHriFontPosition);
typedef int (POSSDKCALL_MODE *pBarcodePrintQR)(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nBasicWidth, int nSymbolType, int nLanguageMode, int nErrorCorrect, int nBytesToPrint);
typedef int (POSSDKCALL_MODE *pBarcodePrintQREx)(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nBasicWidth, int nErrorCorrect, int nBytesToPrint);
typedef int (POSSDKCALL_MODE *pBarcodePrintPDF417)(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nBasicWidth, int nHeight, int nLines, int nColumns, int nScaleH, int nScaleV, int nCorrectGrade, int nBytesToPrint);
typedef int (POSSDKCALL_MODE *pBarcodePrintPDF417Image)(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nBasicWidth, int nHeight, int nLines, int nColumns, int nScaleH, int nScaleV, int nCorrectGrade, int nBytesToPrint);
typedef int (POSSDKCALL_MODE *pBarcodePrintPDF417Simple)(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nWidth, int nHeight);
typedef int (POSSDKCALL_MODE *pBarcodePrintMaxicode)(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nBytesToPrint);
typedef int (POSSDKCALL_MODE *pBarcodePrintGS1DataBar)(DEVICEHANDLE hDev, char *szDataBuffer, int nStartX, int nStartY, int nBarcodeType, int nBasicWidth, int nHeight, int nSegmentNum, int nSeparatorHeight, int nBasicHeight, int nHRI, int nAI, int nBytesToPrint);
typedef int (POSSDKCALL_MODE *pBarcodeReserveFunction)(DEVICEHANDLE hDev, int nInstructionsName, int nPara1, char *szPara2);

/// 文本
typedef int (POSSDKCALL_MODE *pFeedLine)(DEVICEHANDLE hDev);
typedef int (POSSDKCALL_MODE *pPrintTextOut)(DEVICEHANDLE hDev, char *szTextData, int nStartX, int nStartY);
typedef int (POSSDKCALL_MODE *pUniversalTextOut)(DEVICEHANDLE hDev, char *szTextData, int nStartX, int nStartY, int nWidthTimes, int nHeightTimes, int nFontType, int nFontStyle);
typedef int (POSSDKCALL_MODE *pSetTextLineHight)(DEVICEHANDLE hDev, int nLineHeight);
typedef int (POSSDKCALL_MODE *pSetTextBold)(DEVICEHANDLE hDev, int nBold);
typedef int (POSSDKCALL_MODE *pSetTextDoubleWidthAndHeight)(DEVICEHANDLE hDev, int nWidthEnable, int nHeightEnable);
typedef int (POSSDKCALL_MODE *pSetAlignmentMode)(DEVICEHANDLE hDev, int nAlignment);
typedef int (POSSDKCALL_MODE *pSetTextCharacterSpace)(DEVICEHANDLE hDev, int nLeftSpace, int nRightSpace, int nMode);
typedef int (POSSDKCALL_MODE *pSetTextMagnifyTimes)(DEVICEHANDLE hDev, int nHorMagnifyTimes, int nVerMagnifyTimes);
typedef int (POSSDKCALL_MODE *pSetTextFontType)(DEVICEHANDLE hDev, int nFontStyle);
typedef int (POSSDKCALL_MODE *pSetTextUpsideDownMode)(DEVICEHANDLE hDev, int nMode);
typedef int (POSSDKCALL_MODE *pSetTextOppositeColor)(DEVICEHANDLE hDev, int nEnable);
typedef int (POSSDKCALL_MODE *pSetTextColorEnable)(DEVICEHANDLE hDev, int nEnable);
typedef int (POSSDKCALL_MODE *pSetTextFontColor)(DEVICEHANDLE hDev, int nFontColor);
typedef int (POSSDKCALL_MODE *pSetTextUnderline)(DEVICEHANDLE hDev, int nMode);
typedef int (POSSDKCALL_MODE *pSetTextRotate)(DEVICEHANDLE hDev, int nEnable);
typedef int (POSSDKCALL_MODE *pSetTextCharsetAndCodepage)(DEVICEHANDLE hDev, int nCharSet, int nCodePage);
typedef int (POSSDKCALL_MODE *pSetTextUserDefinedCharacterEnable)(DEVICEHANDLE hDev, int nEnable);
typedef int (POSSDKCALL_MODE *pSetTextDefineUserDefinedCharacter)(DEVICEHANDLE hDev, int nStartCode, int nEndCode, int nFontType, char *szChData);
typedef int (POSSDKCALL_MODE *pSetTextUniveral)(DEVICEHANDLE hDev, int nInstructionName, int nPara1, char *szPara2);

/// 基本设置
typedef int (POSSDKCALL_MODE *pDownloadFile)(DEVICEHANDLE hDev, char *szFilePath);
typedef int (POSSDKCALL_MODE *pPrintSetMode)(DEVICEHANDLE hDev, int nPrintMode);
typedef int (POSSDKCALL_MODE *pPageModeSetArea)(DEVICEHANDLE hDev, int nStartX, int nStartY, int nWidth, int nHeight, int nDirection);
typedef int (POSSDKCALL_MODE *pPageModePrint)(DEVICEHANDLE hDev);
typedef int (POSSDKCALL_MODE *pPageModeClearBuffer)(DEVICEHANDLE hDev);
typedef int (POSSDKCALL_MODE *pFeedLineNumber)(DEVICEHANDLE hDev, int nLineNum);
typedef int (POSSDKCALL_MODE *pCutPaper)(DEVICEHANDLE hDev, int nCutMode, int nDistance);
typedef int (POSSDKCALL_MODE *pReset)(DEVICEHANDLE hDev);
typedef int (POSSDKCALL_MODE *pKickOutDrawer)(DEVICEHANDLE hDev, int nID, int nOnTimes, int nOffTimes);
typedef int (POSSDKCALL_MODE *pApplicationUnit)(DEVICEHANDLE hDev, int nUnit);
typedef int (POSSDKCALL_MODE *pPrintDensity)(DEVICEHANDLE hDev, int nDensity);
typedef int (POSSDKCALL_MODE *pMotionUnit)(DEVICEHANDLE hDev, int nHorizontalMU, int nVerticalMU);
typedef int (POSSDKCALL_MODE *pSelectPaperType)(DEVICEHANDLE hDev, int nPaperType);
typedef int (POSSDKCALL_MODE *pSelectPaperTypeEEP)(DEVICEHANDLE hDev, int nPaperType);
typedef int (POSSDKCALL_MODE *pBasicSetReserveFunction)(DEVICEHANDLE hDev, int nInstructionName, int nPara1, char *szPara2);

/// 查询
typedef int (POSSDKCALL_MODE *pRealTimeQueryStatus)(DEVICEHANDLE hDev, char *szStatus, int nDataLength, unsigned long *nRealDataLength);
typedef int (POSSDKCALL_MODE *pNonRealTimeQueryStatus)(DEVICEHANDLE hDev, char *szStatus, int nDataLength, unsigned long *nRealDataLength);
typedef int (POSSDKCALL_MODE *pAutoQueryStatus)(DEVICEHANDLE hDev, char *szStatus, int nDataLength, int nEnable, unsigned long *nRealDataLength);
typedef int (POSSDKCALL_MODE *pFirmwareVersion)(DEVICEHANDLE hDev, char *szFirmwareVersion, int nDataLength, unsigned long *nRealDataLength);
typedef int (POSSDKCALL_MODE *pSoftwareVersion)(DEVICEHANDLE hDev, char *szSoftwareVersion, int nDataLength, unsigned long *nRealDataLength);
typedef int (POSSDKCALL_MODE *pVendorInformation)(DEVICEHANDLE hDev, char *szVendorInformation, int nDataLength, unsigned long *nRealDataLength);
typedef int (POSSDKCALL_MODE *pPrinterName)(DEVICEHANDLE hDev, char *szPrinterName, int nDataLength, unsigned long *nRealDataLength);
typedef int (POSSDKCALL_MODE *pResolutionRatio)(DEVICEHANDLE hDev, char *szResolutionRatio, int nDataLength, unsigned long *nRealDataLength);
typedef int (POSSDKCALL_MODE *pHardwareSerialNumber)(DEVICEHANDLE hDev, char *szHardwareSerialNumber, int nDataLength, unsigned long *nRealDataLength);
typedef int (POSSDKCALL_MODE *pQueryReserveFunction)(DEVICEHANDLE hDev, int nInstructionsName, int nPara, char *szPara, unsigned long *nRealDataLength);

/// 日志
typedef int (POSSDKCALL_MODE *pInstructionsRecord)(DEVICEHANDLE hDev, char *szFileName, char *szFilePath, int nOpen);

