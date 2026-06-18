#include "ADC2_getFiltIdxFromChannel_help.h"

/* FUNCTION TO TEST */
uint8 ADC2_getFiltIdxFromChannel(uint8 u8_channel)
{
  const volatile tADC2_CHCFGx *tpChCfg;
  uint32 u32_addr;
  uint16 u16_offs;
  uint8 u8_fidx;
  /* Initialize the return value to a not used index in the filter channel selection */
  u8_fidx = (uint8)ADC2_FILT_CH_DIS;

  /* Check input parameter validity */
  if (u8_channel < (uint8)ADC2_DCH_CNT)
  {
    /* Violation: cast from pointer to unsigned int [MISRA Rule 45]*/
    u32_addr = (uint32)&ADC2->CHCFG0.reg;
    /* Shift channel by 2 (mult by 4) to calculate address offset for channel */
    u16_offs = (uint16)((uint16)u8_channel << 2u);
    /* Increment address by channel offset */
    u32_addr += u16_offs;
    /* Violation: cast from unsigned int to pointer [MISRA Rule 45]*/
    tpChCfg = (volatile tADC2_CHCFGx *) u32_addr;
    /* Read analog input selection for selected channel */
    u8_fidx = tpChCfg->bit.FILSEL;
  }

  return (u8_fidx);
}