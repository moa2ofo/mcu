#include "PMU_clrFailSafeWatchdogFailSts_help.h"

/* FUNCTION TO TEST */
void PMU_clrFailSafeWatchdogFailSts(void)
{
  while (PMU->FS_STS.bit.WD_FAIL_STS == 1u)
  {
    if (PMU_serviceFailSafeWatchdog() == ERR_LOG_SUCCESS)
    {
      PMU->FS_STS_CLR.bit.WD_FAIL_STS_CLR = 1u;
    }
  }
}