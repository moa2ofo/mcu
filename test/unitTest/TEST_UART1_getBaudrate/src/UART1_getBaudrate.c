#include "UART1_getBaudrate_help.h"

/* FUNCTION TO TEST */
uint32 UART1_getBaudrate(void)
{
  return (uint32)((SCU_fUART_MHz * 1000000 * 2 )  / ((1U << (uint8)UART1->BCON.bit.BR_PRE) * (32 * UART1->BCON.bit.BG_BR_VALUE + (UART1->BCON.bit.BG_FD_SEL))));
}