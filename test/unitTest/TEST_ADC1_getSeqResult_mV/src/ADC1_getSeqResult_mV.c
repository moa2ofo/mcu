#include "ADC1_getSeqResult_mV_help.h"

/* FUNCTION TO TEST */
sint8 ADC1_getSeqResult_mV(uint16 *u16p_digValue_mV, uint8 u8_seqIdx, uint8 u8_slotIdx)
{
  uint32 u32_addr;
  const volatile tADC1_SQCFGx *tpSqCfg;
  const volatile tADC1_SQSLOTx *tpSqSlot;
  uint16 u16_offs;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  /* Check input parameter validity */
  if ((PtrRangeCheck(u16p_digValue_mV) == true) && (u8_seqIdx < (uint8)ADC1_SEQ_CNT))
  {
    /* Violation: cast from pointer to unsigned int [MISRA Rule 45]*/
    u32_addr = (uint32)&ADC1->SQCFG0.reg;
    /* Shift seq. index by 3 (mult by 8) to calculate address offset for SQCFGx register  */
    u16_offs = (uint16)((uint16)u8_seqIdx << 3u);
    /* Increment address by channel offset */
    u32_addr += u16_offs;
    /* Violation: cast from unsigned int to pointer [MISRA Rule 45]*/
    tpSqCfg = (volatile tADC1_SQCFGx *) u32_addr;

    /* Check if selected slot is enabled */
    if (u8_slotIdx < tpSqCfg->bit.SLOTS)
    {
      /* Violation: cast from pointer to unsigned int [MISRA Rule 45]*/
      u32_addr = (uint32)&ADC1->SQSLOT0.reg;
      /* Shift slot index by 3 (mult by 8) to calculate address offset for SQSLOTx register */
      u16_offs = (uint16)((uint16)u8_seqIdx << 3u);
      /* Increment address by channel offset */
      u32_addr += u16_offs;
      /* Violation: cast from unsigned int to pointer [MISRA Rule 45]*/
      tpSqSlot = (volatile tADC1_SQSLOTx *) u32_addr;

      switch (u8_slotIdx)
      {
        case 0:
        {
          s8_returnCode = ADC1_getChResult_mV(u16p_digValue_mV, (uint8)tpSqSlot->bit.CHSEL0);
        }
        break;

        case 1:
        {
          s8_returnCode = ADC1_getChResult_mV(u16p_digValue_mV, (uint8)tpSqSlot->bit.CHSEL1);
        }
        break;

        case 2:
        {
          s8_returnCode = ADC1_getChResult_mV(u16p_digValue_mV, (uint8)tpSqSlot->bit.CHSEL2);
        }
        break;

        case 3:
        {
          s8_returnCode = ADC1_getChResult_mV(u16p_digValue_mV, (uint8)tpSqSlot->bit.CHSEL3);
        }
        break;

        default:
        {
          s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
        }
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