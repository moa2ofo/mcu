#include "SysTick_Handler_help.h"

/* FUNCTION TO TEST */
void SysTick_Handler(void)
{
#if (CPU_SYSTICK_EN == 1)
  CPU_SYSTICK_CALLBACK();
#endif /*(CPU_SYSTICK_EN == 1)*/
  u32_globTimestamp_ms++;
  PMU_countFailSafeWatchdog();
}