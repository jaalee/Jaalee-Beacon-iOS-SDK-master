//
//  JLEBeaconDefinitions.h
//  JaaleeBeaconSDK
//
//  Created by jaalee on 14-4-22.
//  Copyright (c) 2014年 jaalee. All rights reserved.
//

#import <Foundation/Foundation.h>





//BOOL misJaaleeBeacon;
//Jaalee_Beacon_State mBeaconState;
//NSNumber *mBatteryLevel;
//NSString *mFirmwareVersion;
//
//
//NSString *mMacAdress;
//NSString* mProximityUUID;
//NSNumber* mMajor;
//
//NSNumber* mMinor;
//NSNumber* mMeasuredPower;
//JLEBeaconPower mTxPower;
//NSNumber* mAdvInterval;



typedef enum : char
{
    JLEBeaconPowerLevel1 = 4,
    JLEBeaconPowerLevel2 = 0,
    JLEBeaconPowerLevel3 = -4,
    JLEBeaconPowerLevel4 = -6,
    JLEBeaconPowerLevel5 = -8,
    JLEBeaconPowerLevel6 = -12,
    JLEBeaconPowerLevel7 = -16,
    JLEBeaconPowerLevel8 = -20,
    JLEBeaconPowerLevel9 = -23,
    JLEBeaconPowerLevel10 = -30,
    JLEBeaconPowerLevel11 = -40
} JLEBeaconPower;

#define     BEACON_STATE_DISABLE                0x01
#define     BEACON_STATE_IBEACON_NORMAL         0x02
#define     BEACON_STATE_IBEACON_TRIGGER        0x04
#define     BEACON_STATE_URIBEACON_NORMAL       0x08
#define     BEACON_STATE_URIBEACON_TRIGGER      0x10
#define     BEACON_STATE_ACCBEACON_NORMAL       0x20
#define     BEACON_STATE_ACCBEACON_TRIGGER      0x40
#define     BEACON_STATE_UNKNOWN                0

typedef NS_ENUM(uint8_t, Jaalee_Beacon_Acc_Data_Combination) {
    BEACON_ACC_DATA_ADD_MAC_ADRESS = 0x80,
    BEACON_ACC_DATA_ADD_ACC_DATA = 0x40,
    BEACON_ACC_DATA_ADD_TEMP_DATA = 0x20,
    BEACON_ACC_DATA_ADD_BATTERY_DATA = 0x10,
    BEACON_ACC_DATA_ADD_POSITION_DATA = 0x08,
};

typedef NS_ENUM(NSInteger, Jaalee_Beacon_Acc_Data_Broadcast_Type) {
    BEACON_ACC_DATA_BROADCASE_TYPE_AS_MANUFACTURER_DATA = 0,
    BEACON_ACC_DATA_BROADCASE_TYPE_AS_SERVICE_DATA,
};

typedef NS_ENUM(NSInteger, Jaalee_Audio_State) {
    BEACON_AUDIO_STATE_ENABLE = 0,
    BEACON_AUDIO_STATE_ENABLE_WHEN_START,
    BEACON_AUDIO_STATE_ENABLE_WHEN_TAP,
    BEACON_AUDIO_STATE_DISABLE,
    BEACON_AUDIO_STATE_UNKNOWN
};

typedef NS_ENUM(NSInteger, JAALEE_POSITION_DEFINE) {
    JAALEE_POSITION_DEFINE_A = 0,
    JAALEE_POSITION_DEFINE_B,
    JAALEE_POSITION_DEFINE_C,
    JAALEE_POSITION_DEFINE_D,
    JAALEE_POSITION_DEFINE_E,
    JAALEE_POSITION_DEFINE_F,
};


typedef void(^JLECompletionBlock) (NSError* error);
typedef void(^JLEUnsignedShortCompletionBlock) (unsigned short value, NSError* error);
typedef void(^JLEPowerCompletionBlock) (JLEBeaconPower value, NSError* error);
typedef void(^JLEBoolCompletionBlock) (BOOL value, NSError* error);
typedef void(^JLEStringCompletionBlock) (NSString* value, NSError* error);
typedef void(^JLEBeaconStateCompletionBlock) (uint8_t value, NSError* error);
typedef void(^JLEAudioStateCompletionBlock) (Jaalee_Audio_State value, NSError* error);
typedef void(^JLEReadBatteryWithTemperatureBlock) (uint8_t battery, float temperature, NSError* error);


////////////////////////////////////////////////////////////////////
// Interface definition

@interface JLEBeaconDefinitions : NSObject

@end
