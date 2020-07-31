//
//  AirTurnTypes.h
//  AirTurnInterface
//
//  Created by Nick Brook on 04/01/2012.
//  Copyright (c) 2012 Nick Brook. All rights reserved.
//
//  Permission is hereby granted, to any person (the “Licensee”) who has 
//  legitimately purchased a copy of this framework, example code and 
//  associated documentation (the “Software”) from AirTurn Inc, to use the 
//  compiled binary framework and any parts of the example code within their 
//  own software for distribution and sale on the Apple App Store. The 
//  Software must remain unmodified except any portion of the example source 
//  code which may be used and modified without restriction. The Licensee has 
//  no right to distribute any part of the Software further beyond this 
//  Agreement.

//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR 
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING 
//  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER 
//  DEALINGS IN THE SOFTWARE.
//

#import <AirTurnInterface/AirTurnDefines.h>
#import <AirTurnInterface/AirTurnKeyCodes.h>

/// ---------------------------------
/// @name Standard userInfo keys
/// ---------------------------------

/**
 The notification `userInfo` key for the peripheral that the notification is concerning. The value is an `AirTurnPeripheral` object. Only present on BTLE device notifications.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnPeripheralKey;

/**
 The notification `userInfo` key for the AirTurn identifier. The value is a `NSString` object. Only present on BTLE device notifications.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnIDKey;

/**
 The notification `userInfo` key for the device type on connection notification. The value is an `NSNumber` object containing an integer which is one of the `AirTurnDeviceType` enum values.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnDeviceTypeKey;

/**
 The notification `userInfo` key indicating if the device is an AirDirect device or not. The value is an `NSNumber` object containing a boolean value, YES if an AirTurnDirect device.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnConnectionModeAirDirectKey;

/// ---------------------------------
/// @name Pedal State Notifications
/// ---------------------------------

/**
 A notification indicating which pedal was pressed. A press occurs on pedal down, then at the key repeat rate after intial repeat delay. The `userInfo` dictionary contains all standard keys and the key `AirTurnPortNumberKey` contains the port of the pedal that was pressed and `AirTurnPortStateKey` contains the state of the pedal, which will be `AirTurnPortStateDown`. For HID devices, `AirTurnKeyCodeKey` contains the key code. For PED devices, `AirTurnPedalRepeatCount` contains the number of key repeats.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnPedalPressNotification;
/**
 A notification indicating a pedal was pressed down. The `userInfo` dictionary contains all standard keys and the key `AirTurnPortNumberKey` contains the port of the pedal that was pressed and `AirTurnPortStateKey` contains the state of the pedal, which will be `AirTurnPortStateDown`.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnPedalDownNotification;
/**
 A notification indicating a pedal was lifted. The `userInfo` dictionary contains all standard keys and the key `AirTurnPortNumberKey` contains the port of the pedal that was lifted and `AirTurnPortStateKey` contains the state of the pedal, which will be `AirTurnPortStateUp`. For PED devices, `AirTurnPedalRepeatCount` contains the number of key repeats that occurred.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnPedalUpNotification;

/**
 The notification `userInfo` key for the port number. The value is an `NSNumber` object containing an integer which is one of the `AirTurnPort` enum values.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnPortNumberKey;

/**
 The notification `userInfo` key for the port state. The value is an `NSNumber` object containing an integer which is one of the `AirTurnPortState` enum values.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnPortStateKey;

/**
 The notification `userInfo` key for the port state from a HID device only. The value is an `NSNumber` object containing an integer which is one of the `AirTurnKeyCode` enum values.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnKeyCodeKey;

/**
 The notification `userInfo` key for the repeat count when a pedal is held. Only present for PED devices. The value is an `NSNumber` object containing an integer representing the number of repeats. This will be 0 on the first pedal press event and increment subsequently.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnPedalRepeatCount;

/// ---------------------------------
/// @name Analog port Notifications
/// ---------------------------------

/**
 A notification indicating the analog port value changed. The `userInfo` dictionary contains all standard keys and the key `AirTurnPortNumberKey` contains the port that has changed.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnAnalogPortValueChangeNotification;

/// ---------------------------------
/// @name BTLE Central State Notifications
/// ---------------------------------

/**
 A notification indicating the state of the central has changed. The `userInfo` key `AirTurnCentralStateKey` contains an `NSNumber` object containing an integer which is one of the `AirTurnCentralState` enum values
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnCentralStateChangedNotification;

/**
 The notification `userInfo` key for the new central state. The value is an `NSNumber` object containing one of the `AirTurnCentralState` enum values
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnCentralStateKey;


/// ---------------------------------
/// @name BTLE Devices Discovered Notifications
/// ---------------------------------

/**
 A notification indicating the list of BTLE Devices discovered has changed. The `userInfo` dictionary contains all standard keys and the key `AirTurnDiscoveredPeripheralsKey` contains the set of all discovered devices, and `AirTurnPeripheralKey` contains the device just discovered
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnDiscoveredNotification;

/**
 The notification `userInfo` key for all discovered BTLE devices. The value is an `NSSet` object containing `AirTurnPeripheral` objects. Pass a peripheral object back to `-connectToAirTurn:` on `AirTurnCentral` to connect.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnDiscoveredPeripheralsKey;

/**
 A notification indicating the list of BTLE Devices discovered has changed. The `userInfo` dictionary contains all standard keys and the key `AirTurnDiscoveredDevicesKey` contains the set of all discovered devices, and `AirTurnPeripheralKey` contains the device just lost. The device could have been lost if we have not received an advertising packet within a 10 second window, 10 seconds after disconnecting from a device without receiving an advertising packet, or when the state of the Bluetooth radio changes.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnLostNotification;

/// ---------------------------------
/// @name Connection Notifications
/// ---------------------------------

/**
 A notification indicating the BTLE central is connecting to an AirTurn. The `userInfo` dictionary contains all standard keys.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnConnectingNotification;

/**
 A notification indicating the connection state changed. The `userInfo` dictionary contains all standard keys and the key `AirTurnConnectionStateKey` contains the new connection state. Works with AirDirect and Keyboard. Only sent in Keyboard mode if automatic keyboard management is enabled, see `AirTurnViewManager.connected` for more info.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnConnectionStateChangedNotification;
/**
 A notification indicating an AirTurn device connected. The `userInfo` dictionary contains all standard keys and the key `AirTurnConnectionStateKey` contains the new connection state. Works with AirDirect and Keyboard. Only sent in Keyboard mode if automatic keyboard management is enabled, see `AirTurnViewManager.connected` for more info.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnDidConnectNotification;
/**
 A notification indicating an AirTurn device failed to connect. The `userInfo` dictionary contains all standard keys and the key `AirTurnConnectionStateKey` contains the new connection state
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnDidFailToConnectNotification;
/**
 A notification indicating an AirTurn device disconnected. The `userInfo` dictionary contains all standard keys and the key `AirTurnConnectionStateKey` contains the new connection state. Works with AirDirect and Keyboard. Only sent in Keyboard mode if automatic keyboard management is enabled, see `AirTurnViewManager.connected` for more info.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnDidDisconnectNotification;

/**
 The notification `userInfo` key for the connected state. The value is an `NSNumber` object containing an integer which is one of the `AirTurnConnectionState` enum values
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnConnectionStateKey;

/**
 The notification `userInfo` key for the error. The value is an `NSError` object.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnErrorKey;

/// ---------------------------------
/// @name Storage notifications
/// ---------------------------------

/**
 A notification indicating an AirTurn device was added. The `userInfo` dictionary contains all standard keys
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnAddedNotification;

/**
 A notification indicating an AirTurn device was removed. The `userInfo` dictionary contains all standard keys
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnRemovedNotification;

/**
 A notification indicating an AirTurn device was invalidated, meaning the identifier originally used is no longer valid and your Application should removed any stored data relating to that identifier. This notification can only occur at App start. The `userInfo` key `AirTurnIDKey` contains a unique identifier string for the device.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnInvalidatedNotification;

/// ---------------------------------
/// @name Peripheral Notifications
/// ---------------------------------

/**
 A notification indicating a value has been written successfully to the peripheral. The `userInfo` dictionary contains all standard keys and the key `AirTurnWriteTypeKey` contains a `NSNumber` object containing an integer which is one of the `AirTurnPeripheralWriteType` values. The posting object is the `AirTurnPeripheral`.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnWriteCompleteNotification;

/**
 A notification indicating the current mode of the peripheral has changed. The `userInfo` dictionary contains all standard keys. The posting object is the `AirTurnPeripheral`.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnDidUpdateCurrentModeNotification;

/**
 The notification `userInfo` key for the type of value just written on write complete notification. The value is an `NSNumber` object containing an integer which is one of the `AirTurnPeripheralWriteType` values.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnWriteTypeKey;

/**
 A notification indicating the name of the peripheral has changed. The `userInfo` dictionary contains all standard keys. The posting object is the `AirTurnPeripheral`.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnDidUpdateNameNotification;

/**
 A notification indicating the charging state of the peripheral has changed. The `userInfo` dictionary contains all standard keys. The posting object is the `AirTurnPeripheral`.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnDidUpdateChargingStateNotification;

/**
 A notification indicating the battery level of the peripheral has changed. The `userInfo` dictionary contains all standard keys. The posting object is the `AirTurnPeripheral`.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnDidUpdateBatteryLevelNotification;

/**
 A notification indicating the pairing state of the peripheral has changed. The `userInfo` dictionary contains all standard keys. The posting object is the `AirTurnPeripheral`.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnDidUpdatePairingStateNotification;

/// ---------------------------------
/// @name Keyboard Notifications
/// ---------------------------------

/**
 A notification indicating automatic keyboard management was enabled or disabled.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnAutomaticKeyboardManagementEnabledChangedNotification;

/**
 A notification indicating the virtual keyboard will be displayed.  The posting object is the `AirTurnKeyboardManager` shared object. The `userInfo` dictionary contains the keys `AirTurnVirtualKeyboardFrameBeginUserInfoKey`, `AirTurnVirtualKeyboardFrameEndUserInfoKey`, `AirTurnVirtualKeyboardAnimationCurveUserInfoKey` and `AirTurnVirtualKeyboardAnimationDurationUserInfoKey`.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnVirtualKeyboardWillShowNotification;

/**
 A notification indicating the virtual keyboard was displayed.  The posting object is the `AirTurnKeyboardManager` shared object. The `userInfo` dictionary contains the keys `AirTurnVirtualKeyboardFrameBeginUserInfoKey`, `AirTurnVirtualKeyboardFrameEndUserInfoKey`, `AirTurnVirtualKeyboardAnimationCurveUserInfoKey` and `AirTurnVirtualKeyboardAnimationDurationUserInfoKey`.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnVirtualKeyboardDidShowNotification;

/**
 A notification indicating the virtual keyboard will be hidden.  The posting object is the `AirTurnKeyboardManager` shared object. The `userInfo` dictionary contains the keys `AirTurnVirtualKeyboardFrameBeginUserInfoKey`, `AirTurnVirtualKeyboardFrameEndUserInfoKey`, `AirTurnVirtualKeyboardAnimationCurveUserInfoKey` and `AirTurnVirtualKeyboardAnimationDurationUserInfoKey`.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnVirtualKeyboardWillHideNotification;

/**
 A notification indicating the virtual keyboard was hidden.  The posting object is the `AirTurnKeyboardManager` shared object. The `userInfo` dictionary contains the keys `AirTurnVirtualKeyboardFrameBeginUserInfoKey`, `AirTurnVirtualKeyboardFrameEndUserInfoKey`, `AirTurnVirtualKeyboardAnimationCurveUserInfoKey` and `AirTurnVirtualKeyboardAnimationDurationUserInfoKey`.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnVirtualKeyboardDidHideNotification;

/**
 The notification `userInfo` key for the frame of the keyboard at the beginning of an animation at a show/hide notification.  The value is an `NSValue` object containing a `CGRect`.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnVirtualKeyboardFrameBeginUserInfoKey;

/**
 The notification `userInfo` key for the frame of the keyboard at the end of an animation at a show/hide notification.  The value is an `NSValue` object containing a `CGRect`.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnVirtualKeyboardFrameEndUserInfoKey;

/**
 The notification `userInfo` key for the keyboard animation curve at a show/hide notification.  The value is an `NSNumber` object containing a `UIViewAnimationCurve` constant.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnVirtualKeyboardAnimationCurveUserInfoKey;

/**
 The notification `userInfo` key for the keyboard animation duration at a show/hide notification.  The value is an `NSNumber` object containing a `double` that identifies the duration of the animation in seconds.
 */
