#include "BDRV_setHSDischrgSeqMode_help.h"

/* FUNCTION TO TEST */
sint8 BDRV_setHSDischrgSeqMode(tBDRV_hb e_hb, tBDRV_seqCfg s_seqDischrgCfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Violation: Relational operator '<=' always evaluates to 'true' [MISRA 2012 Rule 14.3, required] */
  if ((s_seqDischrgCfg.e_seqPhase1CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqDischrgCfg.e_seqPhase2CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqDischrgCfg.e_seqPhase3CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqDischrgCfg.u16_seqPhase1TimeAct_ns >= (uint16)50) && (s_seqDischrgCfg.u16_seqPhase1TimeAct_ns <= (uint16)3200)
      && (s_seqDischrgCfg.u16_seqPhase2TimeAct_ns >= (uint16)50) && (s_seqDischrgCfg.u16_seqPhase2TimeAct_ns <= (uint16)3200)
      && (s_seqDischrgCfg.u16_seqPhase3TimeAct_ns >= (uint16)50) && (s_seqDischrgCfg.u16_seqPhase3TimeAct_ns <= (uint16)3200)
      && (s_seqDischrgCfg.e_constCurrentFW <= BDRV_currentCfg_350mA) && (s_seqDischrgCfg.u16_constTimeFW_ns >= (uint16)50)
      && (s_seqDischrgCfg.u16_constTimeFW_ns <= (uint16)12800))
  {
    switch (e_hb)
    {
      case BDRV_hb_1:
      {
        BDRV->HS1SEQOFFTC.bit.HS1_T1OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->HS1SEQOFFTC.bit.HS1_T2OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->HS1SEQOFFTC.bit.HS1_T3OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->HS1SEQOFFIC.bit.HS1_I1OFF = (uint8)s_seqDischrgCfg.e_seqPhase1CurrentAct;
        BDRV->HS1SEQOFFIC.bit.HS1_I2OFF = (uint8)s_seqDischrgCfg.e_seqPhase2CurrentAct;
        BDRV->HS1SEQOFFIC.bit.HS1_I3OFF = (uint8)s_seqDischrgCfg.e_seqPhase3CurrentAct;
        BDRV->HS1AFTC.bit.HS1_TAFOFF = (s_seqDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS1AFIC.bit.HS1_IAFOFF = (uint8)s_seqDischrgCfg.e_constCurrentFW;
        break;
      }

      case BDRV_hb_2:
      {
        BDRV->HS2SEQOFFTC.bit.HS2_T1OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->HS2SEQOFFTC.bit.HS2_T2OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->HS2SEQOFFTC.bit.HS2_T3OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->HS2SEQOFFIC.bit.HS2_I1OFF = (uint8)s_seqDischrgCfg.e_seqPhase1CurrentAct;
        BDRV->HS2SEQOFFIC.bit.HS2_I2OFF = (uint8)s_seqDischrgCfg.e_seqPhase2CurrentAct;
        BDRV->HS2SEQOFFIC.bit.HS2_I3OFF = (uint8)s_seqDischrgCfg.e_seqPhase3CurrentAct;
        BDRV->HS2AFTC.bit.HS2_TAFOFF = (s_seqDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS2AFIC.bit.HS2_IAFOFF = (uint8)s_seqDischrgCfg.e_constCurrentFW;
        break;
      }

#if (UC_SERIES == 989)

      case BDRV_hb_3:
      {
        BDRV->HS3SEQOFFTC.bit.HS3_T1OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->HS3SEQOFFTC.bit.HS3_T2OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->HS3SEQOFFTC.bit.HS3_T3OFF = (uint8)((s_seqDischrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->HS3SEQOFFIC.bit.HS3_I1OFF = (uint8)s_seqDischrgCfg.e_seqPhase1CurrentAct;
        BDRV->HS3SEQOFFIC.bit.HS3_I2OFF = (uint8)s_seqDischrgCfg.e_seqPhase2CurrentAct;
        BDRV->HS3SEQOFFIC.bit.HS3_I3OFF = (uint8)s_seqDischrgCfg.e_seqPhase3CurrentAct;
        BDRV->HS3AFTC.bit.HS3_TAFOFF = (s_seqDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS3AFIC.bit.HS3_IAFOFF = (uint8)s_seqDischrgCfg.e_constCurrentFW;
        break;
      }

#endif

      default:
      {
        s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
        break;
      }
    }
  }
  else /* arguments out of range */
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}