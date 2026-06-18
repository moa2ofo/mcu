#include "Mcu_ReloadSystick_help.h"

/* FUNCTION TO TEST */
void Mcu_ReloadSystick(void)
{
  /* Reset the SysTick current value */
  CPU->SYSTICK_CUR.reg = 0u;

  /* Reset Mcu_GetSystemTime_u32 */
  u32_globTimestamp_ms = 0u;
}