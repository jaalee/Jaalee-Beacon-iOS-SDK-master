//
//  MainViewController.m
//  Example
//
//  Created by jaalee on 15/5/22.
//  Copyright (c) 2015年 jaalee. All rights reserved.
//

#import "MainViewController.h"

@interface MainViewController ()<JLEBeaconDeviceDelegate>
@property (weak, nonatomic) IBOutlet UIButton *mBtn_Motion;
@property (weak, nonatomic) IBOutlet UIButton *mBtn_Position;
@property (weak, nonatomic) IBOutlet UIButton *mBtn_Acc;
@property (weak, nonatomic) IBOutlet UIButton *mBtn_UriBeacon;
@property (weak, nonatomic) IBOutlet UIButton *mBtn_iBeacon;

@end

@implementation MainViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    if (self.mSelectBeaconDevice) {
        self.mSelectBeaconDevice.delegate = self;
        [self.mSelectBeaconDevice connectToBeaconWithPassword:@"666666"];
        [WaitProgressShow showWithStatus:@"Trying to connect the Beacon..."];
    }
}

- (void)viewDidAppear:(BOOL)animated
{
    if (self.mSelectBeaconDevice) {
        self.mSelectBeaconDevice.delegate = self;
    }
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}


#pragma mark - JLEBeaconDeviceDelegate Callbacks

- (void)beaconConnectionDidSucceeded:(JLEBeaconDevice *)beacon
{
    [WaitProgressShow showSuccessWithStatus:@"Connected successfully"];
    
//    [beacon writeBeaconState:BEACON_STATE_IBEACON_NORMAL withCompletion:^(BOOL value, NSError*error)
//     {
//         if (value) {
//             NSLog(@"Success");
//         }
//         else
//         {
//             NSLog(@"%@", error);
//         }
//     }];
}

- (void)beaconConnectionDidFail:(JLEBeaconDevice *)beacon withError:(NSError *)error
{
    [WaitProgressShow showErrorWithStatus:@"Connect the beacon Failed"];
    [self.navigationController popToRootViewControllerAnimated:true];
}

- (void)beaconDidDisconnect:(JLEBeaconDevice *)beacon withError:(NSError *)error
{
    [WaitProgressShow showErrorWithStatus:@"Disconnect from the Beacon"];
    [self.navigationController popToRootViewControllerAnimated:true];
}

- (IBAction)OnTouchMotion:(id)sender {
    [self performSegueWithIdentifier:@"BeaconMotionDetect" sender:nil];
}

- (IBAction)OnTouchPosition:(id)sender {
    [self performSegueWithIdentifier:@"BeaconPositionDetect" sender:nil];
}

- (IBAction)OnTouchAcc:(id)sender {
    [self performSegueWithIdentifier:@"BeaconAccValueDetect" sender:nil];
}

- (IBAction)OnTouchURIBeacon:(id)sender {
    [self performSegueWithIdentifier:@"BeaconURIBeacon" sender:nil];
}

- (IBAction)OnTouchiBeacon:(id)sender {
    [self performSegueWithIdentifier:@"BeaconIbeacon" sender:nil];
}
- (IBAction)OnTouchBeaconState:(id)sender {
    [self performSegueWithIdentifier:@"BeaconStateSetting" sender:nil];
}

- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender
{
    BaseViewController *BaseView = (BaseViewController*) segue.destinationViewController;
    BaseView.mSelectBeaconDevice = self.mSelectBeaconDevice;
}

@end
