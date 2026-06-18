#include "BDRV_checkOpenLoad_help.h"

/* FUNCTION TO TEST */
tBDRV_offState BDRV_checkOpenLoad(void)
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
  /* Set Drain-Source comparator threshold to smallest value */
  BDRV->CTRL2.bit.DSMONVTH = 0u;
  /* CHECK PHASE 1 */
#if (UC_SERIES == 988)
  /* TLE988x: Enable HS2 diagnosis current source */
  s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_hsDcs);
#elif (UC_SERIES == 989)
  /* TLE989x: Enable HS2 (&& HS3) diagnosis current source */
  s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_hsDcs, BDRV_chCfg_en, BDRV_chCfg_hsDcs);
#endif

  if (s8_returnCode == ERR_LOG_SUCCESS)
  {
    /* Delay for the diagnosis current source to settle - it depends on the attached motor */
    SCU_delay_us(800u);
    /* Clear status flags */
    BDRV_clrFaultSts();

    /* Check status flags */
    if (BDRV_getHS1DrainSrcMonitoringSts() == 1u)
    {
      //lint --e(9034)
      s_offStateDiag.b_globFailSts = true;
      s_offStateDiag.e_offStateDiagPhase1 = BDRV_offStateDiag_openload;
    }

    /* CHECK PHASE 2 */
#if (UC_SERIES == 988)
    /* TLE988x: Enable HS1 diagnosis current source */
    s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_hsDcs, BDRV_chCfg_en, BDRV_chCfg_en);
#elif (UC_SERIES == 989)
    /* TLE989x: Enable HS1 (&& HS3) diagnosis current source */
    s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_hsDcs, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_en, BDRV_chCfg_hsDcs);
#endif

    if (s8_returnCode == ERR_LOG_SUCCESS)
    {
      /* Delay for the diagnosis current source to settle - it depends on the attached motor */
      SCU_delay_us(800u);
      /* Clear status flags */
      BDRV_clrFaultSts();

      /* Check status flags */
      if (BDRV_getHS2DrainSrcMonitoringSts() == 1u)
      {
        //lint --e(9034)
        s_offStateDiag.b_globFailSts = true;
        s_offStateDiag.e_offStateDiagPhase2 = BDRV_offStateDiag_openload;
      }

#if (UC_SERIES == 989)
      /* CHECK PHASE 3 */
      /* TLE989x: Enable HS2 (&& HS3) diagnosis current source */
      s8_returnCode = BDRV_setBridge(BDRV_chCfg_en, BDRV_chCfg_hsDcs, BDRV_chCfg_en, BDRV_chCfg_hsDcs, BDRV_chCfg_en, BDRV_chCfg_en);

      if (s8_returnCode == ERR_LOG_SUCCESS)
      {
        /* Delay for the diagnosis current source to settle - it depends on the attached motor */
        SCU_delay_us(800u);
        /* Clear status flags */
        BDRV_clrFaultSts();

        /* Check status flags */
        if (BDRV_getHS3DrainSrcMonitoringSts() == 1u)
        {
          //lint --e(9034)
          s_offStateDiag.b_globFailSts = true;
          s_offStateDiag.e_offStateDiagPhase3 = BDRV_offStateDiag_openload;
        }
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