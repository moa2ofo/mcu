#ifndef TEST_MCU_INITIALIZE_H
#define TEST_MCU_INITIALIZE_H

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
 * @brief Initialize the MCU-related hardware services.
 *
 * This function performs the MCU startup initialization sequence handled by this
 * module.
 *
 * The implementation performs the following actions:
 * - Clears the fail-safe watchdog fail status.
 * - Initializes the hardware modules according to the Config Wizard setup.
 * - Clears fail-safe and safe shutdown status registers to release the safe
 *   shutdown mechanism.
 *
 * @pre The low-level device registers and startup environment shall be available.
 *
 * @post The configured hardware modules are initialized.
 * @post The fail-safe watchdog fail status is cleared.
 * @post The safe shutdown mechanism is released when all related status bits are
 *       cleared.
 *
 * @return None.
 */
void Mcu_Initialize(void);


#endif /* TEST_MCU_INITIALIZE_H */
