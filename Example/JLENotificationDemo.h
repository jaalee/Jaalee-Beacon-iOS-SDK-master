//
//  JLENotificationDemo.h
//  Example
//
//  Created by jaalee on 14-4-23.
//  Copyright (c) 2014年 jaalee. All rights reserved.
//

#import "ViewController.h"

@interface JLENotificationDemo : ViewController

- (IBAction)OnSwitchValueChanged:(id)sender;
@property (weak, nonatomic) IBOutlet UISwitch *mEnterSwitch;

@property (weak, nonatomic) IBOutlet UISwitch *mExitSwitch;
@end