AIRTURN_EXTERN NSString * _Nonnull const AirTurnVirtualKeyboardAnimationDurationUserInfoKey;

/// ---------------------------------
/// @name enums
/// ---------------------------------


/**
 Represents the current mode of the AirTurn
 */
typedef NS_ENUM(NSUInteger, AirTurnMode) {
    /**
     No mode
     */
    AirTurnModeNone = 0,
    /**
     Mode 1 – iOS mode
     */
    AirTurnMode1 = 1,
    /**
     Mode 2 – Programmable mode 2
     */
    AirTurnMode2,
    /**
     Mode 3 – Programmable mode 3
     */
    AirTurnMode3,
    /**
     Mode 4 – Programmable mode 4
     */
    AirTurnMode4,
    /**
     Mode 5 – Programmable mode 5
     */
    AirTurnMode5,
    /**
     Programmable mode 6
     */
    AirTurnMode6,
    /**
     Programmable mode 7
     */
    AirTurnMode7,
    /**
     Programmable mode 8
     */
    AirTurnMode8,
    /**
     The minimum mode value
     */
    AirTurnModeMinimum = AirTurnMode1,
    /**
     The maximum mode value
     */
    AirTurnModeMaximum = AirTurnMode8
};

/**
 Defines the number of modes available, equal to `AirTurnModeMaximum - AirTurnModeMinimum + 1`
 */
