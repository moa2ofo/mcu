#include "T20_init_help.h"

/* FUNCTION TO TEST */
sint8 T20_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if ((SCU_PMCON & SCU_PMCON_T2_DIS_Msk) == 0u)
  s8_returnCode = ERR_LOG_SUCCESS;
  T20->CON.reg = (uint32)T20_CON;
  T20->MOD.reg = (uint32)T20_MOD;
  T20->RC.reg = (uint32)T20_RC;
  T20->CNT.reg = (uint32)T20_CNT;
#endif
  return s8_returnCode;
}