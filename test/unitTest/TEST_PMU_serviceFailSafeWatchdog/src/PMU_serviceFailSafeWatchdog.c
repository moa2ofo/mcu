#include "PMU_serviceFailSafeWatchdog_help.h"

/* FUNCTION TO TEST */
sint8 PMU_serviceFailSafeWatchdog(void)
{
  sint8 s8_returnCode;
  //lint --e(9034)
  static bool b_firstNOW = false;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check if the counter is within the effective open window (safe trigger point) or if a SOW service has been done before */
  if ((u32_failsafeWatchdogCnt > PMU_SAFE_TRIGGER) || b_SOWactive)
  {
    /* Service watchdog by toggling bit PMU->WD_TRIG.bit.TRIG */
    PMU->WD_TRIG.bit.TRIG ^= 1u;
    /* Reset the fail-safe watchdog counter */
    u32_failsafeWatchdogCnt = (uint32)0;
    /* Reset "short open window" active flag */
    //lint --e(9034)
    b_SOWactive = false;

    /* For the first normal window, the initialization of the fail-safe watchdog has to be completed */
    if (!b_firstNOW)
    {
      /* Clear SSD_STS and FO_STS bits */
      PMU->FS_SSD_CLR.reg = (uint32)(PMU_FS_SSD_CLR_SSD_STS_CLR_Msk | PMU_FS_SSD_CLR_FO_STS_CLR_Msk);
      /* The first normal open window has happened */
      //lint --e(9034)
      b_firstNOW = true;
    }
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_NO_TRIGGER;
  }

  return s8_returnCode;
}