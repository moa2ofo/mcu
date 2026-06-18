#include "SCU_enterStopMode_help.h"

/* FUNCTION TO TEST */
sint8 SCU_enterStopMode(void)
{
  sint8 s8_returnCode;
  uint32 u32_p0Dir;
  uint32 u32_p1Dir;
  uint32 u32_p0Pud;
  uint32 u32_p1Pud;
  uint32 u32_p2Pud;
  uint32 u32_int;
  s8_returnCode = ERR_LOG_SUCCESS;
  /* Saving the GPIOs settings */
  u32_p0Dir = GPIO->P0_DIR.reg;
  u32_p1Dir = GPIO->P1_DIR.reg;
  u32_p0Pud = GPIO->P0_PUD.reg;
  u32_p1Pud = GPIO->P1_PUD.reg;
  u32_p2Pud = GPIO->P2_PUD.reg;
  /* Saving the interrupt settings */
  u32_int = CPU->NVIC_ISER.reg;
  /* The RAM reduction is configured by default in the Config Wizard */
  /* Clear all wake-up status flags */
  PMU->WAKE_STS_CLR.reg = (uint32)0x1FF73F5u;
  /* The wake-up source can be configured in the Config Wizard */
  /* Select HP_CLK as system clock*/
  /* As the system will start the HP_CLK after the reset anyway, it is to avoid any problems with the PLL clocks in between */
  SCU->CLKSEL.bit.SELSYS0 = 0u;
  SCU->CLKSEL.bit.SELSYS1 = 0u;
  /* Disable XTAL_OSC */
  SCU->XTALCON.bit.XWDGEN = 0u;
  SCU->XTALCON.bit.XPD = 1u;
  /* Disable all interrupts */
  CPU->NVIC_ICER.reg = (uint32)0xFFFFFFFFu;
  /* Enter Stop Mode */
  SCU->PMCON0.bit.STOP = 1u;
  /* Free up pipeline */
  CMSIS_NOP();
  CMSIS_NOP();
  CMSIS_NOP();
  /* Set send event */
  CMSIS_SEV();
  /* Clear send event */
  CMSIS_WFE();
  /* Enter CPU Deep Sleep */
  CMSIS_WFE();
  /* Exit Stop Mode */
  /* Free up the pipeline */
  CMSIS_NOP();
  CMSIS_NOP();
  CMSIS_NOP();
  /* Initialize the system */
  SystemInit();
  /* Release Safe Switch-Off path */
  s8_returnCode = SCU_enSafeSwitchOffSeq();
  /* Enable the interrupts to their states before stop mode*/
  CPU->NVIC_ISER.reg = u32_int;
  /* Program GPIOs to their states before stop mode */
  GPIO->P0_DIR.reg = u32_p0Dir;
  GPIO->P0_PUD.reg = u32_p0Pud;
  GPIO->P1_DIR.reg = u32_p1Dir;
  GPIO->P1_PUD.reg = u32_p1Pud;
  GPIO->P2_PUD.reg = u32_p2Pud;
  return s8_returnCode;
}