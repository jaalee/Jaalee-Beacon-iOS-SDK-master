//
//  AccViewController.m
//  Example
//
//  Created by jaalee on 15/5/22.
//  Copyright (c) 2015年 jaalee. All rights reserved.
//

#import "AccViewController.h"

@interface AccViewController ()<JLEBeaconDeviceDelegate>
@property (weak, nonatomic) IBOutlet UISlider *ProgressX;
@property (weak, nonatomic) IBOutlet UISlider *ProgressZ;

@property (weak, nonatomic) IBOutlet UISlider *ProgressY;

@property (weak, nonatomic) IBOutlet UILabel *LabelX;
@property (weak, nonatomic) IBOutlet UILabel *LabelY;
@property (weak, nonatomic) IBOutlet UILabel *LabelZ;
@end

@implementation AccViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [_ProgressX setValue:0 animated:false];
    [_ProgressY setValue:0 animated:false];
    [_ProgressZ setValue:0 animated:false];
    
    [_LabelX setText:@""];
    [_LabelY setText:@""];
    [_LabelZ setText:@""];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidAppear:(BOOL)animated
{
    self.mSelectBeaconDevice.delegate = self;
    if (self.mSelectBeaconDevice && ![self.mSelectBeaconDevice isAccelerationDataNotifing]) {
        [self.mSelectBeaconDevice startNotifyAccelerationData];
    }
}

-(void) viewDidDisappear:(BOOL)animated
{
    if (self.mSelectBeaconDevice && [self.mSelectBeaconDevice isAccelerationDataNotifing]) {
        [self.mSelectBeaconDevice stopNotifyAccelerationData];
    }
}

#pragma mark - JLEBeaconDeviceDelegate delegate

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

-(void)beaconDidReadAccelerationValue:(JLEBeaconDevice *)beacon x:(float)x y:(float)y z:(float)z
{
//    NSLog(@"x:%f  y:%f  z:%f",x, y, z);
    
    [_ProgressX setValue:x animated:true];
    [_ProgressY setValue:y animated:true];
    [_ProgressZ setValue:z animated:true];
    
    [_LabelX setText:[NSString stringWithFormat:@"%.2fg", x]];
    [_LabelY setText:[NSString stringWithFormat:@"%.2fg", y]];
    [_LabelZ setText:[NSString stringWithFormat:@"%.2fg", z]];

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