extern const NSUInteger AirTurnModeMaxNumberOfModes;

/**
 Constants defining the AirTurn port numbers
 */
typedef NS_ENUM(NSInteger, AirTurnPort) {
    /**
     An invalid port number
     */
    AirTurnPortInvalid = 0,
    /**
     AirTurn Port 1, usually 'Up'
     */
    AirTurnPort1,
    /**
     AirTurn Port 2, usually 'Left'
     */
    AirTurnPort2,
    /**
     AirTurn Port 3, usually 'Down'
     */
    AirTurnPort3,
    /**
     AirTurn Port 4, usually 'Right'
     */
    AirTurnPort4,
    /**
     AirTurn Port 5
     */
    AirTurnPort5,
    /**
     AirTurn Port 6
     */
    AirTurnPort6,
    /**
     AirTurn Port 7
     */
    AirTurnPort7,
    /**
     AirTurn Port 8
     */
    AirTurnPort8,
    /**
     The minimum port number
     */
    AirTurnPortMinimum = AirTurnPort1,
    /**
     The maximum port number
     */
    AirTurnPortMaximum = AirTurnPort8
};

/**
 Defines the number of ports available, equal to `AirTurnPortMaximum - AirTurnPortMinimum + 1`
 */
extern const NSUInteger AirTurnPortMaxNumberOfPorts;

