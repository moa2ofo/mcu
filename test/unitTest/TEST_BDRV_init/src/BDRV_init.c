#include "BDRV_init_help.h"

/* FUNCTION TO TEST */
sint8 BDRV_init(void)
{
  sint8 s8_returnCode;
  sint8 s8_returnCode1;
  sint8 s8_returnCode2;
  uint16 u16_VCP_mV;
  uint16 u16_VSD_mV;
  uint8 u8_stageNb;
  uint16 u16_minCPVolt;
  uint16 u16_voltDiff_mV;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
  s8_returnCode1 = ERR_LOG_SUCCESS;
  s8_returnCode2 = ERR_LOG_SUCCESS;
  u16_VCP_mV = 0;
  u16_VSD_mV = 0;
  u16_voltDiff_mV = 0;
  u8_stageNb = 0;
  u16_minCPVolt = 0;
  /* Check if ADC2 and BDRV are enabled in the CW */
#if (BDRV_GLOBCONF_EN == 1) && ((ADC2_GLOBCONF & ADC2_GLOBCONF_EN_Msk) == 1)
  s8_returnCode = ERR_LOG_CODE_SAFE_SHUTDOWN_ACTIVE;

  /* Check if the Safe-Shutdown Status is inactive */
  if (PMU_getSafeShutdownSts() == 0)
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;

    /* Wait for CP sufficient voltage */
    if (BDRV_getCPReadyStateCW() == 1u)
    {
      u8_stageNb = BDRV_getCPStagesCW();
      s8_returnCode1 = ADC2_getChResult_mV(&u16_VSD_mV, ADC2_DCH1);

      if ((u8_stageNb == 1u) || (u16_VSD_mV >= 8000u))
      {
        u16_minCPVolt = BDRV_MINCPVOLT_NORMALVSD;
      }
      else
      {
        u16_minCPVolt = BDRV_MINCPVOLT_LOWVSD;
      }

      do
      {
        /* ADC2: VSD measurement with Ch1, VCP measurement with Ch3 */
        s8_returnCode1 = ADC2_getChResult_mV(&u16_VSD_mV, ADC2_DCH1);
        s8_returnCode2 = ADC2_getChResult_mV(&u16_VCP_mV, ADC2_DCH3);
        u16_voltDiff_mV = (uint16)(u16_VCP_mV - u16_VSD_mV);
      }
      while ((u16_voltDiff_mV < u16_minCPVolt) && (s8_returnCode1 == ERR_LOG_SUCCESS) && (s8_returnCode2 == ERR_LOG_SUCCESS));
    }

    if ((s8_returnCode1 == ERR_LOG_SUCCESS) && (s8_returnCode2 == ERR_LOG_SUCCESS))
    {
      s8_returnCode = ERR_LOG_SUCCESS;
      /* Clear ADC2 compare unit status bits */
      ADC2->CMPSTATCLR.reg = (uint32)0xFFFFFFFFu;
      /* Clear BDRV status bits */
      BDRV->STSCLR.reg = (uint32)0x80333333u;
      /* Configure bridge driver register */
      BDRV->CTRL1.reg = (uint32)BDRV_CTRL1;
      BDRV->CTRL2.reg = (uint32)BDRV_CTRL2;
      BDRV->PWMSRCSEL.reg = (uint32)BDRV_PWMSRCSEL;
      BDRV->SEQMAP.reg = (uint32)BDRV_SEQMAP;
      BDRV->PROT_CTRL.reg = (uint32)BDRV_PROT_CTRL;
      BDRV->HB1IGATECLMPC.reg = (uint32)BDRV_HB1IGATECLMPC;
      BDRV->HB2IGATECLMPC.reg = (uint32)BDRV_HB2IGATECLMPC;
#if (UC_SERIES == 989)
      BDRV->HB3IGATECLMPC.reg = (uint32)BDRV_HB3IGATECLMPC;
#endif
      BDRV->LS1AFTC.reg = (uint32)BDRV_LS1AFTC;
      BDRV->LS1AFIC.reg = (uint32)BDRV_LS1AFIC;
      BDRV->HS1AFTC.reg = (uint32)BDRV_HS1AFTC;
      BDRV->HS1AFIC.reg = (uint32)BDRV_HS1AFIC;
      BDRV->LS2AFTC.reg = (uint32)BDRV_LS2AFTC;
      BDRV->LS2AFIC.reg = (uint32)BDRV_LS2AFIC;
      BDRV->HS2AFTC.reg = (uint32)BDRV_HS2AFTC;
      BDRV->HS2AFIC.reg = (uint32)BDRV_HS2AFIC;
      BDRV->LS1SEQOFFTC.reg = (uint32)BDRV_LS1SEQOFFTC;
      BDRV->LS1SEQOFFIC.reg = (uint32)BDRV_LS1SEQOFFIC;
      BDRV->HS1SEQOFFTC.reg = (uint32)BDRV_HS1SEQOFFTC;
      BDRV->HS1SEQOFFIC.reg = (uint32)BDRV_HS1SEQOFFIC;
      BDRV->LS2SEQOFFTC.reg = (uint32)BDRV_LS2SEQOFFTC;
      BDRV->LS2SEQOFFIC.reg = (uint32)BDRV_LS2SEQOFFIC;
      BDRV->HS2SEQOFFTC.reg = (uint32)BDRV_HS2SEQOFFTC;
      BDRV->HS2SEQOFFIC.reg = (uint32)BDRV_HS2SEQOFFIC;
      BDRV->LS1SEQONTC.reg = (uint32)BDRV_LS1SEQONTC;
      BDRV->LS1SEQONIC.reg = (uint32)BDRV_LS1SEQONIC;
      BDRV->HS1SEQONTC.reg = (uint32)BDRV_HS1SEQONTC;
      BDRV->HS1SEQONIC.reg = (uint32)BDRV_HS1SEQONIC;
      BDRV->LS2SEQONTC.reg = (uint32)BDRV_LS2SEQONTC;
      BDRV->LS2SEQONIC.reg = (uint32)BDRV_LS2SEQONIC;
      BDRV->HS2SEQONTC.reg = (uint32)BDRV_HS2SEQONTC;
      BDRV->HS2SEQONIC.reg = (uint32)BDRV_HS2SEQONIC;
      BDRV->SEQOFFT4I4.reg = (uint32)BDRV_SEQOFFT4I4;
      BDRV->HCDIS.reg = (uint32)BDRV_HCDIS;
      BDRV->ASEQC.reg = (uint32)BDRV_ASEQC;
      BDRV->ASEQERRCNT.reg = (uint32)BDRV_ASEQERRCNT;
      BDRV->ASEQONTMIN.reg = (uint32)BDRV_ASEQONTMIN;
      BDRV->ASEQONIMIN.reg = (uint32)BDRV_ASEQONIMIN;
      BDRV->ASEQONTMAX.reg = (uint32)BDRV_ASEQONTMAX;
      BDRV->ASEQONIMAX.reg = (uint32)BDRV_ASEQONIMAX;
      BDRV->ASEQOFFTMIN.reg = (uint32)BDRV_ASEQOFFTMIN;
      BDRV->ASEQOFFIMIN.reg = (uint32)BDRV_ASEQOFFIMIN;
      BDRV->ASEQOFFTMAX.reg = (uint32)BDRV_ASEQOFFTMAX;
      BDRV->ASEQOFFIMAX.reg = (uint32)BDRV_ASEQOFFIMAX;
      BDRV->ASEQOFFADDDLY.reg = (uint32)BDRV_ASEQOFFADDDLY;
#if (UC_SERIES == 989)
      BDRV->LS3AFTC.reg = (uint32)BDRV_LS3AFTC;
      BDRV->LS3AFIC.reg = (uint32)BDRV_LS3AFIC;
      BDRV->HS3AFTC.reg = (uint32)BDRV_HS3AFTC;
      BDRV->HS3AFIC.reg = (uint32)BDRV_HS3AFIC;
      BDRV->LS3SEQOFFTC.reg = (uint32)BDRV_LS3SEQOFFTC;
      BDRV->LS3SEQOFFIC.reg = (uint32)BDRV_LS3SEQOFFIC;
      BDRV->HS3SEQOFFTC.reg = (uint32)BDRV_HS3SEQOFFTC;
      BDRV->HS3SEQOFFIC.reg = (uint32)BDRV_HS3SEQOFFIC;
      BDRV->LS3SEQONTC.reg = (uint32)BDRV_LS3SEQONTC;
      BDRV->LS3SEQONIC.reg = (uint32)BDRV_LS3SEQONIC;
      BDRV->HS3SEQONTC.reg = (uint32)BDRV_HS3SEQONTC;
      BDRV->HS3SEQONIC.reg = (uint32)BDRV_HS3SEQONIC;
#endif
#if (BEMFC_GLOBCONF_EN == 1)
      BDRV->BEMFC_CTRL.reg = (uint32)BDRV_BEMFC_CTRL;
#endif
      /* Enable bridge driver */
#if (UC_SERIES == 988)
      s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en);
#elif (UC_SERIES == 989)
      s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en);
#endif
    }
  }

#endif
  return s8_returnCode;
}