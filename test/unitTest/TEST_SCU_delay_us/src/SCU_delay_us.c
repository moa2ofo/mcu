#include "SCU_delay_us_help.h"

/* FUNCTION TO TEST */
void SCU_delay_us(uint32 u32_time_us)
{
  uint32 u32_systickTargetVal;
  uint32 u32_systickVal;
  uint32 u32_delayCnt;
  uint32 u32_systickCur;
  uint32 u32_systickRelVal;
  /* Get current systick value */
  u32_systickRelVal = SCU_getSysTickRelVal();

  /* Adapt systick value into range SYSTICK_DELAY_THRESHOLD...reload value-SYSTICK_DELAY_THRESHOLD to avoid getting stuck in a while, wait in case needed */
  do
  {
    u32_systickVal = SCU_getSysTickCntVal();
  }
  while ((u32_systickVal < SYSTICK_DELAY_THRESHOLD) || (u32_systickVal > (u32_systickRelVal - SYSTICK_DELAY_THRESHOLD)));

  while (u32_time_us >= (uint32)1000)
  {
    /* Wait for underflow */
    while (SCU_getSysTickCntVal() < u32_systickVal)
    {}

    /* Wait target underflowed */
    while (SCU_getSysTickCntVal() > u32_systickVal)
    {}

    u32_time_us -= (uint32)1000;
  }

  u32_delayCnt = u32_time_us * (uint32)MULTIPLIER_US_TO_TICKS;
  /* Adapt systick value into range SYSTICK_DELAY_THRESHOLD...reload value-SYSTICK_DELAY_THRESHOLD to avoid getting stuck in a while, wait in case needed */
  u32_systickVal = SCU_getSysTickCntVal();

  if (u32_systickVal >= u32_delayCnt)
  {
    u32_systickTargetVal = u32_systickVal - u32_delayCnt;

    /* Wait underflow with 1 countdown detection */
    do
    {
      u32_systickCur = SCU_getSysTickCntVal();
    }
    while ((u32_systickCur > u32_systickTargetVal) && (u32_systickCur < u32_systickVal));
  }
  else
  {
    u32_systickTargetVal = SCU_getSysTickRelVal() - (u32_delayCnt - u32_systickVal);

    /* Wait for underflow */
    while (SCU_getSysTickCntVal() < u32_systickVal)
    {}

    /* Wait target underflowed */
    while (SCU_getSysTickCntVal() > u32_systickTargetVal)
    {}
  }

  return;
}