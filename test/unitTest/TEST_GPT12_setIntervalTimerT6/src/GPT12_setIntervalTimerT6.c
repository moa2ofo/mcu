#include "GPT12_setIntervalTimerT6_help.h"

/* FUNCTION TO TEST */
sint8 GPT12_setIntervalTimerT6(uint32 u32_timeInterval_us)
{
  sint8 s8_returnCode;
  uint64 u64_timeInterval_ticks;
  /* Calculate T6 individual prescaler: as long as u64_timeInterval_ticks is larger than
   * the T6 value register (16 bits), the individual prescaler value is incremented
   * and u64_timeInterval_ticks is divided by 2 */
  uint8 u8_T6ClkPrescaler = 0u;
  s8_returnCode = ERR_LOG_SUCCESS;
  /* Calculate time interval in ticks */
  u64_timeInterval_ticks = (uint64)(((uint64)u32_timeInterval_us * (uint64)fGPT2_HZ) / (uint64)1000000U);

  while (u64_timeInterval_ticks > (uint64)0xFFFFu)
  {
    u8_T6ClkPrescaler++;
    u64_timeInterval_ticks >>= 1u;
  }

  /* The individual prescaler maximal value is 0b111 */
  if (u8_T6ClkPrescaler <= 7u)
  {
    /* Set T6 mode as Timer mode */
    GPT12->T6CON.bit.T6M = 0u;
    /* Set the calculated T6 individual prescaler */
    GPT12->T6CON.bit.T6I = (uint8)u8_T6ClkPrescaler;
    /* Disable external up/down count control */
    GPT12->T6CON.bit.T6UDE = 0u;
    /* Select down counting */
    GPT12->T6CON.bit.T6UD = 1u;
    /* Set u64_timeInterval_ticks as T6 value */
    GPT12->T6.bit.T6 = (uint16)u64_timeInterval_ticks;
    /* Set u64_timeInterval_ticks as CAPREL reload value */
    GPT12->CAPREL.bit.CAPREL = (uint16)u64_timeInterval_ticks;
    /* Set T6OTL as reload trigger for T5 */
    GPT12->T6CON.bit.T6OTL = 1u;
    /* Enable T6 reload by CAPREL */
    GPT12->T6CON.bit.T6SR = 1u;
  }
  else /* Arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}