/**
 Constants defining the AirTurn port states
 */
typedef NS_ENUM(NSInteger, AirTurnPortState) {
    /**
     Invalid port state
     */
    AirTurnPortStateInvalid = -1,
    /**
     The port state is up, i.e. the pedal is not pressed
     */
    AirTurnPortStateUp = 0,
    /**
     The port state is down, i.e. the pedal is pressed
     */
    AirTurnPortStateDown = 1
};

/**
 Constants defining the AirTurn device type. If the device is connected via HID the device type cannot be determined and so will be `AirTurnDeviceTypeUnknown`
 */
typedef NS_ENUM(NSInteger, AirTurnDeviceType) {
    /**
     Invalid device type that the framework does not support
     */
    AirTurnDeviceTypeInvalid = -1,
    /**
     Unknown device type
     */
    AirTurnDeviceTypeUnknown = 0,
    /**
     HID device type (probably BT-105)
     */
    AirTurnDeviceTypeHID,
    /**
     AirTurn PED device type
     */
    AirTurnDeviceTypePED,
    /**
     AirTurn virtual PED device type
     */
    AirTurnDeviceTypevPED,
    /**
     AirTurn PED device type
     */
    AirTurnDeviceTypePEDpro,
    /**
     AirTurn DIGIT device type
     */
    AirTurnDeviceTypeDIGIT3,
    /**
     AirTurn BT200 device type
     */
    AirTurnDeviceTypeBT200,
    /**
     AirTurn BT200S-2 device type
     */
    AirTurnDeviceTypeBT200S_2,
    /**
     AirTurn BT200S-4 device type
     */
    AirTurnDeviceTypeBT200S_4,
    /**
     AirTurn BT200S-6 device type
     */
    AirTurnDeviceTypeBT200S_6,
};

