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

/**
 * Delegate method that indicates success in beacon connection.
 *
 * @param beacon reference to beacon object
 *
 * @return void
 */
- (void)beaconStartConnecting:(JLEBeaconDevice*)beacon;

/**
 * Delegate method that beacon did update acceleration value with device.
 *
 * @param beacon reference to beacon object
 * @param x X-axis value of the acceleration
 * @param y Y-axis value of the acceleration
 * @param z Z-axis value of the acceleration
 *
 * @return void
 */
- (void)beaconDidReadAccelerationValue:(JLEBeaconDevice*)beacon x:(float)x y:(float)y z:(float)z;

/**
 * Delegate method that Beacon’s position changes
 *
 * @param beacon reference to beacon object
 *
 * @return void
 */
- (void)beaconDidPositionChanged:(JLEBeaconDevice*)beacon position:(JAALEE_POSITION_DEFINE)position;

/**
 * Delegate method that Beacon moves.
 *
 * @param beacon reference to beacon object
 *
 * @return void
 */
- (void)beaconDisMotionDetected:(JLEBeaconDevice*)beacon;
@end

////////////////////////////////////////////////////////////////////
// Interface definition

/**
 
 You do not create instances of this class directly. The JLEBeaconManager object reports encountered beacons to its associated delegate object. You can use the information in a beacon object to identify which beacon device was encountered.
 
 It allows to connect with Jaalee beacon to read / write its characteristics.
 
 */

@interface JLEBeaconDevice : NSObject


@property (nonatomic, weak)     id <JLEBeaconDeviceDelegate>  delegate;

/// @name Publicly available properties
/**
 *  rssi
 *
 *    Received signal strength in decibels of the specified beacon device.
 *    This value is an average of the RSSI samples collected since this beacon was last reported.
 *
 */
@property (nonatomic)           NSInteger               rssi;

/**
 *  name
 *
 *  Discussion:
 *    name of the beacon device.
 */
@property (nonatomic, strong)   NSString*               LocalName;

/**
 *  isConnectable
 *
 *    Whether the beacon can be connected
 *
 */
@property (nonatomic)           BOOL               isConnectable;

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
 *  name
 *
 *  Discussion:
 *    name of the beacon device.
 */
@property (nonatomic, readonly)   NSString*               name;

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
@property (nonatomic, readonly)   uint8_t               beaconState;

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


/**
 *  accBeaconAdvType
 *
 *  Broadcasting type of AccBeacon data
 */
@property (nonatomic, readonly)   Jaalee_Beacon_Acc_Data_Broadcast_Type      accBeaconAdvType;

/**
 *  accBeaconAdvDataService
 *
 *  Service of  broadcasting AccBeacon data
 */
@property (nonatomic, readonly)   uint16_t                                   accBeaconAdvDataService;

/**
 *  accBeaconAdvDataComposition
 *
 *    AccBeacon Data combination format
 */
@property (nonatomic, readonly)   uint8_t                                    accBeaconAdvDataComposition;

/**
 *  motionIntensityOfDetection
 *
 *  The intensity of motion detection, divided into 127 grades
 */
@property (nonatomic, readonly)   uint8_t                                    motionIntensityOfDetection;

/**
 *  isEnableTap
 *
 *  Whether to allow the switch to the quick-connect mode by tapping
 */
@property (nonatomic, readonly)   BOOL                                       isEnableTap;


/**
 *  URIBeacon_URL
 *
 *    URIBeacon's url
 */
@property (nonatomic, readonly, strong)   NSURL                              *URIBeacon_URLString;

/**
 *  isAccelerationDataNotifing
 *
 *  Is it reading the data of the acceleration sensor
 */
@property (nonatomic, readonly)   BOOL                                       isAccelerationDataNotifing;
/**
 *  isMotionDetecting
 *
 *  Motion detect state
 */
@property (nonatomic, readonly)   BOOL                                       isMotionDetecting;

/**
 *  isPositionDetecting
 *
 *  Is it detecting the position changes of beacon
 */
@property (nonatomic, readonly)   BOOL                                       isPositionDetecting;

/**
 *  isSupportReadAccelerationValue
 *
 *  Is support read accrleration value
 */
@property (nonatomic, readonly)   BOOL                                     isSupportReadAccelerationValue;

/**
 *  isSupportDetectMotion
 *
 *  Is support detect motion
 */
@property (nonatomic, readonly)   BOOL                                     isSupportDetectMotion;

