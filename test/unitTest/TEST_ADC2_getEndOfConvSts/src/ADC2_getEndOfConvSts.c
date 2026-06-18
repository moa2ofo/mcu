#include "ADC2_getEndOfConvSts_help.h"

/* FUNCTION TO TEST */
uint8 ADC2_getEndOfConvSts(uint8 u8_seqIdx, uint8 u8_slotIdx)
{
  uint8 u8_channel;
  uint32 u32_addr;
  const volatile tADC2_SQSLOTx *tpSqSlt;
  uint16 u16_offs;
  uint8 u8_EOCSts;
  u8_EOCSts = 0u;

  /* Check input parameter validity */
  if (u8_seqIdx < (uint8)ADC2_SEQ_CNT)
  {
    /* Violation: cast from pointer to unsigned int [MISRA Rule 45]*/
    u32_addr = (uint32)&ADC2->SQSLOT0.reg;
    /* Shift seq. index by 2 (mult by 4) to calculate address offset for SQSLOTx register */
    u16_offs = (uint16)((uint16)u8_seqIdx << 2u);
    /* Increment address by channel offset */
    u32_addr += u16_offs;
    /* Violation: cast from unsigned int to pointer [MISRA Rule 45]*/
    tpSqSlt = (volatile tADC2_SQSLOTx *) u32_addr;

    /* Check input parameter validity */
    if (u8_slotIdx < (uint8)ADC2_SLOT_CNT)
    {
      /* Get digital channel out of slot configuration */
      u8_channel = (uint8)((tpSqSlt->reg >> (u8_slotIdx * 8u)) & (uint8)0xFF);

      /* Check input parameter validity */
      if (u8_channel < (uint8)ADC2_DCH_CNT)
      {
        /* get status register for configured channel */
        u8_EOCSts = (uint8)((ADC2->CHSTAT.reg >> u8_channel) & 1u);
      }
    }
  }

  return u8_EOCSts;
}