#ifndef TEST_MCU_GETSYSTEMTIME_U32_H
#define TEST_MCU_GETSYSTEMTIME_U32_H

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
 * @brief Get the current system time in milliseconds.
 *
 * This function returns the current value of the global millisecond timestamp.
 *
 * @pre The timestamp variable shall be updated by the system time base.
 *
 * @return Current system time in milliseconds.
 */
uint32_t Mcu_GetSystemTime_u32(void);


#endif /* TEST_MCU_GETSYSTEMTIME_U32_H */
