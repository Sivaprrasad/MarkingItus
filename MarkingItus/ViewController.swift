//
//  ViewController.swift
//  MarkingItus
//
//  Created by Uppalapati SivaPrrasad on 07/11/19.
//  Copyright © 2019 Uppalapati SivaPrrasad. All rights reserved.
//

import UIKit
import Particle_SDK


class ViewController: UIViewController {

    // MARK: User variables
    let USERNAME = "usivaprasad95@gmail.com"
    let PASSWORD = "Sivaprasad@95"
    
    // MARK: Device
    let DEVICE_ID = "300023001047363333343437"
    var myPhoton : ParticleDevice?
    
    var seconds:Int = 0
    var timer:Timer?

    @IBOutlet weak var displaytimerLabel: UILabel!
    
    @IBOutlet weak var sliderLabel: UISlider!
    @IBOutlet weak var slowDownLabel: UILabel!
    
    @IBAction func onStartMonitoringPressed(_ sender: Any) {
        if(timer == nil){
            timer = Timer.scheduledTimer(timeInterval: 1, target: self, selector: #selector(onUpdateTimer), userInfo: nil, repeats: true)
         slowDownLabel.text = "\(timer!.timeInterval)"
        }
    
    }
    
    @objc func onUpdateTimer() -> Void
        {
            if(seconds >= 0 && seconds < 20)
            {
                seconds += 1
    
                displaytimerLabel.text = "\(seconds)"
            }
            else if(seconds == 20)
            {
                if(timer != nil)
                {
                    timer!.invalidate()
                    timer = nil
                           
                }
                print("Time is up")
            }
        }
    

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view.
        
        // 1. Initialize the SDK
               ParticleCloud.init()
        
               // 2. Login to your account
               ParticleCloud.sharedInstance().login(withUser: self.USERNAME, password: self.PASSWORD) { (error:Error?) -> Void in
                   if (error != nil) {
                       // Something went wrong!
                       print("Wrong credentials or as! ParticleCompletionBlock no internet connectivity, please try again")
                       // Print out more detailed information
                       print(error?.localizedDescription)
                   }
                   else {
                       print("Login success!")

                       // try to get the device
                       self.getDeviceFromCloud()

                   }
               } // end login
    }
    
    func getDeviceFromCloud() {
        ParticleCloud.sharedInstance().getDevice(self.DEVICE_ID) { (device:ParticleDevice?, error:Error?) in
            
            if (error != nil) {
                print("Could not get device")
                print(error?.localizedDescription)
                return
            }
            else {
                print("Got photon from cloud: \(device?.id)")
                self.myPhoton = device
                
                // subscribe to events
//                self.subscribeToParticleEvents()
            }
            
        } // end getDevice()
    }
    
    @IBAction func onSliderChanged(_ sender: UISlider) {
        let currentValue = Int(sender.value)
        
        if(currentValue == 0){
           if(timer == nil){
               timer = Timer.scheduledTimer(timeInterval: 1, target: self, selector: #selector(onUpdateTimer), userInfo: nil, repeats: true)
            slowDownLabel.text = "\(timer!.timeInterval)"
           }
        }
            if(currentValue > 0 || currentValue <= 20){
                if(timer == nil){
                    timer = Timer.scheduledTimer(timeInterval: 2, target: self, selector: #selector(onUpdateTimer), userInfo: nil, repeats: true)
                 slowDownLabel.text = "\(timer!.timeInterval)"
                }
             }

             else if(currentValue > 20 || currentValue <= 40){
                if(timer == nil){
                    timer = Timer.scheduledTimer(timeInterval: 3, target: self, selector: #selector(onUpdateTimer), userInfo: nil, repeats: true)
                 slowDownLabel.text = "\(timer!.timeInterval)"

                }
            }
             else if(currentValue > 40 || currentValue <= 60){
                 if(timer == nil){
                     timer = Timer.scheduledTimer(timeInterval: 4, target: self, selector: #selector(onUpdateTimer), userInfo: nil, repeats: true)
                 slowDownLabel.text = "\(timer!.timeInterval)"
                 }
             }
             else if(currentValue > 60 || currentValue <= 80){
                     if(timer == nil){
                         timer = Timer.scheduledTimer(timeInterval: 5, target: self, selector: #selector(onUpdateTimer), userInfo: nil, repeats: true)
                 slowDownLabel.text = "\(timer!.timeInterval)"

                 }
             }
             else if(currentValue > 80 || currentValue <= 500){
                         if(timer == nil){
                             timer = Timer.scheduledTimer(timeInterval: 6, target: self, selector: #selector(onUpdateTimer), userInfo: nil, repeats: true)
                 slowDownLabel.text = "\(timer!.timeInterval)"

                 }
             }


        
                           
       }

    

}
