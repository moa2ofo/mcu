#include "ADC2_init_help.h"

/* FUNCTION TO TEST */
sint8 ADC2_init(void)
{
  sint8 s8_returnCode;
  uint16 i;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if ((ADC2_GLOBCONF & ADC2_GLOBCONF_EN_Msk) == ADC2_GLOBCONF_EN_Msk)
  s8_returnCode = ERR_LOG_SUCCESS;
  /* Configure ADC2 clock */
  ADC2->CLKCON.reg = (uint32)ADC2_CLKCON;
  /* Enable ADC2 */
  ADC2->GLOBCONF.reg = (uint32)ADC2_GLOBCONF;

  /* Wait 266 + 5133 tADC2 cycles */
  //Delay_us((266 + 5133) / ADC2_CLK );

  for (i = 0; i < 1000; i++)
  {
    CMSIS_NOP();
  }

  /* Debug behavior, tbd */
  //ADC2->SUSCTR.reg = ...;
  /* Configure channel class */
  ADC2->CONVCFG2.reg = (uint32)ADC2_CONVCFG2;
  ADC2->CONVCFG3.reg = (uint32)ADC2_CONVCFG3;
  /* Configure filter class - only configurable for Filter Channel 6 and 7 */
  ADC2->FILTCFG.bit.COEF_A6 = (uint8)(((uint32)ADC2_FILTCFG & ADC2_FILTCFG_COEF_A6_Msk) >> ADC2_FILTCFG_COEF_A6_Pos);
  ADC2->FILTCFG.bit.COEF_A7 = (uint8)((uint32)ADC2_FILTCFG & ADC2_FILTCFG_COEF_A7_Msk) >> ADC2_FILTCFG_COEF_A7_Pos;
  /* Configure compare channel - only configurable for Compare Channel 6 and 7 */
  ADC2->CMPCFG6.reg = (uint32)ADC2_CMPCFG6;
  ADC2->CMPCFG7.reg = (uint32)ADC2_CMPCFG7;
  /* Configure user-defined digital channels */
  ADC2->CHCFG0.reg = (uint32)ADC2_CHCFG0;
  ADC2->CHCFG4.reg = (uint32)ADC2_CHCFG4;
  ADC2->CHCFG5.reg = (uint32)ADC2_CHCFG5;
  ADC2->CHCFG6.reg = (uint32)ADC2_CHCFG6;
  ADC2->CHCFG7.reg = (uint32)ADC2_CHCFG7;
  ADC2->CHCFG9.reg = (uint32)ADC2_CHCFG9;
  ADC2->CHCFG10.reg = (uint32)ADC2_CHCFG10;
  ADC2->CHCFG11.reg = (uint32)ADC2_CHCFG11;
  ADC2->CHCFG12.reg = (uint32)ADC2_CHCFG12;
  /* Configure calibration */
  ADC2->CALEN.reg = (uint32)ADC2_CALEN;
#endif
  return s8_returnCode;
}