//
//  JLEURIBeaconManager.h
//  JaaleeBeaconSDK
//
//  Created by jaalee on 15/5/19.
//  Copyright (c) 2015年 jaalee. All rights reserved.
//

#import <Foundation/Foundation.h>


@class JLEURIBeaconManager;



@protocol JLEURIBeaconManagerDelegate <NSObject>

@optional

/**
 * Delegate method invoked during ranging.
 * Allows to retrieve NSArray of all discoverd beacons
 * represented with JLEBeacon objects.
 *
 * @param manager Jaalee beacon manager
 * @param beacons all beacons as JLEBeacon objects
 * @param region Jaalee beacon region
 *
 * @return void
 */
- (void)URIBeaconManager:(JLEURIBeaconManager *)manager didFoundURIBeacons:(NSArray *)beacons;

//- (void)URIBeaconManager:(JLEURIBeaconManager *)manager didStopSncan:(NSArray *)beacons;

@end

@interface JLEURIBeaconManager : NSObject

@property (nonatomic, weak) id <JLEURIBeaconManagerDelegate> delegate;

-(void)startScanURIBeaconAround;
-(BOOL)stopScanURIBeacon;
@end
