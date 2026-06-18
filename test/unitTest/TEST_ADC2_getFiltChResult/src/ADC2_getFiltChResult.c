#include "ADC2_getFiltChResult_help.h"

/* FUNCTION TO TEST */
sint8 ADC2_getFiltChResult(uint16 *u16p_filtDigValue, uint8 u8_filtCh)
{
  uint32 u32_addr;
  const volatile tADC2_FILx *tpResult;
  uint16 u16_offs;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check input parameter validity */
  if ((PtrRangeCheck(u16p_filtDigValue) == true) &&  (u8_filtCh < (uint8)ADC2_FILT_CNT))
  {
    /* Violation: cast from pointer to unsigned int [MISRA Rule 45]*/
    u32_addr = (uint32)&ADC2->FIL0.reg;
    /* Shift channel by to (mult by 4) to calculate address offset for channel */
    u16_offs = (uint16)((uint16)u8_filtCh << 2u);
    /* Increment address by channel offset */
    u32_addr += u16_offs;
    /* Violation: cast from unsigned int to pointer [MISRA Rule 45]*/
    tpResult = (volatile tADC2_FILx *) u32_addr;
    /* Update the value only if there is valid data in result register **
    ** The filter value is stored as a 14bit value, shifting it down   **
    ** to a 12bit value for proper postprocessing                      */
    *u16p_filtDigValue = (uint16)(tpResult->bit.FILRESULT  >> 2u);
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}