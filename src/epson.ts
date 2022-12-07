import EscPosPrinter, {
  getPrinterSeriesByName,
} from 'react-native-esc-pos-printer';
import { EscPos } from '@tillpos/xml-escpos-helper';
import { PrinterSeries, PrinterUtil, PrintRow } from './index';
import { template } from './xmlTemplates';

var isExecuting = false;
export const EpsonUtil: PrinterUtil = {
  connectAndSend: async (
    host: string,
    data: PrintRow[],
    isLan: boolean,
    series: PrinterSeries,
    successCallback: (res: any) => void,
    errorCallback: (res: any) => void
  ) => {
    if (isExecuting) {
      errorCallback('last function is still executing');
      return;
    }
    try {
      isExecuting = true;
      const target = (isLan ? 'TCP:' : 'BT:') + host;

      console.log('in here');
      await EscPosPrinter.init({
        target: target,
        seriesName: getPrinterSeriesByName(series),
      });
      const bufferData: Buffer = EpsonUtil.constructBuffer(data, series);
      const printing = new EscPosPrinter.printing();
      const status = await printing
        .initialize()
        .data(bufferData)
        .send({ timeout: 200000 });
      successCallback('Successfully printed with status:' + status);
    } catch (e) {
      errorCallback(e);
    } finally {
      isExecuting = false;
    }
  },
  constructBuffer: (data: PrintRow[], series: PrinterSeries) => {
    const printMode = series.split('_')[1];
    console.log(printMode);
    const printRows = data.map((row) => ({
      isBold: row.isBold,
      alignment: row.alignment,
      size: row.width.toString() + ':' + row.height.toString(),
      text: row.text,
      feedLine: row.feedLine,
    }));
    console.log(printRows);
    return (EscPos.getBufferFromTemplate(template, {
      printMode: printMode,
      printRows: printRows,
    }) as unknown) as Buffer;
  },
};
