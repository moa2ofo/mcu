#include "CANTRX_init_help.h"

/* FUNCTION TO TEST */
sint8 CANTRX_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if ((CANTRX_CTRL & CANTRX_CTRL_EN_Msk) == CANTRX_CTRL_EN_Msk)
  s8_returnCode = ERR_LOG_SUCCESS;
  CANTRX->CTRL.reg = (uint32)CANTRX_CTRL;
#endif
  return s8_returnCode;
}