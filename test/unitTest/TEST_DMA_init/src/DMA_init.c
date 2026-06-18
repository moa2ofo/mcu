#include "DMA_init_help.h"

/* FUNCTION TO TEST */
sint8 DMA_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if (DMA_GLOBCONF_EN == 1u)
  s8_returnCode = ERR_LOG_SUCCESS;
  /* Set DMA structure base pointer */
  DMA->CTRL_BASE_PTR.reg = DMA_BASE_ADDR;
  /* Channel 0 */
#if (DMA_CH0_MODULE != 0u)
  s_ch0Primary.s_ctrl.bit.u32_srcProtCtrl = 7u;
  s_ch0Primary.s_ctrl.bit.u32_dstProtCtrl = 7u;
  /* Basic Mode */
#if (DMA_CH0_MODE == 0u)
  /* Primary structure */
  s_ch0Primary.s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_Basic;
  s_ch0Primary.s_ctrl.bit.u32_nextUseburst = 0u;
  s_ch0Primary.s_ctrl.bit.u32_Nminus1 = (uint16)(DMA_CH0_NBTRANSFER - 1u);
  s_ch0Primary.s_ctrl.bit.u32_Rpower = 0u;
  s_ch0Primary.s_ctrl.bit.u32_srcSize = (uint8)DMA_CH0_SIZETRANSFER;
#if (DMA_CH0_SRCINC == 1u)
  s_ch0Primary.s_ctrl.bit.u32_srcInc = (uint8)DMA_CH0_SIZETRANSFER;
#else
  s_ch0Primary.s_ctrl.bit.u32_srcInc = (uint8)3;
#endif
  s_ch0Primary.s_ctrl.bit.u32_dstSize = (uint8)DMA_CH0_SIZETRANSFER;
#if (DMA_CH0_DSTINC == 1u)
  s_ch0Primary.s_ctrl.bit.u32_dstInc = (uint8)DMA_CH0_SIZETRANSFER;
#else
  s_ch0Primary.s_ctrl.bit.u32_dstInc = (uint8)3;
#endif
  s_ch0Primary.u32_srcEndPtr = (uint32)&DMA_CH0_SRC + (uint32)DMA_CH0_SRCPTROFFS;
  s_ch0Primary.u32_dstEndPtr = (uint32)&DMA_CH0_DST + (uint32)DMA_CH0_DSTPTROFFS;
  /* Scatter Gather Mode */
#elif (DMA_CH0_MODE == 1u)
  /* Primary structure */
  s_ch0Primary.s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_MemSctGthPrim;
  s_ch0Primary.s_ctrl.bit.u32_nextUseburst = 0u;
  s_ch0Primary.s_ctrl.bit.u32_Nminus1 = (uint16)(((uint16)DMA_CH0_NBTASK * 4u) - 1u);
  s_ch0Primary.s_ctrl.bit.u32_Rpower = 2u;
  s_ch0Primary.s_ctrl.bit.u32_srcSize = (uint8)DMA_transferSize_32bit;
  s_ch0Primary.s_ctrl.bit.u32_srcInc = DMA_incrementSize_32bit;
  s_ch0Primary.s_ctrl.bit.u32_dstSize = (uint8)DMA_transferSize_32bit;
  s_ch0Primary.s_ctrl.bit.u32_dstInc = DMA_incrementSize_32bit;
  s_ch0Primary.u32_srcEndPtr = (uint32)&DMA_CH0_TASKLIST[0] + (uint32)((uint16)(((uint16)DMA_CH0_NBTASK * 4u) - 1u) * ((uint8)1u << (uint8)DMA_transferSize_32bit));
  s_ch0Primary.u32_dstEndPtr = DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH0 * sizeof(tDMA_entry) + 12u;
  /* Alternate structure */
  s_ch0Alternate.s_ctrl.reg = 0u;
  s_ch0Alternate.u32_srcEndPtr = 0u;
  s_ch0Alternate.u32_dstEndPtr = 0u;
#endif
  /* Enable the DMA channel */
  DMA->CHNL_ENABLE_SET.reg |= (uint32)(1u << DMA_CH0);
#endif
  /* Channel 1 */
#if (DMA_CH1_MODULE != 0u)
  s_ch1Primary.s_ctrl.bit.u32_srcProtCtrl = 7u;
  s_ch1Primary.s_ctrl.bit.u32_dstProtCtrl = 7u;
  /* Basic Mode */
