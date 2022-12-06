import { StyleSheet, View, Text, TouchableOpacity } from 'react-native';
import {
  NetPrinter,
  PrinterBrand,
  PrinterSeries,
  PrintRow,
  RowAlignment,
} from '@tillpos/rn-receipt-printer-utils';
import React, { Fragment, useCallback } from 'react';

interface Printer {
  device_name: string;
  host: string;
  port: number;
}
const PRINTERS: Array<Printer> = [
  { device_name: 'P1', host: '10.15.0.101', port: 9100 },
];

export default function App() {
  const testPrint = useCallback(async () => {
    const printRows: PrintRow[] = [
      {
        isBold: true,
        alignment: RowAlignment.CENTER,
        height: 4,
        width: 1,
        text: 'New Order \n',
        feedLine: false,
      },
      {
        isBold: false,
        alignment: RowAlignment.RIGHT,
        height: 0,
        width: 2,
        text: 'test \n',
        feedLine: true,
      },
      {
        isBold: false,
        alignment: RowAlignment.RIGHT,
        height: 0,
        width: 2,
        text: 'test \n',
        feedLine: false,
      },
      {
        isBold: false,
        alignment: RowAlignment.RIGHT,
        height: 0,
        width: 2,
        text: 'test \n',
        feedLine: true,
      },
      {
        isBold: false,
        alignment: RowAlignment.RIGHT,
        height: 0,
        width: 2,
        text: 'test \n',
        feedLine: true,
      },
      {
        isBold: false,
        alignment: RowAlignment.RIGHT,
        height: 0,
        width: 2,
        text: 'Hello World! \n',
        feedLine: false,
      },
      {
        isBold: false,
        alignment: RowAlignment.RIGHT,
        height: 0,
        width: 2,
        text: 'test \n',
        feedLine: true,
      },
    ];
    for (let i = 0; i < 1; i++) {
      let spont: number = Math.floor(Math.random() * PRINTERS.length);
      const printer = PRINTERS[spont];
      try {
        console.log('sending data to;' + printer.host);
        await NetPrinter.connectAndSend(
          printer.host,
          printer.port,
          printRows,
          PrinterBrand.EPSON,
          PrinterSeries.TM_M30
        );
      } catch (err) {
        console.log('error', err);
      }
    }
  }, []);

  return (
    <View style={styles.container}>
      <Fragment>
        <TouchableOpacity onPress={testPrint} style={styles.btn}>
          <Text> Print receipt </Text>
        </TouchableOpacity>
      </Fragment>
    </View>
  );
}

const styles = StyleSheet.create({
  scrollView: {},
  engine: {
    position: 'absolute',
    right: 0,
  },
  body: {},
  container: {
    marginTop: 32,
    paddingHorizontal: 24,
  },
  highlight: {
    fontWeight: '700',
  },
  btn: {
    padding: 10,
    backgroundColor: '#ccc',
    margin: 10,
  },
});
