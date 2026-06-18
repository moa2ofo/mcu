#include "ADC1_getChResult_mV_help.h"

/* FUNCTION TO TEST */
sint8 ADC1_getChResult_mV(uint16 *u16p_digValue_mV, uint8 u8_channel)
{
  uint32 u32_val_mV;
  uint16 u16_val;
  uint8 u8_aidx;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check input parameter validity */
  if ((PtrRangeCheck(u16p_digValue_mV) == true) && (u8_channel < (uint8)ADC1_DCH_CNT))
  {
    if (ADC1_getChResult(&u16_val, u8_channel) == ERR_LOG_SUCCESS)
    {
      /* ADC1 Voltage(mV) = (10bit_value * VREF_5000(mV)) / ADC1_MAX_RESOLUTION */
      u32_val_mV = (uint32)(((uint32)u16_val * (uint16)ADC1_VREF_5000mV) / (uint16)ADC1_MAX_RESOLUTION);
      /* Read analog input selection for selected channel */
      u8_aidx = ADC1_getAnalogInputFromChannel(u8_channel);

      /* Check analog input range */
      if (u8_aidx < (uint8)ADC1_AI_CNT)
      {
        /* Adjust millivolt value based on attenuator for selected analog intut */
        *u16p_digValue_mV = (uint16)((uint32)(u32_val_mV * (uint16)ADC1_ATT_DENOM) / cu16_ADC1_analogInput_Att[u8_aidx]);
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
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}