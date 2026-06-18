#include "CCU7_init_help.h"

/* FUNCTION TO TEST */
sint8 CCU7_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if (CCU7_EN == 1)
  s8_returnCode = ERR_LOG_SUCCESS;
  /* Port */
  CCU7->PISEL0.reg = (uint32)CCU7_PISEL0;
  CCU7->PISEL2.reg = (uint32)CCU7_PISEL2;
  CCU7->PISEL24.reg = (uint32)CCU7_PISEL24;
  CCU7->PISEL25.reg = (uint32)CCU7_PISEL25;
  CCU7->PISEL26.reg = (uint32)CCU7_PISEL26;
  /* Clock */
  CCU7->T_FDIV0.reg = (uint32)CCU7_T_FDIV0;
  CCU7->T_FDIV1.reg = (uint32)CCU7_T_FDIV1;
  CCU7->T_CLK_CTRL.reg = (uint32)CCU7_T_CLK_CTRL;
  /* Control register */
  CCU7->TCTR0.reg = (uint32)CCU7_TCTR0;
  CCU7->TCTR2.reg = (uint32)CCU7_TCTR2;
  CCU7->TCTR24.reg = (uint32)CCU7_TCTR24;
  CCU7->TCTR25.reg = (uint32)CCU7_TCTR25;
  CCU7->TCTR26.reg = (uint32)CCU7_TCTR26;
  CCU7->MCMCTR.reg = (uint32)CCU7_MCMCTR;
  CCU7->T12MSEL.reg = (uint32)CCU7_T12MSEL;
  CCU7->TRPCTR.reg = (uint32)CCU7_TRPCTR;
  CCU7->MODCTR.reg = (uint32)CCU7_MODCTR;
  /* Compare status, Passive level select */
  CCU7->CMPSTAT.reg = (uint32)CCU7_CMPSTAT;
  CCU7->PSLR.reg = (uint32)CCU7_PSLR;
  /* Period values */
  CCU7->T12PR.reg = (uint32)CCU7_T12PR;
  CCU7->T13PR.reg = (uint32)CCU7_T13PR;
  CCU7->T14PR.reg = (uint32)CCU7_T14PR;
  CCU7->T15PR.reg = (uint32)CCU7_T15PR;
  CCU7->T16PR.reg = (uint32)CCU7_T16PR;
  CCU7->TCTR1.reg = (uint32)CCU7_TCTR1;
  /* Compare values */
  CCU7->CC70SR.reg = (uint32)CCU7_CC70SR;
  CCU7->CC71SR.reg = (uint32)CCU7_CC71SR;
  CCU7->CC72SR.reg = (uint32)CCU7_CC72SR;
  CCU7->CC70BSR.reg = (uint32)CCU7_CC70BSR;
  CCU7->CC71BSR.reg = (uint32)CCU7_CC71BSR;
  CCU7->CC72BSR.reg = (uint32)CCU7_CC72BSR;
  CCU7->C73SR.reg = (uint32)CCU7_C73SR;
  CCU7->C74SR.reg = (uint32)CCU7_C74SR;
  CCU7->C75SR.reg = (uint32)CCU7_C75SR;
  CCU7->C76SR.reg = (uint32)CCU7_C76SR;
  /* Dead Time */
  CCU7->T12DTC.reg = (uint32)CCU7_T12DTC;
  CCU7->T12DT0_VAL.reg = (uint32)CCU7_T12DT0_VAL;
  CCU7->T12DT1_VAL.reg = (uint32)CCU7_T12DT1_VAL;
  CCU7->T12DT2_VAL.reg = (uint32)CCU7_T12DT2_VAL;
  CCU7->T12DTINSEL.reg = (uint32)CCU7_T12DTINSEL;
  /* Debug behavior */
  CCU7->KSCSR.reg = (uint32)CCU7_KSCSR;
  CCU7->OCS.reg = (uint32)CCU7_OCS;
  CCU7->LI.reg = (uint32)CCU7_LI & (uint32)0x3FEu;
  /* Set Shadow Transfer Request */
  CCU7_setT12ShadowTransferReq();
  CCU7_setT13ShadowTransferReq();
  CCU7_setT14ShadowTransferReq();
  CCU7_setT15ShadowTransferReq();
  CCU7_setT16ShadowTransferReq();
#endif
  return s8_returnCode;
}