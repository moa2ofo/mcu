#include "SDADC_init_help.h"

/* FUNCTION TO TEST */
sint8 SDADC_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if (SDADC_GLOBCONF_EN == 1u)
  s8_returnCode = ERR_LOG_SUCCESS;
  SDADC->CFG0.reg = (uint32)SDADC_CFG0;
  SDADC->CFG1.reg = (uint32)SDADC_CFG1;
  SDADC->CMP0_CTRL.reg = (uint32)SDADC_CMP0_CTRL;
  SDADC->CMP1_CTRL.reg = (uint32)SDADC_CMP1_CTRL;
  SDADC->ALTSEL.reg = (uint32)SDADC_ALTSEL;
  SDADC->INSEL.reg = (uint32)SDADC_INSEL;
  SDADC->DITHCFG.reg = (uint32)SDADC_DITHCFG;
#endif
  return s8_returnCode;
}