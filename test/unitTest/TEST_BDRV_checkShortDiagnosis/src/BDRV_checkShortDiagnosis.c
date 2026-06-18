#include "BDRV_checkShortDiagnosis_help.h"

/* FUNCTION TO TEST */
tBDRV_offState BDRV_checkShortDiagnosis(void)
{
  sint8 s8_returnCode;
  tBDRV_offState s_offStateDiag;
  uint32 u32_intEnNode0 = 0;
  uint32 u32_intEnNode1 = 0;
  s8_returnCode = ERR_LOG_SUCCESS;
  //lint --e(9034)
  s_offStateDiag.b_globFailSts = false;
  s_offStateDiag.e_offStateDiagPhase1 = BDRV_offStateDiag_ok;
  s_offStateDiag.e_offStateDiagPhase2 = BDRV_offStateDiag_ok;
#if (UC_SERIES == 989)
  s_offStateDiag.e_offStateDiagPhase3 = BDRV_offStateDiag_ok;
#endif
  /* Save BDRV interrupt enable */
  u32_intEnNode0 = CPU->NVIC_ISER.bit.IRQEN0;
  u32_intEnNode1 = CPU->NVIC_ISER.bit.IRQEN1;
  /* Disable BDRV interrupt */
  CPU->NVIC_ICER.bit.IRQCLREN0 = 1u;
  CPU->NVIC_ICER.bit.IRQCLREN1 = 1u;
  /* Set Drain-Source comparator threshold to value < 1V */
  BDRV->CTRL2.bit.DSMONVTH = 3;
  /* Enable all gate drivers */
#if (UC_SERIES == 988)
  s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en);
#elif (UC_SERIES == 989)
  s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en);
#endif

  if (s8_returnCode == ERR_LOG_SUCCESS)
  {
    /* Activate diagnosis current sources */
#if (UC_SERIES == 988)
    s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_hsDcs, BDRV_chCfg_en, BDRV_chCfg_hsDcs);
#elif (UC_SERIES == 989)
    s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_hsDcs, BDRV_chCfg_en, BDRV_chCfg_hsDcs, BDRV_chCfg_en, BDRV_chCfg_hsDcs);
#endif

    if (s8_returnCode == ERR_LOG_SUCCESS)
    {
      //lint --e{9034}
      /* Delay for the diagnosis current source to settle - it depends on the attached motor */
      SCU_delay_us(800u);
      /* Clear status flags */
      BDRV_clrFaultSts();

      /* Check status flags */
      if (BDRV_getLS1DrainSrcMonitoringSts() == 1u)
      {
        s_offStateDiag.b_globFailSts = true;
        s_offStateDiag.e_offStateDiagPhase1 = BDRV_offStateDiag_short2gnd;
      }

      if (BDRV_getHS1DrainSrcMonitoringSts() == 1u)
      {
        s_offStateDiag.b_globFailSts = true;
        s_offStateDiag.e_offStateDiagPhase1 = BDRV_offStateDiag_short2bat;
      }

      if (BDRV_getLS2DrainSrcMonitoringSts() == 1u)
      {
        s_offStateDiag.b_globFailSts = true;
        s_offStateDiag.e_offStateDiagPhase2 = BDRV_offStateDiag_short2gnd;
      }

      if (BDRV_getHS2DrainSrcMonitoringSts() == 1u)
      {
        s_offStateDiag.b_globFailSts = true;
        s_offStateDiag.e_offStateDiagPhase2 = BDRV_offStateDiag_short2bat;
      }

#if (UC_SERIES == 989)

      if (BDRV_getLS3DrainSrcMonitoringSts() == 1u)
      {
        s_offStateDiag.b_globFailSts = true;
        s_offStateDiag.e_offStateDiagPhase3 = BDRV_offStateDiag_short2gnd;
      }

      if (BDRV_getHS3DrainSrcMonitoringSts() == 1u)
      {
        s_offStateDiag.b_globFailSts = true;
        s_offStateDiag.e_offStateDiagPhase3 = BDRV_offStateDiag_short2bat;
      }

#endif
      /* Switch-off all drivers */
#if (UC_SERIES == 988)
      s8_returnCode = BDRV_setBridge(BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off);
#elif (UC_SERIES == 989)
      s8_returnCode = BDRV_setBridge(BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off, BDRV_chCfg_off);
#endif

      if (s8_returnCode == ERR_LOG_SUCCESS)
      {
        /* Restore BDRV interrupt enable */
        if (u32_intEnNode0 == (uint32)1u)
        {
          CPU->NVIC_ISER.bit.IRQEN0 = 1u;
        }

        if (u32_intEnNode1 == (uint32)1u)
        {
          CPU->NVIC_ISER.bit.IRQEN1 = 1u;
        }
      }
    }
  }

  return s_offStateDiag;
}