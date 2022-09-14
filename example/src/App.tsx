import { StyleSheet, View, Text, TouchableOpacity } from 'react-native';
import {
  NetPrinter,
  PrinterBrand,
  PrinterSeries,
} from '@tillpos/rn-receipt-printer-utils';
import { Buffer } from 'buffer';
import React, { Fragment, useCallback } from 'react';

interface Printer {
  device_name: string;
  host: string;
  port: number;
}
const PRINTERS: Array<Printer> = [
  { device_name: 'P1', host: '10.15.0.78', port: 9100 },
  { device_name: 'P2', host: '10.15.0.174', port: 9100 },
];

let globalCount = 0;

export default function App() {
  const testPrint = useCallback(async () => {
    globalCount++;
    const buffer = Buffer.from(
      globalCount + ' ::: minions minions minions \n \n '
    );
    for (let i = 0; i < 100; i++) {
      let spont: number = Math.floor(Math.random() * PRINTERS.length);
      const printer = PRINTERS[spont];
      try {
        console.log('sending data to;' + printer.host);
        await NetPrinter.connectAndSend(
          printer.host,
          printer.port,
          buffer,
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
