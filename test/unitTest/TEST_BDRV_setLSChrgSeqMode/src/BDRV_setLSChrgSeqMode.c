#include "BDRV_setLSChrgSeqMode_help.h"

/* FUNCTION TO TEST */
sint8 BDRV_setLSChrgSeqMode(tBDRV_hb e_hb, tBDRV_seqCfg s_seqChrgCfg)
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
      && (s_seqChrgCfg.e_constCurrentFW <= BDRV_currentCfg_350mA)
      && (s_seqChrgCfg.u16_constTimeFW_ns >= (uint16)50) && (s_seqChrgCfg.u16_constTimeFW_ns <= (uint16)12800))
  {
    switch (e_hb)
    {
      case BDRV_hb_1:
      {
        BDRV->LS1SEQONTC.bit.LS1_T1ON = (uint8)((s_seqChrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->LS1SEQONTC.bit.LS1_T2ON = (uint8)((s_seqChrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->LS1SEQONTC.bit.LS1_T3ON = (uint8)((s_seqChrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->LS1SEQONTC.bit.LS1_T4ON = (uint8)((s_seqChrgCfg.u16_seqPhase4TimeAct_ns / 50u) - 1u);
        BDRV->LS1SEQONIC.bit.LS1_I1ON = (uint8)s_seqChrgCfg.e_seqPhase1CurrentAct;
        BDRV->LS1SEQONIC.bit.LS1_I2ON = (uint8)s_seqChrgCfg.e_seqPhase2CurrentAct;
        BDRV->LS1SEQONIC.bit.LS1_I3ON = (uint8)s_seqChrgCfg.e_seqPhase3CurrentAct;
        BDRV->LS1SEQONIC.bit.LS1_I4ON = (uint8)s_seqChrgCfg.e_seqPhase4CurrentAct;
        BDRV->LS1AFTC.bit.LS1_TAFON = (s_seqChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS1AFIC.bit.LS1_IAFON = (uint8)s_seqChrgCfg.e_constCurrentFW;
        break;
      }

      case BDRV_hb_2:
      {
        BDRV->LS2SEQONTC.bit.LS2_T1ON = (uint8)((s_seqChrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->LS2SEQONTC.bit.LS2_T2ON = (uint8)((s_seqChrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->LS2SEQONTC.bit.LS2_T3ON = (uint8)((s_seqChrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->LS2SEQONTC.bit.LS2_T4ON = (uint8)((s_seqChrgCfg.u16_seqPhase4TimeAct_ns / 50u) - 1u);
        BDRV->LS2SEQONIC.bit.LS2_I1ON = (uint8)s_seqChrgCfg.e_seqPhase1CurrentAct;
        BDRV->LS2SEQONIC.bit.LS2_I2ON = (uint8)s_seqChrgCfg.e_seqPhase2CurrentAct;
        BDRV->LS2SEQONIC.bit.LS2_I3ON = (uint8)s_seqChrgCfg.e_seqPhase3CurrentAct;
        BDRV->LS2SEQONIC.bit.LS2_I4ON = (uint8)s_seqChrgCfg.e_seqPhase4CurrentAct;
        BDRV->LS2AFTC.bit.LS2_TAFON = (s_seqChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS2AFIC.bit.LS2_IAFON = (uint8)s_seqChrgCfg.e_constCurrentFW;
        break;
      }

#if (UC_SERIES == 989)

      case BDRV_hb_3:
      {
        BDRV->LS3SEQONTC.bit.LS3_T1ON = (uint8)((s_seqChrgCfg.u16_seqPhase1TimeAct_ns / 50u) - 1u);
        BDRV->LS3SEQONTC.bit.LS3_T2ON = (uint8)((s_seqChrgCfg.u16_seqPhase2TimeAct_ns / 50u) - 1u);
        BDRV->LS3SEQONTC.bit.LS3_T3ON = (uint8)((s_seqChrgCfg.u16_seqPhase3TimeAct_ns / 50u) - 1u);
        BDRV->LS3SEQONTC.bit.LS3_T4ON = (uint8)((s_seqChrgCfg.u16_seqPhase4TimeAct_ns / 50u) - 1u);
        BDRV->LS3SEQONIC.bit.LS3_I1ON = (uint8)s_seqChrgCfg.e_seqPhase1CurrentAct;
        BDRV->LS3SEQONIC.bit.LS3_I2ON = (uint8)s_seqChrgCfg.e_seqPhase2CurrentAct;
        BDRV->LS3SEQONIC.bit.LS3_I3ON = (uint8)s_seqChrgCfg.e_seqPhase3CurrentAct;
        BDRV->LS3SEQONIC.bit.LS3_I4ON = (uint8)s_seqChrgCfg.e_seqPhase4CurrentAct;
        BDRV->LS3AFTC.bit.LS3_TAFON = (s_seqChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS3AFIC.bit.LS3_IAFON = (uint8)s_seqChrgCfg.e_constCurrentFW;
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