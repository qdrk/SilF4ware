#include "defines.h"

// PID values in pid.c

// rate in deg/sec for acro mode
#define MAX_RATE 1800
#define MAX_RATEYAW 1800

// max angle for level mode
#define LEVEL_MAX_ANGLE 80

// max rate used by level pid (limit)
#define LEVEL_MAX_RATE 1800

#define LOW_RATES_MULTI 0.5

// Change this factor to get a correct battery voltage.
#define ADC_SCALEFACTOR 11.167 // 11.0 for an ideal 10k/1k voltage divider

// Make sure to understand CELL_COUNT_UNSCALED in battery.c before enabling this.
#define BATTERY_CELL_COUNT_DETECTION

// Do not start software if battery is too low. Flashes 2 times repeatedly at startup.
// #define STOP_LOWBATTERY // If below 3.3 Volt

// If enabled, start LED blinking at low battery voltage
#define WARN_ON_LOW_BATTERY 3.6 // Volt

// Voltage hysteresis for WARN_ON_LOW_BATTERY
#define VOLTAGE_HYSTERESIS 0.10 // Volt

// compensation for battery voltage vs throttle drop
#define VDROP_FACTOR 0.7
// calculate above factor automatically
#define AUTO_VDROP_FACTOR

// lower throttle when battery below threshold
#define LVC_LOWER_THROTTLE
#define LVC_LOWER_THROTTLE_VOLTAGE 3.30
#define LVC_LOWER_THROTTLE_VOLTAGE_RAW 2.70
#define LVC_LOWER_THROTTLE_KP 3.0

// on-chip Gyro LPF filter frequency
// gyro filter 0 = 250hz delay 0.97mS (use this to get 8k gyro update frequency)
// gyro filter 1 = 184hz delay 2.9mS
// gyro filter 2 = 92hz delay 3.9mS
// gyro filter 3 = 41hz delay 5.9mS
#define GYRO_LOW_PASS_FILTER 0

// Software Gyro Filters

#define BIQUAD_NOTCH_A_HZ 200
#define BIQUAD_NOTCH_A_Q 6

// #define BIQUAD_NOTCH_B_HZ BIQUAD_NOTCH_A_HZ * 3
// #define BIQUAD_NOTCH_B_Q BIQUAD_NOTCH_A_Q

// #define BIQUAD_NOTCH_C_HZ BIQUAD_NOTCH_A_HZ * 6
// #define BIQUAD_NOTCH_C_Q BIQUAD_NOTCH_A_Q

// #define DYNAMIC_LPF_1ST_HZ // Raises filter frequency with throttle.
// #define DYNAMIC_LPF_1ST_HZ_BASE 400 // Filter frequency at zero throttle.
// #define DYNAMIC_LPF_1ST_HZ_MAX 400 // A higher filter frequency than loopfrequency/3 causes ripples.
// #define DYNAMIC_LPF_1ST_HZ_THROTTLE 0.25 // MAX reached at 1/4 throttle.

#define DYNAMIC_LPF_2ND_HZ
#define DYNAMIC_LPF_2ND_HZ_BASE 400 * ( aux[ FN_INVERTED ] ? 0.75f : 1.0f )
#define DYNAMIC_LPF_2ND_HZ_MAX 400
#define DYNAMIC_LPF_2ND_HZ_THROTTLE 0.25

// D-Term second order LPF (cannot be turned off)
#define DYNAMIC_DTERM_LPF_2ND_HZ_BASE 80 * ( aux[ FN_INVERTED ] ? 0.75f : 1.0f )
#define DYNAMIC_DTERM_LPF_2ND_HZ_MAX 120
#define DYNAMIC_DTERM_LPF_2ND_HZ_THROTTLE 0.5

// If enabled, the D-Term filter uses the LP filtered gyro signal from above. (Notch filters are always applied.)
// #define CASCADE_GYRO_AND_DTERM_FILTER

// Switch function selection

#define RATES DEVO_CHAN_9 // LOW_RATES_MULTI gets applied when RATES is 0.

#define LEVELMODE DEVO_CHAN_10

#define LEDS_ON DEVO_CHAN_7

// To stop the motors on ground a switch on the remote control is necessary.
#define THROTTLE_KILL_SWITCH DEVO_CHAN_5

// enable inverted (3D) flight code (brushless only)
#define INVERTED_ENABLE
#define FN_INVERTED DEVO_CHAN_6 // for brushless only

