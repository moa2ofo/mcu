#include "SCU_initClk_help.h"

/* FUNCTION TO TEST */
sint8 SCU_initClk(void)
{
  sint8 s8_returnCode;
  uint8 u8_nmiEnTemp;
#if (((SCU_XTALCON & SCU_XTALCON_XPD_Msk) == 0u) || \
    ((SCU_PLL0_EN == 1u)) || \
    ((SCU_PLL1_EN == 1u)))
  uint32 u32_currentTime_ms;
  uint32 u32_endTime_ms;
#endif
  /* Prepare for CLK_Init: switch to HP40_Ckl, disable PLL, disable XTAL */
  SCU->CLKSEL.reg = 0x00000000u;
  PLL->CON0.bit.PLLEN = 0;
  PLL->CON1.bit.PLLEN = 0;
  SCU->XTALCON.reg = 0x00000033u;
  s8_returnCode = ERR_LOG_SUCCESS;
  /* Initialize Clock Sources */
  /* XTAL (only if needed) */
#if ((SCU_XTALCON & SCU_XTALCON_XPD_Msk) == 0u)
  e_xtalSts = ERR_LOG_SUCCESS;
  u8_nmiEnTemp = 0;

  if (SCU->NMICON.bit.NMIXTALEN == 1u)
  {
    SCU->NMICON.bit.NMIXTALEN = 0;
    u8_nmiEnTemp = 1u;
  }

  /* Disable P2.0 and P2.1 input */
  GPIO->P2_INDIS.reg |= 0x3;
  /* Configure XTALOSC, Start XTALOSC, Start XTALWDG */
  SCU->XTALCON.reg = SCU_XTALCON;
  u32_endTime_ms = INT_getGlobTimestamp() + SCU_XTAL_START_TIME_MS;

  do
  {
    /* wait for XTAL ok */
    u32_currentTime_ms = INT_getGlobTimestamp();
  }
  while ((SCU_GetXTALFailSts() == 1u) && (u32_currentTime_ms < u32_endTime_ms));

  /* Check timeout */
  if (u32_currentTime_ms >= u32_endTime_ms)
  {
    s8_returnCode = ERR_LOG_CODE_TIMEOUT;
    e_xtalSts = SCU_checkXTALDiagnosis();
  }

  /* Clear XTAL FAIL status */
  SCU->XTALSTATC.reg = SCU_XTALSTATC_XTAL_FAIL_STSCLR_Msk;
  /* Clear NMIXTAL status */
  SCU->NMISRC.reg = SCU_NMISRC_NMIXTALCLR_Msk;

  /* Enable XTAL NMI if needed */
  if (u8_nmiEnTemp == 1u)
  {
    SCU->NMICON.bit.NMIXTALEN = 1;
  }

#endif
  /* PLL0 (only if needed) */
#if (SCU_PLL0_EN == 1u)
  /* Disable PLLx NMI */
  u8_nmiEnTemp = 0u;

  if (SCU->NMICON.bit.NMIPLL0EN == 1u)
  {
    SCU->NMICON.bit.NMIPLL0EN = 0;
    u8_nmiEnTemp = 1u;
  }

  /* Configure PLLx */
  PLL->CON0.reg = (uint32)PLL_CON0 & (~PLL_CON0_PLLEN_Msk);
  PLL->SPCTR.reg |= (uint32)PLL_SPCTR & ((~(uint32)PLL_SPCTR_SPEN0_Msk) & 0x0000FFFFu);
  PLL->SPCTR.reg |= (uint32)PLL_SPCTR & PLL_SPCTR_SPEN0_Msk;
  /* Start PLLx */
  PLL->CON0.bit.PLLEN = 1;
  u32_endTime_ms = INT_getGlobTimestamp() + SCU_PLL0_START_TIME_MS;

  do
  {
    /* wait for PLLx being locked */
    u32_currentTime_ms = INT_getGlobTimestamp();
  }
  while ((SCU_GetPLL0LockSts() == 0u) && (u32_currentTime_ms < u32_endTime_ms));

  /* Check timeout */
  if (u32_currentTime_ms >= u32_endTime_ms)
  {
    s8_returnCode = ERR_LOG_CODE_TIMEOUT;
  }

  /* Clear PLLx Loss of Lock status */
  PLL->STATC.reg = PLL_STATC_PLL0_LOL_STSCLR_Msk;
  /* Clear PLLx NMI status */
  SCU->NMISRC.reg = SCU_NMISRC_NMIPLL0CLR_Msk;

  /* Enable PLLx NMI if needed */
  if (u8_nmiEnTemp == 1u)
  {
    SCU->NMICON.bit.NMIPLL0EN = 1;
  }

#endif
  /* PLL1 (only if needed) */
#if (SCU_PLL1_EN == 1u)
  /* Disable PLLx NMI */
  u8_nmiEnTemp = 0u;

  if (SCU->NMICON.bit.NMIPLL1EN == 1u)
  {
    SCU->NMICON.bit.NMIPLL1EN = 0;
    u8_nmiEnTemp = 1u;
  }

  /* Configure PLLx */
  PLL->CON1.reg = (uint32)PLL_CON1 & (~PLL_CON1_PLLEN_Msk);
  PLL->SPCTR.reg |= (uint32)PLL_SPCTR & ((~(uint32)PLL_SPCTR_SPEN1_Msk) & 0xFFFF0000u);
  PLL->SPCTR.reg |= (uint32)PLL_SPCTR & PLL_SPCTR_SPEN1_Msk;
  /* Start PLLx */
  PLL->CON1.bit.PLLEN = 1;
  u32_endTime_ms = INT_getGlobTimestamp() + SCU_PLL1_START_TIME_MS;

  do
  {
    /* wait for PLLx being locked */
    u32_currentTime_ms = INT_getGlobTimestamp();
  }
  while ((SCU_GetPLL1LockSts() == 0u) && (u32_currentTime_ms < u32_endTime_ms));

  /* Check timeout */
  if (u32_currentTime_ms >= u32_endTime_ms)
  {
    s8_returnCode = ERR_LOG_CODE_TIMEOUT;
  }

  /* Clear PLLx Loss of Lock status */
  PLL->STATC.reg = PLL_STATC_PLL1_LOL_STSCLR_Msk;
  /* Clear PLLx NMI status */
  SCU->NMISRC.reg = SCU_NMISRC_NMIPLL1CLR_Msk;

  /* Enable PLLx NMI if needed */
  if (u8_nmiEnTemp == 1u)
  {
    SCU->NMICON.bit.NMIPLL1EN = 1;
  }

#endif
  /* Initialize Clock tree Configuration */
  /* Don't enable CLKOUT here, done ein SCU_init */
  SCU->CLKSEL.reg = ((uint32)SCU_CLKSEL) & (~SCU_CLKSEL_CLKOUTEN_Msk);
  /* Write CLKCON=0 before setting CLKCON (PRECAN/PREUART can only be written when CANCLKEN/UARTCLKEN=0 */
  SCU->CLKEN.reg = (uint32)0u;
  SCU->CLKCON.reg = (uint32)SCU_CLKCON;
  SCU->CLKEN.reg = (uint32)SCU_CLKEN;
  return s8_returnCode;
}