[![Platform](https://img.shields.io/cocoapods/p/LFAlertController.svg?style=flat)](http://cocoapods.org/pods/LFAlertController) [![Swift Version][swift-image]][swift-url]

# 🖨️ IOS Printer for Toshiba BV420 

Wrapper over Toshiba files to configurate communication with their printers

## ☝️ What is it?
We have create this pod in order to simplify configuration of toshiba sdk for ios. Toshiba SDK has 2 configuration (Device and Simulator) and both of them are made up of:
- 64 header files
- 1 static library .a
- 2 system libraries

It will be used for Toshiba BV420 

## ✌️ Installation

### CocoaPods

[CocoaPods](https://cocoapods.org) is a dependency manager for Cocoa projects. For usage and installation instructions, visit their website. To integrate this pod into your Xcode project using CocoaPods, specify it in your `Podfile`:

**IMPORTANT** there are 2 pods depending on how are you going to use it Simulator and Device. This is because Toshiba SDK is built this way.

Simulator:
```ruby
pod 'ios-printer-toshiba/Simulator', :path => '../ios-printer-toshiba'
```
Device
```ruby
pod 'ios-printer-toshiba/Device', :path => '../ios-printer-toshiba'
```

### Additional needs

Once you have your Podfile set up and installed you must add `Supported external accessory protocols`to your `Info.plist` with value `jp.co.toshibatec`

## 💻 Usage
This pod is quite straightforward you can forget about Toshiba SDK and just use `PrinterManager`as your entry point.

**Connect to printer**
```swift
let tcpIp = "TCP://1.1.1.1:9100"
let connection = PrinterManager.shared.connect(this: tcpIp)
if connection {
    // Connected
}else{
    // Error trying to connect
}
```

**Disconnect from printer**
```swift
let disconnected = PrinterManager.shared.disconnect()
if disconnected {
    // Disconnected
}else{
    // Error
}
```

**Print (you must be connected)**
```swift
text =  "ZPL Lines"
let result = PrinterManager.shared.write(this: text)
if result{
    // Sent to printer
}else{
    // Error
}
```

**Connect print and disconnect**
```swift
let tcpIp = "TCP://1.1.1.1:9100"
let result = PrinterManager.shared.connectPrintAndDisconnect(to: tcpIp, this: text)
switch result {
    case .sendToprint:
        // Envio correctamente enviado a la impresora
    case .errorPrinting:
        // Error imprimiendo, comprueba que tienes correctamente configurada la dirección de la impresora y esta esta activa"
    default:
        break
}
```

## ⚙️ Features

- [x]  Connect / Disconnect to printer
- [x]  Print ZPL labels
- [x]  Example
- [ ]  Check status

## 📝 Requirements

- iOS 13.0+
- Xcode 13.4

## 🔒 Copyright

Mercadona

[swift-image]:https://img.shields.io/badge/swift-5.3-orange.svg
[swift-url]: https://swift.org/