/**
 Constants defining the type of inputs the AirTurn has.
 */
typedef NS_ENUM(NSUInteger, AirTurnInputType) {
	/**
	 AirTurn has 'port' inputs. Examples include older keyboard only devices and unknown devices.
	 */
	AirTurnInputTypePort,
	/**
	 AirTurn has 'pedal' inputs. Examples include PEDpro.
	 */
	AirTurnInputTypePedal,
	/**
	 AirTurn has 'switch' inputs. Examples include BT200S-2
	 */
	AirTurnInputTypeSwitch,
	/**
	 AirTurn has 'button' inputs. Examples include DIGITIII
	 */
	AirTurnInputTypeButton
};

/**
 Constants defining the AirTurn connection states
 */
typedef NS_ENUM(NSInteger, AirTurnConnectionState) {
    /**
     Unknown connection state
     */
    AirTurnConnectionStateUnknown = 0,
    /**
     The AirTurn is disconnecting
     */
    AirTurnConnectionStateDisconnecting,
    /**
     The AirTurn is disconnected
     */
    AirTurnConnectionStateDisconnected,
    /**
     The AirTurn is connecting
     */
    AirTurnConnectionStateConnecting,
    /**
     The AirTurn is connected to the system, but not the App
     */
    AirTurnConnectionStateSystemConnected,
    /**
     The AirTurn is being interrogated
     */
    AirTurnConnectionStateDiscovering,
    /**
     The AirTurn is ready to use with the App
     */
    AirTurnConnectionStateReady
};

/**
 Defines which features are available for a mode
 */
