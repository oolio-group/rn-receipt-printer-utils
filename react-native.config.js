module.exports = {
  dependency: {
    platforms: {
      android: {
        sourceDir: '../android',
        packageImportPath: 'import com.pinmi.react.printer.RNPrinterPackage;',
      },
      ios: {
        podspecPath: '../tillpos-rn-receipt-printer-utils.podspec',
      },
    },
  },
};