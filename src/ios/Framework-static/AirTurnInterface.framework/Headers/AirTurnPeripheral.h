//
//  AirTurnPeripheral.h
//  AirTurnInterface
//
//  Created by Nick Brook on 27/02/2014.
//  Copyright (c) 2014 Nick Brook. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AirTurnInterface/AirTurnTypes.h>
#import <AirTurnInterface/AirTurnError.h>
#import <AirTurnInterface/ARCHelper.h>
#import <AirTurnInterface/EDSemver.h>

/**
 Represents one AirTurn peripheral
 */
@interface AirTurnPeripheral : NSObject

/// ---------------------------------
/// @name Peripheral state
/// ---------------------------------

/**
 The current state of the peripheral
 */
@property(nonatomic, readonly) AirTurnConnectionState  state;

/**
 The type of connected device
 */
@property(nonatomic, readonly) AirTurnDeviceType deviceType;

/**
 YES if the last connection attempt to the device failed
 */
@property(nonatomic, readonly) BOOL lastConnectionFailed;

/**
 Indicates if the peripheral has bonding, probably to another device. Can't connect to it if it does (unless the system connects automatically for us).
 */
@property(nonatomic, assign) BOOL hasBonding;

/**
 `YES` if pairing failed
 */
@property(nonatomic, readonly) BOOL pairingFailed;

/// ---------------------------------
/// @name Peripheral values
/// ---------------------------------

/**
 A unique identifier for this device
 */
@property(nonatomic, readonly, nonnull) NSString *identifier;

/**
 The name of the peripheral
 */
@property(nonatomic, readonly, nullable) NSString * name;

/**
 The default name of the peripheral
 */
@property(nonatomic, readonly, nullable) NSString * defaultName;

/**
 The firmware version of the peripheral
 */
@property(nonatomic, readonly, nullable) EDSemver * firmwareVersion;

/**
 The hardware version of the peripheral
 */
@property(nonatomic, readonly, nullable) EDSemver * hardwareVersion;

/**
 A bit field describing the features available on this peripheral
 */
@property(nonatomic, readonly) AirTurnPeripheralFeaturesAvailable featuresAvailable;

/**
 The peripheral battery level, a percentage 0-100%
 */
@property(nonatomic, readonly) uint8_t batteryLevel;

/**
 The peripheral charging state
 */
@property(nonatomic, readonly) AirTurnPeripheralChargingState chargingState;

/**
 Defines the delay before key repeat, a programmable property on the device.  The delay before repeat is calculated, in seconds, as `delay = AirTurnPeripheralMaxDelayBeforeRepeatSeconds * value / 255`.  The maximum delay currently defined as 4s, the minimum is 0.015625 seconds.  If the value of the divisor is zero and `repeatRateDivisor` is zero, there will be no key repeat.
 */
@property(readonly) uint8_t delayBeforeRepeatMultiplier;

/**
 Defines the key repeat rate, a programmable property on the device.  The key repeat rate is calculated, in seconds, as `time between repeat = AirTurnPeripheralMaxRepeatRateSeconds / value`.  The maximum time between repeat is currently defined as 4s, the minimum is 0.015625 seconds.  If the value of the divisor is zero, there will be no key repeat. If it is one, and `delayBeforeRepeatMultiplier` is zero, key repeat will be left to the OS.
 */
@property(readonly) uint8_t repeatRateDivisor;

/**
 Defines if key repeat is enabled. This is a calculated property, true if `delayBeforeRepeatMultiplier` and `repeatRateDivisor` are non-zero
 */
@property(readonly) BOOL keyRepeatEnabled;

/**
 Defines if the key repeat mode is operating system. This is a calculated property, true if `delayBeforeRepeatMultiplier` is 0 and `repeatRateDivisor` is 1
 */
@property(readonly) BOOL OSKeyRepeat;

/**
 Defines the idle power off interval, a programmable property on the device.  The idle power off interval is defined in seconds.  If the value of the interval is zero, there will be no idle power off.
 */
@property(readonly) uint16_t idlePowerOff;

/**
 Defines the connection configuration, a programmable property on the device.  This can be used to adjust the power/performance balance of the connection.
 */
@property(readonly) AirTurnPeripheralConnectionConfiguration connectionConfiguration;


/**
 Determine if the peripheral has all the given features

 @param features A bitfield of features
 */
- (BOOL)hasFeatures:(AirTurnPeripheralFeaturesAvailable)features;

/**
 Get the port state for a given port.
 @param port The port
 @return The port state
 */
- (AirTurnPortState)portStateForPort:(AirTurnPort)port;

/// ---------------------------------
/// @name Programming
/// ---------------------------------

/**
 Write the delay before repeat divisor to the device.
 @param multiplier The delay before repeat is calculated, in seconds, as `delay = 4 * multiplier / 255`.  The maximum delay is therefore 4 seconds, the minimum is 0.015625 seconds.  If the value of the multiplier is zero, if the repeat rate is 1 the key repeat will be left to the operating system, else there will be no key repeat.
 */
- (void)writeDelayBeforeRepeat:(uint8_t)multiplier;

/**
 Write the key repeat rate divisor to the device
 @param divisor The key repeat rate is calculated, in seconds, as `time between repeat = 4 / divisor`.  The maximum time between repeat is therefore 4 seconds, the minimum is 0.015625 seconds.  If the value of the divisor is zero and the delay before repeat is zero, there will be no key repeat.
 */
- (void)writeRepeatRate:(uint8_t)divisor;

/**
 Write the idle power off interval to the device
 @param idlePowerOff The idle power off duration in seconds.  0 is 'Never'
 */
- (void)writeIdlePowerOff:(uint16_t)idlePowerOff;

/**
 Write the connection configuration to the device
 
 @param connectionConfiguration The connection configuration
 */
- (void)writeConnectionConfiguration:(AirTurnPeripheralConnectionConfiguration)connectionConfiguration;

/**
 Store the device name locally
 
 @param deviceName The device name. Max length defined in `AirTurnPeripheralMaxNameLength`. Pass a `nil` value or empty string to reset the device name to default.
 */
- (void)storeDeviceName:(nullable NSString *)deviceName;

/**
 Check for a firmware update for this AirTurn
 
 @param callback Called back on result. YES if an update is available.
 */
- (void)checkForFirmwareUpdate:(void (^_Nonnull)(EDSemver * _Nullable newVersion))callback;

@end
