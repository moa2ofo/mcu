#include "BDRV_getCPReadyStateCW_help.h"

/* FUNCTION TO TEST */
uint8 BDRV_getCPReadyStateCW(void)
{
  return (uint8)((BDRV_CP_CTRL & BDRV_CP_CTRL_CP_RDY_EN_Msk) >> BDRV_CP_CTRL_CP_RDY_EN_Pos);
}