#if (DMA_CH1_MODE == 0u)
  /* Primary structure */
  s_ch1Primary.s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_Basic;
  s_ch1Primary.s_ctrl.bit.u32_nextUseburst = 0u;
  s_ch1Primary.s_ctrl.bit.u32_Nminus1 = (uint16)(DMA_CH1_NBTRANSFER - 1u);
  s_ch1Primary.s_ctrl.bit.u32_Rpower = 0u;
  s_ch1Primary.s_ctrl.bit.u32_srcSize = (uint8)DMA_CH1_SIZETRANSFER;
#if (DMA_CH1_SRCINC == 1u)
  s_ch1Primary.s_ctrl.bit.u32_srcInc = (uint8)DMA_CH1_SIZETRANSFER;
#else
  s_ch1Primary.s_ctrl.bit.u32_srcInc = (uint8)3;
#endif
  s_ch1Primary.s_ctrl.bit.u32_dstSize = (uint8)DMA_CH1_SIZETRANSFER;
#if (DMA_CH1_DSTINC == 1u)
  s_ch1Primary.s_ctrl.bit.u32_dstInc = (uint8)DMA_CH1_SIZETRANSFER;
#else
  s_ch1Primary.s_ctrl.bit.u32_dstInc = (uint8)3;
#endif
  s_ch1Primary.u32_srcEndPtr = (uint32)&DMA_CH1_SRC + (uint32)DMA_CH1_SRCPTROFFS;
  s_ch1Primary.u32_dstEndPtr = (uint32)&DMA_CH1_DST + (uint32)DMA_CH1_DSTPTROFFS;
  /* Scatter Gather Mode */
#elif (DMA_CH1_MODE == 1u)
  /* Primary structure */
  s_ch1Primary.s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_MemSctGthPrim;
  s_ch1Primary.s_ctrl.bit.u32_nextUseburst = 0u;
  s_ch1Primary.s_ctrl.bit.u32_Nminus1 = (uint16)(((uint16)DMA_CH1_NBTASK * 4u) - 1u);
  s_ch1Primary.s_ctrl.bit.u32_Rpower = 2u;
  s_ch1Primary.s_ctrl.bit.u32_srcSize = (uint8)DMA_transferSize_32bit;
  s_ch1Primary.s_ctrl.bit.u32_srcInc = DMA_incrementSize_32bit;
  s_ch1Primary.s_ctrl.bit.u32_dstSize = (uint8)DMA_transferSize_32bit;
  s_ch1Primary.s_ctrl.bit.u32_dstInc = DMA_incrementSize_32bit;
  s_ch1Primary.u32_srcEndPtr = (uint32)&DMA_CH1_TASKLIST[0] + (uint32)((uint16)(((uint16)DMA_CH1_NBTASK * 4u) - 1u) * ((uint8)1u << (uint8)DMA_transferSize_32bit));
  s_ch1Primary.u32_dstEndPtr = DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH1 * sizeof(tDMA_entry) + 12u;
  /* Alternate structure */
  s_ch1Alternate.s_ctrl.reg = 0u;
  s_ch1Alternate.u32_srcEndPtr = 0u;
  s_ch1Alternate.u32_dstEndPtr = 0u;
#endif
  /* Enable the DMA channel */
  DMA->CHNL_ENABLE_SET.reg |= (uint32)(1u << DMA_CH1);
#endif
  /* Channel 2 */
#if (DMA_CH2_MODULE != 0u)
  s_ch2Primary.s_ctrl.bit.u32_srcProtCtrl = 7u;
  s_ch2Primary.s_ctrl.bit.u32_dstProtCtrl = 7u;
  /* Basic Mode */
#if (DMA_CH2_MODE == 0u)
  /* Primary structure */
  s_ch2Primary.s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_Basic;
  s_ch2Primary.s_ctrl.bit.u32_nextUseburst = 0u;
  s_ch2Primary.s_ctrl.bit.u32_Nminus1 = (uint16)(DMA_CH2_NBTRANSFER - 1u);
  s_ch2Primary.s_ctrl.bit.u32_Rpower = 0u;
  s_ch2Primary.s_ctrl.bit.u32_srcSize = (uint8)DMA_CH2_SIZETRANSFER;