typedef NS_OPTIONS(uint16_t, AirTurnModeFeatures) {
    /**
     Digital port config is available for this mode
     */
    AirTurnModeFeaturesDigitalPortConfig = 1 << 0,
    /**
     Analog port config is available for this mode
     */
    AirTurnModeFeaturesAnalogPortConfig = 1 << 1,
    /**
     Proprietary output is available for this mode
     */
    AirTurnModeFeaturesProprietary = 1 << 2,
    /**
     Keyboard output is available for this mode
     */
    AirTurnModeFeaturesKeyboard = 1 << 3,
    /**
     Consumer output is available for this mode
     */
    AirTurnModeFeaturesConsumer = 1 << 4,
    /**
     Mouse output is available for this mode
     */
    AirTurnModeFeaturesMouse = 1 << 5,
    /**
     Joystick output is available for this mode
     */
    AirTurnModeFeaturesJoystick = 1 << 6,
    /**
     MIDI output is available for this mode
     */
    AirTurnModeFeaturesMIDI = 1 << 7,
	/**
	 A mask of mode features that represent port configuration types
	 */
	AirTurnModeFeaturesPortConfigurationTypesMask = AirTurnModeFeaturesKeyboard | AirTurnModeFeaturesConsumer | AirTurnModeFeaturesMouse | AirTurnModeFeaturesJoystick | AirTurnModeFeaturesMIDI
};

/**
 Defines which value has been written
 */
typedef NS_ENUM(NSInteger, AirTurnPeripheralWriteType) {
    /**
     The delay before repeat value has been written
     */
    AirTurnPeripheralWriteTypeDelayBeforeRepeat = 1,
    /**
     The repeat rate has been written
     */
    AirTurnPeripheralWriteTypeRepeatRate,
    /**
     The idle power off has been written
     */
    AirTurnPeripheralWriteTypeIdlePowerOff,
    /**
     The connection configuration has been written
     */
    AirTurnPeripheralWriteTypeConnectionConfiguration,
    /**
     The pairing method has been written
     */
    AirTurnPeripheralWriteTypePairingMethod,
	/**
	 The debounce time has been written
	 */
	AirTurnPeripheralWriteTypeDebounceTime,
};

/**
 Defines the Connection Configuration options
 */
typedef NS_ENUM(uint8_t, AirTurnPeripheralConnectionConfiguration){
    /**
     The connection will be optimised for power saving. Default.
     */
    AirTurnPeripheralConnectionConfigurationLowPower = 0,
    /**
     The connection will be optimised for responsiveness
     */
    AirTurnPeripheralConnectionConfigurationLowLatency = 1
};

/**
 Defines the charging states
 */
typedef NS_ENUM(uint8_t, AirTurnPeripheralChargingState) {
    /**
     The device is not connected to external power and is discharging
     */
    AirTurnPeripheralChargingStateDisconnectedDischarging,
    /**
     The device is connected to external power and is charging
     */
    AirTurnPeripheralChargingStateConnectedCharging,
    /**
     The device is connected to external power and is fully charged
     */
    AirTurnPeripheralChargingStateConnectedFullyCharged,
    /**
     The device is connected to external power and the battery is being validated before charging begins
     */
    AirTurnPeripheralChargingStateConnectedValidating,
    /**
     The device is connected to external power and a fault occurred during charging
     */
    AirTurnPeripheralChargingStateConnectedFault
};

/**
 Defines the features that are available on a peripheral above the base features
 */
typedef NS_OPTIONS(NSUInteger, AirTurnPeripheralFeaturesAvailable){
    /**
     Indicates connection speed configuration is available
     */
    AirTurnPeripheralFeaturesAvailableConnectionSpeedConfiguration = 1 << 0,
    /**
     Indicates OS key repeat configuration is available
     */
    AirTurnPeripheralFeaturesAvailableOSKeyRepeatConfiguration = 1 << 1,
    /**
     Indicates port configuration is available
     */
    AirTurnPeripheralFeaturesAvailablePortConfig = 1 << 2,
    /**
     Indicates analog is available
     */
    AirTurnPeripheralFeaturesAvailableAnalog = 1 << 3,
    /**
     Indicates pairing method configuration is available
     */
    AirTurnPeripheralFeaturesAvailablePairingMethod = 1 << 4,
	/**
	 Indicates extended port configuration is available
	 */
	AirTurnPeripheralFeaturesAvailableExtendedPortConfig = 1 << 5,
	/**
	 Indicates debounce time configuration is available
	 */
	AirTurnPeripheralFeaturesAvailableDebounceTime = 1 << 6,
};

