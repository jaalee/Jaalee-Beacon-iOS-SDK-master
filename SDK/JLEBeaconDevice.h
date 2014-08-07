//
//  JLEBeacon.h
//  JaaleeBeaconSDK
//
//  Created by jaalee on 14-4-22.
//  Copyright (c) 2014年 jaalee. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "JLEBeaconDefinitions.h"



@class JLEBeaconDevice;

////////////////////////////////////////////////////////////////////
// JAALEE beacon delegate protocol


/**
 
 JLEBeaconDelegate defines beacon connection delegate mathods. Connection is asynchronous operation so you need to be prepared that eg. beaconDidDisconnectWith: method can be invoked without previous action.
 
 */

@protocol JLEBeaconDeviceDelegate <NSObject>

@optional

/**
 * Delegate method that indicates error in beacon connection.
 *
 * @param beacon reference to beacon object
 * @param error information about reason of error
 *
 * @return void
 */
- (void)beaconConnectionDidFail:(JLEBeaconDevice*)beacon withError:(NSError*)error;

/**
 * Delegate method that indicates success in beacon connection.
 *
 * @param beacon reference to beacon object
 *
 * @return void
 */
- (void)beaconConnectionDidSucceeded:(JLEBeaconDevice*)beacon;

/**
 * Delegate method that beacon did disconnect with device.
 *
 * @param beacon reference to beacon object
 * @param error information about reason of error
 *
 * @return void
 */
- (void)beaconDidDisconnect:(JLEBeaconDevice*)beacon withError:(NSError*)error;


/**
 * Delegate method that beacon did update rssi with device.
 *
 * @param beacon reference to beacon object
 * @param error information about reason of error
 *
 * @return void
 */
- (void)beaconDidUpdateRssi:(JLEBeaconDevice*)beacon Error:(NSError*)error;

@end

////////////////////////////////////////////////////////////////////
// Interface definition

/**
 
 You do not create instances of this class directly. The JLEBeaconManager object reports encountered beacons to its associated delegate object. You can use the information in a beacon object to identify which beacon device was encountered.
 
 It allows to connect with Jaalee beacon to read / write its characteristics.
 
 */

@interface JLEBeaconDevice : NSObject


@property (nonatomic, weak)     id <JLEBeaconDeviceDelegate>  delegate;

@property (nonatomic, strong)        CBCentralManager *manager;
/// @name Publicly available properties
/**
 *  name
 *
 *  Discussion:
 *    name of the beacon device.
 */
@property (nonatomic, strong)   NSString*               name;

/**
 *  rssi
 *
 *    Received signal strength in decibels of the specified beacon device.
 *    This value is an average of the RSSI samples collected since this beacon was last reported.
 *
 */
@property (nonatomic)           NSInteger               rssi;

/**
 *  isConnected
 *
 *    Flag indicating connection status.
 */
@property (nonatomic, readonly)   BOOL                  isConnected;


/**
 *  peripheral
 *
 *    Reference of the beacon device peripheral object.
 */
@property (nonatomic, strong)   CBPeripheral*           peripheral;




/////////////////////////////////////////////////////
// @name Properties available after connection

/**
 *  isJaaleeBeacon
 *
 *    Wether the beacon is belong to Jaalee.
 */
@property (nonatomic, readonly)   BOOL                  isJaaleeBeacon;

/**
 *  batteryLevel
 *
 *    Battery strength in %. Battery level change from 100% - 0%. Value available after connection with the beacon
 */
@property (nonatomic, strong, readonly)   NSNumber*               batteryLevel;

/**
 *  batteryLevel
 *
 *    Battery strength in %. Battery level change from 100% - 0%. Value available after connection with the beacon
 */
@property (nonatomic, strong, readonly)   NSString*               firmwareVersion;

/**
 *  macAddress
 *
 *  Discussion:
 *    Hardware MAC address of the beacon device.
 */
@property (nonatomic, strong, readonly)   NSString*               macAddress;

