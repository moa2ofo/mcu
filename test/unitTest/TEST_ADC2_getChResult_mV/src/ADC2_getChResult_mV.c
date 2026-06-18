#include "ADC2_getChResult_mV_help.h"

/* FUNCTION TO TEST */
sint8 ADC2_getChResult_mV(uint16 *u16p_digValue_mV, uint8 u8_channel)
{
  uint32 u32_val_mV;
  uint16 u16_val;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check input parameter validity */
  if ((PtrRangeCheck(u16p_digValue_mV) == true) && (u8_channel < (uint8)ADC2_DCH_CNT))
  {
    if (ADC2_getChResult(&u16_val, u8_channel) == ERR_LOG_SUCCESS)
    {
      /* ADC2 Voltage(mV) = (12bit_value * ADC2_VAREF(mV)) / ADC2_MAX_RESOLUTION */
      u32_val_mV = (uint32)(((uint32)u16_val * (uint16)ADC2_VAREF_mV) / (uint16)ADC2_MAX_RESOLUTION);
      /* Adjust millivolt value based on attenuator for selected analog intut */
      *u16p_digValue_mV = (uint16)((uint32)(u32_val_mV * (uint16)ADC2_ATT_DENOM) / cu16_ADC2_analogInput_Att[u8_channel]);
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