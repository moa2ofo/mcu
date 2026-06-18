#include "BDRV_getCPStagesCW_help.h"

/* FUNCTION TO TEST */
uint8 BDRV_getCPStagesCW(void)
{
  return (uint8)((BDRV_CP_CTRL & BDRV_CP_CTRL_CP_1STAGE_Msk) >> BDRV_CP_CTRL_CP_1STAGE_Pos);
}