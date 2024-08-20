//
//  ViewController.swift
//  BTMeshDeviceDiscoveryDemo
//
//  Created by Mantosh Kumar on 20/08/24.
//

import UIKit
import CoreBluetooth

class ViewController: UIViewController {
    
    @IBOutlet weak var meshDeviceListTableView: UITableView!
    
    var cbCenteralManager: CBCentralManager!
    var meshPeripheralList: [CBPeripheral] = []
    
    override func viewDidLoad() {
        super.viewDidLoad()
        navigationItem.title = "Mesh Devices"
        setStatusBarBGColor()
    }
    
    override func viewWillAppear(_ animated: Bool) {
        super.viewWillAppear(animated)
        cbCenteralManager = CBCentralManager(delegate: self, queue: nil)
    }
    
    private func setStatusBarBGColor() {
        let window = UIApplication.shared.windows.filter{$0.isKeyWindow}.first
        let statusBar = UIView(frame: window?.windowScene?.statusBarManager?.statusBarFrame ?? CGRect.zero)
        statusBar.backgroundColor = .systemGray5
        window?.addSubview(statusBar)
        navigationController?.navigationBar.backgroundColor = .systemGray5
    }
    
    func startDescovering(services: [String]) {
        cbCenteralManager.scanForPeripherals(withServices: services.map{ CBUUID(string: $0)}, options: [CBCentralManagerRestoredStateScanOptionsKey : true])
    }
    
    @IBAction func scanAction(_ sender: Any) {
        // Mesh Provisioning Service = 0x1827
        // https://www.bluetooth.com/specifications/assigned-numbers/
        startDescovering(services:["1827"])
    }
}

extension ViewController: CBCentralManagerDelegate {
    func centralManagerDidUpdateState(_ central: CBCentralManager) {
        // Check Bluetooth Status
        if central.state == CBManagerState.poweredOn {
            debugPrint("Bluetooth is ON")
        } else {
            debugPrint("Bluetooth is OFF")
        }
    }
    
    func centralManager(_ central: CBCentralManager, didDiscover peripheral: CBPeripheral, advertisementData: [String : Any], rssi RSSI: NSNumber) {
        print("Peripheral: \(peripheral)")
        meshPeripheralList.append(peripheral)
        meshDeviceListTableView.reloadData()
    }
}

extension ViewController: UITableViewDataSource {
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
        return meshPeripheralList.count
    }
    
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
        let cell = meshDeviceListTableView.dequeueReusableCell(withIdentifier: "Peripheral", for: indexPath)
        cell.textLabel?.text = meshPeripheralList[indexPath.row].name
        return cell
    }
}

