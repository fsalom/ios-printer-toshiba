import UIKit
import ios_printer_toshiba

class ViewController: UIViewController {

    @IBOutlet weak var connectButton: UIButton!
    @IBOutlet weak var ipTextfield: UITextField!
    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
        ipTextfield.text = "TCP://10.99.248.56:9100"
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }

    func showAlert(title: String, message: String){
        let alert = UIAlertController(title: title, message: message, preferredStyle: .alert)
        alert.addAction(UIAlertAction(title: "OK", style: .default, handler: { action in
                alert.dismiss(animated: true)
        }))
        self.present(alert, animated: true, completion: nil)
    }

    func readFile(this file: String) -> String? {
        let tokens = file.components(separatedBy: ".")
        if tokens.count <= 1 {
            showAlert(title: "Error", message: "comprueba que has indicado nombre y extensión del archivo. Ejemplo: file1.dat")
            return nil
        }
        guard let fn = Bundle.main.path(forResource: tokens[0], ofType: tokens[1]) else{
            return nil
        }
        do{
            let ct = try(String(contentsOfFile: fn, encoding: String.Encoding.utf8))
            return ct
        }catch _ as NSError {
            return nil
        }
    }

    @IBAction func onPressOpenConnection(_ sender: Any) {
        guard let tcpIp = ipTextfield.text else {
            showAlert(title: "Falta información", message: "Debes escribir la dirección y puerto de la impresora. Ejemplo: TCP://192.168.1.1:9100")
            return
        }
        let connection = PrinterHandler.shared.connect(this: tcpIp)
        if connection {
            connectButton.backgroundColor = UIColor.green
            showAlert(title: "Conexión", message: "Conectado")
        }else{
            connectButton.backgroundColor = UIColor.red
            showAlert(title: "Conexión", message: "Fallo de conexión, valida que sea correcta la dirección de la impresora y el puerto")
        }
    }
    @IBAction func onPressPrintFile(_ sender: Any) {
        guard let text =  readFile(this: "file1.dat") else {
            showAlert(title: "Error", message: "Fallo al leer  le fichero")
            return
        }
        let result = PrinterHandler.shared.write(this: text)
        if result{
            showAlert(title: "Éxito", message: "Envio correctamente enviado a la impresora")
        }else{
            showAlert(title: "Error", message: "No se ha podido enviar el contenido a la impresora compruebe que esta conectado")
        }
    }
    @IBAction func onPressCloseConnection(_ sender: Any) {
        let disconnected = PrinterHandler.shared.disconnect()
        if disconnected {
            showAlert(title: "Éxito", message: "desconectado exitosamente")
        }else{
            showAlert(title: "Error", message: "No se ha podido conectar compruebe que esta conectado")
        }
    }
    @IBAction func onPressConnectPrintDisconnect(_ sender: Any) {
        guard let tcpIp = ipTextfield.text else {
            showAlert(title: "Falta información", message: "Debes escribir la dirección y puerto de la impresora. Ejemplo: TCP://192.168.1.1:9100")
            return
        }
        guard let text =  readFile(this: "file1.dat") else {
            showAlert(title: "Error", message: "Fallo al leer  le fichero")
            return
        }
        let result = PrinterHandler.shared.connectPrintAndDisconnect(to: tcpIp, this: text)
        switch result {
        case .sendToprint:
            showAlert(title: "Éxito", message: "Envio correctamente enviado a la impresora")
        case .errorPrinting:
            showAlert(title: "Error", message: "Error imprimiendo, comprueba que tienes correctamente configurada la dirección de la impresora y esta esta activa")
        default:
            break
        }

    }
}