// Two switchable channels via gestures: CH_AUX1 and CH_AUX2
// Channel CH_AUX1 changed via gestures LLU -> 1 and LLD -> 0
// Channel CH_AUX2 changed via gestures RRU -> 1 and RRD -> 0
// #define AUX1_START_ON // CH_AUX1 channel starts on if this is defined, otherwise off.
// #define AUX2_START_ON // CH_AUX2 channel starts on if this is defined, otherwise off.

// lost quad beeps using motors (60 sec timeout)
#define MOTOR_BEEPS
#define MOTOR_BEEPS_CHANNEL DEVO_CHAN_12

// Send maximum measured g-force in the telemetry data.
#define DISPLAY_MAX_G_INSTEAD_OF_VOLTAGE

// Radio module and protocol selection (only Bayang protocol implemented)
#define RX_BAYANG_PROTOCOL_TELEMETRY // For XN297 radio module harvested from toy TX
// #define RX_NRF24_BAYANG_TELEMETRY // For nRF24L01+ radio module

// led brightness 0 .. 15 (used for solid lights only)
#define LED_BRIGHTNESS 15

// Comment out to disable pid tuning gestures
#define PID_GESTURE_TUNING
#define COMBINE_PITCH_ROLL_PID_TUNING

// a filter which makes throttle feel faster (aka Throttle Boost) (not active in LOW_RATES)
#define THROTTLE_TRANSIENT_COMPENSATION_FACTOR 3.0

// For smoother motor reversing in 3D flight
#define THROTTLE_REVERSING_KICK 0.1f

// Add linear interpolation between the otherwise 5 ms staircase steps of the RX signal
#define RX_SMOOTHING

// Betaflight like mix scaling
#define MIX_SCALING
// Mix increasing yields a more crisp response but also a more jumpy quad at low RPM
#define ALLOW_MIX_INCREASING

// Use a square root motor curve to counteract thrust ~ RPM^2
// 0.0f .. no compensation, 1.0f .. full square root curve
#define THRUST_LINEARIZATION 0.5f

// A deadband can be used to eliminate stick center jitter and non-returning to exactly 0.
#define STICKS_DEADBAND 0.02f

// throttle direct to motors for thrust measure
// #define MOTORS_TO_THROTTLE

// throttle direct to motors for thrust measure as a flight mode
#define MOTORS_TO_THROTTLE_MODE CH_AUX1

// Compensate PID values for sagging battery voltage
#define PID_VOLTAGE_COMPENSATION

// Invert yaw pid. Necessary when spinning props outwards.
#define INVERT_YAW_PID

// Rotate I-term vector for a stable yaw axis (aka iTerm Rotation)
#define PID_ROTATE_ERRORS

// Removes roll and pitch bounce back after flips (aka iTerm Relax)
#define TRANSIENT_WINDUP_PROTECTION

// Feed fast roll/pitch-stick changes directly to the motors to give a snappier response
// 0.0f (or commented out) equates D-term on measurement, 1.0f equates D-term on error.
#define FEED_FORWARD_STRENGTH 1.0f
//#define SMART_FF

// loop time in us
#define LOOPTIME 125

// failsafe time in us. Shut motors down after FAILSAFETIME no RX signal.
#define FAILSAFETIME 1000000 // one second

// Gyro orientation:
// The expected orientation is with the dot on the chip in the front-left corner.
// Specify by how much you have to rotate the board so that the dot is front left.
// The rotations are performed in order and cumulated.
// Note, the motors don't get rotated, so they have to be referenced to the new gyro position.
//#define SENSOR_ROTATE_45_CCW
//#define SENSOR_ROTATE_45_CW
//#define SENSOR_ROTATE_90_CW
//#define SENSOR_ROTATE_90_CCW
#define SENSOR_ROTATE_180
//#define SENSOR_FLIP_180 // Flip is forward. If you want to flip sideways then you have to FLIP_180 and ROTATE_180.

// Motor order
#define MOTOR_BL 2
#define MOTOR_FL 1
#define MOTOR_BR 4
#define MOTOR_FR 3

// Disable the check for known gyro that causes the 4 times LED flash.
#define GYRO_CHECK

// Disable the check for development without RX module (3 times LED flash).
#define RADIO_CHECK

#define RADIO_XN297