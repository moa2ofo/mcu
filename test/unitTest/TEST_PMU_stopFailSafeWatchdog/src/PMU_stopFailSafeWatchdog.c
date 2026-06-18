#include "PMU_stopFailSafeWatchdog_help.h"

/* FUNCTION TO TEST */
void PMU_stopFailSafeWatchdog(void)
{
  /* Disable the SysTick Timer */
  CPU->SYSTICK_CS.bit.ENABLE = 0u;
}