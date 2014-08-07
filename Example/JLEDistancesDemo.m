//
//  JLEDistancesDemo.m
//  Example
//
//  Created by jaalee on 14-4-23.
//  Copyright (c) 2014年 jaalee. All rights reserved.
//

#import "JLEDistancesDemo.h"
#import "JLEBeaconManager.h"
#import "JLEBeacon.h"

static NSString * const kIdentifier = @"jaalee.Example";

@interface JLEDistancesDemo ()<JLEBeaconManagerDelegate>

@property (nonatomic, strong) JLEBeaconManager  *beaconManager;
@property (nonatomic, strong) JLEBeaconRegion  *beaconRegion;
@end

@implementation JLEDistancesDemo

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
    
    _beaconManager = [[JLEBeaconManager alloc] init];
    _beaconManager.delegate = self;
    
    _beaconRegion = [[JLEBeaconRegion alloc] initWithProximityUUID:JAALEE_PROXIMITY_UUID major:1 minor:1 identifier:kIdentifier];
    _beaconRegion = [[JLEBeaconRegion alloc] initWithProximityUUID:JAALEE_PROXIMITY_UUID identifier:kIdentifier];
    
    [_beaconManager startRangingBeaconsInRegion:_beaconRegion];
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

#pragma mark - JLEBeaconManager delegate

- (void)beaconManager:(JLEBeaconManager *)manager didRangeBeacons:(NSArray *)beacons inRegion:(JLEBeaconRegion *)region
{
    JLEBeacon *temp = [beacons firstObject];
    self.mProximityUUID.text = [temp.proximityUUID UUIDString];
    self.mMajorValue.text = [NSString stringWithFormat:@"%d", [temp.major intValue]];
    self.mMinorValue.text = [NSString stringWithFormat:@"%d", [temp.major intValue]];
    self.mAccValue.text = [NSString stringWithFormat:@"%.2f", temp.accuracy];
    
}
@end