#if (DMA_CH2_SRCINC == 1u)
  s_ch2Primary.s_ctrl.bit.u32_srcInc = (uint8)DMA_CH2_SIZETRANSFER;
#else
  s_ch2Primary.s_ctrl.bit.u32_srcInc = (uint8)3;
#endif
  s_ch2Primary.s_ctrl.bit.u32_dstSize = (uint8)DMA_CH2_SIZETRANSFER;
#if (DMA_CH2_DSTINC == 1u)
  s_ch2Primary.s_ctrl.bit.u32_dstInc = (uint8)DMA_CH2_SIZETRANSFER;
#else
  s_ch2Primary.s_ctrl.bit.u32_dstInc = (uint8)3;
#endif
  s_ch2Primary.u32_srcEndPtr = (uint32)&DMA_CH2_SRC + (uint32)DMA_CH2_SRCPTROFFS;
  s_ch2Primary.u32_dstEndPtr = (uint32)&DMA_CH2_DST + (uint32)DMA_CH2_DSTPTROFFS;
  /* Scatter Gather Mode */
#elif (DMA_CH2_MODE == 1u)
  /* Primary structure */
  s_ch2Primary.s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_MemSctGthPrim;
  s_ch2Primary.s_ctrl.bit.u32_nextUseburst = 0u;
  s_ch2Primary.s_ctrl.bit.u32_Nminus1 = (uint16)(((uint16)DMA_CH2_NBTASK * 4u) - 1u);
  s_ch2Primary.s_ctrl.bit.u32_Rpower = 2u;
  s_ch2Primary.s_ctrl.bit.u32_srcSize = (uint8)DMA_transferSize_32bit;
  s_ch2Primary.s_ctrl.bit.u32_srcInc = DMA_incrementSize_32bit;
  s_ch2Primary.s_ctrl.bit.u32_dstSize = (uint8)DMA_transferSize_32bit;
  s_ch2Primary.s_ctrl.bit.u32_dstInc = DMA_incrementSize_32bit;
  s_ch2Primary.u32_srcEndPtr = (uint32)&DMA_CH2_TASKLIST[0] + (uint32)((uint16)(((uint16)DMA_CH2_NBTASK * 4u) - 1u) * ((uint8)1u << (uint8)DMA_transferSize_32bit));
  s_ch2Primary.u32_dstEndPtr = DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH2 * sizeof(tDMA_entry) + 12u;
  /* Alternate structure */
  s_ch2Alternate.s_ctrl.reg = 0u;
  s_ch2Alternate.u32_srcEndPtr = 0u;
  s_ch2Alternate.u32_dstEndPtr = 0u;
#endif
  /* Enable the DMA channel */
  DMA->CHNL_ENABLE_SET.reg |= (uint32)(1u << DMA_CH2);
#endif
  /* Channel 3 */
#if (DMA_CH3_MODULE != 0u)
  s_ch3Primary.s_ctrl.bit.u32_srcProtCtrl = 7u;
  s_ch3Primary.s_ctrl.bit.u32_dstProtCtrl = 7u;
  /* Basic Mode */
#if (DMA_CH3_MODE == 0u)
  /* Primary structure */
  s_ch3Primary.s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_Basic;
  s_ch3Primary.s_ctrl.bit.u32_nextUseburst = 0u;
  s_ch3Primary.s_ctrl.bit.u32_Nminus1 = (uint16)(DMA_CH3_NBTRANSFER - 1u);
  s_ch3Primary.s_ctrl.bit.u32_Rpower = 0u;
  s_ch3Primary.s_ctrl.bit.u32_srcSize = (uint8)DMA_CH3_SIZETRANSFER;
#if (DMA_CH3_SRCINC == 1u)
  s_ch3Primary.s_ctrl.bit.u32_srcInc = (uint8)DMA_CH3_SIZETRANSFER;
#else
  s_ch3Primary.s_ctrl.bit.u32_srcInc = (uint8)3;
#endif
  s_ch3Primary.s_ctrl.bit.u32_dstSize = (uint8)DMA_CH3_SIZETRANSFER;
#if (DMA_CH3_DSTINC == 1u)
  s_ch3Primary.s_ctrl.bit.u32_dstInc = (uint8)DMA_CH3_SIZETRANSFER;
#else
  s_ch3Primary.s_ctrl.bit.u32_dstInc = (uint8)3;
