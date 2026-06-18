#ifndef TEST_PMU_SERVICEFAILSAFEWATCHDOG_HELP_H
#define TEST_PMU_SERVICEFAILSAFEWATCHDOG_HELP_H

#include "PMU_serviceFailSafeWatchdog.h"
#include <stddef.h>
#include <string.h>

/* static globals (copied) */
static bool b_SOWactive = false;
_Bool get_b_SOWactive(void) { return b_SOWactive; }
void set_b_SOWactive(_Bool val) { b_SOWactive = val; }
static volatile uint32 u32_failsafeWatchdogCnt;
volatile uint32 get_u32_failsafeWatchdogCnt(void) { return u32_failsafeWatchdogCnt; }
void set_u32_failsafeWatchdogCnt(volatile uint32 val) { u32_failsafeWatchdogCnt = val; }

#endif /* TEST_PMU_SERVICEFAILSAFEWATCHDOG_HELP_H */
