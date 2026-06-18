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

#include "timer2x.h"

/*******************************************************************************
**                        Private Constant Declarations                       **
*******************************************************************************/

/*******************************************************************************
**                         Private Macro Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                        Private Variable Definitions                        **
*******************************************************************************/

/*******************************************************************************
**                        Private Function Declarations                       **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

/** \brief Initialize all CW registers of the timer 20
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 T20_init(void) {
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if((SCU_PMCON & SCU_PMCON_T2_DIS_Msk) == 0u)
  s8_returnCode = ERR_LOG_SUCCESS;
  T20->CON.reg = (uint32)T20_CON;
  T20->MOD.reg = (uint32)T20_MOD;
  T20->RC.reg = (uint32)T20_RC;
  T20->CNT.reg = (uint32)T20_CNT;
#endif
  return s8_returnCode;
}

/** \brief Initialize all CW registers of the timer 21
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 T21_init(void) {
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if((SCU_PMCON & SCU_PMCON_T21_DIS_Msk) == 0u)
  s8_returnCode = ERR_LOG_SUCCESS;
  T21->CON.reg = (uint32)T21_CON;
  T21->MOD.reg = (uint32)T21_MOD;
  T21->RC.reg = (uint32)T21_RC;
  T21->CNT.reg = (uint32)T21_CNT;
#endif
  return s8_returnCode;
}

/** \brief Define an interval timer with the timer T20
 *
 * \param u32_timeInterval_us Duration of the timer T20 in microseconds
 * \return sint8 0: success, <0: error codes
 */
sint8 T20_setIntervalTimer(uint32 u32_timeInterval_us) {
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

  while(u64_timeInterval_ticks > (uint64)0xFFFFu) {
    u8_T20ClkPrescaler++;
    u64_timeInterval_ticks >>= 1u;
  }

  /* T20 operates in reload mode and is counting up by default */
  u64_timeInterval_ticks = (uint64)0x10000 - u64_timeInterval_ticks;

  /* The individual prescaler maximal value is 0b111 */
  if(u8_T20ClkPrescaler <= 7u) {
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
  } else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}

/** \brief Define an interval timer with the timer T21
 *
 * \param u32_timeInterval_us Duration of the timer T21 in microseconds
 * \return sint8 0: success, <0: error codes
 */
sint8 T21_setIntervalTimer(uint32 u32_timeInterval_us) {
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

  while(u64_timeInterval_ticks > (uint64)0xFFFFu) {
    u8_T21ClkPrescaler++;
    u64_timeInterval_ticks >>= 1u;
  }

  /* T21 operates in reload mode and is counting up by default */
  u64_timeInterval_ticks = (uint64)0x10000u - u64_timeInterval_ticks;

  /* The individual prescaler maximal value is 0b111 */
  if(u8_T21ClkPrescaler <= 7u) {
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
  } else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}
