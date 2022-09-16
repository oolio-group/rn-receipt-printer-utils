import { NativeModules, NativeEventEmitter } from 'react-native';
import { StarUtil } from './star';

const RNUSBPrinter = NativeModules.RNUSBPrinter;
const RNBLEPrinter = NativeModules.RNBLEPrinter;
const RNNetPrinter = NativeModules.RNNetPrinter;

export enum PrinterBrand {
  EPSON = 'EPSON',
  STAR = 'STAR',
  OTHER = 'OTHER',
}

export enum PrinterSeries {
  TM_M30 = 'TM_M30',
  TM_M30II = 'TM_M30II',
  TM_U220 = 'TM_U220',
  TM_T82 = 'TM_T82',
  TM_L90 = 'TM_L90',
}
export interface PrinterOptions {
  beep?: boolean;
  cut?: boolean;
  tailingLine?: boolean;
  encoding?: string;
}

export interface IBasePrinter {
  device_name: string;
  brand?: PrinterBrand;
  series?: PrinterSeries;
}

export interface IUSBPrinter extends IBasePrinter {
  vendor_id: string;
  product_id: string;
}

export interface IBLEPrinter extends IBasePrinter {
  bdAddress: string;
}

export interface INetPrinter extends IBasePrinter {
  host: string;
  port: number;
}

// Timeout for returning response to client
const SDK_RESPONSE_TIMEOUT = 30000;

// Promise with timeout
const promiseWithTimeout = <T>(
  promise: Promise<T>
): {
  promiseOrTimeout: Promise<T>;
  timeoutId: ReturnType<typeof setTimeout>;
} => {
  let timeoutId;
  const timeoutPromise: Promise<T> = new Promise((_, reject) => {
    timeoutId = setTimeout(() => {
      reject(new Error('Request timed out'));
    }, SDK_RESPONSE_TIMEOUT);
  });
  return {
    promiseOrTimeout: Promise.race([promise, timeoutPromise]),
    // @ts-ignore
    timeoutId,
  };
};

export const USBPrinter = {
  connectAndSend: (
    vendorId: string,
    productId: number,
    data: Buffer,
    brand: PrinterBrand
  ): Promise<IUSBPrinter> => {
    return new Promise((resolve, reject) =>
      RNUSBPrinter.connectAndSend(
        vendorId,
        productId,
        data.toString('base64'),
        brand,
        (printer: IUSBPrinter) => resolve(printer),
        (error: Error) => reject(error)
      )
    );
  },
};

export const BLEPrinter = {
  connectAndSend: (
    bdAddress: string,
    data: Buffer,
    brand: PrinterBrand,
    series?: PrinterSeries
  ): Promise<IBLEPrinter> => {
    const { promiseOrTimeout, timeoutId } = promiseWithTimeout<IBLEPrinter>(
      new Promise((resolve, reject) =>
        brand === PrinterBrand.STAR
          ? StarUtil.connectAndSend(
              bdAddress,
              data,
              false,
              (printer: IBLEPrinter) => resolve(printer),
              (error: Error) => reject(error)
            )
          : RNBLEPrinter.connectAndSend(
              bdAddress,
              data.toString('base64'),
              brand,
              series || 'NOT_EPSON',
              (printer: IBLEPrinter) => resolve(printer),
              (error: Error) => reject(error)
            )
      )
    );
    return new Promise((resolve, reject) =>
      promiseOrTimeout
        .then((printer: IBLEPrinter) => resolve(printer))
        .catch((error: Error) => reject(error))
        .finally(() => clearTimeout(timeoutId))
    );
  },
};

export const NetPrinter = {
  connectAndSend: (
    host: string,
    port: number,
    data: Buffer,
    brand: PrinterBrand,
    series?: PrinterSeries
  ): Promise<INetPrinter> => {
    const { promiseOrTimeout, timeoutId } = promiseWithTimeout<INetPrinter>(
      new Promise((resolve, reject) =>
        brand === PrinterBrand.STAR
          ? StarUtil.connectAndSend(
              host,
              data,
              true,
              (printer: INetPrinter) => resolve(printer),
              (error: Error) => reject(error)
            )
          : RNNetPrinter.connectAndSend(
              host,
              port,
              data.toString('base64'),
              brand,
              series || 'NOT_EPSON',
              (printer: INetPrinter) => resolve(printer),
              (error: Error) => reject(error)
            )
      )
    );
    return new Promise((resolve, reject) =>
      promiseOrTimeout
        .then((printer: INetPrinter) => resolve(printer))
        .catch((error: Error) => reject(error))
        .finally(() => clearTimeout(timeoutId))
    );
  },
};

export const NetPrinterEventEmitter = new NativeEventEmitter(RNNetPrinter);

export enum RN_THERMAL_RECEIPT_PRINTER_EVENTS {
  EVENT_NET_PRINTER_SCANNED_SUCCESS = 'scannerResolved',
  EVENT_NET_PRINTER_SCANNING = 'scannerRunning',
  EVENT_NET_PRINTER_SCANNED_ERROR = 'registerError',
}
