#include "ADC1_getCalibEnFromChannel_help.h"

/* FUNCTION TO TEST */
uint8 ADC1_getCalibEnFromChannel(uint8 u8_channel)
{
  uint8 u8_aidx;
  uint8 u8_res;
  u8_res = 0;

  /* Check input parameter validity */
  if (u8_channel < (uint8)ADC1_DCH_CNT)
  {
    u8_aidx = ADC1_getAnalogInputFromChannel(u8_channel);

    /* Check analog input range */
    if (u8_aidx < (uint8)ADC1_AI_CNT)
    {
      u8_res = (uint8)((ADC1->CALEN.reg >> u8_aidx) & 1u);
    }
  }

  return (u8_res);
}