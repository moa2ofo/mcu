#include "BDRV_clrFaultSts_help.h"

/* FUNCTION TO TEST */
void BDRV_clrFaultSts(void)
{
  BDRV->STSCLR.reg = (uint32)0x80333333u;
}