/**
 *  isSupportDetectPosition
 *
 *  Is support detect position
 */
@property (nonatomic, readonly)   BOOL                                     isSupportDetectPosition;

/**
 *  isSupportURIBeacon
 *
 *  Is support uriBeacon
 */
@property (nonatomic, readonly)   BOOL                                     isSupportURIBeacon;

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
- (void) writeBeaconState:(uint8_t)state connectable:(BOOL)connectable withCompletion:(JLEBoolCompletionBlock)completion;

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
 * Write value to service and characteristic whth value and completion.
 *
 * @param Service The service of the beacon.
 * @param Characteristic  The characteristic under the service.
 * @param Value The value.
 * @param completion block handling operation completion.
 *
 * @return void
 */
-(void) writeValuetoService:(UInt16)Service Characteristic:(UInt16) Characteristic value:(uint8_t)value withCompletion:(JLEBoolCompletionBlock)completion;


/**
 * Call the Beacon of bluetooth connected beacon.
 *
 * @return Wether the method is call success
 */
- (BOOL) callJaaleeBeacon;

/**
 * Enable jaalee beacon ring when disconnect.
 *
 * @return Wether the method is call success
 */
- (BOOL) enableJaaleeBeaconRingWhenDisconnect;

/**
 * Disable jaalee beacon ring when disconnect.
 *
 * @return Wether the method is call success
 */
- (BOOL) disableJaaleeBeaconRingWhenDisconnect;

/**
 *  Change uribeacon's parameter.
 *
 * @param url url like this “http://www.jaalee.com/”
 * @param txPower this value just for measured the distance, it would not change the transmition distance of the beacon
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void) writeURIBeaconURL:(NSString*)url txPower:(int)txPower WithCompletion:(JLEBoolCompletionBlock)completion;

/**
 * Start get the value of acceleration
 *
 * @return Wether the method is call success
 */
- (BOOL) startNotifyAccelerationData;

/**
 * Stop get the value of acceleration
 *
 * @return Wether the method is call success
 */
- (BOOL) stopNotifyAccelerationData;

/**
 * Start to detect motion
 *
 * @return Wether the method is call success
 */
- (BOOL) startDetectMotion;

/**
 * Stop to detect motion
 *
 * @return Wether the method is call success
 */
- (BOOL) stopDetectMotion;

/**
 * Start to detect position
 *
 * @return Wether the method is call success
 */
- (BOOL) startDetectPosition;

/**
 * Stop to detect position
 *
 * @return Wether the method is call success
 */
- (BOOL) stopDetectPosition;

/**
 * Set the intensity of motion detection Range:1-127 (Previous connection
 * required)
 *
 * @param level Range: 1-127
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void) setIntensityOfMotionDetection:(uint8_t)level WithCompletion:(JLEBoolCompletionBlock)completion;


/**
 * Set acc beacon data (Previous connection
 * required)
 *
 * @param value the value want to add(BEACON_ACC_DATA_ADD_MAC_ADRESS | BEACON_ACC_DATA_ADD_ACC_DATA)
 * @param type Broadcast type @seeJaalee_Beacon_Acc_Data_Broadcast_Type
 * @param Rate Acc value update rate
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void) writeAccBeaconAdvDataComposition:(uint8_t)value type:(Jaalee_Beacon_Acc_Data_Broadcast_Type)type AccDataUpdateRate:(uint8_t)Rate WithCompletion:(JLEBoolCompletionBlock)completion;

/**
 * Set the service of acc beacon (Previous connection
 * required)
 *
 * @param service
 * @param completion block handling operation completion
 *
 * @return void
 */
- (void) writeAccBeaconAdvDataService:(uint16_t)service WithCompletion:(JLEBoolCompletionBlock)completion;

/**
 * Read temperature and battery (Previous connection
 * required)
 *
 * @param completion block with device state as param
 *
 * @return void
 */
- (void) readBatteryAndTemperatureWithCompletion:(JLEReadBatteryWithTemperatureBlock)completion;

/**
 * Enable beacon change to fase connect mode by tap
 *
 * @return Wether the method is call success
 */
- (BOOL) enableBeaconChangeToFastConnectModeByTap;

/**
 * Disnable beacon change to fase connect mode by tap
 *
 * Warning: This means if the beacon staying non-connectable mode, the only way to change the
 * state is by re battery
 *
 * @return
 */
- (BOOL) disableBeaconChangeToFastConnectModeByTap;

@end
