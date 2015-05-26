//
//  BeaconStateViewController.m
//  Example
//
//  Created by jaalee on 15/5/25.
//  Copyright (c) 2015年 jaalee. All rights reserved.
//

#import "BeaconStateViewController.h"

@interface BeaconStateViewController ()
@property (weak, nonatomic) IBOutlet UISegmentedControl *mIBeaconSelect;

@property (weak, nonatomic) IBOutlet UISegmentedControl *mURIBeaconSelect;
@end

@implementation BeaconStateViewController
{
    uint8_t BeaconState;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidAppear:(BOOL)animated
{
    if (self.mSelectBeaconDevice) {
        [WaitProgressShow showWithStatus:@"Trying to read message"];
        [self.mSelectBeaconDevice readBeaconStateWithCompletion:^(uint8_t value, NSError *error){
            BeaconState = value;
            [WaitProgressShow showSuccessWithStatus:@"Success"];
            [self HandleUI];
        }];
    }
}

- (void) HandleUI
{
    if (BeaconState & BEACON_STATE_IBEACON_NORMAL) {
        NSLog(@"BEACON_STATE_IBEACON_NORMAL");
    }
    if (BeaconState & BEACON_STATE_IBEACON_TRIGGER)
    {
        NSLog(@"BEACON_STATE_IBEACON_TRIGGER");
    }
    
    if (BeaconState & BEACON_STATE_URIBEACON_NORMAL) {
        NSLog(@"BEACON_STATE_URIBEACON_NORMAL");
    }
    if (BeaconState & BEACON_STATE_URIBEACON_TRIGGER)
    {
        NSLog(@"BEACON_STATE_URIBEACON_TRIGGER");
    }
}

- (IBAction)OnSelectIBeacon:(id)sender {
    NSLog(@"%d", _mIBeaconSelect.selectedSegmentIndex);    
    [self WriteValueToBeacon];
   
}
- (IBAction)OnSelectURIBeacon:(id)sender {
    NSLog(@"%d", _mURIBeaconSelect.selectedSegmentIndex);
    
    [self WriteValueToBeacon];
}

- (void) WriteValueToBeacon
{
    uint8_t beacon_state = 0;
    
    switch (self.mIBeaconSelect.selectedSegmentIndex) {
        case 0:
            beacon_state = (beacon_state | BEACON_STATE_IBEACON_NORMAL);
            break;
        case 1:
            beacon_state = (beacon_state | BEACON_STATE_IBEACON_TRIGGER);
            break;
        default:
            break;
    }
    
    switch (self.mURIBeaconSelect.selectedSegmentIndex) {
        case 0:
            beacon_state = (beacon_state | BEACON_STATE_URIBEACON_NORMAL);
            break;
        case 1:
            beacon_state = (beacon_state | BEACON_STATE_URIBEACON_TRIGGER);
            break;
        default:
            break;
    }
    
    if (_mIBeaconSelect.selectedSegmentIndex == 2 && _mURIBeaconSelect.selectedSegmentIndex == 2)
    {
        beacon_state = BEACON_STATE_DISABLE;
    }
    
    if (self.mSelectBeaconDevice) {
        [WaitProgressShow showWithStatus:@"Trying to configure"];
        [self.mSelectBeaconDevice writeBeaconState:beacon_state connectable:false withCompletion:^(BOOL value, NSError *error){
            
            if (value) {
                [WaitProgressShow showSuccessWithStatus:@"Success"];
            }
            else
            {
                [WaitProgressShow showSuccessWithStatus:@"Failed"];
            }
            
        }];
    }
}

@end
