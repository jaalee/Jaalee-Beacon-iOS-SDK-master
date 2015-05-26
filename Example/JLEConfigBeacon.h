//
//  JLEConfigBeacon.h
//  Example
//
//  Created by jaalee on 14-4-23.
//  Copyright (c) 2014年 jaalee. All rights reserved.
//

#import "ViewController.h"

#import "JAALEEBeaconSDK.h"

@interface JLEConfigBeacon : ViewController<UIScrollViewDelegate, UITableViewDataSource, UITableViewDelegate, JLEBeaconConfigManagerDelegate>

@property (weak, nonatomic) IBOutlet UITableView *mTableView;
@end
