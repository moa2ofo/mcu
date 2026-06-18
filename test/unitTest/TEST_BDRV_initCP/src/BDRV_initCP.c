#include "BDRV_initCP_help.h"

/* FUNCTION TO TEST */
sint8 BDRV_initCP(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if (BDRV_GLOBCONF_EN == 1u)
  s8_returnCode = ERR_LOG_SUCCESS;
  BDRV->CP_CTRL.reg = (uint32)BDRV_CP_CTRL;
  BDRV->CP_CLK_CTRL.reg = (uint32)BDRV_CP_CLK_CTRL;
#endif
  return s8_returnCode;
}