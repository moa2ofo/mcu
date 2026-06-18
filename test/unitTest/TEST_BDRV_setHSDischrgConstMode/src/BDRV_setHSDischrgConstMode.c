#include "BDRV_setHSDischrgConstMode_help.h"

/* FUNCTION TO TEST */
sint8 BDRV_setHSDischrgConstMode(tBDRV_hb e_hb, tBDRV_constCfg s_constDischrgCfg)
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
        BDRV->HS1SEQOFFTC.bit.HS1_T1OFF = (s_constDischrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->HS1SEQOFFIC.bit.HS1_I1OFF = (uint8)s_constDischrgCfg.e_constCurrentAct;
        BDRV->HS1AFTC.bit.HS1_TAFOFF = (s_constDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS1AFIC.bit.HS1_IAFOFF = (uint8)s_constDischrgCfg.e_constCurrentFW;
        break;
      }

      case BDRV_hb_2:
      {
        BDRV->HS2SEQOFFTC.bit.HS2_T1OFF = (s_constDischrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->HS2SEQOFFIC.bit.HS2_I1OFF = (uint8)s_constDischrgCfg.e_constCurrentAct;
        BDRV->HS2AFTC.bit.HS2_TAFOFF = (s_constDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS2AFIC.bit.HS2_IAFOFF = (uint8)s_constDischrgCfg.e_constCurrentFW;
        break;
      }

#if (UC_SERIES == 989)

      case BDRV_hb_3:
      {
        BDRV->HS3SEQOFFTC.bit.HS3_T1OFF = (s_constDischrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->HS3SEQOFFIC.bit.HS3_I1OFF = (uint8)s_constDischrgCfg.e_constCurrentAct;
        BDRV->HS3AFTC.bit.HS3_TAFOFF = (s_constDischrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS3AFIC.bit.HS3_IAFOFF = (uint8)s_constDischrgCfg.e_constCurrentFW;
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