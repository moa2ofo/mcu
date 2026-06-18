#include "UART1_setBaudrate_help.h"

/* FUNCTION TO TEST */
sint8 UART1_setBaudrate(uint32 u32_baudrate)
{
  sint8 s8_returnCode;
  uint32 u32_addr;
  tUARTx_BCON *tp_baudrateReg;
  u32_addr = (uint32)&UART1->BCON.reg;
  tp_baudrateReg = (tUARTx_BCON *) u32_addr;
  s8_returnCode = UARTx_setBaudrate(u32_baudrate, tp_baudrateReg);
  return s8_returnCode;
}