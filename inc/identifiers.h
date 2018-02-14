// Identifiers will contain 7 message type bits followed by 4 board identifier bits

static const uint16_t = BID_BMS_MASTER = 0x0000;
static const uint16_t = BID_SHUTDOWN = 0x0001;
static const uint16_t = BID_MOTOR_CONTROLLER = 0x0002;
static const uint16_t = BID_IO = 0x0003;
static const uint16_t = BID_CORE = 0x0004;

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


// Faults (0x0000 - 0x000A)
static const uint16_t FAULT_NR = 0x0000 << 4;
static const uint16_t FAULT = 0x0001 << 4;
static const uint16_t HEARTBEAT = 0x0002 << 4;

static const uint16_t THROTTLE_MSM  = 0x0009 << 4;
static const uint16_t BRAKE_MSM = 0x000A << 4;

// Control (0x000B - 0x001B)
static const uint16_t ACKNOWLEDGE = 0x000B << 4;
static const uint16_t END_DRIVE = 0x000C << 4;
static const uint16_t TORQUE_COMMAND = 0x000D << 4;
static const uint16_t THROTTLE = 0x000E << 4;
static const uint16_t BRAKE = 0x000F << 4;
static const uint16_t START_DRIVE = 0x0010 << 4;
static const uint16_t RESET_FAULTS = 0x0011 << 4;

// Feedback (0x002B - 0x004B)
static const uint16_t PRECHARGE_STATUS = 0x002B << 4;
static const uint16_t AIR_STATUS = 0x002C << 4;
static const uint16_t CAR_STATUS = 0x002D << 4; 
static const uint16_t FAULT_STATUS = 0x002E << 4;
static const uint16_t INTERLOCK_STATUS = 0x002F << 4;
static const uint16_t MC_STATUS = 0x0030 << 4;
static const uint16_t THROTTLE_PRESSED = 0x0031 << 4;
static const uint16_t BRAKE_PRESSED = 0x0032 << 4;
static const uint16_t SPEED = 0x0033 << 4;
static const uint16_t BATTERY_TEMPERATURE = 0x0034 << 4;
static const uint16_t BATTERY_VOLTAGE = 0x0035 << 4;
static const uint16_t BATTERY_CURRENT = 0x0036 << 4;
static const uint16_t TORQUE_STATUS = 0x0037 << 4;