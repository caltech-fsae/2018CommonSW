#ifndef IDENTIFIERS_H_
#define IDENTIFIERS_H_

#include <stdint.h>

// Identifiers will contain 7 message type bits followed by 4 board identifier bits

static const uint16_t BID_BMS_MASTER = 0x0000;
static const uint16_t BID_SHUTDOWN = 0x0001;
static const uint16_t BID_MOTOR_CONTROLLER = 0x0002;
static const uint16_t BID_IO = 0x0003;
static const uint16_t BID_CORE = 0x0004;

// Motor Controller Message Types
/* FAULT_NR
 * FAULT
 * ACKNOWLEDGE
 * Speed
 * MC_Status (temp, etc...)
 * HEARTBEAT
 * Torque_Status (REQUESTED_APPLIED)
 * Battery_Current
 */

// BMS Master Message Types
/* FAULT_NR
 * FAULT
 * ACKNOWLEDGE
 * HEARTBEAT
 * Precharge_Status
 * AIR_STATUS (REQUESTED_APPLIED)
 * Battery_Voltage
 * Battery_Temperature
 */

// IO Board Message Types
/* FAULT_NR
 * FAULT
 * ACKNOWLEDGE
 * HEARTBEAT
 * Throttle
 * Brake
 * Throttle_Pressed
 * Brake_Pressed
 * Throttle_MSM (mismatch)
 * Brake_MSM (mismatch)
 * BPPC
 */

 // Core Board Message Types
 /* FAULT_NR
  * FAULT
  * ACKNOWLEDGE
  * HEARTBEAT
  * Torque_Command
  * Car_status
  * Reset_Faults
  * Start_Drive
  * End_Drive
  */


// Shutdown Board Message Types
/* FAULT_NR
 * FAULT
 * ACKNOWLEDGE
 * FAULT_STATUS (BSPD, AMS, IMD)
 * INTERLOCK_STATUS
 */


// FAULTS (0x0000 - 0x000A) ////////////////////////////////////////////////////////////////////
static const uint16_t MID_FAULT_NR            = 0x0000 << 4;
static const uint16_t MID_FAULT               = 0x0001 << 4;
static const uint16_t MID_HEARTBEAT           = 0x0002 << 4;
static const uint16_t MID_THROTTLE_MSM        = 0x0008 << 4;
static const uint16_t MID_BRAKE_MSM           = 0x0009 << 4;
// Cause of fault: sent from core board, provides reason car entered fault state.
//                 (Shutdown also will broadcast, but in case the fault is because
//                 shutdown went offline and cannot send that message)
///// Resettable Faults (bits 8 - 15) /////
// Bit 8: BPPC      fault (YES/NO)
///// Nonresettable Fault (bits 0 - 7) ////
// Bit 5: HEARTBEAT fault (YES/NO)
// Bit 4: IMD       fault (YES/NO)
// Bit 3: BSPD      fault (YES/NO)
// Bit 2: APPS      fault (YES/NO)
// Bit 1: BSE       fault (YES/NO)
// Bit 0: BMS       fault (YES/NO)
// Generic NR fault if no bits set, Generic R fault if all bits set
static const uint16_t MID_FAULT_CAUSE         = 0x000A << 4;
static const uint16_t MID_BPPC_BSPD			  = 0x000B << 4;

// CONTROL (0x000B - 0x001B) ///////////////////////////////////////////////////////////////////
static const uint16_t MID_ACKNOWLEDGE         = 0x000C << 4;
static const uint16_t MID_END_DRIVE           = 0x000D << 4;
static const uint16_t MID_TORQUE_COMMAND      = 0x000E << 4;
static const uint16_t MID_THROTTLE            = 0x000F << 4;
static const uint16_t MID_BRAKE               = 0x0010 << 4;
static const uint16_t MID_START_DRIVE         = 0x0011 << 4;
static const uint16_t MID_RESET_FAULTS        = 0x0012 << 4;
static const uint16_t MID_REDUCE_PWR          = 0x0013 << 4;

// FEEDBACK (0x002B - 0x004B) //////////////////////////////////////////////////////////////////
static const uint16_t MID_PRECHARGE_STATUS    = 0x002B << 4;
static const uint16_t MID_AIR_STATUS          = 0x002C << 4;
// Car state: sent from core board. Can only be in one state, bit set to 1 if in that state.
//  Message contents:
//   Bit 5: NO_RST_FAULT   - non-resettable fault state
//   Bit 4: RST_FAULT      - resettable fault state
//   Bit 3: DRIVE          - normal driving state
//   Bit 2: START_BRAKE    - waiting for driver start sequence start button
//   Bit 1: WAIT_DRIVER    - waiting for driver start sequence brake
//   Bit 0: WAIT_HEARTBEAT - waiting for all other boards to send a heartbeat
static const uint16_t MID_CAR_STATE           = 0x002D << 4;

// Fault status: sent from shutdown board. Message contents:
// Bit 6: battery fault (YES/NO)
// Bit 5: interlock fault (YES/NO)
// Bit 4: generic flt fault (YES/NO)
// Bit 3: generic flt_nr fault (YES/NO)
// Bit 2: IMD fault (YES/NO)
// Bit 1: AMS fault (YES/NO)
// Bit 0: BSPD fault (YES/NO)
static const uint16_t MID_FAULT_STATUS        = 0x002E << 4;

// Interlock status: do not use. Check bit 5 of fault status instead.
static const uint16_t MID_INTERLOCK_STATUS    = 0x002F << 4;
static const uint16_t MID_MC_STATUS           = 0x0030 << 4;
static const uint16_t MID_THROTTLE_PRESSED    = 0x0031 << 4;
static const uint16_t MID_BRAKE_PRESSED       = 0x0032 << 4;
static const uint16_t MID_SPEED               = 0x0033 << 4;
static const uint16_t MID_BATTERY_TEMPERATURE = 0x0034 << 4;
static const uint16_t MID_BATTERY_VOLTAGE     = 0x0035 << 4;
static const uint16_t MID_BATTERY_CURRENT     = 0x0036 << 4;
static const uint16_t MID_TORQUE_STATUS       = 0x0037 << 4;

#endif /* IDENTIFIERS_H_ */
