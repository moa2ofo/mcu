#include "DMA_setBasicTransfer_help.h"

/* FUNCTION TO TEST */
void DMA_setBasicTransfer(uint8 u8_chIdx, uint32 u32_srcAddr, uint32 u32_dstAddr, uint32 u32_transferCnt, tDMA_transferSize e_transferSize, tDMA_incrementMode e_incrementMode)
{
  tDMA_entry *s_entry;
  uint32 u32_startAddress;
  u32_startAddress = u8_chIdx * sizeof(tDMA_entry) + DMA_BASE_ADDR;
  s_entry = (tDMA_entry *)u32_startAddress;
  /* Control structure */
  s_entry->s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_Basic;
  s_entry->s_ctrl.bit.u32_nextUseburst = 0u;
  s_entry->s_ctrl.bit.u32_Nminus1 = (uint16)(u32_transferCnt - 1u);
  s_entry->s_ctrl.bit.u32_Rpower = 0u;
  s_entry->s_ctrl.bit.u32_srcProtCtrl = 7u;
  s_entry->s_ctrl.bit.u32_dstProtCtrl = 7u;
  s_entry->s_ctrl.bit.u32_srcSize = (uint8)e_transferSize;
  s_entry->s_ctrl.bit.u32_dstSize = (uint8)e_transferSize;

  switch (e_incrementMode)
  {
    case DMA_incrementMode_noInc:
    {
      /* Source end pointer */
      s_entry->u32_srcEndPtr = u32_srcAddr;
      /* Destination end pointer */
      s_entry->u32_dstEndPtr = u32_dstAddr;
      /* Control structure (continued) */
      s_entry->s_ctrl.bit.u32_srcInc = (uint8)DMA_incrementMode_noInc;
      s_entry->s_ctrl.bit.u32_dstInc = (uint8)DMA_incrementMode_noInc;
      break;
    }

    case DMA_incrementMode_srcInc:
    {
      /* Source end pointer */
      s_entry->u32_srcEndPtr = u32_srcAddr + (u32_transferCnt - 1u) * (1u << (uint8)e_transferSize);
      /* Destination end pointer */
      s_entry->u32_dstEndPtr = u32_dstAddr;
      /* Control structure (continued) */
      s_entry->s_ctrl.bit.u32_srcInc = (uint8)e_transferSize;
      s_entry->s_ctrl.bit.u32_dstInc = (uint8)DMA_incrementMode_noInc;
      break;
    }

    case DMA_incrementMode_dstInc:
    {
      /* Source end pointer */
      s_entry->u32_srcEndPtr = u32_srcAddr;
      /* Destination end pointer */
      s_entry->u32_dstEndPtr = u32_dstAddr + (u32_transferCnt - 1u) * (1u << (uint8)e_transferSize);
      /* Control structure (continued) */
      s_entry->s_ctrl.bit.u32_srcInc = (uint8)DMA_incrementMode_noInc;
      s_entry->s_ctrl.bit.u32_dstInc = (uint8)e_transferSize;
      break;
    }

    case DMA_incrementMode_srcDstInc:
    {
      /* Source end pointer */
      s_entry->u32_srcEndPtr = u32_srcAddr + (u32_transferCnt - 1u) * (1u << (uint8)e_transferSize);
      /* Destination end pointer */
      s_entry->u32_dstEndPtr = u32_dstAddr + (u32_transferCnt - 1u) * (1u << (uint8)e_transferSize);
      /* Control structure (continued) */
      s_entry->s_ctrl.bit.u32_srcInc = (uint8)e_transferSize;
      s_entry->s_ctrl.bit.u32_dstInc = (uint8)e_transferSize;
      break;
    }

    default:
    {
      /* Source end pointer */
      s_entry->u32_srcEndPtr = u32_srcAddr;
      /* Destination end pointer */
      s_entry->u32_dstEndPtr = u32_dstAddr;
      /* Control structure (continued) */
      s_entry->s_ctrl.bit.u32_srcInc = (uint8)DMA_incrementMode_noInc;
      s_entry->s_ctrl.bit.u32_dstInc = (uint8)DMA_incrementMode_noInc;
      break;
    }
  }

  /* Set DMA structure base pointer */
  DMA->CTRL_BASE_PTR.reg = DMA_BASE_ADDR;
  /* Enable the DMA channel */
  DMA->CHNL_ENABLE_SET.reg |= ((uint32)1u << u8_chIdx);
}