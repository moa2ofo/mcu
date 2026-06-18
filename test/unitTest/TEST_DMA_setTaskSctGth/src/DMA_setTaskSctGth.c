#include "DMA_setTaskSctGth_help.h"

/* FUNCTION TO TEST */
tDMA_entry *DMA_setTaskSctGth(tDMA_entry *s_entry, tDMA_cycleType e_cycleType, uint8 u8_Rpower, uint32 u32_srcAddr, uint32 u32_dstAddr, uint32 u32_transferCnt, tDMA_transferSize e_transferSize, tDMA_incrementMode e_incrementMode)
{
  /* Control structure */
  s_entry->s_ctrl.bit.u32_cycleCtrl = (uint8)e_cycleType;
  s_entry->s_ctrl.bit.u32_nextUseburst = 0;
  s_entry->s_ctrl.bit.u32_Nminus1 = (uint16)(u32_transferCnt - 1u);
  s_entry->s_ctrl.bit.u32_Rpower = u8_Rpower;
  s_entry->s_ctrl.bit.u32_srcProtCtrl = 7u;
  s_entry->s_ctrl.bit.u32_dstProtCtrl = 7u;
  s_entry->s_ctrl.bit.u32_srcSize = (uint8)e_transferSize;
  s_entry->s_ctrl.bit.u32_dstSize = (uint8)e_transferSize;

  switch (e_incrementMode)
  {
    case DMA_incrementMode_srcInc:
    {
      /* Source end pointer, points to the last task in the task list */
      s_entry->u32_srcEndPtr = u32_srcAddr + ((u32_transferCnt - 1u) * ((uint32)1u << (uint8)e_transferSize));
      /* Destination pointer, points to the channel index in the alternate stucture */
      s_entry->u32_dstEndPtr = u32_dstAddr;
      /* Control structure (end) */
      s_entry->s_ctrl.bit.u32_srcInc = (uint8)e_transferSize;
      s_entry->s_ctrl.bit.u32_dstInc = (uint8)DMA_incrementMode_noInc;
      break;
    }

    case DMA_incrementMode_dstInc:
    {
      /* Source end pointer, points to the last task in the task list */
      s_entry->u32_srcEndPtr = u32_srcAddr;
      /* Destination pointer, points to the channel index in the alternate stucture */
      s_entry->u32_dstEndPtr = u32_dstAddr + ((u32_transferCnt - 1u) * ((uint32)1u << (uint8)e_transferSize));
      /* Control structure (end) */
      s_entry->s_ctrl.bit.u32_srcInc = (uint8)DMA_incrementMode_noInc;
      s_entry->s_ctrl.bit.u32_dstInc = (uint8)e_transferSize;
      break;
    }

    case DMA_incrementMode_srcDstInc:
    {
      /* Source end pointer, points to the last task in the task list */
      s_entry->u32_srcEndPtr = u32_srcAddr + ((u32_transferCnt - 1u) * ((uint32)1u << (uint8)e_transferSize));
      /* Destination pointer, points to the channel index in the alternate stucture */
      s_entry->u32_dstEndPtr = u32_dstAddr + ((u32_transferCnt - 1u) * ((uint32)1u << (uint8)e_transferSize));
      /* Control structure (end) */
      s_entry->s_ctrl.bit.u32_srcInc = (uint8)e_transferSize;
      s_entry->s_ctrl.bit.u32_dstInc = (uint8)e_transferSize;
      break;
    }

    case DMA_incrementMode_noInc:
    {
      /* Source end pointer, points to the last task in the task list */
      s_entry->u32_srcEndPtr = u32_srcAddr;
      /* Destination pointer, points to the channel index in the alternate stucture */
      s_entry->u32_dstEndPtr = u32_dstAddr;
      /* Control structure (end) */
      s_entry->s_ctrl.bit.u32_srcInc = (uint8)DMA_incrementMode_noInc;
      s_entry->s_ctrl.bit.u32_dstInc = (uint8)DMA_incrementMode_noInc;
      break;
    }

    default:
    {
      /* Source end pointer, points to the last task in the task list */
      s_entry->u32_srcEndPtr = u32_srcAddr;
      /* Destination pointer, points to the channel index in the alternate stucture */
      s_entry->u32_dstEndPtr = u32_dstAddr;
      /* Control structure (end) */
      s_entry->s_ctrl.bit.u32_srcInc = (uint8)DMA_incrementMode_noInc;
      s_entry->s_ctrl.bit.u32_dstInc = (uint8)DMA_incrementMode_noInc;
      break;
    }
  }

  return (s_entry);
}