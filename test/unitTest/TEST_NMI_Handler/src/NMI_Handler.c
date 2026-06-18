#include "NMI_Handler_help.h"

/* FUNCTION TO TEST */
void NMI_Handler(void)
{
  /* XTAL Watchdog Fail */
#if (SCU_NMICON_NMIXTALEN_NMI_EN == 1)
  if (SCU->NMICON.bit.NMIXTALEN == 1u)
  {
    if (SCU->NMISR.bit.NMIXTAL == 1u)
    {
      SCU_NMICON_NMIXTALEN_CALLBACK();
      SCU->NMISRC.bit.NMIXTALCLR = 1u;
    }
  }

#endif /* Interrupt enabled */
  /* PLL0 Loss of Lock */
#if (SCU_NMICON_NMIPLL0EN_NMI_EN == 1)

  if (SCU->NMICON.bit.NMIPLL0EN == 1u)
  {
    if (SCU->NMISR.bit.NMIPLL0 == 1u)
    {
      SCU_NMICON_NMIPLL0EN_CALLBACK();
      SCU->NMISRC.bit.NMIPLL0CLR = 1u;
    }
  }

#endif /* Interrupt enabled */
  /* PLL1 Loss of Lock */
#if (SCU_NMICON_NMIPLL1EN_NMI_EN == 1)

  if (SCU->NMICON.bit.NMIPLL1EN == 1u)
  {
    if (SCU->NMISR.bit.NMIPLL1 == 1u)
    {
      SCU_NMICON_NMIPLL1EN_CALLBACK();
      SCU->NMISRC.bit.NMIPLL1CLR = 1u;
    }
  }

#endif /* Interrupt enabled */
  /* DSRAM Double Bit ECC Error */
#if (MEMCTRL_NMICON_NMIDSEN_NMI_EN == 1)

  if (MEMCTRL->NMICON.bit.NMIDSEN == 1u)
  {
    if (MEMCTRL->NMISR.bit.NMIDS == 1u)
    {
      MEMCTRL_NMICON_NMIDSEN_CALLBACK();
      MEMCTRL->NMISRC.bit.NMIDSCLR = 1u;
    }
  }

#endif /* Interrupt enabled */
  /* PSRAM Double Bit ECC Error */
#if (MEMCTRL_NMICON_NMIPSEN_NMI_EN == 1)

  if (MEMCTRL->NMICON.bit.NMIPSEN == 1u)
  {
    if (MEMCTRL->NMISR.bit.NMIPS == 1u)
    {
      MEMCTRL_NMICON_NMIPSEN_CALLBACK();
      MEMCTRL->NMISRC.bit.NMIPSCLR = 1u;
    }
  }

#endif /* Interrupt enabled */
  /* Cache Data RAM Double Bit ECC Error */
#if (MEMCTRL_NMICON_NMICDEN_NMI_EN == 1)

  if (MEMCTRL->NMICON.bit.NMICDEN == 1u)
  {
    if (MEMCTRL->NMISR.bit.NMICD == 1u)
    {
      MEMCTRL_NMICON_NMICDEN_CALLBACK();
      MEMCTRL->NMISRC.bit.NMICDCLR = 1u;
    }
  }

#endif /* Interrupt enabled */
  /* NVM0 Double Bit ECC Error NMI Enable */
#if (MEMCTRL_NMICON_NMINVM0EN_NMI_EN == 1)

  if (MEMCTRL->NMICON.bit.NMINVM0EN == 1u)
  {
    if (MEMCTRL->NMISR.bit.NMINVM0 == 1u)
    {
      MEMCTRL_NMICON_NMINVM0EN_CALLBACK();
      MEMCTRL->NMISRC.bit.NMINVM0CLR = 1u;
    }
  }

#endif /* Interrupt enabled */
  /* NVM1 Double Bit ECC Error */
#if (MEMCTRL_NMICON_NMINVM1EN_NMI_EN == 1)

  if (MEMCTRL->NMICON.bit.NMINVM1EN == 1u)
  {
    if (MEMCTRL->NMISR.bit.NMINVM1 == 1u)
    {
      MEMCTRL_NMICON_NMINVM1EN_CALLBACK();
      MEMCTRL->NMISRC.bit.NMINVM1CLR = 1u;
    }
  }

#endif /* Interrupt enabled */
  /* NVM0 MAP Error */
#if (MEMCTRL_NMICON_NMIMAP0EN_NMI_EN == 1)

  if (MEMCTRL->NMICON.bit.NMIMAP0EN == 1u)
  {
    if (MEMCTRL->NMISR.bit.NMIMAP0 == 1u)
    {
      MEMCTRL_NMICON_NMIMAP0EN_CALLBACK();
      MEMCTRL->NMISRC.bit.NMIMAP0CLR = 1u;
    }
  }

#endif /* Interrupt enabled */
  /* NVM1 MAP Error */
#if (MEMCTRL_NMICON_NMIMAP1EN_NMI_EN == 1)

  if (MEMCTRL->NMICON.bit.NMIMAP1EN == 1u)
  {
    if (MEMCTRL->NMISR.bit.NMIMAP1 == 1u)
    {
      MEMCTRL_NMICON_NMIMAP1EN_CALLBACK();
      MEMCTRL->NMISRC.bit.NMIMAP1CLR = 1u;
    }
  }

#endif /* Interrupt enabled */
  /* Watchdog Timer */
#if (MEMCTRL_NMICON_NMIWDTEN_NMI_EN == 1)

  if (MEMCTRL->NMICON.bit.NMIWDTEN == 1u)
  {
    if (MEMCTRL->NMISR.bit.NMIWDT == 1u)
    {
      MEMCTRL_NMICON_NMIWDTEN_CALLBACK();
      MEMCTRL->NMISRC.bit.NMIWDTCLR = 1u;
    }
  }

#endif /* Interrupt enabled */
  /* Stack Overflow */
#if (MEMCTRL_NMICON_NMISTOFEN_NMI_EN == 1)

  if (MEMCTRL->NMICON.bit.NMISTOFEN == 1u)
  {
    if (MEMCTRL->NMISR.bit.NMISTOF == 1u)
    {
      MEMCTRL_NMICON_NMISTOFEN_CALLBACK();
      MEMCTRL->NMISRC.bit.NMISTOFCLR = 1u;
    }
  }

#endif /* Interrupt enabled */
  /* ADC2 UPTH0 */
#if (ADC2_UPTH0_INT_EN == 1)
#if ((ADC2_INP2 & ADC2_INP2_INP_CMP_UP0_Msk) >>  ADC2_INP2_INP_CMP_UP0_Pos == NMI_INP_NMI)

  if (ADC2->IEN1.bit.IEN_UP0 == 1u)
  {
    if (ADC2->CMPSTAT.bit.CMP_UP0_IS == 1u)
    {
      ADC2_UPTH0_CALLBACK();
      ADC2->CMPSTATCLR.bit.CMP_UP0_ISCLR = 1u;
    }
  }

#endif /* Interrupt assigned to this Node */
#endif /* Interrupt enabled */
  /* ADC2 LOTH0 */
#if (ADC2_LOTH0_INT_EN == 1)
#if ((ADC2_INP2 & ADC2_INP2_INP_CMP_LO0_Msk) >>  ADC2_INP2_INP_CMP_LO0_Pos == NMI_INP_NMI)

  if (ADC2->IEN1.bit.IEN_LO0 == 1u)
  {
    if (ADC2->CMPSTAT.bit.CMP_LO0_IS == 1u)
    {
      ADC2_LOTH0_CALLBACK();
      ADC2->CMPSTATCLR.bit.CMP_LO0_ISCLR = 1u;
    }
  }

#endif /* Interrupt assigned to this Node */
#endif /* Interrupt enabled */
  /* ADC2 LOTH1 */
#if (ADC2_LOTH1_INT_EN == 1)
#if ((ADC2_INP2 & ADC2_INP2_INP_CMP_LO1_Msk) >>  ADC2_INP2_INP_CMP_LO1_Pos == NMI_INP_NMI)

  if (ADC2->IEN1.bit.IEN_LO1 == 1u)
  {
    if (ADC2->CMPSTAT.bit.CMP_LO1_IS == 1u)
    {
      ADC2_LOTH1_CALLBACK();
      ADC2->CMPSTATCLR.bit.CMP_LO1_ISCLR = 1u;
    }
  }

#endif /* Interrupt assigned to this Node */
#endif /* Interrupt enabled */
  /* ADC2 UPTH2 */
#if (ADC2_UPTH2_INT_EN == 1)
#if ((ADC2_INP2 & ADC2_INP2_INP_CMP_UP2_Msk) >>  ADC2_INP2_INP_CMP_UP2_Pos == NMI_INP_NMI)

  if (ADC2->IEN1.bit.IEN_UP2 == 1u)
  {
    if (ADC2->CMPSTAT.bit.CMP_UP2_IS == 1u)
    {
      ADC2_UPTH2_CALLBACK();
      ADC2->CMPSTATCLR.bit.CMP_UP2_ISCLR = 1u;
    }
  }

#endif /* Interrupt assigned to this Node */
#endif /* Interrupt enabled */
  /* ADC2 LOTH2 */
#if (ADC2_LOTH2_INT_EN == 1)
#if ((ADC2_INP2 & ADC2_INP2_INP_CMP_LO2_Msk) >>  ADC2_INP2_INP_CMP_LO2_Pos == NMI_INP_NMI)

  if (ADC2->IEN1.bit.IEN_LO2 == 1u)
  {
    if (ADC2->CMPSTAT.bit.CMP_LO2_IS == 1u)
    {
      ADC2_LOTH2_CALLBACK();
      ADC2->CMPSTATCLR.bit.CMP_LO2_ISCLR = 1u;
    }
  }

#endif /* Interrupt assigned to this Node */
#endif /* Interrupt enabled */
  /* ADC2 LOTH3 */
#if (ADC2_LOTH3_INT_EN == 1)
#if ((ADC2_INP2 & ADC2_INP2_INP_CMP_LO3_Msk) >>  ADC2_INP2_INP_CMP_LO3_Pos == NMI_INP_NMI)

  if (ADC2->IEN1.bit.IEN_LO3 == 1u)
  {
    if (ADC2->CMPSTAT.bit.CMP_LO3_IS == 1u)
    {
      ADC2_LOTH3_CALLBACK();
      ADC2->CMPSTATCLR.bit.CMP_LO3_ISCLR = 1u;
    }
  }

#endif /* Interrupt assigned to this Node */
#endif /* Interrupt enabled */
  /* ADC2 UPTH4 */
#if (ADC2_UPTH4_INT_EN == 1)
#if ((ADC2_INP2 & ADC2_INP2_INP_CMP_UP4_Msk) >>  ADC2_INP2_INP_CMP_UP4_Pos == NMI_INP_NMI)

  if (ADC2->IEN1.bit.IEN_UP4 == 1u)
  {
    if (ADC2->CMPSTAT.bit.CMP_UP4_IS == 1u)
    {
      ADC2_UPTH4_CALLBACK();
      ADC2->CMPSTATCLR.bit.CMP_UP4_ISCLR = 1u;
    }
  }

#endif /* Interrupt assigned to this Node */
#endif /* Interrupt enabled */
}