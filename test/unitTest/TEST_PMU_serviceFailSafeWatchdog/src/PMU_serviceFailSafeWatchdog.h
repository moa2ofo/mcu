#ifndef TEST_PMU_SERVICEFAILSAFEWATCHDOG_H
#define TEST_PMU_SERVICEFAILSAFEWATCHDOG_H

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

/** \brief Service the fail-safe watchdog
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 PMU_serviceFailSafeWatchdog(void);

_Bool get_b_SOWactive(void);
void set_b_SOWactive(_Bool val);
volatile uint32 get_u32_failsafeWatchdogCnt(void);
void set_u32_failsafeWatchdogCnt(volatile uint32 val);

#endif /* TEST_PMU_SERVICEFAILSAFEWATCHDOG_H */
