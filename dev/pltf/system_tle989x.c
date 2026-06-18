/*
 ***********************************************************************************************************************
 *
 * Copyright (c) Infineon Technologies AG
 * All rights reserved.
 *
 * The applicable license agreement can be found at this pack's installation directory in the file
 * license/IFX_SW_Licence_MOTIX_LITIX.txt
 *
 **********************************************************************************************************************/

/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/

#include "system_tle989x.h"
#include "pmu.h"
#include "scu.h"
#include "tle989x.h"
#include "tle_variants.h"

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

/** \brief Initialize the system
 */
void SystemInit(void) {
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
