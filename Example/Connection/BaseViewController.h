//
//  BaseViewController.h
//  Example
//
//  Created by jaalee on 15/5/22.
//  Copyright (c) 2015年 jaalee. All rights reserved.
//

#import <UIKit/UIKit.h>
#import "JAALEEBeaconSDK.h"
#import "WaitProgressShow.h"

@interface BaseViewController : UIViewController
@property (nonatomic, strong) JLEBeaconDevice          *mSelectBeaconDevice;
@end
