#include "UART0_getBaudrate_help.h"

/* FUNCTION TO TEST */
uint32 UART0_getBaudrate(void)
{
  return (uint32)((SCU_fUART_MHz * 1000000 * 2 )  / ((1U << (uint8)UART0->BCON.bit.BR_PRE) * (32 * UART0->BCON.bit.BG_BR_VALUE + (UART0->BCON.bit.BG_FD_SEL))));
}