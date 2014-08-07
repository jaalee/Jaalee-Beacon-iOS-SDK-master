//
//  JLENotificationDemo.m
//  Example
//
//  Created by jaalee on 14-4-23.
//  Copyright (c) 2014年 jaalee. All rights reserved.
//

#import "JLENotificationDemo.h"

#import "JLEBeaconManager.h"
#import "JLEBeacon.h"

static NSString * const kIdentifier = @"jaalee.Example";

@interface JLENotificationDemo ()<JLEBeaconManagerDelegate>

@property (nonatomic, strong) JLEBeaconManager  *beaconManager;
@property (nonatomic, strong) JLEBeaconRegion  *beaconRegion;

@end

@implementation JLENotificationDemo

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
    
    self.beaconManager = [[JLEBeaconManager alloc] init];
    self.beaconManager.delegate = self;
    
    _beaconRegion = [[JLEBeaconRegion alloc] initWithProximityUUID:JAALEE_PROXIMITY_UUID major:1 minor:1 identifier:kIdentifier];
    
    self.beaconRegion.notifyOnEntry = self.mEnterSwitch.isOn;
    self.beaconRegion.notifyOnExit = self.mExitSwitch.isOn;
    
    [self.beaconManager startMonitoringForRegion:self.beaconRegion];
    
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


- (IBAction)OnSwitchValueChanged:(id)sender {
    
    [self.beaconManager stopMonitoringForRegion:self.beaconRegion];
    
    self.beaconRegion.notifyOnEntry = self.mEnterSwitch.isOn;
    self.beaconRegion.notifyOnExit = self.mExitSwitch.isOn;
    
    [self.beaconManager startMonitoringForRegion:self.beaconRegion];
    
}


#pragma mark - JLEBeaconManager delegate

- (void)beaconManager:(JLEBeaconManager *)manager didEnterRegion:(JLEBeaconRegion *)region
{
    UILocalNotification *notification = [UILocalNotification new];
    notification.alertBody = @"Enter region notification";
    
    [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
}

- (void)beaconManager:(JLEBeaconManager *)manager didExitRegion:(JLEBeaconRegion *)region
{
    UILocalNotification *notification = [UILocalNotification new];
    notification.alertBody = @"Exit region notification";
    
    [[UIApplication sharedApplication] presentLocalNotificationNow:notification];
}

@end
