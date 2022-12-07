import { NativeModules, NativeEventEmitter } from 'react-native';
import { EpsonUtil } from './epson';
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

export enum RowAlignment {
  CENTER = 'center',
  RIGHT = 'right',
  LEFT = 'left',
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

export interface PrintRow {
  isBold: boolean;
  alignment: RowAlignment;
  height: number;
  width: number;
  text: string;
  feedLine: boolean;
}
export interface PrinterUtil {
  connectAndSend: (...args: any) => void;
  constructBuffer: (...args: any) => Buffer;
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
    data: PrintRow[],
    brand: PrinterBrand,
    series = PrinterSeries.TM_M30
  ): Promise<IBLEPrinter> => {
    const { promiseOrTimeout, timeoutId } = promiseWithTimeout<IBLEPrinter>(
      new Promise((resolve, reject) =>
        brand === PrinterBrand.EPSON
          ? EpsonUtil.connectAndSend(
              bdAddress,
              data,
              false,
              series,
              (printer: IBLEPrinter) => resolve(printer),
              (error: Error) => reject(error)
            )
          : brand === PrinterBrand.STAR
          ? StarUtil.connectAndSend(
              bdAddress,
              data,
              false,
              (printer: IBLEPrinter) => resolve(printer),
              (error: Error) => reject(error)
            )
          : RNBLEPrinter.connectAndSend(
              bdAddress,
              EpsonUtil.constructBuffer(data, PrinterSeries.TM_M30II).toString(
                'base64'
              ),
              brand,
              series,
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
    data: PrintRow[],
    brand: PrinterBrand,
    series = PrinterSeries.TM_M30
  ): Promise<INetPrinter> => {
    const { promiseOrTimeout, timeoutId } = promiseWithTimeout<INetPrinter>(
      new Promise((resolve, reject) =>
        brand === PrinterBrand.EPSON
          ? EpsonUtil.connectAndSend(
              host,
              data,
              true,
              series,
              (printer: INetPrinter) => resolve(printer),
              (error: Error) => reject(error)
            )
          : brand === PrinterBrand.STAR
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
              EpsonUtil.constructBuffer(data, PrinterSeries.TM_M30II).toString(
                'base64'
              ),
              brand,
              series,
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
