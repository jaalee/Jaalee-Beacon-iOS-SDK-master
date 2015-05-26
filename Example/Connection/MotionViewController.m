//
//  MotionViewController.m
//  Example
//
//  Created by jaalee on 15/5/22.
//  Copyright (c) 2015年 jaalee. All rights reserved.
//

#import "MotionViewController.h"
#import <AudioToolbox/AudioToolbox.h>

@interface MotionViewController ()<JLEBeaconDeviceDelegate>
@property (weak, nonatomic) IBOutlet UIImageView *mMotionImage;

@end

@implementation MotionViewController
{
    BOOL CurrentIsMotion;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    CurrentIsMotion = false;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)viewDidAppear:(BOOL)animated
{
    self.mSelectBeaconDevice.delegate = self;
    if (self.mSelectBeaconDevice && ![self.mSelectBeaconDevice isMotionDetecting]) {
        [self.mSelectBeaconDevice startDetectMotion];
    }
}

-(void) viewDidDisappear:(BOOL)animated
{
    if (self.mSelectBeaconDevice && [self.mSelectBeaconDevice isMotionDetecting]) {
        [self.mSelectBeaconDevice stopDetectMotion];
    }
}

- (void)beaconDisMotionDetected:(JLEBeaconDevice *)beacon
{
    if (!CurrentIsMotion) {
        CurrentIsMotion = true;
        [self earthquake];
        AudioServicesPlaySystemSound(kSystemSoundID_Vibrate);
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


-(void)earthquake
{
    CGFloat t =2.0;
    
    CGAffineTransform leftQuake  =CGAffineTransformTranslate(CGAffineTransformIdentity, t,-t);
    CGAffineTransform rightQuake =CGAffineTransformTranslate(CGAffineTransformIdentity,-t, t);
    
    _mMotionImage.transform = leftQuake;  // starting point
    
    [UIView beginAnimations:@"earthquake" context:nil];
    [UIView setAnimationRepeatAutoreverses:YES];// important
    [UIView setAnimationRepeatCount:5];
    [UIView setAnimationDuration:0.07];
    [UIView setAnimationDelegate:self];
    [UIView setAnimationDidStopSelector:@selector(earthquakeEnded:finished:context:)];
    _mMotionImage.transform = rightQuake;// end here & auto-reverse
    
    [UIView commitAnimations];
}

-(void)earthquakeEnded:(NSString*)animationID finished:(NSNumber*)finished context:(void*)context
{
    if([finished boolValue])
    {
        CurrentIsMotion = false;
        _mMotionImage.transform =CGAffineTransformIdentity;
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
