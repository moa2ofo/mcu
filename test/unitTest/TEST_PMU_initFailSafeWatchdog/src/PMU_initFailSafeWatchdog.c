#include "PMU_initFailSafeWatchdog_help.h"

/* FUNCTION TO TEST */
sint8 PMU_initFailSafeWatchdog(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;
  /* Initialisation of the tick counter */
  u32_failsafeWatchdogCnt = 0u;

  /* A successful self-test of the fail-safe watchdog sets the FS_STS.WD_FAIL_STS bit */
  if (PMU_getWDFailSts() == 1u)
  {
    /* The watchdog starts in Long Open Window (typically 180 ms) */
    /* The fail-safe watchdog period can only be programmed during the LOW phase */
    /* wd_en is masked: the FW automatically resets the EN bit when entering debug mode or sets it when entering user mode */
    PMU->WD_CTRL.bit.WDP = (uint8)(((uint32)PMU_WD_CTRL & PMU_WD_CTRL_WDP_Msk) >> PMU_WD_CTRL_WDP_Pos);
    /* The number of SOW must be set before the first fail-safe watchdog in the LOW */
    PMU->WD_CTRL.bit.SOW = (uint8)(((uint32)PMU_WD_CTRL & PMU_WD_CTRL_SOW_Msk) >> PMU_WD_CTRL_SOW_Pos);
    /* The bit TRIG needs to be toggled to provide a proper trigger */
    PMU->WD_TRIG.bit.TRIG ^= 1u;
    /* The fail-safe watchdog counter must be reset, since a new window starts */
    u32_failsafeWatchdogCnt = 0;
    /* The fail-safe watchdog status bit must be cleared to release the safe shut-down */
    PMU_clrWDFailSts();
  }
  else
  {
    s8_returnCode = ERR_LOG_ERROR;
  }

  return s8_returnCode;
}