#include "SystemInit_help.h"

/* FUNCTION TO TEST */
void SystemInit(void)
{
  /* SysTick is needed for SCU_initClk, so configure the Systick based on the HP40_Clk (used by default) */
  SCU_initSysTick(CPU_SYSTICK_RL_RELOAD_HP40_CLK);
  /* Initialize clock */
  (void)SCU_initClk();
  /* Initialize SysTick to 1ms based on CPU clock */
  SCU_initSysTick(CPU_SYSTICK_RL);
#if defined SYSTEMINIT_FSWD_INIT && (SYSTEMINIT_FSWD_INIT == 1u)
  /* Initialize Fail safe Watchdog */
  (void)PMU_initFailSafeWatchdog();
#endif
}