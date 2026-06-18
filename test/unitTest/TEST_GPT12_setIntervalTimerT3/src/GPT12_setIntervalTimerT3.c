#include "GPT12_setIntervalTimerT3_help.h"

/* FUNCTION TO TEST */
sint8 GPT12_setIntervalTimerT3(uint32 u32_timeInterval_us)
{
  sint8 s8_returnCode;
  uint64 u64_timeInterval_ticks;
  /* Calculate T3 individual prescaler: as long as u64_timeInterval_ticks is larger than
   * the T3 value register (16 bits), the individual prescaler value is incremented
   * and u64_timeInterval_ticks is divided by 2 */
  uint8 u8_T3ClkPrescaler = 0u;
  s8_returnCode = ERR_LOG_SUCCESS;
  /* Calculate time interval in ticks */
  u64_timeInterval_ticks = (uint64)(((uint64)u32_timeInterval_us * (uint64)fGPT1_HZ) / (uint64)1000000U);

  while (u64_timeInterval_ticks > (uint64)0xFFFFu)
  {
    u8_T3ClkPrescaler++;
    u64_timeInterval_ticks >>= 1u;
  }

  /* The individual prescaler maximal value is 0b111 */
  if (u8_T3ClkPrescaler <= 7u)
  {
    /* Set T3 mode as Timer mode */
    GPT12->T3CON.bit.T3M = 0u;
    /* Set the calculated T3 individual prescaler */
    GPT12->T3CON.bit.T3I = (uint8)u8_T3ClkPrescaler;
    /* Disable external up/down count control */
    GPT12->T3CON.bit.T3UDE = 0u;
    /* Select down counting */
    GPT12->T3CON.bit.T3UD = 1u;
    /* Set u64_timeInterval_ticks as T3 value */
    GPT12->T3.bit.T3 = (uint16)u64_timeInterval_ticks;
    /* Set T2 mode as Reload mode */
    GPT12->T2CON.bit.T2M = 4u;
    /* Set u64_timeInterval_ticks as T2 reload value */
    GPT12->T2.bit.T2 = (uint16)u64_timeInterval_ticks;
    /* Set T3OTL as reload trigger for T2 */
    GPT12->T3CON.bit.T3OTL = 1u;
    /* Set T2 to trigger reload every T3OTL toggle, for rising and falling edge */
    GPT12->T2CON.bit.T2I = 7u;
  }
  else /* Arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}