/**
 *  proximityUUID
 *
 *    Proximity identifier read from the beacon device.
 *
 */
@property (nonatomic, strong, readonly)   NSString*                 proximityUUID;

/**
 *  major
 *
 *    Beacon major value read from the beacon device.
 *
 */
@property (nonatomic, strong, readonly)   NSNumber*               major;

/**
 *  minor
 *
 *    Beacon minor value read from the beacon device.
 *
 */
@property (nonatomic, strong, readonly)   NSNumber*               minor;

/**
 *  measuredPower
 *
 *    Measured Power value read from the beacon device.
 */
@property (nonatomic, strong, readonly)   NSNumber*               measuredPower;

/**
 *  beaconState
 *
 *    The beacon state. Value available after connection with the beacon
 */
@property (nonatomic, readonly)   Jaalee_Beacon_State               beaconState;

/**
 *  txPower
 *
 *    Power of signal in dBm. Value available after connection with the beacon. It takes one of the values represented by JLEBeaconPower .
 */
@property (nonatomic, readonly)   JLEBeaconPower               txPower;

/**
 *  advInterval
 *
 *    Advertising interval of the beacon. Value change from 100ms to 10000ms. Value available after connection with the beacon
 */
@property (nonatomic, strong, readonly)   NSNumber*               advInterval;

/**
 *  audioState
 *
 *    the audio state of the beacon. Value available after connection with the beacon
 */
@property (nonatomic, readonly)   Jaalee_Audio_State      audioState;

/// @name Connection handling methods


/**
 * Connect to particular beacon using bluetooth.
 * Connection is required to change values like
 * UUID, Major, Minor, Power and Advertising interval.
 *
 * @return void
 */
-(void)connectToBeaconWithPassword:(NSString*)password;

/**
 * Disconnect device with particular beacon
 *
 * @return void
 */
-(void)disconnectBeacon;


/// @name Methods for reading beacon configuration

/**
 * Read Proximity UUID of connected beacon (Previous connection
 * required)
 *
 * @param completion block with major value as param
 *
 * @return void
 */
- (void)readBeaconProximityUUIDWithCompletion:(JLEStringCompletionBlock)completion;

/**
 * Read major of connected beacon (Previous connection
 * required)
 *
 * @param completion block with major value as param
 *
 * @return void
 */
- (void)readBeaconMajorWithCompletion:(JLEUnsignedShortCompletionBlock)completion;

/**
 * Read minor of connected beacon (Previous connection
 * required)
 *
 * @param completion block with minor value as param
 *
 * @return void
 */
- (void)readBeaconMinorWithCompletion:(JLEUnsignedShortCompletionBlock)completion;

/**
 * Read measured power value of connected beacon (Previous connection
 * required)
 *
 * @param completion block with measured power value as param
 *
 * @return void
 */
- (void)readBeaconMeasuredPowerWithCompletion:(JLEUnsignedShortCompletionBlock)completion;

/**
 * Read advertising interval of connected beacon (Previous connection
 * required)
 *
 * @param completion block with advertising interval value as param
 *
 * @return void
 */
- (void)readBeaconAdvIntervalWithCompletion:(JLEUnsignedShortCompletionBlock)completion;


/**
 * Read Tx power of connected beacon (Previous connection
 * required)
 *
 * @param completion block with power value as param
 *
 * @return float value of beacon power
 */
- (void)readBeaconTxPowerWithCompletion:(JLEPowerCompletionBlock)completion;

/**
 * Read battery level of connected beacon (Previous connection
 * required)
 *
 * @param completion block with battery level value as param
 *
 * @return void
 */
- (void)readBeaconBatteryWithCompletion:(JLEUnsignedShortCompletionBlock)completion;


/**
 * Read device name of connected beacon (Previous connection
 * required)
 *
 * @param completion block with device name as param
 *
 * @return void
 */
- (void)readBeaconDeviceNameWithCompletion:(JLEStringCompletionBlock)completion;

/**
 * Read device state of connected beacon (Previous connection
 * required)
 *
 * @param completion block with device state as param
 *
 * @return void
 */
