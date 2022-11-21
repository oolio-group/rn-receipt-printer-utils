import EscPosPrinter, {
  getPrinterSeriesByName,
} from 'react-native-esc-pos-printer';
import { PrinterSeries } from '.';

var isExecuting = false;
export const EpsonUtil = {
  connectAndSend: async (
    host: string,
    data: Buffer,
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

      const printing = new EscPosPrinter.printing();
      const status = await printing.initialize().data(data).send();
      successCallback('Successfully printed with status:' + status);
    } catch (e) {
      errorCallback(e);
    } finally {
      isExecuting = false;
    }
  },
};
