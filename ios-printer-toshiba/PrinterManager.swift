import Foundation

public enum PrinterStatus {
    case connected
    case disconnected
    case sendToprint
    case errorPrinting

}

public final class PrinterManager {
    public static var shared  = PrinterManager()

    var controller: BCPControl = BCPControl()

    public func connect(this tcp: String) -> Bool {
        controller.setPortSettingWith(tcp)
        let ref = LongRef(long: 0)
        return (controller.openPort(1, result: ref) && ref?.longValue == 0) ? true : false
    }

    public func disconnect() -> Bool {
        let ref = LongRef(long: 0)
        if (controller.closePort(ref)) {
            return true
        }else{
            return false
        }
    }

    public func checkConnected() -> Bool {
        var result: Bool = false
        result = controller.pCom?.sck?.connected ?? false
        if (result == nil) {
            return false
        }
        if (!result) {
            return false
        }
        return true
    }    

    public func readStatus(_ sender: AnyObject) {
        if !self.checkConnected() {
            return
        }
        let str = StringRef.init("")
        let ref2 = LongRef(long: 0)
        DispatchQueue.global().async(execute: {
            self.controller.getStatus(str, withResult: ref2)
            DispatchQueue.main.async(execute: {
                let sref = StringRef.init("")
                self.controller.getMessage(str!.stringValue, withMessage: sref)
                print("---->\(String(describing: str?.stringValue))")
            })
        })
    }

    public func write(this text: String) -> Bool {
        let ref = LongRef(long: 0)
        let result = controller.writePort(text, withResult: ref)
        return result
    }


    public func connectPrintAndDisconnect(to ip: String, this text: String) -> PrinterStatus {
        if connect(this: ip) {
            let ref = LongRef(long: 0)
            let printStatus = controller.writePort(text, withResult: ref)
            DispatchQueue.main.asyncAfter(deadline: .now() + 1) {
                _ = self.disconnect()
            }
            return printStatus ? .sendToprint : .errorPrinting
        }else{
            return .errorPrinting
        }
    }
}
