import {
  StyleSheet,
  View,
  Text,
  TextInput,
  TouchableOpacity,
} from "react-native";
import { NetPrinter } from "@tillpos/rn-receipt-printer-utils";
import { Buffer } from "buffer";
import React, {
  Fragment,
  useCallback,
  useEffect,
  useMemo,
  useState,
} from "react";

export const usePrinterConnection = () => {
  const sendMessage = useCallback(async (buffer) => {
    NetPrinter.print(buffer);
  }, []);

  return useMemo(
    () => ({
      sendMessage,
    }),
    [sendMessage]
  );
};

interface Printer {
  device_name: string;
  host: string;
  port: number;
}
const PRINTERS: Array<Printer> = [
  { device_name: "P1", host: "192.168.0.8", port: 9100 },
];

export default function App() {
  const [printers, setPrinters] = useState<Array<Printer>>([]);
  const [currentPrinter, setCurrentPrinter] = useState();
  const { sendMessage } = usePrinterConnection();

  const _connectPrinter = (host: string, port: number) => {
    //connect printer
    NetPrinter.connectPrinter(host, port).then(
      (printer: any) => setCurrentPrinter(printer),
      (error: any) => console.warn(error)
    );
  };

  const initDevices = async () => {
    try {
      await NetPrinter.init();
      setPrinters(PRINTERS);
    } catch (err) {
      console.warn(err);
    }
  };

  useEffect(() => {
    initDevices();
  }, []);

  const testPrint = useCallback(async () => {
    if (currentPrinter) {
      const buf = Buffer.from('Minions');

      await sendMessage(buf);
    }
  }, [sendMessage, currentPrinter]);

  return (
    <View style={styles.container}>
      {printers.map((printer, i) => (
        <TouchableOpacity
          key={i}
          style={{
            padding: 10,
            backgroundColor: "#fff",
            margin: 10,
            borderColor: "#000",
            borderWidth: 1,
          }}
          onPress={() => _connectPrinter(printer.host, printer.port)}
        >
          <Text>
            {" "}
            {`device_name: ${printer.device_name}, host: ${printer.host}, port: ${printer.port}`}
          </Text>
        </TouchableOpacity>
      ))}

      {!currentPrinter && <Text>Select a printer</Text>}
      {currentPrinter && (
        <Fragment>
          <TouchableOpacity
            onPress={testPrint}
            style={{ padding: 10, backgroundColor: "#ccc", margin: 10 }}
          >
            <Text> Print receipt </Text>
          </TouchableOpacity>
        </Fragment>
      )}
    </View>
  );
}

const styles = StyleSheet.create({
  scrollView: {
    // backgroundColor: Colors.lighter,
  },
  engine: {
    position: "absolute",
    right: 0,
  },
  body: {
    // backgroundColor: Colors.white,
  },
  container: {
    marginTop: 32,
    paddingHorizontal: 24,
  },
  highlight: {
    fontWeight: "700",
  },
});
