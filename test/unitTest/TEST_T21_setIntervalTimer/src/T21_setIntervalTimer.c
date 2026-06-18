#include "T21_setIntervalTimer_help.h"

/* FUNCTION TO TEST */
sint8 T21_setIntervalTimer(uint32 u32_timeInterval_us)
{
  sint8 s8_returnCode;
  uint64 u64_timeInterval_ticks;
  /* T21 frequency in Hz */
  uint32 u32_T21Freq_MHz = (uint32)fT21;
  /* Calculate T21 individual prescaler: as long as u64_timeInterval_ticks is larger than
   * the T21 value register (16 bits), the individual prescaler value is incremented
   * and u64_timeInterval_ticks is divided by 2 */
  uint8 u8_T21ClkPrescaler = 0u;
  s8_returnCode = ERR_LOG_SUCCESS;
  /* Calculate time interval in ticks */
  u64_timeInterval_ticks = ((uint64)u32_timeInterval_us * (uint64)u32_T21Freq_MHz);

  while (u64_timeInterval_ticks > (uint64)0xFFFFu)
  {
    u8_T21ClkPrescaler++;
    u64_timeInterval_ticks >>= 1u;
  }

  /* T21 operates in reload mode and is counting up by default */
  u64_timeInterval_ticks = (uint64)0x10000u - u64_timeInterval_ticks;

  /* The individual prescaler maximal value is 0b111 */
  if (u8_T21ClkPrescaler <= 7u)
  {
    /* Select Reload mode */
    T21->CON.bit.CP_RL2 = 0u;
    /* Disable external up/down counter mode */
    T21->MOD.bit.DCEN = 0u;
    /* Enable the T21 clock prescaler */
    T21->MOD.bit.PREN = 1u;
    /* Program the calculated prescaler */
    T21->MOD.bit.T2PRE = (uint8)u8_T21ClkPrescaler;
    /* Program the first period */
    T21->CNT.bit.T2H = (uint16)u64_timeInterval_ticks >> 8u;
    T21->CNT.bit.T2L = (uint16)u64_timeInterval_ticks & 0xFFu;
    /* Program the reload value */
    T21->RC.bit.RCH2 = (uint16)u64_timeInterval_ticks >> 8u;
    T21->RC.bit.RCL2 = (uint16)u64_timeInterval_ticks & 0xFFu;
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}