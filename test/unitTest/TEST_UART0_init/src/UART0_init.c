#include "UART0_init_help.h"

/* FUNCTION TO TEST */
sint8 UART0_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if (UART0_GLOBCONF_EN == 1u)
  s8_returnCode = ERR_LOG_SUCCESS;
  UART0->INSEL.reg = (uint32)UART0_INSEL;
  UART0->SCON.reg = (uint32)UART0_SCON;
  UART0->IEN.reg = (uint32)UART0_IEN;
  UART0->BCON.reg = (uint32)UART0_BCON & ~UART0_BCON_BR_R_Msk;
  /* In case of variable baudrate, the generator must be enabled --> Write UARTx->SCON.bit.SM1 to UARTx->BCON.bit.BR_R */
  UART0->BCON.bit.BR_R = UART0->SCON.bit.SM1;
  UART0->LINCON.reg = UART0_LINCON;
#endif
  return s8_returnCode;
}