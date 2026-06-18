#include "ADC2_startSequence_help.h"

/* FUNCTION TO TEST */
sint8 ADC2_startSequence(uint8 u8_seqIdx)
{
  uint32 u32_addr;
  volatile tADC2_SQCFGx *tpSqCfg;
  uint16 u16_offs;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check input parameter validity */
  if (u8_seqIdx < (uint8)ADC2_SEQ_CNT)
  {
    /* Violation: cast from pointer to unsigned int [MISRA Rule 45]*/
    u32_addr = (uint32)&ADC2->SQCFG0.reg;
    /* Shift seq. index by 2 (mult by 4) to calculate address offset for SQCFGx register */
    u16_offs = (uint16)((uint16)u8_seqIdx << 2u);
    /* Increment address by channel offset */
    u32_addr += u16_offs;
    /* Violation: cast from unsigned int to pointer [MISRA Rule 45]*/
    tpSqCfg = (volatile tADC2_SQCFGx *) u32_addr;

    /* Check if software trigger is selected */
    if (ADC2_SW_TRIGGER == tpSqCfg->bit.TRGSEL)
    {
      /* Trigger start of conversion by software */
      tpSqCfg->bit.TRGSW = 1u;
      /* Sequence start triggered */
      s8_returnCode = ERR_LOG_SUCCESS;
    }
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}