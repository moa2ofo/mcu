#ifndef TEST_PMU_SERVICEFAILSAFEWATCHDOGSOW_HELP_H
#define TEST_PMU_SERVICEFAILSAFEWATCHDOGSOW_HELP_H

#include "PMU_serviceFailSafeWatchdogSOW.h"
#include <stddef.h>
#include <string.h>

/* static globals (copied) */
static bool b_SOWactive = false;
_Bool get_b_SOWactive(void) { return b_SOWactive; }
void set_b_SOWactive(_Bool val) { b_SOWactive = val; }

#endif /* TEST_PMU_SERVICEFAILSAFEWATCHDOGSOW_HELP_H */
