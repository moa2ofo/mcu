#include "CSACSC_init_help.h"

/* FUNCTION TO TEST */
sint8 CSACSC_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if ((CSACSC_CTRL1 & CSACSC_CTRL1_CSAC_EN_Msk) == CSACSC_CTRL1_CSAC_EN_Msk)
  /* Program gain min., offset min. and threshold max., CSAC_EN remains reset */
  CSACSC->CTRL1.reg = (uint32)CSACSC_CTRL1 & (uint32)~CSACSC_CTRL1_CSAC_EN_Msk;
  /* Set CSAC_EN */
  CSACSC->CTRL1.reg = CSACSC_CTRL1;

  while ((CSACSC_getBistSts() == 0u) && (PMU->FS_STS.bit.CSC_BIST_FAIL_STS == 0u))
  {
    /* Wait until CSA/CSC BIST is finished, duration: 28us nom. */
    s8_returnCode = PMU_serviceFailSafeWatchdog();
  }

  if (CSACSC_getBistSts() == 1u)
  {
    /* CSA/CSC BIST passed, configure remaining parameters */
    CSACSC->CTRL2.reg = CSACSC_CTRL2;
    s8_returnCode = ERR_LOG_SUCCESS;
  }
  else
  {
    /* In case the BIST test failed: PMU->FS_STS.bit.CSC_BIST_FAIL_STS = 1 */
    s8_returnCode = ERR_LOG_ERROR;
  }

  /* Clear fail-safe related registers due to overcurrent flag after BIST */
  PMU->FS_STS_CLR.reg = (uint32)0x17FFFu;
  PMU->FS_SSD_CLR.reg = (uint32)0x3u;
#endif
  return s8_returnCode;
}