#endif
  s_ch3Primary.u32_srcEndPtr = (uint32)&DMA_CH3_SRC + (uint32)DMA_CH3_SRCPTROFFS;
  s_ch3Primary.u32_dstEndPtr = (uint32)&DMA_CH3_DST + (uint32)DMA_CH3_DSTPTROFFS;
  /* Scatter Gather Mode */
#elif (DMA_CH3_MODE == 1u)
  /* Primary structure */
  s_ch3Primary.s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_MemSctGthPrim;
  s_ch3Primary.s_ctrl.bit.u32_nextUseburst = 0u;
  s_ch3Primary.s_ctrl.bit.u32_Nminus1 = (uint16)(((uint16)DMA_CH3_NBTASK * 4u) - 1u);
  s_ch3Primary.s_ctrl.bit.u32_Rpower = 2u;
  s_ch3Primary.s_ctrl.bit.u32_srcSize = (uint8)DMA_transferSize_32bit;
  s_ch3Primary.s_ctrl.bit.u32_srcInc = DMA_incrementSize_32bit;
  s_ch3Primary.s_ctrl.bit.u32_dstSize = (uint8)DMA_transferSize_32bit;
  s_ch3Primary.s_ctrl.bit.u32_dstInc = DMA_incrementSize_32bit;
  s_ch3Primary.u32_srcEndPtr = (uint32)&DMA_CH3_TASKLIST[0] + (uint32)((uint16)(((uint16)DMA_CH3_NBTASK * 4u) - 1u) * ((uint8)1u << (uint8)DMA_transferSize_32bit));
  s_ch3Primary.u32_dstEndPtr = DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH3 * sizeof(tDMA_entry) + 12u;
  /* Alternate structure */
  s_ch3Alternate.s_ctrl.reg = 0u;
  s_ch3Alternate.u32_srcEndPtr = 0u;
  s_ch3Alternate.u32_dstEndPtr = 0u;
#endif
  /* Enable the DMA channel */
  DMA->CHNL_ENABLE_SET.reg |= (uint32)(1u << DMA_CH3);
#endif
  /* Channel 4 */
#if (DMA_CH4_MODULE != 0u)
  s_ch4Primary.s_ctrl.bit.u32_srcProtCtrl = 7u;
  s_ch4Primary.s_ctrl.bit.u32_dstProtCtrl = 7u;
  /* Basic Mode */
#if (DMA_CH4_MODE == 0u)
  /* Primary structure */
  s_ch4Primary.s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_Basic;
  s_ch4Primary.s_ctrl.bit.u32_nextUseburst = 0u;
  s_ch4Primary.s_ctrl.bit.u32_Nminus1 = (uint16)(DMA_CH4_NBTRANSFER - 1u);
  s_ch4Primary.s_ctrl.bit.u32_Rpower = 0u;
  s_ch4Primary.s_ctrl.bit.u32_srcSize = (uint8)DMA_CH4_SIZETRANSFER;
#if (DMA_CH4_SRCINC == 1u)
  s_ch4Primary.s_ctrl.bit.u32_srcInc = (uint8)DMA_CH4_SIZETRANSFER;
#else
  s_ch4Primary.s_ctrl.bit.u32_srcInc = (uint8)3;
#endif
  s_ch4Primary.s_ctrl.bit.u32_dstSize = (uint8)DMA_CH4_SIZETRANSFER;
#if (DMA_CH4_DSTINC == 1u)
  s_ch4Primary.s_ctrl.bit.u32_dstInc = (uint8)DMA_CH4_SIZETRANSFER;
#else
  s_ch4Primary.s_ctrl.bit.u32_dstInc = (uint8)3;
#endif
  s_ch4Primary.u32_srcEndPtr = (uint32)&DMA_CH4_SRC + (uint32)DMA_CH4_SRCPTROFFS;
  s_ch4Primary.u32_dstEndPtr = (uint32)&DMA_CH4_DST + (uint32)DMA_CH4_DSTPTROFFS;
  /* Scatter Gather Mode */
