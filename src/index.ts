import { NativeModules, NativeEventEmitter, Platform } from "react-native";

const RNUSBPrinter = NativeModules.RNUSBPrinter;
const RNBLEPrinter = NativeModules.RNBLEPrinter;
const RNNetPrinter = NativeModules.RNNetPrinter;

export interface PrinterOptions {
  beep?: boolean;
  cut?: boolean;
  tailingLine?: boolean;
  encoding?: string;
}

export interface IUSBPrinter {
  device_name: string;
  vendor_id: string;
  product_id: string;
}

export interface IBLEPrinter {
  device_name: string;
  inner_mac_address: string;
}

export interface INetPrinter {
  device_name: string;
  host: string;
  port: string;
}

// TODO: may be we can remove this, as we are going to send buffer as input (for iOS)
const textPreprocessingIOS = (text: string) => {
  let options = {
    beep: true,
    cut: true,
  };
  return {
    text: text
      .replace(/<\/?CB>/g, "")
      .replace(/<\/?CM>/g, "")
      .replace(/<\/?CD>/g, "")
      .replace(/<\/?C>/g, "")
      .replace(/<\/?D>/g, "")
      .replace(/<\/?B>/g, "")
      .replace(/<\/?M>/g, ""),
    opts: options,
  };
};

export const USBPrinter = {
  init: (): Promise<void> =>
    new Promise((resolve, reject) =>
      RNUSBPrinter.init(
        () => resolve(),
        (error: Error) => reject(error)
      )
    ),

  getDeviceList: (): Promise<IUSBPrinter[]> =>
    new Promise((resolve, reject) =>
      RNUSBPrinter.getDeviceList(
        (printers: IUSBPrinter[]) => resolve(printers),
        (error: Error) => reject(error)
      )
    ),

  connectPrinter: (vendorId: string, productId: string): Promise<IUSBPrinter> =>
    new Promise((resolve, reject) =>
      RNUSBPrinter.connectPrinter(
        vendorId,
        productId,
        (printer: IUSBPrinter) => resolve(printer),
        (error: Error) => reject(error)
      )
    ),

  closeConn: (): Promise<void> =>
    new Promise((resolve) => {
      RNUSBPrinter.closeConn();
      resolve();
    }),

  print: (text: string): void =>
    RNUSBPrinter.printRawData(text, (error: Error) => console.warn(error)),
};

export const BLEPrinter = {
  init: (): Promise<void> =>
    new Promise((resolve, reject) =>
      RNBLEPrinter.init(
        () => resolve(),
        (error: Error) => reject(error)
      )
    ),

  getDeviceList: (): Promise<IBLEPrinter[]> =>
    new Promise((resolve, reject) =>
      RNBLEPrinter.getDeviceList(
        (printers: IBLEPrinter[]) => resolve(printers),
        (error: Error) => reject(error)
      )
    ),

  connectPrinter: (inner_mac_address: string): Promise<IBLEPrinter> =>
    new Promise((resolve, reject) =>
      RNBLEPrinter.connectPrinter(
        inner_mac_address,
        (printer: IBLEPrinter) => resolve(printer),
        (error: Error) => reject(error)
      )
    ),

  closeConn: (): Promise<void> =>
    new Promise((resolve) => {
      RNBLEPrinter.closeConn();
      resolve();
    }),

  print: (text: string): void => {
    if (Platform.OS === "ios") {
      // const processedText = textPreprocessingIOS(text);
      RNBLEPrinter.printRawData(
        text,
        // processedText.opts,
        (error: Error) => console.warn(error)
      );
    } else {
      RNBLEPrinter.printRawData(text, (error: Error) => console.warn(error));
    }
  },
};

export const NetPrinter = {
  init: (): Promise<void> =>
    new Promise((resolve, reject) =>
      RNNetPrinter.init(
        () => resolve(),
        (error: Error) => reject(error)
      )
    ),

  getDeviceList: (): Promise<INetPrinter[]> =>
    new Promise((resolve, reject) =>
      RNNetPrinter.getDeviceList(
        (printers: INetPrinter[]) => resolve(printers),
        (error: Error) => reject(error)
      )
    ),

  connectPrinter: (host: string, port: string): Promise<INetPrinter> =>
    new Promise((resolve, reject) =>
      RNNetPrinter.connectPrinter(
        host,
        port,
        (printer: INetPrinter) => resolve(printer),
        (error: Error) => reject(error)
      )
    ),

  closeConn: (): Promise<void> =>
    new Promise((resolve) => {
      RNNetPrinter.closeConn();
      resolve();
    }),

  print: (text: string): void => {
    if (Platform.OS === "ios") {
      const processedText = textPreprocessingIOS(text);
      RNNetPrinter.printRawData(
        processedText.text,
        processedText.opts,
        (error: Error) => console.warn(error)
      );
    } else {
      RNNetPrinter.printRawData(text, (error: Error) => console.warn(error));
      // Or may be we try to send byte data
      // RNNetPrinter.printByteData(Object.values(text), (error: Error) =>
      //    console.warn(error)
      // );
    }
  },
};

export const NetPrinterEventEmitter = new NativeEventEmitter(RNNetPrinter);

export enum RN_THERMAL_RECEIPT_PRINTER_EVENTS {
  EVENT_NET_PRINTER_SCANNED_SUCCESS = "scannerResolved",
  EVENT_NET_PRINTER_SCANNING = "scannerRunning",
  EVENT_NET_PRINTER_SCANNED_ERROR = "registerError",
}
