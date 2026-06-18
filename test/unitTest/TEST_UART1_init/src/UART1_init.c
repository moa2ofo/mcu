#include "UART1_init_help.h"

/* FUNCTION TO TEST */
sint8 UART1_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if (UART1_GLOBCONF_EN == 1u)
  s8_returnCode = ERR_LOG_SUCCESS;
  UART1->INSEL.reg = (uint32)UART1_INSEL;
  UART1->SCON.reg = (uint32)UART1_SCON;
  UART1->IEN.reg = (uint32)UART1_IEN;
  UART1->BCON.reg = (uint32)UART1_BCON & ~UART1_BCON_BR_R_Msk;
  /* In case of variable baudrate, the generator must be enabled --> Write UARTx->SCON.bit.SM1 to UARTx->BCON.bit.BR_R */
  UART1->BCON.bit.BR_R = UART1->SCON.bit.SM1;
  UART1->LINCON.reg = UART1_LINCON;
#endif
  return s8_returnCode;
}