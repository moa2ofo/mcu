#ifndef TEST_MCU_SERVICEWATCHDOG_H
#define TEST_MCU_SERVICEWATCHDOG_H

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
 * @brief Service the main fail-safe watchdog.
 *
 * This function services the watchdog by toggling the watchdog trigger bit.
 *
 * It shall be called periodically within the allowed watchdog service window.
 * Based on the current configuration, the expected call period is between
 * 19.2 ms and 27.2 ms.
 *
 * @pre Mcu_Initialize() shall have been executed before this function is used
 *      in normal runtime operation.
 *
 * @post The main watchdog trigger bit is toggled.
 *
 * @return None.
 */
void Mcu_ServiceWatchdog(void);


#endif /* TEST_MCU_SERVICEWATCHDOG_H */
