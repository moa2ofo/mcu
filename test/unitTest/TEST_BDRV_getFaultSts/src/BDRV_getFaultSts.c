#include "BDRV_getFaultSts_help.h"

/* FUNCTION TO TEST */
bool BDRV_getFaultSts(void)
{
  //lint --e{9034}
  bool status = false;

  if (BDRV->STS.reg > (uint32)0)
  {
    status = true;
  }

  return status;
}