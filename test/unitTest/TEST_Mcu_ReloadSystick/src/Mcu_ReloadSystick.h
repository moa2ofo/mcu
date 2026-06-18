#ifndef TEST_MCU_RELOADSYSTICK_H
#define TEST_MCU_RELOADSYSTICK_H

#include "RTE_Components.h"
#include "gpio_defines.h"
#include "isr_defines.h"
#include "pmu_defines.h"
#include "scu_defines.h"
#include "Mcu.h"
#include "bootrom.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "cmsis_misra.h"
#include "cmsis_version.h"
#include "core_cm3.h"
#include "error_codes.h"
#include "gpio.h"
#include "isr.h"
#include "pmu.h"
#include "system_tle989x.h"
#include "tle989x.h"
#include "tle_device.h"
#include "tle_variants.h"
#include "types.h"

/**
 * @brief Reload the SysTick counter and reset the module timestamp.
 *
 * This function resets the current SysTick counter value and clears the global
 * millisecond timestamp used by Mcu_GetSystemTime_u32().
 *
 * @pre The CPU SysTick register interface shall be available.
 *
 * @post The SysTick current value register is reset to 0.
 * @post The global millisecond timestamp is reset to 0.
 *
 * @return None.
 */
void Mcu_ReloadSystick(void);


#endif /* TEST_MCU_RELOADSYSTICK_H */
