//
//  JLEBeaconManager.h
//  JaaleeBeaconSDK
//
//  Created by jaalee on 14-4-22.
//  Copyright (c) 2014年 jaalee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "JLEBeaconRegion.h"
#import "JLEBeacon.h"

#define JAALEE_PROXIMITY_UUID   [[NSUUID alloc] initWithUUIDString:@"EBEFD083-70A2-47C8-9837-E7B5634DF524"]

@class JLEBeaconManager;

/**
 
 The JLEBeaconManagerDelegate protocol defines the delegate methods to respond for related events.
 */

@protocol JLEBeaconManagerDelegate <NSObject>

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
- (void)beaconManager:(JLEBeaconManager *)manager didRangeBeacons:(NSArray *)beacons inRegion:(JLEBeaconRegion *)region;

/**
 * Delegate method invoked wehen ranging fails
 * for particular region. Related NSError object passed.
 *
 * @param manager Jaalee beacon manager
 * @param region Jaalee beacon region
 * @param error object containing error info
 *
 * @return void
 */
-(void)beaconManager:(JLEBeaconManager *)manager rangingBeaconsDidFailForRegion:(JLEBeaconRegion *)region
           withError:(NSError *)error;


/**
 * Delegate method invoked wehen monitoring fails
 * for particular region. Related NSError object passed.
 *
 * @param manager Jaalee beacon manager
 * @param region Jaalee beacon region
 * @param error object containing error info
 *
 * @return void
 */
-(void)beaconManager:(JLEBeaconManager *)manager monitoringDidFailForRegion:(JLEBeaconRegion *)region
           withError:(NSError *)error;
/**
 * Method triggered when iOS device enters jaalee
 * beacon region during monitoring.
 *
 * @param manager jaalee beacon manager
 * @param region jaalee beacon region
 *
 * @return void
 */
-(void)beaconManager:(JLEBeaconManager *)manager didEnterRegion:(JLEBeaconRegion *)region;


/**
 * Method triggered when iOS device leaves jaalee
 * beacon region during monitoring.
 *
 * @param manager jaalee beacon manager
 * @param region jaalee beacon region
 *
 * @return void
 */
-(void)beaconManager:(JLEBeaconManager *)manager didExitRegion:(JLEBeaconRegion *)region;

/**
 * Method triggered when jaalee beacon region state
 * was determined using requestStateForRegion:
 *
 * @param manager jaalee beacon manager
 * @param state jaalee beacon region state
 * @param region jaalee beacon region
 *
 * @return void
 */
-(void)beaconManager:(JLEBeaconManager *)manager didDetermineState:(CLRegionState)state
           forRegion:(JLEBeaconRegion *)region;
@end



/**
 
 The JLEBeaconManager class defines the interface for handling and configuring the jaalee beacons and get related events to your application. You use an instance of this class to establish the parameters that describes each beacon behavior. You can also use a beacon manager object to retrieve all beacons in range.
 
 A beacon manager object provides support for the following location-related activities:
 
 * Monitoring distinct regions of interest and generating location events when the user enters or leaves those regions (works in background mode).
 * Reporting the range to nearby beacons and ther distance for the device.
 
 */

@interface JLEBeaconManager : NSObject <CLLocationManagerDelegate>

@property (nonatomic, weak) id <JLEBeaconManagerDelegate> delegate;

/**
 Allows to avoid beacons with unknown state (proximity == 0), when ranging. Default value is NO.
 */
@property (nonatomic) BOOL avoidUnknownStateBeacons;

@property (nonatomic, strong) JLEBeaconRegion*         virtualBeaconRegion;


/// @name CoreLocation based iBeacon monitoring and ranging methods

/**
 * Range all jaalee beacons that are visible in range.
 * Delegate method beaconManager:didRangeBeacons:inRegion:
 * is used to retrieve found beacons. Returned NSArray contains
 * JLEBeacon objects.
 *
 * @param region jaalee beacon region
 *
 * @return void
 */
-(void)startRangingBeaconsInRegion:(JLEBeaconRegion*)region;

/**
 * Start monitoring for particular region.
 * Functionality works in the background mode as well.
 * Every time you enter or leave region appropriet
 * delegate method inovked: beaconManager:didEnterRegtion:
 * and beaconManager:didExitRegion:
 *
 * @param region jaalee beacon region
 *
 * @return void
 */
-(void)startMonitoringForRegion:(JLEBeaconRegion*)region;

/**
 * Stops ranging jaalee beacons.
 *
 * @param region jaalee beacon region
 *
 * @return void
 */
-(void)stopRangingBeaconsInRegion:(JLEBeaconRegion*)region;

/**
 * Unsubscribe application from iOS monitoring of
 * jaalee beacon region.
 *
 * @param region jaalee beacon region
 *
 * @return void
 */
-(void)stopMonitoringForRegion:(JLEBeaconRegion *)region;

/**
 * Allows to validate current state for particular region
 *
 * @param region jaalee beacon region
 *
 * @return void
 */
-(void)requestStateForRegion:(JLEBeaconRegion *)region;




@end

