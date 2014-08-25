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

typedef NS_ENUM(NSInteger, Jaalee_Beacon_State) {
    BEACON_STATE_ENABLE = 0,
    BEACON_STATE_DISABLE,
    BEACON_STATE_UNKNOWN
};

typedef NS_ENUM(NSInteger, Jaalee_Audio_State) {
    BEACON_AUDIO_STATE_ENABLE = 0,
    BEACON_AUDIO_STATE_ENABLE_WHEN_START,
    BEACON_AUDIO_STATE_ENABLE_WHEN_TAP,
    BEACON_AUDIO_STATE_DISABLE,
    BEACON_AUDIO_STATE_UNKNOWN
};


typedef void(^JLECompletionBlock) (NSError* error);
typedef void(^JLEUnsignedShortCompletionBlock) (unsigned short value, NSError* error);
typedef void(^JLEPowerCompletionBlock) (JLEBeaconPower value, NSError* error);
typedef void(^JLEBoolCompletionBlock) (BOOL value, NSError* error);
typedef void(^JLEStringCompletionBlock) (NSString* value, NSError* error);
typedef void(^JLEBeaconStateCompletionBlock) (Jaalee_Beacon_State value, NSError* error);
typedef void(^JLEAudioStateCompletionBlock) (Jaalee_Audio_State value, NSError* error);




////////////////////////////////////////////////////////////////////
// Interface definition

@interface JLEBeaconDefinitions : NSObject

@end
