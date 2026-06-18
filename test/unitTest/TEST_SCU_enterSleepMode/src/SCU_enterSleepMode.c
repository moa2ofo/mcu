#include "SCU_enterSleepMode_help.h"

/* FUNCTION TO TEST */
void SCU_enterSleepMode(void)
{
  /* Clear all wake-up status flags */
  PMU->WAKE_STS_CLR.reg = (uint32)0x1FF73F5u;
  /* Select HP_CLK as system clock */
  SCU->CLKSEL.bit.SELSYS0 = 0u;
  SCU->CLKSEL.bit.SELSYS1 = 0u;
  /* Disable XTAL_OSC */
  SCU->XTALCON.bit.XPD = 1u;
  /* Disable all interrupts */
  CPU->NVIC_ICER.reg = (uint32)0xFFFFFFFFu;
  /* Enter Sleep mode */
  SCU->PMCON0.bit.SLEEP = 1u;
  /* Set send event */
  CMSIS_SEV();
  /* Clear send event */
  CMSIS_WFE();
  /* Enter CPU Deep Sleep */
  CMSIS_WFE();
}