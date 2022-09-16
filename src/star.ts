import {
  InterfaceType,
  StarConnectionSettings,
  StarPrinter,
} from 'react-native-star-io10';

export const StarUtil = {
  connectAndSend: async (
    identifier: string,
    text: Buffer,
    isLan: boolean,
    successCallback: (res: any) => void,
    errorCallback: (res: any) => void
  ) => {
    let settings = new StarConnectionSettings();
    settings.interfaceType = isLan
      ? InterfaceType.Lan
      : InterfaceType.Bluetooth;
    settings.identifier = identifier;

    console.log(
      'sending to ' + identifier + 'type' + settings.interfaceType.toString()
    );

    let printer = new StarPrinter(settings);
    let callback = (callbackFunc: (val: any) => void, val: any) => () =>
      callbackFunc(val);
    let lazyCallback = () => errorCallback('Failed to Print');

    try {
      await printer.open();
      const status = await printer.getStatus();
      console.log('status ' + JSON.stringify(status));
      await printer.printRawData([...text]);
      lazyCallback = callback(successCallback, 'Successfully printed');
    } catch (err) {
      lazyCallback = callback(errorCallback, err);
    } finally {
      await printer.close();
      await printer.dispose();
      lazyCallback();
    }
  },
};
