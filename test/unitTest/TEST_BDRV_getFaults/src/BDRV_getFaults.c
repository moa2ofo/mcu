#include "BDRV_getFaults_help.h"

/* FUNCTION TO TEST */
uint8 BDRV_getFaults(void)
{
  uint8 u8_res1;
  uint8 u8_res2;
  uint8 u8_res3;
  uint8 u8_res4;
  uint8 u8_res5;
  uint8 u8_res6;
  uint8 u8_res7;
  uint8 u8_res;
  u8_res7 = BDRV->STS.bit.VCP_UPTH_STS;
  u8_res7 |= BDRV->STS.bit.VSD_UPTH_STS;
  u8_res7 |= BDRV->STS.bit.VSD_OV_STS;
  u8_res7 <<= 7u;
  u8_res6 = BDRV->STS.bit.VCP_LOTH1_STS;
  u8_res6 |= BDRV->STS.bit.VCP_LOTH2_STS;
  u8_res6 |= BDRV->STS.bit.VSD_LOTH_STS;
  u8_res6 <<= 6u;
  u8_res5 = (uint8)(BDRV->STS.bit.HS3_OC_STS << 5u);
  u8_res4 = (uint8)(BDRV->STS.bit.LS3_OC_STS << 4u);
  u8_res3 = (uint8)(BDRV->STS.bit.HS2_OC_STS << 3u);
  u8_res2 = (uint8)(BDRV->STS.bit.LS2_OC_STS << 2u);
  u8_res1 = (uint8)(BDRV->STS.bit.HS1_OC_STS << 1u);
  u8_res = BDRV->STS.bit.LS1_OC_STS | u8_res1;
  u8_res |= u8_res2;
  u8_res |= u8_res3;
  u8_res |= u8_res4;
  u8_res |= u8_res5;
  u8_res |= u8_res6;
  u8_res |= u8_res7;
  return (uint8)u8_res;
}