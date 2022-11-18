import EscPosPrinter, {
  getPrinterSeriesByName,
} from 'react-native-esc-pos-printer';

var isExecuting = false;
export const EpsonUtil = {
  connectAndSend: async (
    host: string,
    data: Buffer,
    isLan: boolean,
    successCallback: (res: any) => void,
    errorCallback: (res: any) => void
  ) => {
    try {
      if (isExecuting) {
        throw new Error('last job still executing');
      }
      isExecuting = true;
      const target = (isLan ? 'TCP:' : 'BT:') + host;
      const printers = await EscPosPrinter.discover();
      console.log(printers[0].target);
      const printer = printers.find(
        (printerObj) =>
          printerObj.target === target || (isLan && printerObj.ip === host)
      );
      if (printer) {
        console.log('in here');
        await EscPosPrinter.init({
          target: printer.target,
          seriesName: getPrinterSeriesByName(printer.name),
        });

        const printing = new EscPosPrinter.printing();
        const status = await printing.initialize().data(data).send();
        successCallback('Successfully printed with status:' + status);
      } else {
        console.log('in here error');
        throw new Error('Cannot find printer ' + target);
      }
    } catch (e) {
      errorCallback(e);
    } finally {
      isExecuting = false;
    }
  },
};
