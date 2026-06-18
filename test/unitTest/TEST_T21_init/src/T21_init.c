#include "T21_init_help.h"

/* FUNCTION TO TEST */
sint8 T21_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if ((SCU_PMCON & SCU_PMCON_T21_DIS_Msk) == 0u)
  s8_returnCode = ERR_LOG_SUCCESS;
  T21->CON.reg = (uint32)T21_CON;
  T21->MOD.reg = (uint32)T21_MOD;
  T21->RC.reg = (uint32)T21_RC;
  T21->CNT.reg = (uint32)T21_CNT;
#endif
  return s8_returnCode;
}