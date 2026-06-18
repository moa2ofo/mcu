#include "ClearFailSafeRegisters_help.h"

/* FUNCTION TO TEST */
void ClearFailSafeRegisters(void)
{
  /* Clear all fail safe status bits */
  while (PMU->FS_STS.reg != 0u)
  {
    PMU->FS_STS_CLR.reg = FS_STS_CLR_ALL_MASK;
  }
  
  /* Clear all safe shutdown status bits */
  while (PMU->FS_SSD.reg != 0u)
  {
    PMU->FS_SSD_CLR.reg = FS_SSD_CLR_ALL_MASK;
  }

}