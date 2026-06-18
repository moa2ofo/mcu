#include "DMA_setMemSctGth_help.h"

/* FUNCTION TO TEST */
void DMA_setMemSctGth(uint8 u8_chIdx, tDMA_entry *s_taskList, uint32 u32_taskCnt)
{
  tDMA_entry *s_entry;
  uint32 u32_startAddress;
  u32_startAddress = u8_chIdx * sizeof(tDMA_entry) + DMA_BASE_ADDR;
  s_entry = (tDMA_entry *)u32_startAddress;
  /* Source end pointer */
  s_entry->u32_srcEndPtr = (uint32)s_taskList + (((u32_taskCnt * 4u) - 1u) * ((uint32)1u << (uint8)DMA_transferSize_32bit));
  /* Destination end pointer */
  s_entry->u32_dstEndPtr = (DMA->ALT_CTRL_BASE_PTR.reg + (u8_chIdx * sizeof(tDMA_entry))) + 12u;
  /* Control structure */
  s_entry->s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_MemSctGthPrim;
  s_entry->s_ctrl.bit.u32_nextUseburst = 0u;
  s_entry->s_ctrl.bit.u32_Nminus1 = (uint16)((u32_taskCnt * 4u) - 1u);
  s_entry->s_ctrl.bit.u32_Rpower = 2u;
  s_entry->s_ctrl.bit.u32_srcProtCtrl = 7u;
  s_entry->s_ctrl.bit.u32_dstProtCtrl = 7u;
  s_entry->s_ctrl.bit.u32_srcSize = (uint8)DMA_transferSize_32bit;
  s_entry->s_ctrl.bit.u32_srcInc = (uint8)DMA_incrementSize_32bit;
  s_entry->s_ctrl.bit.u32_dstSize = (uint8)DMA_transferSize_32bit;
  s_entry->s_ctrl.bit.u32_dstInc = (uint8)DMA_incrementSize_32bit;
  /* Set DMA structure base pointer */
  DMA->CTRL_BASE_PTR.reg = DMA_BASE_ADDR;
  /* Enable the DMA channel */
  DMA->CHNL_ENABLE_SET.reg |= ((uint32)1u << u8_chIdx);
}