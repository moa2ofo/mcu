#include "ADC2_getChFiltResult_help.h"

/* FUNCTION TO TEST */
sint8 ADC2_getChFiltResult(uint16 *u16p_filtDigValue, uint8 u8_channel)
{
  uint8 u8_fidx;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check input parameter validity */
  if ((PtrRangeCheck(u16p_filtDigValue) == true) && (u8_channel < (uint8)ADC2_DCH_CNT))
  {
    /* Read analog input selection for selected channel */
    u8_fidx = ADC2_getFiltIdxFromChannel(u8_channel);

    /* Check analog input range */
    if (u8_fidx < (uint8)ADC2_FILT_CNT)
    {
      s8_returnCode = ADC2_getFiltChResult(u16p_filtDigValue, u8_fidx);
    }
    else
    {
      s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
    }
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}