- (void)readBeaconStateWithCompletion:(JLEBeaconStateCompletionBlock)completion;

/**
 * Read device audio state of connected beacon (Previous connection
 * required)
 *
 * @param completion block with device state as param
 *
 * @return void
 */
- (void)readAudioStateWithCompletion:(JLEAudioStateCompletionBlock)completion;

/**
 * Read device Mfgr of connected beacon (Previous connection
 * required)
 *
 * @param completion block with device state as param
 *
 * @return void
 */
- (void)readMfgrWithCompletion:(JLEUnsignedShortCompletionBlock)completion;




/// @name Methods for writing beacon configuration

/**
 * Writes Proximity UUID param to bluetooth connected beacon. Please  remember that If you change the UUID to your very own value anyone can read it, copy it and spoof your beacons. So if you are working on a mission critical application where security is an issue - be sure to implement it on your end. We are also working on a secure mode for our beacons and it will be included in one of the next firmware updates.
 *
 * @param pUUID new Proximity UUID value
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconProximityUUID:(NSString*)pUUID withCompletion:(JLEBoolCompletionBlock)completion;

/**
 * Writes major param to bluetooth connected beacon.
 *
 * @param major major beacon value
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconMajor:(unsigned short)major withCompletion:(JLEBoolCompletionBlock)completion;

/**
 * Writes minor param to bluetooth connected beacon.
 *
 * @param minor minor beacon value
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconMinor:(unsigned short)minor withCompletion:(JLEBoolCompletionBlock)completion;

/**
 * Writes measured power param to bluetooth connected beacon.
 *
 * @param measuredPower measured power beacon value
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconMesauredPower:(unsigned short)measuredPower withCompletion:(JLEBoolCompletionBlock)completion;


/**
 * Writes advertising interval (in milisec) of connected beacon.
 *
 * @param advertising interval of beacon (100 - 10000 ms)
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconAdvInterval:(unsigned short)interval withCompletion:(JLEBoolCompletionBlock)completion;


/**
 * Writes txPower of bluetooth connected beacon.
 *
 * @param txPower advertising beacon power (can take value from JLEBeaconPowerLevel1 / waak to JLEBeaconPowerLevel11 / strong)
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconTxPower:(JLEBeaconPower)txPower withCompletion:(JLEBoolCompletionBlock)completion;


/**
 * Writes device name of bluetooth connected beacon.
 *
 * @param name beacon device name (lenth <= 15byte)
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)writeBeaconDeviceName:(NSString*)name withCompletion:(JLEBoolCompletionBlock)completion;


/**
 * Writes device name of bluetooth connected beacon.
 *
 * @param state beacon device state
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void) writeBeaconState:(Jaalee_Beacon_State)state withCompletion:(JLEBoolCompletionBlock)completion;

/**
 * Writes device audio state of bluetooth connected beacon.
 *
 * @param state audio state
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void) writeAudioState:(Jaalee_Audio_State)state withCompletion:(JLEBoolCompletionBlock)completion;

/**
 * write device Mfgr of connected beacon (Previous connection
 * required)
 *
 * @param value Value of mfgr
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void) writeBeaconMfgr:(unsigned short)value WithCompletion:(JLEBoolCompletionBlock)completion;


/**
 * Change config password of bluetooth connected beacon.
 *
 * @param oldPassword beacon config old password
 * @param newPassword beacon config new password
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void)changeConfigPassword:(NSString*)newPassword withCompletion:(JLEBoolCompletionBlock)completion;


/**
 * Call the Beacon of bluetooth connected beacon.
 *
 * @return void
 */
- (BOOL) callJaaleeBeacon;

/**
 * Enable jaalee beacon ring when disconnect.
 *
 * @return void
 */
- (BOOL) enableJaaleeBeaconRingWhenDisconnect;

/**
 * Disable jaalee beacon ring when disconnect.
 *
 * @return void
 */
- (BOOL) disableJaaleeBeaconRingWhenDisconnect;

@end
