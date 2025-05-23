package com.pinmi.react.printer;

import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.pinmi.react.printer.adapter.BLEPrinterDeviceId;
import com.pinmi.react.printer.adapter.NetPrinterAdapter;
import com.pinmi.react.printer.adapter.NetPrinterDeviceId;
import com.pinmi.react.printer.adapter.PrinterAdapter;
import android.util.Log;
import java.util.*;

/**
 * Created by xiesubin on 2017/9/22.
 */

public class RNNetPrinterModule extends ReactContextBaseJavaModule implements RNPrinterModule {

    private PrinterAdapter adapter;
    private ReactApplicationContext reactContext;
    private String LOG_TAG = "RNNetPrinterModule";

    public RNNetPrinterModule(ReactApplicationContext reactContext){
        super(reactContext);
        this.reactContext = reactContext;
    }

    @ReactMethod
    @Override
    public void init(Callback successCallback, Callback errorCallback) {
        this.adapter = NetPrinterAdapter.getInstance();
        this.adapter.init(reactContext,  successCallback, errorCallback);
    }

    @ReactMethod
    @Override
    public void closeConn() {
        this.adapter = NetPrinterAdapter.getInstance();
        this.adapter.closeConnectionIfExists();
    }

    @ReactMethod
    @Override
    public void getDeviceList(Callback successCallback, Callback errorCallback) {
        try {
            this.adapter.getDeviceList(errorCallback);
            successCallback.invoke();
        } catch (Exception ex) {
            errorCallback.invoke(ex.getMessage());
        }
        // this.adapter.getDeviceList(errorCallback);
    }

    @ReactMethod
    public void connectPrinter(String host, Integer port, Callback successCallback, Callback errorCallback) {
        adapter.selectDevice(NetPrinterDeviceId.valueOf(host, port), successCallback, errorCallback);
    }

    @ReactMethod
    public void connectAndSend(String host, Integer port, String data, String brand,String series, Callback successCallback, Callback errorCallback) {
      new Thread(() -> {
        adapter = NetPrinterAdapter.getInstance();
        adapter.init(reactContext,  null, null);

        adapter.connectAndSend(host, port, data, successCallback, errorCallback);
        adapter.closeConnectionIfExists();
      }).start();
    }

    @ReactMethod
    @Override
    public void printRawData(String base64Data, Callback errorCallback) {
        adapter.printRawData(base64Data, errorCallback);
    }

    @ReactMethod
    @Override
    public void printByteData(byte[] base64Data, Callback errorCallback) {
        adapter.printByteData(base64Data, errorCallback);
    }

    @Override
    public String getName() {
        return "RNNetPrinter";
    }
}
