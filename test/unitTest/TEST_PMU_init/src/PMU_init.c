#include "PMU_init_help.h"

/* FUNCTION TO TEST */
sint8 PMU_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;
  PMU->START_CONFIG.reg = (uint32)PMU_START_CONFIG;
  /* Configure the FIFO pull-up resistor */
  PMU->MISC_CTRL.reg = (uint32)PMU_MISC_CTRL;
#if defined(UC_FEATURE_48PIN)
  {
    /* 48pin only, FIFO pull-up enabled */
    PMU->MISC_CTRL.bit.FI_PU_EN = 1;
  }
#endif
  /* Checking for possible reset trigger source(s) and resetting the status flags if necessary can be done in the application */
  PMU->RST_CTRL.reg = (uint32)PMU_RST_CTRL;

  /* Checking for possible hardware failure trigger source(s) and for possible wake-up
  trigger source(s) and resetting the status flags if necessary can be done in the application */
  if (PMU->WAKE_FAIL_STS.reg != (uint32)0u)
  {
    s8_returnCode = ERR_LOG_ERROR;
  }

  /* Configure the fail-safe watchdog - done in System_init */
  /* The safe-shutdown path is initialized in system_tle989x.c */
  /* Configure the voltage regulator */
  PMU->VDDP_CTRL.reg = (uint32)PMU_VDDP_CTRL;
  PMU->VDDC_CTRL.reg = (uint32)PMU_VDDC_CTRL;
  PMU->VDDEXT_CTRL.reg = (uint32)PMU_VDDEXT_CTRL;
  /* Configure the wake-up control unit */
  PMU->WAKE_FILT_CTRL.reg = (uint32)PMU_WAKE_FILT_CTRL;
  PMU->WAKE_GPIO_CTRL0.reg = (uint32)PMU_WAKE_GPIO_CTRL0;
  PMU->WAKE_GPIO_CTRL1.reg = (uint32)PMU_WAKE_GPIO_CTRL1;
  PMU->WAKE_GPIO_CTRL2.reg = (uint32)PMU_WAKE_GPIO_CTRL2;
  PMU->WAKE_GPIO_CTRL3.reg = (uint32)PMU_WAKE_GPIO_CTRL3;
  PMU->WAKE_GPIO_CTRL4.reg = (uint32)PMU_WAKE_GPIO_CTRL4;
  PMU->WAKE_GPIO_CTRL5.reg = (uint32)PMU_WAKE_GPIO_CTRL5;
  PMU->MON_CTRL1.reg = (uint32)PMU_MON_CTRL1;
  PMU->MON_CTRL2.reg = (uint32)PMU_MON_CTRL2;
  PMU->MON_CTRL3.reg = (uint32)PMU_MON_CTRL3;
  PMU->CYC_CTRL.reg = (uint32)PMU_CYC_CTRL;
  PMU->WAKE_CTRL.reg = (uint32)PMU_WAKE_CTRL;
  return s8_returnCode;
}