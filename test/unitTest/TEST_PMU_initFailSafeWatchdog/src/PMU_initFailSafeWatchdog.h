#ifndef TEST_PMU_INITFAILSAFEWATCHDOG_H
#define TEST_PMU_INITFAILSAFEWATCHDOG_H

#include "RTE_Components.h"
#include "pmu_defines.h"
#include "scu_defines.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "cmsis_misra.h"
#include "cmsis_version.h"
#include "core_cm3.h"
#include "error_codes.h"
#include "pmu.h"
#include "system_tle989x.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "types.h"

/** \brief Initialize the fail-safe watchdog
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 PMU_initFailSafeWatchdog(void);

volatile uint32 get_u32_failsafeWatchdogCnt(void);
void set_u32_failsafeWatchdogCnt(volatile uint32 val);

#endif /* TEST_PMU_INITFAILSAFEWATCHDOG_H */
