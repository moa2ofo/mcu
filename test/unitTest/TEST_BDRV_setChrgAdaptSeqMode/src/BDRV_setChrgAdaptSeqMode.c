#include "BDRV_setChrgAdaptSeqMode_help.h"

/* FUNCTION TO TEST */
sint8 BDRV_setChrgAdaptSeqMode(tBDRV_aseqCfg s_aseqChrgCfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Violation: Relational operator '<=' always evaluates to 'true' [MISRA 2012 Rule 14.3, required] */
  if ((s_aseqChrgCfg.e_aseqMinCurrent <= BDRV_currentCfg_350mA)
      && (s_aseqChrgCfg.e_aseqMaxCurrent <= BDRV_currentCfg_350mA)
      && (s_aseqChrgCfg.u16_aseqMinTime_ns >= (uint16)50) && (s_aseqChrgCfg.u16_aseqMinTime_ns <= (uint16)12800)
      && (s_aseqChrgCfg.u16_aseqMaxTime_ns >= (uint16)50) && (s_aseqChrgCfg.u16_aseqMaxTime_ns <= (uint16)12800))
  {
    BDRV->ASEQONTMIN.bit.T12ONMIN = (s_aseqChrgCfg.u16_aseqMinTime_ns / 50u) - 1u;
    BDRV->ASEQONTMAX.bit.T12ONMAX = (s_aseqChrgCfg.u16_aseqMaxTime_ns / 50u) - 1u;
    BDRV->ASEQONIMIN.bit.I1ONMIN = (uint8)s_aseqChrgCfg.e_aseqMinCurrent;
    BDRV->ASEQONIMAX.bit.I1ONMAX = (uint8)s_aseqChrgCfg.e_aseqMaxCurrent;
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}