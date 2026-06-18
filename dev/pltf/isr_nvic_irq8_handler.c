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

/* Check if NVIC node 8 is enabled */
#if((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN8_Msk) == (1u << CPU_NVIC_ISER_IRQEN8_Pos))

/*******************************************************************************
**                        Global Variable Definitions                         **
*******************************************************************************/

#if(NVIC_IRQ8_HANDLER_INT_CHECK == 1)
uint8 u8_interrupt_cnt_irq8 = 0;
#endif

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void NVIC_IRQ8_Handler(void) {
#if(NVIC_IRQ8_HANDLER_INT_CHECK == 1)
  u8_interrupt_cnt_irq8 = 0;
#endif
  /* GPT12 T2 */
#if(GPT12_GPT1T2_INT_EN == 1)
#if(((SCU_INP1 & SCU_INP1_INP_GPT1T2_Msk) >> SCU_INP1_INP_GPT1T2_Pos) == GPT12_INP_NVIC_IRQ8)

  if(SCU->GPTIEN.bit.GPT1T2EN == 1u) {
    if(SCU->GPTIS.bit.GPT1T2 == 1u) {
      GPT12_GPT1T2_CALLBACK();
      SCU->GPTISC.bit.GPT1T2CLR = 1u;
#if(NVIC_IRQ8_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq8 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* GPT12 T3 */
#if(GPT12_GPT1T3_INT_EN == 1)
#if(((SCU_INP1 & SCU_INP1_INP_GPT1T3_Msk) >> SCU_INP1_INP_GPT1T3_Pos) == GPT12_INP_NVIC_IRQ8)

  if(SCU->GPTIEN.bit.GPT1T3EN == 1u) {
    if(SCU->GPTIS.bit.GPT1T3 == 1u) {
      GPT12_GPT1T3_CALLBACK();
      SCU->GPTISC.bit.GPT1T3CLR = 1u;
#if(NVIC_IRQ8_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq8 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* GPT12 T4 */
#if(GPT12_GPT1T4_INT_EN == 1)
#if(((SCU_INP1 & SCU_INP1_INP_GPT1T4_Msk) >> SCU_INP1_INP_GPT1T4_Pos) == GPT12_INP_NVIC_IRQ8)

  if(SCU->GPTIEN.bit.GPT1T4EN == 1u) {
    if(SCU->GPTIS.bit.GPT1T4 == 1u) {
      GPT12_GPT1T4_CALLBACK();
      SCU->GPTISC.bit.GPT1T4CLR = 1u;
#if(NVIC_IRQ8_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq8 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* GPT12 T5 */
#if(GPT12_GPT2T5_INT_EN == 1)
#if(((SCU_INP1 & SCU_INP1_INP_GPT2T5_Msk) >> SCU_INP1_INP_GPT2T5_Pos) == GPT12_INP_NVIC_IRQ8)

  if(SCU->GPTIEN.bit.GPT2T5EN == 1u) {
    if(SCU->GPTIS.bit.GPT2T5 == 1u) {
      GPT12_GPT2T5_CALLBACK();
      SCU->GPTISC.bit.GPT2T5CLR = 1u;
#if(NVIC_IRQ8_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq8 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* GPT12 T6 */
#if(GPT12_GPT2T6_INT_EN == 1)
#if(((SCU_INP1 & SCU_INP1_INP_GPT2T6_Msk) >> SCU_INP1_INP_GPT2T6_Pos) == GPT12_INP_NVIC_IRQ8)

  if(SCU->GPTIEN.bit.GPT2T6EN == 1u) {
    if(SCU->GPTIS.bit.GPT2T6 == 1u) {
      GPT12_GPT2T6_CALLBACK();
      SCU->GPTISC.bit.GPT2T6CLR = 1u;
#if(NVIC_IRQ8_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq8 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* GPT12 CAPREL */
#if(GPT12_GPT2CAPREL_INT_EN == 1)
#if(((SCU_INP1 & SCU_INP1_INP_GPT2CR_Msk) >> SCU_INP1_INP_GPT2CR_Pos) == GPT12_INP_NVIC_IRQ8)

  if(SCU->GPTIEN.bit.GPT2CREN == 1u) {
    if(SCU->GPTIS.bit.GPT2CR == 1u) {
      GPT12_GPT2CAPREL_CALLBACK();
      SCU->GPTISC.bit.GPT2CRCLR = 1u;
#if(NVIC_IRQ8_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq8 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
}
#endif /* ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN8_Msk) == 1u) */