/**
 Defines the central state
 */
typedef NS_ENUM(NSInteger, AirTurnCentralState) {
    /**
     Unknown central state
     */
    AirTurnCentralStateUnknown = 0,
    /**
     The central manager is resetting, wait for next state change...
     */
    AirTurnCentralStateResetting,
    /**
     Bluetooth low energy is not supported on this device
     */
    AirTurnCentralStateUnsupported,
    /**
     Bluetooth low energy is not authorised for this application
     */
    AirTurnCentralStateUnauthorized,
    /**
     Bluetooth is powered off
     */
    AirTurnCentralStatePoweredOff,
    /**
     AirTurn Central is disabled
     */
    AirTurnCentralStateDisabled,
    /**
     AirTurn Central is not connected to an AirTurn
     */
    AirTurnCentralStateDisconnected,
    /**
     AirTurn Central is connected
     */
    AirTurnCentralStateConnected
};

/**
 The pairing state between the central and peripheral
 */
typedef NS_ENUM(uint8_t, AirTurnPeripheralPairingState) {
    /**
     There is no pairing between the central and peripheral
     */
    AirTurnPeripheralPairingStateNotPaired,
    /**
     A pairing exists between the central and peripheral
     */
    AirTurnPeripheralPairingStatePaired
};

/**
 The pairing method the AirTurn is in
 */
typedef NS_ENUM(uint8_t, AirTurnPeripheralPairingMethod) {
    /**
     If the AirTurn is in 'Open method' it will not require pairing in mode 1, but will require it in other modes. It can pair with up to 8 devices, after which it will delete the pairing which has not been used for the longest period of time.
     */
    AirTurnPeripheralPairingMethodOpen,
    /**
     If the AirTurn is in 'Closed method' it will only pair with one device. Pairing is required in all modes.
     */
    AirTurnPeripheralPairingMethodClosed
};

/**
 A type for debounce time durations
 */
typedef uint16_t AirTurnPeripheralDebounceTime;

/**
 A type for analog values
 */
typedef int16_t AirTurnPeripheralAnalogValue;

/**
 The maximum possible analog value
 */
extern const AirTurnPeripheralAnalogValue AirTurnPeripheralAnalogValueMax;
/**
 The minimum possible analog value
 */
extern const AirTurnPeripheralAnalogValue AirTurnPeripheralAnalogValueMin;

/**
 Defines the max delay before repeat in seconds
 */
extern const uint8_t AirTurnPeripheralMaxDelayBeforeRepeatSeconds;
/**
 Defines the suggested default delay before repeat divisor value, for when delay before repeat is to be set non-zero but is currently zero
 */
extern const uint8_t AirTurnPeripheralDefaultDelayBeforeRepeat;
/**
 Defines the max repeat rate in seconds
 */
extern const uint8_t AirTurnPeripheralMaxRepeatRateSeconds;
/**
 Defines the suggested default repeat rate divisor value, for when repeat rate is to be set non-zero but is currently zero
 */
extern const uint8_t AirTurnPeripheralDefaultKeyRepeatRate;
/**
 Defines the suggested default key repeat enabled value
 */
extern const BOOL AirTurnPeripheralDefaultKeyRepeatEnabled;
/**
 Defines the suggested default OS key repeat enabled value
 */
extern const BOOL AirTurnPeripheralDefaultOSKeyRepeatEnabled;
/**
 Defines the suggested default idle power off value in seconds
 */
extern const uint16_t AirTurnPeripheralDefaultIdlePowerOff;
/**
 Defines the suggested default connection configuration value
 */
extern const AirTurnPeripheralConnectionConfiguration AirTurnPeripheralDefaultConnectionConfiguration;
/**
 Defines the maximum name length
 */
extern const NSUInteger AirTurnPeripheralMaxDeviceNameLength;
/**
 Defines the low battery level cut off
 */
extern const uint8_t AirTurnPeripheralLowBatteryLevel;
