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

/* Check if NVIC node 23 is enabled */
#if((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN23_Msk) == (1u << CPU_NVIC_ISER_IRQEN23_Pos))

/*******************************************************************************
**                        Global Variable Definitions                         **
*******************************************************************************/

#if(NVIC_IRQ23_HANDLER_INT_CHECK == 1)
uint8 u8_interrupt_cnt_irq23 = 0;
#endif

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void NVIC_IRQ23_Handler(void) {
#if(NVIC_IRQ23_HANDLER_INT_CHECK == 1)
  u8_interrupt_cnt_irq23 = 0;
#endif
  /* UART0 Transmit */
#if(UART0_TI_INT_EN == 1)
#if(((SCU_INP5 & SCU_INP5_INP_UART0_TI_Msk) >> SCU_INP5_INP_UART0_TI_Pos) == UART_INP_NVIC_IRQ23)

  if(UART0->IEN.bit.TIEN == 1u) {
    if(UART0->IS.bit.TI == 1u) {
      UART0_TI_CALLBACK();
      UART0->ISC.bit.TICLR = 1u;
#if(NVIC_IRQ23_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq23 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* UART0 Receive */
#if(UART0_RI_INT_EN == 1)
#if(((SCU_INP5 & SCU_INP5_INP_UART0_RI_Msk) >> SCU_INP5_INP_UART0_RI_Pos) == UART_INP_NVIC_IRQ23)

  if(UART0->IEN.bit.RIEN == 1u) {
    if(UART0->IS.bit.RI == 1u) {
      UART0_RI_CALLBACK();
      UART0->ISC.bit.RICLR = 1u;
#if(NVIC_IRQ23_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq23 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* LIN0 End of Sync */
#if(UART0_EOS_INT_EN == 1)
#if(((SCU_INP5 & SCU_INP5_INP_LIN0_EOFSYN_Msk) >> SCU_INP5_INP_LIN0_EOFSYN_Pos) == UART_INP_NVIC_IRQ23)

  if(UART0->IEN.bit.EOFSYNEN == 1u) {
    if(UART0->IS.bit.EOFSYN == 1u) {
      UART0_EOS_CALLBACK();
      UART0->ISC.bit.EOFSYNCLR = 1u;
#if(NVIC_IRQ23_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq23 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* LIN0 Sync Error */
#if(UART0_SYNCERR_INT_EN == 1)
#if(((SCU_INP5 & SCU_INP5_INP_LIN0_ERRSYN_Msk) >> SCU_INP5_INP_LIN0_ERRSYN_Pos) == UART_INP_NVIC_IRQ23)

  if(UART0->IEN.bit.ERRSYNEN == 1u) {
    if(UART0->IS.bit.ERRSYN == 1u) {
      UART0_SYNCERR_CALLBACK();
      UART0->ISC.bit.ERRSYNCLR = 1u;
#if(NVIC_IRQ23_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq23 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* UART1 Transmit */
#if(UART1_TI_INT_EN == 1)
#if(((SCU_INP5 & SCU_INP5_INP_UART1_TI_Msk) >> SCU_INP5_INP_UART1_TI_Pos) == UART_INP_NVIC_IRQ23)

  if(UART1->IEN.bit.TIEN == 1u) {
    if(UART1->IS.bit.TI == 1u) {
      UART1_TI_CALLBACK();
      UART1->ISC.bit.TICLR = 1u;
#if(NVIC_IRQ23_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq23 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* UART1 Receive */
#if(UART1_RI_INT_EN == 1)
#if(((SCU_INP5 & SCU_INP5_INP_UART1_RI_Msk) >> SCU_INP5_INP_UART1_RI_Pos) == UART_INP_NVIC_IRQ23)

  if(UART1->IEN.bit.RIEN == 1u) {
    if(UART1->IS.bit.RI == 1u) {
      UART1_RI_CALLBACK();
      UART1->ISC.bit.RICLR = 1u;
#if(NVIC_IRQ23_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq23 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* LIN1 End of Sync */
#if(UART1_EOS_INT_EN == 1)
#if(((SCU_INP5 & SCU_INP5_INP_LIN1_EOFSYN_Msk) >> SCU_INP5_INP_LIN1_EOFSYN_Pos) == UART_INP_NVIC_IRQ23)

  if(UART1->IEN.bit.EOFSYNEN == 1u) {
    if(UART1->IS.bit.EOFSYN == 1u) {
      UART1_EOS_CALLBACK();
      UART1->ISC.bit.EOFSYNCLR = 1u;
#if(NVIC_IRQ23_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq23 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* LIN1 Sync Error */
#if(UART1_SYNCERR_INT_EN == 1)
#if(((SCU_INP5 & SCU_INP5_INP_LIN1_ERRSYN_Msk) >> SCU_INP5_INP_LIN1_ERRSYN_Pos) == UART_INP_NVIC_IRQ23)

  if(UART1->IEN.bit.ERRSYNEN == 1u) {
    if(UART1->IS.bit.ERRSYN == 1u) {
      UART1_SYNCERR_CALLBACK();
      UART1->ISC.bit.ERRSYNCLR = 1u;
#if(NVIC_IRQ23_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq23 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
}
#endif /* ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN23_Msk) == 1u) */
