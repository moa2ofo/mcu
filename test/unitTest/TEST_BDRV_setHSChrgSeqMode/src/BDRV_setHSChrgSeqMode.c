#include "BDRV_setHSChrgSeqMode_help.h"

/* FUNCTION TO TEST */
sint8 BDRV_setHSChrgSeqMode(tBDRV_hb e_hb, tBDRV_seqCfg s_seqChrgCfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Violation: Relational operator '<=' always evaluates to 'true' [MISRA 2012 Rule 14.3, required] */
  if ((s_seqChrgCfg.e_seqPhase1CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqChrgCfg.e_seqPhase2CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqChrgCfg.e_seqPhase3CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqChrgCfg.e_seqPhase4CurrentAct <= BDRV_currentCfg_350mA)
      && (s_seqChrgCfg.u16_seqPhase1TimeAct_ns >= (uint16)50) && (s_seqChrgCfg.u16_seqPhase1TimeAct_ns <= (uint16)3200)
      && (s_seqChrgCfg.u16_seqPhase2TimeAct_ns >= (uint16)50) && (s_seqChrgCfg.u16_seqPhase2TimeAct_ns <= (uint16)3200)
      && (s_seqChrgCfg.u16_seqPhase3TimeAct_ns >= (uint16)50) && (s_seqChrgCfg.u16_seqPhase3TimeAct_ns <= (uint16)3200)
      && (s_seqChrgCfg.u16_seqPhase4TimeAct_ns >= (uint16)50) && (s_seqChrgCfg.u16_seqPhase4TimeAct_ns <= (uint16)3200)
      && (s_seqChrgCfg.e_constCurrentFW <= BDRV_currentCfg_350mA) && (s_seqChrgCfg.u16_constTimeFW_ns >= (uint16)50)
      && (s_seqChrgCfg.u16_constTimeFW_ns <= (uint16)12800))
  {
    switch (e_hb)
    {
      case BDRV_hb_1:
      {
        BDRV->HS1SEQONTC.bit.HS1_T1ON = (uint8)((s_seqChrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->HS1SEQONTC.bit.HS1_T2ON = (uint8)((s_seqChrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->HS1SEQONTC.bit.HS1_T3ON = (uint8)((s_seqChrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->HS1SEQONTC.bit.HS1_T4ON = (uint8)((s_seqChrgCfg.u16_seqPhase4TimeAct_ns / 50u) - 1u);
        BDRV->HS1SEQONIC.bit.HS1_I1ON = (uint8)s_seqChrgCfg.e_seqPhase1CurrentAct;
        BDRV->HS1SEQONIC.bit.HS1_I2ON = (uint8)s_seqChrgCfg.e_seqPhase2CurrentAct;
        BDRV->HS1SEQONIC.bit.HS1_I3ON = (uint8)s_seqChrgCfg.e_seqPhase3CurrentAct;
        BDRV->HS1SEQONIC.bit.HS1_I4ON = (uint8)s_seqChrgCfg.e_seqPhase4CurrentAct;
        BDRV->HS1AFTC.bit.HS1_TAFON = (s_seqChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS1AFIC.bit.HS1_IAFON = (uint8)s_seqChrgCfg.e_constCurrentFW;
        break;
      }

      case BDRV_hb_2:
      {
        BDRV->HS2SEQONTC.bit.HS2_T1ON = (uint8)((s_seqChrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->HS2SEQONTC.bit.HS2_T2ON = (uint8)((s_seqChrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->HS2SEQONTC.bit.HS2_T3ON = (uint8)((s_seqChrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->HS2SEQONTC.bit.HS2_T4ON = (uint8)((s_seqChrgCfg.u16_seqPhase4TimeAct_ns / 50u) - 1u);
        BDRV->HS2SEQONIC.bit.HS2_I1ON = (uint8)s_seqChrgCfg.e_seqPhase1CurrentAct;
        BDRV->HS2SEQONIC.bit.HS2_I2ON = (uint8)s_seqChrgCfg.e_seqPhase2CurrentAct;
        BDRV->HS2SEQONIC.bit.HS2_I3ON = (uint8)s_seqChrgCfg.e_seqPhase3CurrentAct;
        BDRV->HS2SEQONIC.bit.HS2_I4ON = (uint8)s_seqChrgCfg.e_seqPhase4CurrentAct;
        BDRV->HS2AFTC.bit.HS2_TAFON = (s_seqChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS2AFIC.bit.HS2_IAFON = (uint8)s_seqChrgCfg.e_constCurrentFW;
        break;
      }

#if (UC_SERIES == 989)

      case BDRV_hb_3:
      {
        BDRV->HS3SEQONTC.bit.HS3_T1ON = (uint8)((s_seqChrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->HS3SEQONTC.bit.HS3_T2ON = (uint8)((s_seqChrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->HS3SEQONTC.bit.HS3_T3ON = (uint8)((s_seqChrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->HS3SEQONTC.bit.HS3_T4ON = (uint8)((s_seqChrgCfg.u16_seqPhase4TimeAct_ns / 50u) - 1u);
        BDRV->HS3SEQONIC.bit.HS3_I1ON = (uint8)s_seqChrgCfg.e_seqPhase1CurrentAct;
        BDRV->HS3SEQONIC.bit.HS3_I2ON = (uint8)s_seqChrgCfg.e_seqPhase2CurrentAct;
        BDRV->HS3SEQONIC.bit.HS3_I3ON = (uint8)s_seqChrgCfg.e_seqPhase3CurrentAct;
        BDRV->HS3SEQONIC.bit.HS3_I4ON = (uint8)s_seqChrgCfg.e_seqPhase4CurrentAct;
        BDRV->HS3AFTC.bit.HS3_TAFON = (s_seqChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS3AFIC.bit.HS3_IAFON = (uint8)s_seqChrgCfg.e_constCurrentFW;
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