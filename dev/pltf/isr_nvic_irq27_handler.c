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

#include "tle989x.h"
#include "isr.h"
#include "isr_defines.h"


/* Check if NVIC node 27 is enabled */
#if ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN27_Msk) == (1u << CPU_NVIC_ISER_IRQEN27_Pos))

/*******************************************************************************
**                        Global Variable Definitions                         **
*******************************************************************************/

#if (NVIC_IRQ27_HANDLER_INT_CHECK == 1)
  uint8 u8_interrupt_cnt_irq27 = 0;
#endif

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void NVIC_IRQ27_Handler(void)
{
#if (NVIC_IRQ27_HANDLER_INT_CHECK == 1)
  u8_interrupt_cnt_irq27 = 0;
#endif
  // Functionality to be defined by user
}
#endif /* ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN27_Msk) == 1u) */
