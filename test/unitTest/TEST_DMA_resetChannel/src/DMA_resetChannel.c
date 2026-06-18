#include "DMA_resetChannel_help.h"

/* FUNCTION TO TEST */
void DMA_resetChannel(uint8 u8_chIdx, uint32 u32_transferCnt)
{
  tDMA_entry *s_entry;
  uint32 u32_startAddress;
  u32_startAddress = u8_chIdx * sizeof(tDMA_entry) + DMA_BASE_ADDR;
  s_entry = (tDMA_entry *)u32_startAddress;
  s_entry->s_ctrl.bit.u32_Nminus1 = (uint16)(u32_transferCnt - 1u);
  s_entry->s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_Basic;
  DMA->CHNL_ENABLE_SET.reg |= ((uint32)1u << u8_chIdx);
}