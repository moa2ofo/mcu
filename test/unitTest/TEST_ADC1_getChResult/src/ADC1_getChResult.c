#include "ADC1_getChResult_help.h"

/* FUNCTION TO TEST */
sint8 ADC1_getChResult(uint16 *u16p_digValue, uint8 u8_channel)
{
  uint32 u32_addr;
  const volatile tADC1_RESx *tpResult;
  uint16 u16_offs;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check input parameter validity */
  if ((PtrRangeCheck(u16p_digValue) == true) && (u8_channel < (uint8)ADC1_DCH_CNT))
  {
    /* Violation: cast from pointer to unsigned int [MISRA Rule 45]*/
    u32_addr = (uint32)&ADC1->RES0.reg;
    /* Shift channel by 2 (mult by 4) to calculate address offset for channel */
    u16_offs = (uint16)((uint16)u8_channel << 2u);
    /* Increment address by channel offset */
    u32_addr += u16_offs;
    /* Violation: cast from unsigned int to pointer [MISRA Rule 45]*/
    tpResult = (volatile tADC1_RESx *) u32_addr;
    /* Update the value - to get a valid data, the ADC1.RESx.VALID bitfield must be checked before calling this function */
    *u16p_digValue = tpResult->bit.RESULT;
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}