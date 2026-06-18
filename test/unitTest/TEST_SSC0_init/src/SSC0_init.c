#include "SSC0_init_help.h"

/* FUNCTION TO TEST */
sint8 SSC0_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if ((SCU_PMCON & SCU_PMCON_SSC0_DIS_Msk) == 0u)
  s8_returnCode = ERR_LOG_SUCCESS;
  SSC0->CON.reg = (uint32)SSC0_CON;
  SSC0->INSEL.reg = (uint32)SSC0_INSEL;
  SSC0->CSTIM.reg = (uint32)SSC0_CSTIM;
  SSC0->BR.reg = (uint32)SSC0_BR;
#endif
  return s8_returnCode;
}