#include "SSC1_init_help.h"

/* FUNCTION TO TEST */
sint8 SSC1_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if ((SCU_PMCON & SCU_PMCON_SSC1_DIS_Msk) == 0u)
  s8_returnCode = ERR_LOG_SUCCESS;
  SSC1->CON.reg = (uint32)SSC1_CON;
  SSC1->INSEL.reg = (uint32)SSC1_INSEL;
  SSC1->CSTIM.reg = (uint32)SSC1_CSTIM;
  SSC1->BR.reg = (uint32)SSC1_BR;
#endif
  return s8_returnCode;
}