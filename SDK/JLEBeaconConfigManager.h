//
//  JLEBeaconConfigManager.h
//  JaaleeBeaconSDK
//
//  Created by jaalee on 14-4-22.
//  Copyright (c) 2014年 jaalee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JLEBeaconDevice.h"


@class JLEBeaconConfigManager;

/**
 
 The JLEBeaconManagerDelegate protocol defines the delegate methods to respond for related events.
 */

@protocol JLEBeaconConfigManagerDelegate <NSObject>

@optional

/**
 * Delegate method invoked to handle discovered
 * JLEBeacon objects using CoreBluetooth framework
 * in particular region.
 *
 * @param manager jaalee beacon manager
 * @param beacon discovered Beacon
 *
 * @return void
 */

- (void)beaconConfigManager:(JLEBeaconConfigManager *)manager didDiscoverBeacon:(JLEBeaconDevice *)beacon RSSI:(NSNumber *)RSSI AdvData:(NSDictionary*)AdvData;

///**
// * Delegate method invoked when CoreBluetooth based
// * discovery process fails.
// *
// * @param manager jaalee beacon config manager
// *
// * @return void
// */
//
//- (void)beaconConfigManagerDiscoveryDidFail:(JLEBeaconDevice*)beacon manager:(NSError*)error;

@end


@interface JLEBeaconConfigManager : NSObject

@property (nonatomic, weak) id <JLEBeaconConfigManagerDelegate> delegate;


/// @name CoreBluetooth based utility methods


/**
 * Start beacon discovery process based on CoreBluetooth
 * framework. Method is useful for older beacons discovery
 * that are not advertising as iBeacons.
 *
 *
 * @return void
 */
-(void)startJaaleeBeaconsDiscovery;


/**
 * Stops CoreBluetooth based beacon discovery process.
 *
 * @return void
 */
-(void)stopJaaleeBeaconDiscovery;


@end
