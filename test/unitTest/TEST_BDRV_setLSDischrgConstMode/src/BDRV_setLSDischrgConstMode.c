#include "BDRV_setLSDischrgConstMode_help.h"

/* FUNCTION TO TEST */
sint8 BDRV_setLSDischrgConstMode(tBDRV_hb e_hb, tBDRV_constCfg s_constDischrgCfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Violation: Relational operator '<=' always evaluates to 'true' [MISRA 2012 Rule 14.3, required] */
  if ((s_constDischrgCfg.e_constCurrentAct <= BDRV_currentCfg_350mA) && (s_constDischrgCfg.u16_constTimeAct_ns >= (uint16)50) && (s_constDischrgCfg.u16_constTimeAct_ns <= (uint16)12800)
      && (s_constDischrgCfg.e_constCurrentFW <= BDRV_currentCfg_350mA) && (s_constDischrgCfg.u16_constTimeFW_ns >= (uint16)50) && (s_constDischrgCfg.u16_constTimeFW_ns <= (uint16)12800))
  {
    switch (e_hb)
    {
      case BDRV_hb_1:
      {
        BDRV->LS1SEQOFFTC.bit.LS1_T1OFF = (s_constDischrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->LS1SEQOFFIC.bit.LS1_I1OFF = (uint8)s_constDischrgCfg.e_constCurrentAct;
        BDRV->LS1AFTC.bit.LS1_TAFOFF = (s_constDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS1AFIC.bit.LS1_IAFOFF = (uint8)s_constDischrgCfg.e_constCurrentFW;
        break;
      }

      case BDRV_hb_2:
      {
        BDRV->LS2SEQOFFTC.bit.LS2_T1OFF = (s_constDischrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->LS2SEQOFFIC.bit.LS2_I1OFF = (uint8)s_constDischrgCfg.e_constCurrentAct;
        BDRV->LS2AFTC.bit.LS2_TAFOFF = (s_constDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS2AFIC.bit.LS2_IAFOFF = (uint8)s_constDischrgCfg.e_constCurrentFW;
        break;
      }

#if (UC_SERIES == 989)

      case BDRV_hb_3:
      {
        BDRV->LS3SEQOFFTC.bit.LS3_T1OFF = (s_constDischrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->LS3SEQOFFIC.bit.LS3_I1OFF = (uint8)s_constDischrgCfg.e_constCurrentAct;
        BDRV->LS3AFTC.bit.LS3_TAFOFF = (s_constDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->LS3AFIC.bit.LS3_IAFOFF = (uint8)s_constDischrgCfg.e_constCurrentFW;
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