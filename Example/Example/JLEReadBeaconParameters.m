//
//  ReadBeaconParameters.m
//  Example
//
//  Created by jaalee on 14-4-23.
//  Copyright (c) 2014年 jaalee. All rights reserved.
//

#import "JLEReadBeaconParameters.h"
#import "JLEWaitProgressShow.h"

@interface JLEReadBeaconParameters ()<JLEBeaconDeviceDelegate>

@end

@implementation JLEReadBeaconParameters

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
        // Custom initialization
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    if (self.mSelectBeaconDevice) {
        self.mSelectBeaconDevice.delegate = self;
        [self.mSelectBeaconDevice connectToBeaconWithPassword:@"666666"];
        [JLEWaitProgressShow showWithStatus:@"Trying to connect the Beacon..."];
    }
}

- (void)viewDidDisappear:(BOOL)animated
{
    if (self.mSelectBeaconDevice.isConnected)
    {
        [self.mSelectBeaconDevice disconnectBeacon];
    }
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


#pragma mark - JLEBeaconDeviceDelegate Callbacks

- (void)beaconConnectionDidSucceeded:(JLEBeaconDevice *)beacon
{
    [JLEWaitProgressShow showSuccessWithStatus:@"Connected successfully"];
    
    [self ConfigBeacon];
}

- (void)beaconConnectionDidFail:(JLEBeaconDevice *)beacon withError:(NSError *)error
{
    [JLEWaitProgressShow showErrorWithStatus:@"Connect the beacon Failed"];
    [self.navigationController popToRootViewControllerAnimated:true];
}

- (void)beaconDidDisconnect:(JLEBeaconDevice *)beacon withError:(NSError *)error
{
    [JLEWaitProgressShow showErrorWithStatus:@"Disconnect from the Beacon"];
    [self.navigationController popToRootViewControllerAnimated:true];
}



#pragma mark - Read Beacon Parameter Method
- (void) ReadProximityUUID
{
    if (self.mSelectBeaconDevice.isConnected) {
        [self.mSelectBeaconDevice readBeaconProximityUUIDWithCompletion:^(NSString* value, NSError* error){
            self.mUUID.text = value;
        }];
    }
}

- (void) ReadMajorValue
{
    if (self.mSelectBeaconDevice.isConnected) {
        [self.mSelectBeaconDevice readBeaconMajorWithCompletion:^(unsigned short value, NSError* error){
            self.mMajorValue.text = [NSString stringWithFormat:@"%d", value];
        }];
    }
}

- (void) ReadMinorValue
{
    if (self.mSelectBeaconDevice.isConnected) {
        [self.mSelectBeaconDevice readBeaconMinorWithCompletion:^(unsigned short value, NSError* error){
            self.mMinorValue.text = [NSString stringWithFormat:@"%d", value];
        }];
    }
}

- (void) ReadMeasuredPowerValue
{
    if (self.mSelectBeaconDevice.isConnected) {
        [self.mSelectBeaconDevice readBeaconMeasuredPowerWithCompletion:^(unsigned short value, NSError* error){
            self.mMeasuredPowerValue.text = [NSString stringWithFormat:@"%d", value];
        }];
    }
}

- (void) ReadTxPowerValue
{
    if (self.mSelectBeaconDevice.isConnected) {
        [self.mSelectBeaconDevice readBeaconTxPowerWithCompletion:^(JLEBeaconPower value, NSError* error){
            self.TxPowerLevel.text = [NSString stringWithFormat:@"%d", value];
        }];
    }
}


- (void) ReadBattery
{
    if (self.mSelectBeaconDevice.isConnected) {
        [self.mSelectBeaconDevice readBeaconBatteryWithCompletion:^(unsigned short value, NSError* error){
            self.mBattLevel.text = [NSString stringWithFormat:@"%d", value];
        }];
    }
}

- (void) ReadDeviceName
{
    if (self.mSelectBeaconDevice.isConnected) {
        [self.mSelectBeaconDevice readBeaconDeviceNameWithCompletion:^(NSString *value, NSError* error){
            self.mDeviceName.text = value;
        }];
    }
}

- (void) ReadBroadcastRate
{
    if (self.mSelectBeaconDevice.isConnected) {
        [self.mSelectBeaconDevice readBeaconAdvIntervalWithCompletion:^(unsigned short value, NSError* error){
            self.mBroadcastRete.text = [NSString stringWithFormat:@"%d ms", value];
            
        }];
    }
}

#pragma mark - Write Beacon Parameter Method
- (void) WriteProximityUUID
{
    if (self.mSelectBeaconDevice.isConnected) {
        [self.mSelectBeaconDevice writeBeaconProximityUUID:@"EBEFD083-70A2-47C8-9837-E7B5634DF524" withCompletion:^(BOOL value, NSError* error){
            
            if (value) {
                NSLog(@"Beacon Proximity UUID Config Success..");
            }
            
        }];
    }
}

- (void) WriteMajorValue
{
    if (self.mSelectBeaconDevice.isConnected) {
        [self.mSelectBeaconDevice writeBeaconMajor:10000 withCompletion:^(BOOL value, NSError* error){
            
            if (value) {
                NSLog(@"Beacon Major Value Config Success..");
            }
            
        }];
    }
}

- (void) WriteMinorValue
{
    if (self.mSelectBeaconDevice.isConnected) {
        [self.mSelectBeaconDevice writeBeaconMinor:10001 withCompletion:^(BOOL value, NSError* error){
            
            if (value) {
                NSLog(@"Beacon Minor Value Config Success..");
            }
            
        }];
    }
}

- (void) WriteMeasuredPowerValue
{
    if (self.mSelectBeaconDevice.isConnected) {
        [self.mSelectBeaconDevice writeBeaconMesauredPower:196 withCompletion:^(BOOL value, NSError* error){
            
            if (value) {
                NSLog(@"Beacon Measured Power Value Config Success..");
            }
            
        }];
    }
}

- (void) WriteTxPowerValue
{
    if (self.mSelectBeaconDevice.isConnected) {
        [self.mSelectBeaconDevice writeBeaconTxPower:JLEBeaconPowerLevel1 withCompletion:^(BOOL value, NSError* error){
            
            if (value) {
                NSLog(@"Beacon Tx Power Config Success..");
            }
            
        }];
    }
}

- (void) WriteDeviceName
{
    if (self.mSelectBeaconDevice.isConnected) {
        [self.mSelectBeaconDevice writeBeaconDeviceName:@"6161616161" withCompletion:^(BOOL value, NSError* error){
            
            if (value) {
                NSLog(@"Beacon Device Name Config Success..");
            }
            
        }];
    }
}

- (void) WriteBroadcastRate
{
    if (self.mSelectBeaconDevice.isConnected) {
        [self.mSelectBeaconDevice callJaaleeBeacon];
    }
}

#pragma mark - Local Method

-(void) ReadParaFromBeacon
{
    [self ReadProximityUUID];
    
    [UIView animateWithDuration:0.0 delay:1.0 options:UIViewAnimationOptionAllowUserInteraction animations:^{
    } completion:^(BOOL finished) {
        [self ReadMajorValue];
        
    }];
    
    [UIView animateWithDuration:0.0 delay:1.5 options:UIViewAnimationOptionAllowUserInteraction animations:^{
    } completion:^(BOOL finished) {
        
        [self ReadMinorValue];
        
    }];
    
    [UIView animateWithDuration:0.0 delay:2.0 options:UIViewAnimationOptionAllowUserInteraction animations:^{
    } completion:^(BOOL finished) {
        [self ReadMeasuredPowerValue];
        
    }];
    
    [UIView animateWithDuration:0.0 delay:2.5 options:UIViewAnimationOptionAllowUserInteraction animations:^{
    } completion:^(BOOL finished) {
        
        [self ReadTxPowerValue];
        
    }];
    
    [UIView animateWithDuration:0.0 delay:3.0 options:UIViewAnimationOptionAllowUserInteraction animations:^{
    } completion:^(BOOL finished) {
        [self ReadBattery];
        
    }];
    
    [UIView animateWithDuration:0.0 delay:3.5 options:UIViewAnimationOptionAllowUserInteraction animations:^{
    } completion:^(BOOL finished) {
        [self ReadDeviceName];
        
    }];
    
    [UIView animateWithDuration:0.0 delay:4.0 options:UIViewAnimationOptionAllowUserInteraction animations:^{
    } completion:^(BOOL finished) {
        [self ReadBroadcastRate];
        
    }];
}

- (void) ConfigBeacon
{
    [self WriteProximityUUID];
    
    [UIView animateWithDuration:0.0 delay:1.0 options:UIViewAnimationOptionAllowUserInteraction animations:^{
    } completion:^(BOOL finished) {
        [self WriteMajorValue];
        
    }];
    
    [UIView animateWithDuration:0.0 delay:1.5 options:UIViewAnimationOptionAllowUserInteraction animations:^{
    } completion:^(BOOL finished) {
        
        [self WriteMinorValue];
        
    }];
    
    [UIView animateWithDuration:0.0 delay:2.0 options:UIViewAnimationOptionAllowUserInteraction animations:^{
    } completion:^(BOOL finished) {
        [self WriteMeasuredPowerValue];
        
    }];
    
    [UIView animateWithDuration:0.0 delay:2.5 options:UIViewAnimationOptionAllowUserInteraction animations:^{
    } completion:^(BOOL finished) {
        
        [self WriteTxPowerValue];
        
    }];
    
    [UIView animateWithDuration:0.0 delay:3.5 options:UIViewAnimationOptionAllowUserInteraction animations:^{
    } completion:^(BOOL finished) {
        [self WriteDeviceName];
        
    }];
    
    [UIView animateWithDuration:0.0 delay:4.0 options:UIViewAnimationOptionAllowUserInteraction animations:^{
    } completion:^(BOOL finished) {
        [self WriteBroadcastRate];
        
    }];
}

@end
