import { StyleSheet, View, Text, TouchableOpacity } from 'react-native';
import {
  // NetPrinter,
  PrinterBrand,
  BLEPrinter,
} from '@tillpos/rn-receipt-printer-utils';
import { Buffer } from 'buffer';
import React, { Fragment, useCallback } from 'react';

interface Printer {
  device_name: string;
  bdAddress: string;
}
const PRINTERS: Array<Printer> = [
  { device_name: 'P1', bdAddress: 'A0:E6:F8:26:62:38' },
  // { device_name: 'P2', host: '10.15.0.160', port: 9100 }, works ok
];

export default function App() {
  const testPrint = useCallback(async () => {
    const buffer = Buffer.from('Minions MinionsMinions \n');

    try {
      await Promise.all(
        PRINTERS.map(async (printer) => {
          return await BLEPrinter.connectAndSend(
            printer.bdAddress,
            buffer,
            PrinterBrand.SNBC
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
