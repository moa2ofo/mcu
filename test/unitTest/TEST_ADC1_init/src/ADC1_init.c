#include "ADC1_init_help.h"

/* FUNCTION TO TEST */
sint8 ADC1_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if ((ADC1_GLOBCONF & ADC1_GLOBCONF_EN_Msk) == ADC1_GLOBCONF_EN_Msk)
  s8_returnCode = ERR_LOG_SUCCESS;
  /* Enable internal VAREF */
  ARVG_enVAREF();
  /* Configure ADC1 clock */
  ADC1->CLKCON.reg = (uint32)ADC1_CLKCON;
  /* Enable ADC1 */
  ADC1->GLOBCONF.reg = (uint32)ADC1_GLOBCONF;

  /* ADC1 startup time: wait until ADC1 is ready */
  while (ADC1_getReady() == 0) {}

  /* Debug behavior, tbd */
  //ADC1->SUSCTR.reg = ...;
  /* Configure channel class 0 */
  ADC1->CONVCFG0.reg = (uint32)ADC1_CONVCFG0;
  /* Configure channel class 1 */
  ADC1->CONVCFG1.reg = (uint32)ADC1_CONVCFG1;
  /* Configure channel class 2 */
  ADC1->CONVCFG2.reg = (uint32)ADC1_CONVCFG2;
  /* Configure channel class 3 */
  ADC1->CONVCFG3.reg = (uint32)ADC1_CONVCFG3;
  /* Configure filter class */
  ADC1->FILTCFG.reg = (uint32)ADC1_FILTCFG;
  /* Configure compare channel 0 */
  ADC1->CMPCFG0.reg = (uint32)ADC1_CMPCFG0;
  /* Configure compare channel 1 */
  ADC1->CMPCFG1.reg = (uint32)ADC1_CMPCFG1;
  /* Configure compare channel 2 */
  ADC1->CMPCFG2.reg = (uint32)ADC1_CMPCFG2;
  /* Configure compare channel 3 */
  ADC1->CMPCFG3.reg = (uint32)ADC1_CMPCFG3;
  /* Configure digital channel 0 */
  ADC1->CHCFG0.reg = (uint32)ADC1_CHCFG0;
  /* Configure digital channel 1 */
  ADC1->CHCFG1.reg = (uint32)ADC1_CHCFG1;
  /* Configure digital channel 2 */
  ADC1->CHCFG2.reg = (uint32)ADC1_CHCFG2;
  /* Configure digital channel 3 */
  ADC1->CHCFG3.reg = (uint32)ADC1_CHCFG3;
  /* Configure digital channel 4 */
  ADC1->CHCFG4.reg = (uint32)ADC1_CHCFG4;
  /* Configure digital channel 5 */
  ADC1->CHCFG5.reg = (uint32)ADC1_CHCFG5;
  /* Configure digital channel 6 */
  ADC1->CHCFG6.reg = (uint32)ADC1_CHCFG6;
  /* Configure digital channel 7 */
  ADC1->CHCFG7.reg = (uint32)ADC1_CHCFG7;
  /* Configure digital channel 8 */
  ADC1->CHCFG8.reg = (uint32)ADC1_CHCFG8;
  /* Configure digital channel 9 */
  ADC1->CHCFG9.reg = (uint32)ADC1_CHCFG9;
  /* Configure digital channel 10 */
  ADC1->CHCFG10.reg = (uint32)ADC1_CHCFG10;
  /* Configure digital channel 11 */
  ADC1->CHCFG11.reg = (uint32)ADC1_CHCFG11;
  /* Configure digital channel 12 */
  ADC1->CHCFG12.reg = (uint32)ADC1_CHCFG12;
  /* Configure digital channel 13 */
  ADC1->CHCFG13.reg = (uint32)ADC1_CHCFG13;
  /* Configure digital channel 14 */
  ADC1->CHCFG14.reg = (uint32)ADC1_CHCFG14;
  /* Configure digital channel 15 */
  ADC1->CHCFG15.reg = (uint32)ADC1_CHCFG15;
  /* Configure digital channel 16 */
  ADC1->CHCFG16.reg = (uint32)ADC1_CHCFG16;
  /* Configure digital channel 17 */
  ADC1->CHCFG17.reg = (uint32)ADC1_CHCFG17;
  /* Configure digital channel 18 */
  ADC1->CHCFG18.reg = (uint32)ADC1_CHCFG18;
  /* Configure digital channel 19 */
  ADC1->CHCFG19.reg = (uint32)ADC1_CHCFG19;
  /* Configure calibration */
  ADC1->CALEN.reg = (uint32)ADC1_CALEN;
  /* Configure sequencer 0 */
  ADC1->SQCFG0.reg = (uint32)ADC1_SQCFG0;
  /* Configure sequencer 0 slots */
  ADC1->SQSLOT0.reg = (uint32)ADC1_SQSLOT0;
  /* Configure sequencer 1 */
  ADC1->SQCFG1.reg = (uint32)ADC1_SQCFG1;
  /* Configure sequencer 1 slots */
  ADC1->SQSLOT1.reg = (uint32)ADC1_SQSLOT1;
  /* Configure sequencer 2 */
  ADC1->SQCFG2.reg = (uint32)ADC1_SQCFG2;
  /* Configure sequencer 2 slots */
  ADC1->SQSLOT2.reg = (uint32)ADC1_SQSLOT2;
  /* Configure sequencer 3 */
  ADC1->SQCFG3.reg = (uint32)ADC1_SQCFG3;
  /* Configure sequencer 3 slots */
  ADC1->SQSLOT3.reg = (uint32)ADC1_SQSLOT3;
  /* Shadow transfer trigger set to software */
  ADC1->SHDCTR.reg = (uint32)ADC1_SHADOWTRANS_EN;
  ADC1->SHDCTR.reg = (uint32)ADC1_SHADOWTRANS_BY_SW;
#endif
  return s8_returnCode;
}