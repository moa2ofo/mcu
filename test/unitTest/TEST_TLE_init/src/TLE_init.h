#ifndef TEST_TLE_INIT_H
#define TEST_TLE_INIT_H

#include "RTE_Components.h"
#include "cantrx_defines.h"
#include "dma_defines.h"
#include "gpio_defines.h"
#include "isr_defines.h"
#include "pmu_defines.h"
#include "scu_defines.h"
#include "uart_defines.h"
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

/** \brief Initialize all modules of the device
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 TLE_init(void);


#endif /* TEST_TLE_INIT_H */
