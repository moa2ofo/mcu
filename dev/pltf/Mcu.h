#ifndef MCU_H
#define MCU_H

#include <stdint.h>

void Mcu_Initialize(void);
void Mcu_ServiceWatchdog(void); // Must be called periodically with a period between 19.2 and 27.2 ms */
void Mcu_ServiceWatchdogSow(void);
void Mcu_ReloadSystick(void);
uint32_t Mcu_GetSystemTime_u32(void);

/************* example code *************/
void toggle_led(void);
/****************************************/

#endif // MCU_H
