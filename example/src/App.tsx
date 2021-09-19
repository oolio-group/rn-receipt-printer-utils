import { StyleSheet, View, Text, TouchableOpacity } from 'react-native';
import { NetPrinter, PrinterBrand } from '@tillpos/rn-receipt-printer-utils';
import { Buffer } from 'buffer';
import React, { Fragment, useCallback } from 'react';

interface Printer {
  device_name: string;
  host: string;
  port: number;
}
const PRINTERS: Array<Printer> = [
  { device_name: 'P1', host: '192.168.0.8', port: 9100 },
  { device_name: 'P2', host: '192.168.0.9', port: 9100 },
];

export default function App() {
  const testPrint = useCallback(async () => {
    const buffer = Buffer.from('Minions MinionsMinions \n');

    try {
      await Promise.all(
        PRINTERS.map(async (printer) => {
          return await NetPrinter.connectAndSend(
            printer.host,
            printer.port,
            buffer,
            PrinterBrand.EPSON
          );
        })
      );
    } catch (err) {
      console.log('error', err);
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
