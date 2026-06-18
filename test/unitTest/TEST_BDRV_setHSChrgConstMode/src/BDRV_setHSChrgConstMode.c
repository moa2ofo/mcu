#include "BDRV_setHSChrgConstMode_help.h"

/* FUNCTION TO TEST */
sint8 BDRV_setHSChrgConstMode(tBDRV_hb e_hb, tBDRV_constCfg s_constChrgCfg)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Violation: Relational operator '<=' always evaluates to 'true' [MISRA 2012 Rule 14.3, required] */
  if ((s_constChrgCfg.e_constCurrentAct <= BDRV_currentCfg_350mA) && (s_constChrgCfg.u16_constTimeAct_ns >= (uint16)50) && (s_constChrgCfg.u16_constTimeAct_ns <= (uint16)12800)
      && (s_constChrgCfg.e_constCurrentFW <= BDRV_currentCfg_350mA) && (s_constChrgCfg.u16_constTimeFW_ns >= (uint16)50) && (s_constChrgCfg.u16_constTimeFW_ns <= (uint16)12800))
  {
    switch (e_hb)
    {
      case BDRV_hb_1:
      {
        BDRV->HS1SEQONTC.bit.HS1_T1ON = (s_constChrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->HS1SEQONIC.bit.HS1_I1ON = (uint8)s_constChrgCfg.e_constCurrentAct;
        BDRV->HS1AFTC.bit.HS1_TAFON = (s_constChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS1AFIC.bit.HS1_IAFON = (uint8)s_constChrgCfg.e_constCurrentFW;
        break;
      }

      case BDRV_hb_2:
      {
        BDRV->HS2SEQONTC.bit.HS2_T1ON = (s_constChrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->HS2SEQONIC.bit.HS2_I1ON = (uint8)s_constChrgCfg.e_constCurrentAct;
        BDRV->HS2AFTC.bit.HS2_TAFON = (s_constChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS2AFIC.bit.HS2_IAFON = (uint8)s_constChrgCfg.e_constCurrentFW;
        break;
      }

#if (UC_SERIES == 989)

      case BDRV_hb_3:
      {
        BDRV->HS3SEQONTC.bit.HS3_T1ON = (s_constChrgCfg.u16_constTimeAct_ns / 50u) - 1u;
        BDRV->HS3SEQONIC.bit.HS3_I1ON = (uint8)s_constChrgCfg.e_constCurrentAct;
        BDRV->HS3AFTC.bit.HS3_TAFON = (s_constChrgCfg.u16_constTimeFW_ns / 50u) - 1u;
        BDRV->HS3AFIC.bit.HS3_IAFON = (uint8)s_constChrgCfg.e_constCurrentFW;
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