#elif (DMA_CH4_MODE == 1u)
  /* Primary structure */
  s_ch4Primary.s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_MemSctGthPrim;
  s_ch4Primary.s_ctrl.bit.u32_nextUseburst = 0u;
  s_ch4Primary.s_ctrl.bit.u32_Nminus1 = (uint16)(((uint16)DMA_CH4_NBTASK * 4u) - 1u);
  s_ch4Primary.s_ctrl.bit.u32_Rpower = 2u;
  s_ch4Primary.s_ctrl.bit.u32_srcSize = (uint8)DMA_transferSize_32bit;
  s_ch4Primary.s_ctrl.bit.u32_srcInc = DMA_incrementSize_32bit;
  s_ch4Primary.s_ctrl.bit.u32_dstSize = (uint8)DMA_transferSize_32bit;
  s_ch4Primary.s_ctrl.bit.u32_dstInc = DMA_incrementSize_32bit;
  s_ch4Primary.u32_srcEndPtr = (uint32)&DMA_CH4_TASKLIST[0] + (uint32)((uint16)(((uint16)DMA_CH4_NBTASK * 4u) - 1u) * ((uint8)1u << (uint8)DMA_transferSize_32bit));
  s_ch4Primary.u32_dstEndPtr = DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH4 * sizeof(tDMA_entry) + 12u;
  /* Alternate structure */
  s_ch4Alternate.s_ctrl.reg = 0u;
  s_ch4Alternate.u32_srcEndPtr = 0u;
  s_ch4Alternate.u32_dstEndPtr = 0u;
#endif
  /* Enable the DMA channel */
  DMA->CHNL_ENABLE_SET.reg |= (uint32)(1u << DMA_CH4);
#endif
  /* Channel 5 */
#if (DMA_CH5_MODULE != 0u)
  s_ch5Primary.s_ctrl.bit.u32_srcProtCtrl = 7u;
  s_ch5Primary.s_ctrl.bit.u32_dstProtCtrl = 7u;
  /* Basic Mode */
#if (DMA_CH5_MODE == 0u)
  /* Primary structure */
  s_ch5Primary.s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_Basic;
  s_ch5Primary.s_ctrl.bit.u32_nextUseburst = 0u;
  s_ch5Primary.s_ctrl.bit.u32_Nminus1 = (uint16)(DMA_CH5_NBTRANSFER - 1u);
  s_ch5Primary.s_ctrl.bit.u32_Rpower = 0u;
  s_ch5Primary.s_ctrl.bit.u32_srcSize = (uint8)DMA_CH5_SIZETRANSFER;
#if (DMA_CH5_SRCINC == 1u)
  s_ch5Primary.s_ctrl.bit.u32_srcInc = (uint8)DMA_CH5_SIZETRANSFER;
#else
  s_ch5Primary.s_ctrl.bit.u32_srcInc = (uint8)3;
#endif
  s_ch5Primary.s_ctrl.bit.u32_dstSize = (uint8)DMA_CH5_SIZETRANSFER;
#if (DMA_CH5_DSTINC == 1u)
  s_ch5Primary.s_ctrl.bit.u32_dstInc = (uint8)DMA_CH5_SIZETRANSFER;
#else
  s_ch5Primary.s_ctrl.bit.u32_dstInc = (uint8)3;
#endif
  s_ch5Primary.u32_srcEndPtr = (uint32)&DMA_CH5_SRC + (uint32)DMA_CH5_SRCPTROFFS;
  s_ch5Primary.u32_dstEndPtr = (uint32)&DMA_CH5_DST + (uint32)DMA_CH5_DSTPTROFFS;
  /* Scatter Gather Mode */
#elif (DMA_CH5_MODE == 1u)
  /* Primary structure */
  s_ch5Primary.s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_MemSctGthPrim;
  s_ch5Primary.s_ctrl.bit.u32_nextUseburst = 0u;
  s_ch5Primary.s_ctrl.bit.u32_Nminus1 = (uint16)(((uint16)DMA_CH5_NBTASK * 4u) - 1u);
  s_ch5Primary.s_ctrl.bit.u32_Rpower = 2u;
  s_ch5Primary.s_ctrl.bit.u32_srcSize = (uint8)DMA_transferSize_32bit;
  s_ch5Primary.s_ctrl.bit.u32_srcInc = DMA_incrementSize_32bit;
  s_ch5Primary.s_ctrl.bit.u32_dstSize = (uint8)DMA_transferSize_32bit;
  s_ch5Primary.s_ctrl.bit.u32_dstInc = DMA_incrementSize_32bit;
  s_ch5Primary.u32_srcEndPtr = (uint32)&DMA_CH5_TASKLIST[0] + (uint32)((uint16)(((uint16)DMA_CH5_NBTASK * 4u) - 1u) * ((uint8)1u << (uint8)DMA_transferSize_32bit));
  s_ch5Primary.u32_dstEndPtr = DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH5 * sizeof(tDMA_entry) + 12u;
  /* Alternate structure */
  s_ch5Alternate.s_ctrl.reg = 0u;
  s_ch5Alternate.u32_srcEndPtr = 0u;
  s_ch5Alternate.u32_dstEndPtr = 0u;
