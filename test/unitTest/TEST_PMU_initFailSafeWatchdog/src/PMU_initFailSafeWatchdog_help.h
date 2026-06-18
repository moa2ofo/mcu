#ifndef TEST_PMU_INITFAILSAFEWATCHDOG_HELP_H
#define TEST_PMU_INITFAILSAFEWATCHDOG_HELP_H

#include "PMU_initFailSafeWatchdog.h"
#include <stddef.h>
#include <string.h>

/* static globals (copied) */
static volatile uint32 u32_failsafeWatchdogCnt;
volatile uint32 get_u32_failsafeWatchdogCnt(void) { return u32_failsafeWatchdogCnt; }
void set_u32_failsafeWatchdogCnt(volatile uint32 val) { u32_failsafeWatchdogCnt = val; }

#endif /* TEST_PMU_INITFAILSAFEWATCHDOG_HELP_H */
