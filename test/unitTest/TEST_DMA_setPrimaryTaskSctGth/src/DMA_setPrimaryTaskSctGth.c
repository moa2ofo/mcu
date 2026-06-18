#include "DMA_setPrimaryTaskSctGth_help.h"

/* FUNCTION TO TEST */
tDMA_entry *DMA_setPrimaryTaskSctGth(tDMA_entry *s_primEntry, uint8 u8_chIdx, tDMA_entry *s_taskList, uint32 u32_taskCnt)
{
  /* Source end pointer, points to the last task in the task list */
  s_primEntry->u32_srcEndPtr = (uint32)s_taskList + (((u32_taskCnt * 4u) - 1u) * ((uint32)1u << (uint8)DMA_transferSize_32bit));
  /* Destination pointer, points to the channel index in the alternate stucture */
  s_primEntry->u32_dstEndPtr = (DMA->ALT_CTRL_BASE_PTR.reg + (u8_chIdx * sizeof(tDMA_entry))) + 12u;
  /* Control structure */
  s_primEntry->s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_MemSctGthPrim;
  s_primEntry->s_ctrl.bit.u32_nextUseburst = 0u;
  s_primEntry->s_ctrl.bit.u32_Nminus1 = (uint16)(u32_taskCnt * 4u) - 1u;
  s_primEntry->s_ctrl.bit.u32_Rpower = 2u;
  s_primEntry->s_ctrl.bit.u32_srcProtCtrl = 7u;
  s_primEntry->s_ctrl.bit.u32_dstProtCtrl = 7u;
  s_primEntry->s_ctrl.bit.u32_srcSize = (uint8)DMA_transferSize_32bit;
  s_primEntry->s_ctrl.bit.u32_srcInc = (uint8)DMA_incrementSize_32bit;
  s_primEntry->s_ctrl.bit.u32_dstSize = (uint8)DMA_transferSize_32bit;
  s_primEntry->s_ctrl.bit.u32_dstInc = (uint8)DMA_incrementSize_32bit;
  return (s_primEntry);
}