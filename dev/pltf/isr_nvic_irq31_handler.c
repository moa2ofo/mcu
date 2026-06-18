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

/* Check if NVIC node 31 is enabled */
#if((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN31_Msk) == (1u << CPU_NVIC_ISER_IRQEN31_Pos))

/*******************************************************************************
**                        Global Variable Definitions                         **
*******************************************************************************/

#if(NVIC_IRQ31_HANDLER_INT_CHECK == 1)
uint8 u8_interrupt_cnt_irq31 = 0;
#endif

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void NVIC_IRQ31_Handler(void) {
#if(NVIC_IRQ31_HANDLER_INT_CHECK == 1)
  u8_interrupt_cnt_irq31 = 0;
#endif
  /* External Int */
#if(T21_EXF2_INT_EN == 1)

  if(T21->CON1.bit.EXF2EN == 1u) {
    if(T21->CON.bit.EXF2 == 1u) {
      T21_EXF2_CALLBACK();
      T21->ICLR.bit.EXF2CLR = 1u;
#if(NVIC_IRQ31_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq31 += 1u;
#endif
    }
  }

#endif /* Interrupt enabled */
  /* Over-/Underflow Int */
#if(T21_TF2_INT_EN == 1)

  if(T21->CON1.bit.TF2EN == 1u) {
    if(T21->CON.bit.TF2 == 1u) {
      T21_TF2_CALLBACK();
      T21->ICLR.bit.TF2CLR = 1u;
#if(NVIC_IRQ31_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq31 += 1u;
#endif
    }
  }

#endif /* Interrupt enabled */
}
#endif /* ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN31_Msk) == 1u) */