#endif
  /* Enable the DMA channel */
  DMA->CHNL_ENABLE_SET.reg |= (uint32)(1u << DMA_CH5);
#endif
  /* Channel 6 */
#if (DMA_CH6_MODULE != 0u)
  s_ch6Primary.s_ctrl.bit.u32_srcProtCtrl = 7u;
  s_ch6Primary.s_ctrl.bit.u32_dstProtCtrl = 7u;
  /* Basic Mode */
#if (DMA_CH6_MODE == 0u)
  /* Primary structure */
  s_ch6Primary.s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_Basic;
  s_ch6Primary.s_ctrl.bit.u32_nextUseburst = 0u;
  s_ch6Primary.s_ctrl.bit.u32_Nminus1 = (uint16)(DMA_CH6_NBTRANSFER - 1u);
  s_ch6Primary.s_ctrl.bit.u32_Rpower = 0u;
  s_ch6Primary.s_ctrl.bit.u32_srcSize = (uint8)DMA_CH6_SIZETRANSFER;
#if (DMA_CH6_SRCINC == 1u)
  s_ch6Primary.s_ctrl.bit.u32_srcInc = (uint8)DMA_CH6_SIZETRANSFER;
#else
  s_ch6Primary.s_ctrl.bit.u32_srcInc = (uint8)3;
#endif
  s_ch6Primary.s_ctrl.bit.u32_dstSize = (uint8)DMA_CH6_SIZETRANSFER;
#if (DMA_CH6_DSTINC == 1u)
  s_ch6Primary.s_ctrl.bit.u32_dstInc = (uint8)DMA_CH6_SIZETRANSFER;
#else
  s_ch6Primary.s_ctrl.bit.u32_dstInc = (uint8)3;
#endif
  s_ch6Primary.u32_srcEndPtr = (uint32)&DMA_CH6_SRC + (uint32)DMA_CH6_SRCPTROFFS;
  s_ch6Primary.u32_dstEndPtr = (uint32)&DMA_CH6_DST + (uint32)DMA_CH6_DSTPTROFFS;
  /* Scatter Gather Mode */
#elif (DMA_CH6_MODE == 1u)
  /* Primary structure */
  s_ch6Primary.s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_MemSctGthPrim;
  s_ch6Primary.s_ctrl.bit.u32_nextUseburst = 0u;
  s_ch6Primary.s_ctrl.bit.u32_Nminus1 = (uint16)(((uint16)DMA_CH6_NBTASK * 4u) - 1u);
  s_ch6Primary.s_ctrl.bit.u32_Rpower = 2u;
  s_ch6Primary.s_ctrl.bit.u32_srcSize = (uint8)DMA_transferSize_32bit;
  s_ch6Primary.s_ctrl.bit.u32_srcInc = DMA_incrementSize_32bit;
  s_ch6Primary.s_ctrl.bit.u32_dstSize = (uint8)DMA_transferSize_32bit;
  s_ch6Primary.s_ctrl.bit.u32_dstInc = DMA_incrementSize_32bit;
  s_ch6Primary.u32_srcEndPtr = (uint32)&DMA_CH6_TASKLIST[0] + (uint32)((uint16)(((uint16)DMA_CH6_NBTASK * 4u) - 1u) * ((uint8)1u << (uint8)DMA_transferSize_32bit));
  s_ch6Primary.u32_dstEndPtr = DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH6 * sizeof(tDMA_entry) + 12u;
  /* Alternate structure */
  s_ch6Alternate.s_ctrl.reg = 0u;
  s_ch6Alternate.u32_srcEndPtr = 0u;
  s_ch6Alternate.u32_dstEndPtr = 0u;
#endif
  /* Enable the DMA channel */
  DMA->CHNL_ENABLE_SET.reg |= (uint32)(1u << DMA_CH6);
#endif
  /* Channel 7 */
