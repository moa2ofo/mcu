#include "SCU_initSysTick_help.h"

/* FUNCTION TO TEST */
void SCU_initSysTick(uint32 u32_value)
{
  /* Program the SysTick reload value */
  CPU->SYSTICK_RL.reg = u32_value;
  /* Reset the SysTick current value */
  CPU->SYSTICK_CUR.reg = (uint32)0u;
  /* Define the SysTick timer clock as the CPU clock */
  CPU->SYSTICK_CS.bit.CLKSOURCE = 1u;
  /* Enable the SysTick exception request */
  CPU->SYSTICK_CS.bit.TICKINT = 1u;
  /* Enable the SysTick counter */
  CPU->SYSTICK_CS.bit.ENABLE = 1u;
}