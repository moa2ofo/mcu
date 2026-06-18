/*
 ***********************************************************************************************************************
 *
 * Copyright (c) Infineon Technologies AG
 * All rights reserved.
 *
 * The applicable license agreement can be found at this pack's installation directory in the file
 * license/IFX_SW_Licence_MOTIX_LITIX.txt
 *
 **********************************************************************************************************************/

/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/

#include "isr.h"
#include "isr_defines.h"
#include "tle989x.h"

/* Check if NVIC node 30 is enabled */
#if((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN30_Msk) == (1u << CPU_NVIC_ISER_IRQEN30_Pos))

/*******************************************************************************
**                        Global Variable Definitions                         **
*******************************************************************************/

#if(NVIC_IRQ30_HANDLER_INT_CHECK == 1)
uint8 u8_interrupt_cnt_irq30 = 0;
#endif

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void NVIC_IRQ30_Handler(void) {
#if(NVIC_IRQ30_HANDLER_INT_CHECK == 1)
  u8_interrupt_cnt_irq30 = 0;
#endif
  /* DMA Ch0 */
#if(DMA_CH0_INT_EN == 1)
#if(((SCU_INP7 & SCU_INP7_INP_DMACH0_Msk) >> SCU_INP7_INP_DMACH0_Pos) == DMA_INP_NVIC_IRQ30)

  if(SCU->DMAIEN.bit.DMACH0EN == 1u) {
    if(SCU->DMAIS.bit.DMACH0 == 1u) {
      DMA_CH0_CALLBACK();
      SCU->DMAISC.bit.DMACH0CLR = 1u;
#if(NVIC_IRQ30_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq30 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* DMA Ch1 */
#if(DMA_CH1_INT_EN == 1)
#if(((SCU_INP7 & SCU_INP7_INP_DMACH1_Msk) >> SCU_INP7_INP_DMACH1_Pos) == DMA_INP_NVIC_IRQ30)

  if(SCU->DMAIEN.bit.DMACH1EN == 1u) {
    if(SCU->DMAIS.bit.DMACH1 == 1u) {
      DMA_CH1_CALLBACK();
      SCU->DMAISC.bit.DMACH1CLR = 1u;
#if(NVIC_IRQ30_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq30 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* DMA Ch2 */
#if(DMA_CH2_INT_EN == 1)
#if(((SCU_INP7 & SCU_INP7_INP_DMACH2_Msk) >> SCU_INP7_INP_DMACH2_Pos) == DMA_INP_NVIC_IRQ30)

  if(SCU->DMAIEN.bit.DMACH2EN == 1u) {
    if(SCU->DMAIS.bit.DMACH2 == 1u) {
      DMA_CH2_CALLBACK();
      SCU->DMAISC.bit.DMACH2CLR = 1u;
#if(NVIC_IRQ30_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq30 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* DMA Ch3 */
#if(DMA_CH3_INT_EN == 1)
#if(((SCU_INP7 & SCU_INP7_INP_DMACH3_Msk) >> SCU_INP7_INP_DMACH3_Pos) == DMA_INP_NVIC_IRQ30)

  if(SCU->DMAIEN.bit.DMACH3EN == 1u) {
    if(SCU->DMAIS.bit.DMACH3 == 1u) {
      DMA_CH3_CALLBACK();
      SCU->DMAISC.bit.DMACH3CLR = 1u;
#if(NVIC_IRQ30_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq30 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* DMA Ch4 */
#if(DMA_CH4_INT_EN == 1)
#if(((SCU_INP7 & SCU_INP7_INP_DMACH4_Msk) >> SCU_INP7_INP_DMACH4_Pos) == DMA_INP_NVIC_IRQ30)

  if(SCU->DMAIEN.bit.DMACH4EN == 1u) {
    if(SCU->DMAIS.bit.DMACH4 == 1u) {
      DMA_CH4_CALLBACK();
      SCU->DMAISC.bit.DMACH4CLR = 1u;
#if(NVIC_IRQ30_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq30 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* DMA Ch5 */
#if(DMA_CH5_INT_EN == 1)
#if(((SCU_INP7 & SCU_INP7_INP_DMACH5_Msk) >> SCU_INP7_INP_DMACH5_Pos) == DMA_INP_NVIC_IRQ30)

  if(SCU->DMAIEN.bit.DMACH5EN == 1u) {
    if(SCU->DMAIS.bit.DMACH5 == 1u) {
      DMA_CH5_CALLBACK();
      SCU->DMAISC.bit.DMACH5CLR = 1u;
#if(NVIC_IRQ30_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq30 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* DMA Ch6 */
#if(DMA_CH6_INT_EN == 1)
#if(((SCU_INP7 & SCU_INP7_INP_DMACH6_Msk) >> SCU_INP7_INP_DMACH6_Pos) == DMA_INP_NVIC_IRQ30)

  if(SCU->DMAIEN.bit.DMACH6EN == 1u) {
    if(SCU->DMAIS.bit.DMACH6 == 1u) {
      DMA_CH6_CALLBACK();
      SCU->DMAISC.bit.DMACH6CLR = 1u;
#if(NVIC_IRQ30_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq30 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* DMA Ch7 */
#if(DMA_CH7_INT_EN == 1)
#if(((SCU_INP7 & SCU_INP7_INP_DMACH7_Msk) >> SCU_INP7_INP_DMACH7_Pos) == DMA_INP_NVIC_IRQ30)

  if(SCU->DMAIEN.bit.DMACH7EN == 1u) {
    if(SCU->DMAIS.bit.DMACH7 == 1u) {
      DMA_CH7_CALLBACK();
      SCU->DMAISC.bit.DMACH7CLR = 1u;
#if(NVIC_IRQ30_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq30 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* DMA Error */
#if(DMA_ERROR_INT_EN == 1)
#if(((SCU_INP7 & SCU_INP7_INP_DMATRERR_Msk) >> SCU_INP7_INP_DMATRERR_Pos) == DMA_INP_NVIC_IRQ30)

  if(SCU->DMAIEN.bit.DMATRERREN == 1u) {
    if(DMA->ERR_CLR.bit.ERR_CLR == 1u) {
      DMA_ERROR_CALLBACK();
      DMA->ERR_CLR.bit.ERR_CLR = 1u;
#if(NVIC_IRQ30_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq30 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
}
#endif /* ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN30_Msk) == 1u) */