#if (DMA_CH7_MODULE != 0u)
  s_ch7Primary.s_ctrl.bit.u32_srcProtCtrl = 7u;
  s_ch7Primary.s_ctrl.bit.u32_dstProtCtrl = 7u;
  /* Basic Mode */
#if (DMA_CH7_MODE == 0u)
  /* Primary structure */
  s_ch7Primary.s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_Basic;
  s_ch7Primary.s_ctrl.bit.u32_nextUseburst = 0u;
  s_ch7Primary.s_ctrl.bit.u32_Nminus1 = (uint16)(DMA_CH7_NBTRANSFER - 1u);
  s_ch7Primary.s_ctrl.bit.u32_Rpower = 0u;
  s_ch7Primary.s_ctrl.bit.u32_srcSize = (uint8)DMA_CH7_SIZETRANSFER;
#if (DMA_CH7_SRCINC == 1u)
  s_ch7Primary.s_ctrl.bit.u32_srcInc = (uint8)DMA_CH7_SIZETRANSFER;
#else
  s_ch7Primary.s_ctrl.bit.u32_srcInc = (uint8)3;
#endif
  s_ch7Primary.s_ctrl.bit.u32_dstSize = (uint8)DMA_CH7_SIZETRANSFER;
#if (DMA_CH7_DSTINC == 1u)
  s_ch7Primary.s_ctrl.bit.u32_dstInc = (uint8)DMA_CH7_SIZETRANSFER;
#else
  s_ch7Primary.s_ctrl.bit.u32_dstInc = (uint8)3;
#endif
  s_ch7Primary.u32_srcEndPtr = (uint32)&DMA_CH7_SRC + (uint32)DMA_CH7_SRCPTROFFS;
  s_ch7Primary.u32_dstEndPtr = (uint32)&DMA_CH7_DST + (uint32)DMA_CH7_DSTPTROFFS;
  /* Scatter Gather Mode */
#elif (DMA_CH7_MODE == 1u)
  /* Primary structure */
  s_ch7Primary.s_ctrl.bit.u32_cycleCtrl = (uint8)DMA_cycleType_MemSctGthPrim;
  s_ch7Primary.s_ctrl.bit.u32_nextUseburst = 0u;
  s_ch7Primary.s_ctrl.bit.u32_Nminus1 = (uint16)(((uint16)DMA_CH7_NBTASK * 4u) - 1u);
  s_ch7Primary.s_ctrl.bit.u32_Rpower = 2u;
  s_ch7Primary.s_ctrl.bit.u32_srcSize = (uint8)DMA_transferSize_32bit;
  s_ch7Primary.s_ctrl.bit.u32_srcInc = DMA_incrementSize_32bit;
  s_ch7Primary.s_ctrl.bit.u32_dstSize = (uint8)DMA_transferSize_32bit;
  s_ch7Primary.s_ctrl.bit.u32_dstInc = DMA_incrementSize_32bit;
  s_ch7Primary.u32_srcEndPtr = (uint32)&DMA_CH7_TASKLIST[0] + (uint32)((uint16)(((uint16)DMA_CH7_NBTASK * 4u) - 1u) * ((uint8)1u << (uint8)DMA_transferSize_32bit));
  s_ch7Primary.u32_dstEndPtr = DMA->ALT_CTRL_BASE_PTR.reg + DMA_CH7 * sizeof(tDMA_entry) + 12u;
  /* Alternate structure */
  s_ch7Alternate.s_ctrl.reg = 0u;
  s_ch7Alternate.u32_srcEndPtr = 0u;
  s_ch7Alternate.u32_dstEndPtr = 0u;
#endif
  /* Enable the DMA channel */
  DMA->CHNL_ENABLE_SET.reg |= (uint32)(1u << DMA_CH7);
#endif
  /* Set the selected channels */
  SCU->DMAP_CCU7.reg = (uint32)SCU_DMAP_CCU7;
  SCU->DMAP_ADC.reg = (uint32)SCU_DMAP_ADC;
  SCU->DMAP_TIM.reg = (uint32)SCU_DMAP_TIM;
  SCU->DMAP_COM.reg = (uint32)SCU_DMAP_COM;
  /* Set continuous transfer setting */
  SCU->DMACTRL.reg = SCU_DMACTRL;
  /* Set DMA Master Enable setting */
#if (DMA_DMA_CFG != 0u)
  DMA_enMaster();
#endif
#endif
  return s8_returnCode;
}