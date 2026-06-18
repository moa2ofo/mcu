#include "CSACSC_startCalibration_help.h"

/* FUNCTION TO TEST */
sint8 CSACSC_startCalibration(uint16 *u16p_Val_mV)
{
  uint32 u32_chCfg19Bak;
  uint32 u32_sqCfg3Bak;
  uint32 u32_sq3SlotBak;
  tADC1_CHCFGx s_chCfgNew;
  tADC1_SQCFGx s_sqCfgNew;
  tADC1_SQSLOTx s_slotNew;
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_SUCCESS;

  if (PtrRangeCheck(u16p_Val_mV) == true)
  {
    /* Backup ADC1 channel19-/sequence3-/slot.seq3-configuration */
    u32_chCfg19Bak = ADC1->CHCFG19.reg;
    u32_sqCfg3Bak = ADC1->SQCFG3.reg;
    u32_sq3SlotBak = ADC1->SQSLOT3.reg;
    /* Configure the channel */
    s_chCfgNew.reg = 0;
    /* Conversion Class 2 (2) */
    s_chCfgNew.bit.CLASSEL = 2;
    /* No compare channel selected (4) */
    s_chCfgNew.bit.CMPSEL = 4;
    /* No filter channel selected (4) */
    s_chCfgNew.bit.FILSEL = 4;
    /* Analog input 18 (CSA) selected */
    s_chCfgNew.bit.INSEL = 18;
    /* Configure the sequencer */
    s_sqCfgNew.reg = 0;
    /* Enable one slot (1) */
    s_sqCfgNew.bit.SLOTS = 1;
    /* Configure the slot */
    s_slotNew.reg = 0;
    /* Select digital channel 19 for slot 0 (19)*/
    s_slotNew.bit.CHSEL0 = 19;
    /* Load new configuration to ADC1 channel19-/sequence3-/slot.seq3-configuration */
    ADC1->SQSLOT3.reg = s_slotNew.reg;
    ADC1->SQCFG3.reg = s_sqCfgNew.reg;
    ADC1->CHCFG19.reg = s_chCfgNew.reg;
    /* Shadow transfer trigger set to software */
    ADC1->SHDCTR.reg = (uint32)ADC1_SHADOWTRANS_EN;
    ADC1->SHDCTR.reg = (uint32)ADC1_SHADOWTRANS_BY_SW;
    /* Start the sequencer 3 */
    s8_returnCode = ADC1_startSequence(ADC1_SEQ3);

    if (s8_returnCode == ERR_LOG_SUCCESS)
    {
      /* Wait for end-of-conversion event for sequence 3 */
      while (ADC1_getEndOfConvSts(ADC1_SEQ3, ADC1_SEQ_SLOT0) == 0) {}

      /* Get the result in millivolt for sequence 3 slot 0 */
      s8_returnCode = ADC1_getSeqResult_mV(u16p_Val_mV, ADC1_SEQ3, ADC1_SEQ_SLOT0);
    }

    /* Restore ADC1 channel19-/sequence3-/slot.seq3-configuration */
    ADC1->SQSLOT3.reg = u32_sq3SlotBak;
    ADC1->SQCFG3.reg = u32_sqCfg3Bak;
    ADC1->CHCFG19.reg = u32_chCfg19Bak;
    /* Shadow transfer trigger set to software */
    ADC1->SHDCTR.reg = (uint32)ADC1_SHADOWTRANS_EN;
    ADC1->SHDCTR.reg = (uint32)ADC1_SHADOWTRANS_BY_SW;
  }
  else
  {
    s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  }

  return s8_returnCode;
}