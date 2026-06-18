#include "GPT12_init_help.h"

/* FUNCTION TO TEST */
sint8 GPT12_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if ((SCU_PMCON & SCU_PMCON_GPT12_DIS_Msk) == 0u)
  s8_returnCode = ERR_LOG_SUCCESS;
  GPT12->T2CON.reg = GPT12_T2CON;
  GPT12->T2.reg = GPT12_T2;
  GPT12->T3CON.reg = GPT12_T3CON;
  GPT12->T3.reg = GPT12_T3;
  GPT12->T4CON.reg = GPT12_T4CON;
  GPT12->T4.reg = GPT12_T4;
  GPT12->T5CON.reg = GPT12_T5CON;
  GPT12->T5.reg = GPT12_T5;
  GPT12->T6CON.reg = GPT12_T6CON;
  GPT12->T6.reg = GPT12_T6;
  GPT12->CAPREL.reg = GPT12_CAPREL;
  GPT12->PISEL.reg = GPT12_PISEL;
#endif
  return s8_returnCode;
}