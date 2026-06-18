#include "PMU_serviceFailSafeWatchdogSOW_help.h"

/* FUNCTION TO TEST */
sint8 PMU_serviceFailSafeWatchdogSOW(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  if (PMU->WD_CTRL.bit.SOW != 0u)
  {
    PMU->WD_TRIG_SOW.bit.TRIG ^= 1u;
    //lint --e(9034)
    b_SOWactive = true;
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_SOW_DISABLED;
  }

  return s8_returnCode;
}