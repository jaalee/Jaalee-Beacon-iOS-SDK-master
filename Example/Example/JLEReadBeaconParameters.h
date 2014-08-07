//
//  ReadBeaconParameters.h
//  Example
//
//  Created by jaalee on 14-4-23.
//  Copyright (c) 2014年 jaalee. All rights reserved.
//

#import "ViewController.h"
#import "JLEBeaconDevice.h"
#import "JLEBeaconConfigManager.h"

@interface JLEReadBeaconParameters : ViewController
@property (weak, nonatomic) IBOutlet UILabel *mUUID;
@property (weak, nonatomic) IBOutlet UILabel *mMajorValue;
@property (weak, nonatomic) IBOutlet UILabel *mMinorValue;
@property (weak, nonatomic) IBOutlet UILabel *mBroadcastRete;
@property (weak, nonatomic) IBOutlet UILabel *mBattLevel;
@property (weak, nonatomic) IBOutlet UILabel *mDeviceName;
@property (weak, nonatomic) IBOutlet UILabel *mMeasuredPowerValue;

@property (weak, nonatomic) IBOutlet UILabel *TxPowerLevel;

@property (nonatomic, strong) JLEBeaconDevice          *mSelectBeaconDevice;

@end
