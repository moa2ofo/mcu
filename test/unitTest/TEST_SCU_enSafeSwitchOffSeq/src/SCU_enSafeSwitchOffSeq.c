#include "SCU_enSafeSwitchOffSeq_help.h"

/* FUNCTION TO TEST */
sint8 SCU_enSafeSwitchOffSeq(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;
  /* Initialize the Fail-Safe Watchdog */
  s8_returnCode = PMU_initFailSafeWatchdog();

  if (s8_returnCode == ERR_LOG_SUCCESS)
  {
    /* Initialize the CSA/CSC module */
    s8_returnCode = CSACSC_init();

    if (s8_returnCode == ERR_LOG_SUCCESS)
    {
      /* Initialize the Bridge Driver module */
      s8_returnCode = BDRV_init();
    }
  }

  return s8_returnCode;
}