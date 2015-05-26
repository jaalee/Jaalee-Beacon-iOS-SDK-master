//
//  JLEURIBeacon.h
//  JaaleeBeaconSDK
//
//  Created by jaalee on 15/5/19.
//  Copyright (c) 2015年 jaalee. All rights reserved.
//

#import <Foundation/Foundation.h>


typedef NS_ENUM(NSInteger, JAALEEURIBeaconRegion) {
    JAALEEURIBeaconRegionNear = 0,              /*between 0 and 0.5 meter*/
    JAALEEURIBeaconRegionMid,                   /*between 0.5 and 2 meters*/
    JAALEEURIBeaconRegionFar,                   /*larger than 2 meters*/
    JAALEEURIBeaconRegionUnknown,               /*distance could not be determined*/
};

@interface JLEURIBeacon : NSObject

- (id)initWithObject:(id)object;

/** iOS bluetooth device identifier. */
@property(nonatomic, copy) NSUUID* identifier;

@property(nonatomic, assign) NSInteger RSSI;

/** URI of the beacon. */
@property(nonatomic, copy) NSURL* URI;

/** Measured power level. */
@property(nonatomic, assign) int txPowerLevel;

/** Flags. The flags need to be set to 0. */
@property(nonatomic, assign) NSUInteger flags;

/** returns YES if it's going to fit in a bluetooth LE advertisement packet. */
- (BOOL)isValid;

/** returns the region of the beacon */
- (JAALEEURIBeaconRegion)region;
@end
