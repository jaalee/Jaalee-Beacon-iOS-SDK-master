//
//  iBeaconViewController.m
//  Example
//
//  Created by jaalee on 15/5/22.
//  Copyright (c) 2015年 jaalee. All rights reserved.
//

#import "iBeaconViewController.h"

@interface iBeaconViewController ()<JLEBeaconDeviceDelegate>
@property (weak, nonatomic) IBOutlet UITextField *BeaconUUID;
@property (weak, nonatomic) IBOutlet UITextField *BeaconMajor;
@property (weak, nonatomic) IBOutlet UITextField *BeaconMinor;

@end

@implementation iBeaconViewController

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
        [self.mSelectBeaconDevice readBeaconProximityUUIDWithCompletion:^(NSString *value, NSError *error){
            [_BeaconUUID setText:value];
            [self.mSelectBeaconDevice readBeaconMajorWithCompletion:^(unsigned short value, NSError *errir){
                [_BeaconMajor setText:[NSString stringWithFormat:@"%d", value]];
                [self.mSelectBeaconDevice readBeaconMinorWithCompletion:^(unsigned short value, NSError *errir){
                    [_BeaconMinor setText:[NSString stringWithFormat:@"%d", value]];
                    [WaitProgressShow showSuccessWithStatus:@"Success"];
                }];
            }];
        }];
    }
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

-(BOOL)textFieldShouldReturn:(UITextField *)textField
{
    if (self.mSelectBeaconDevice && [self.mSelectBeaconDevice isSupportURIBeacon]) {
        
        [WaitProgressShow showWithStatus:@"Trying to configure..."];        
        if (textField.tag == 1) {
            [self.mSelectBeaconDevice writeBeaconProximityUUID:textField.text withCompletion:^(BOOL value, NSError *error){
                if (value) {
                    [WaitProgressShow showSuccessWithStatus:@"Success"];
                }
                else
                {
                    [WaitProgressShow showSuccessWithStatus:@"Failed"];
                }
                
            }];
        }
        else if (textField.tag == 2)
        {
            [self.mSelectBeaconDevice writeBeaconMajor:[textField.text intValue] withCompletion:^(BOOL value, NSError *error){
                if (value) {
                    [WaitProgressShow showSuccessWithStatus:@"Success"];
                }
                else
                {
                    [WaitProgressShow showSuccessWithStatus:@"Failed"];
                }
                
            }];
        }
        else if (textField.tag == 3)
        {
            [self.mSelectBeaconDevice writeBeaconMinor:[textField.text intValue] withCompletion:^(BOOL value, NSError *error){
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
    
    return true;
}
/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
