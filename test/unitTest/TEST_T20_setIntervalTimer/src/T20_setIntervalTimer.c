#include "T20_setIntervalTimer_help.h"

/* FUNCTION TO TEST */
sint8 T20_setIntervalTimer(uint32 u32_timeInterval_us)
{
  sint8 s8_returnCode;
  uint64 u64_timeInterval_ticks;
  /* T20 frequency in Hz */
  uint32 u32_T20Freq_MHz = (uint32)fT20;
  /* Calculate T20 individual prescaler: as long as u64_timeInterval_ticks is larger than
   * the T20 value register (16 bits), the individual prescaler value is incremented
   * and u64_timeInterval_ticks is divided by 2 */
  uint8 u8_T20ClkPrescaler = 0u;
  s8_returnCode = ERR_LOG_SUCCESS;
  /* Calculate time interval in ticks */
  u64_timeInterval_ticks = ((uint64)u32_timeInterval_us * (uint64)u32_T20Freq_MHz);

  while (u64_timeInterval_ticks > (uint64)0xFFFFu)
  {
    u8_T20ClkPrescaler++;
    u64_timeInterval_ticks >>= 1u;
  }

  /* T20 operates in reload mode and is counting up by default */
  u64_timeInterval_ticks = (uint64)0x10000 - u64_timeInterval_ticks;

  /* The individual prescaler maximal value is 0b111 */
  if (u8_T20ClkPrescaler <= 7u)
  {
    /* Select Reload mode */
    T20->CON.bit.CP_RL2 = 0u;
    /* Disable external up/down counter mode */
    T20->MOD.bit.DCEN = 0u;
    /* Enable the T20 clock prescaler */
    T20->MOD.bit.PREN = 1u;
    /* Program the calculated prescaler */
    T20->MOD.bit.T2PRE = (uint8)u8_T20ClkPrescaler;
    /* Program the first period */
    T20->CNT.bit.T2H = (uint16)u64_timeInterval_ticks >> 8u;
    T20->CNT.bit.T2L = (uint16)u64_timeInterval_ticks & 0xFFu;
    /* Program the reload value */
    T20->RC.bit.RCH2 = (uint16)u64_timeInterval_ticks >> 8u;
    T20->RC.bit.RCL2 = (uint16)u64_timeInterval_ticks & 0xFFu;
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}