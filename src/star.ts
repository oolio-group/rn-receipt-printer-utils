import {
  InterfaceType,
  StarConnectionSettings,
  StarPrinter,
  StarXpandCommand,
} from 'react-native-star-io10';
import { PrintRow, RowAlignment } from './index';

export const StarUtil = {
  connectAndSend: async (
    identifier: string,
    data: PrintRow[],
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
      const commands = await StarUtil.constructBuffer(data);
      await printer.print(commands);
      lazyCallback = callback(successCallback, 'Successfully printed');
    } catch (err) {
      lazyCallback = callback(errorCallback, err);
    } finally {
      await printer.close();
      await printer.dispose();
      lazyCallback();
    }
  },
  constructBuffer: async (data: PrintRow[]) => {
    try {
      var printerCommandBuilder = new StarXpandCommand.PrinterBuilder()
        .styleInternationalCharacter(
          StarXpandCommand.Printer.InternationalCharacterType.Usa
        )
        .styleCharacterSpace(0);
      data.forEach((row) => {
        if (row.feedLine) {
          printerCommandBuilder.actionFeedLine(1);
        } else {
          const starAlignment = (() => {
            switch (row.alignment) {
              case RowAlignment.CENTER:
                return StarXpandCommand.Printer.Alignment.Center;
              case RowAlignment.RIGHT:
                return StarXpandCommand.Printer.Alignment.Right;
              default:
                return StarXpandCommand.Printer.Alignment.Left;
            }
          })();

          const starMagnification = new StarXpandCommand.MagnificationParameter(
            row.width,
            row.height
          );
          printerCommandBuilder.add(
            new StarXpandCommand.PrinterBuilder()
              .styleAlignment(starAlignment)
              .styleBold(row.isBold)
              .styleMagnification(starMagnification)
              .actionPrintText(row.text)
          );
        }
      });
      printerCommandBuilder.actionCut(StarXpandCommand.Printer.CutType.Partial);
      var builder = new StarXpandCommand.StarXpandCommandBuilder();
      builder.addDocument(
        new StarXpandCommand.DocumentBuilder().addPrinter(printerCommandBuilder)
      );
      var commands = await builder.getCommands();
      return commands;
    } catch (e) {
      throw e;
    }
  },
};
