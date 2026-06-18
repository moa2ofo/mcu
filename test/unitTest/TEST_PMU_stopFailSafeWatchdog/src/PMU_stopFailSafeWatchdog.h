#ifndef TEST_PMU_STOPFAILSAFEWATCHDOG_H
#define TEST_PMU_STOPFAILSAFEWATCHDOG_H

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

/** \brief Stop the fail-safe watchdog
 */
void PMU_stopFailSafeWatchdog(void);


#endif /* TEST_PMU_STOPFAILSAFEWATCHDOG_H */
