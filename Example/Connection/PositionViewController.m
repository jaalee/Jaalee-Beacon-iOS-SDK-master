//
//  PositionViewController.m
//  Example
//
//  Created by jaalee on 15/5/22.
//  Copyright (c) 2015年 jaalee. All rights reserved.
//

#import "PositionViewController.h"

@interface PositionViewController ()<JLEBeaconDeviceDelegate>
@property (weak, nonatomic) IBOutlet UIImageView *mPositionImage;

@end

@implementation PositionViewController

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
    self.mSelectBeaconDevice.delegate = self;
    if (self.mSelectBeaconDevice && ![self.mSelectBeaconDevice isPositionDetecting]) {
        [self.mSelectBeaconDevice startDetectPosition];
    }
}

-(void) viewDidDisappear:(BOOL)animated
{
    if (self.mSelectBeaconDevice && [self.mSelectBeaconDevice isMotionDetecting]) {
        [self.mSelectBeaconDevice stopDetectPosition];
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

- (void)beaconDidPositionChanged:(JLEBeaconDevice *)beacon position:(JAALEE_POSITION_DEFINE)position
{
    switch (position) {
        case JAALEE_POSITION_DEFINE_A:
            [self.mPositionImage setImage:[UIImage imageNamed:@"position_a"]];
            break;
        case JAALEE_POSITION_DEFINE_B:
            [self.mPositionImage setImage:[UIImage imageNamed:@"position_b"]];
            break;
        case JAALEE_POSITION_DEFINE_C:
            [self.mPositionImage setImage:[UIImage imageNamed:@"position_c"]];
            break;
        case JAALEE_POSITION_DEFINE_D:
            [self.mPositionImage setImage:[UIImage imageNamed:@"position_d"]];
            break;
        case JAALEE_POSITION_DEFINE_E:
            [self.mPositionImage setImage:[UIImage imageNamed:@"position_e"]];
            break;
        case JAALEE_POSITION_DEFINE_F:
            [self.mPositionImage setImage:[UIImage imageNamed:@"position_f"]];
            break;
        default:
            break;
    }
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
