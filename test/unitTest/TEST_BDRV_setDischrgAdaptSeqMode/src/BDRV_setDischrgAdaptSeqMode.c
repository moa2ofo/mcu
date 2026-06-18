#include "BDRV_setDischrgAdaptSeqMode_help.h"

/* FUNCTION TO TEST */
sint8 BDRV_setDischrgAdaptSeqMode(tBDRV_aseqCfg s_aseqDischrgCfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Violation: Relational operator '<=' always evaluates to 'true' [MISRA 2012 Rule 14.3, required] */
  if ((s_aseqDischrgCfg.e_aseqMinCurrent <= BDRV_currentCfg_350mA)
      && (s_aseqDischrgCfg.e_aseqMaxCurrent <= BDRV_currentCfg_350mA)
      && (s_aseqDischrgCfg.u16_aseqMinTime_ns >= (uint16)50) && (s_aseqDischrgCfg.u16_aseqMinTime_ns <= (uint16)12800)
      && (s_aseqDischrgCfg.u16_aseqMaxTime_ns >= (uint16)50) && (s_aseqDischrgCfg.u16_aseqMaxTime_ns <= (uint16)12800))
  {
    BDRV->ASEQOFFTMIN.bit.T1OFFMIN = (s_aseqDischrgCfg.u16_aseqMinTime_ns / 50u) - 1u;
    BDRV->ASEQOFFTMAX.bit.T1OFFMAX = (s_aseqDischrgCfg.u16_aseqMaxTime_ns / 50u) - 1u;
    BDRV->ASEQOFFIMIN.bit.I1OFFMIN = (uint8)s_aseqDischrgCfg.e_aseqMinCurrent;
    BDRV->ASEQOFFIMAX.bit.I1OFFMAX = (uint8)s_aseqDischrgCfg.e_aseqMaxCurrent;
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}