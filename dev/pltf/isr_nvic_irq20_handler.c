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


/* Check if NVIC node 20 is enabled */
#if ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN20_Msk) == (1u << CPU_NVIC_ISER_IRQEN20_Pos))

/*******************************************************************************
**                        Global Variable Definitions                         **
*******************************************************************************/

#if (NVIC_IRQ20_HANDLER_INT_CHECK == 1)
  uint8 u8_interrupt_cnt_irq20 = 0;
#endif

/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

void NVIC_IRQ20_Handler(void)
{
#if (NVIC_IRQ20_HANDLER_INT_CHECK == 1)
  u8_interrupt_cnt_irq20 = 0;
#endif
  /* EXTINT0 Rising Edge */
#if (SCU_EXTINT0_RISING_INT_EN == 1)
#if (((SCU_INP4 & SCU_INP4_INP_EXINT0_Msk) >>  SCU_INP4_INP_EXINT0_Pos) == EXTINT_INP_NVIC_IRQ20)

  if ((SCU->EXTCON.bit.EXTINT0IEV & (uint8)(1u << 0u)) == 1u)
  {
    if (SCU->EXTIS.bit.EXTINT0R == 1u)
    {
      SCU_EXTINT0_RISING_CALLBACK();
      SCU->EXTISC.bit.EXTINT0RCLR = 1u;
#if (NVIC_IRQ20_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq20 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* EXTINT0 Falling Edge */
#if (SCU_EXTINT0_FALLING_INT_EN == 1)
#if (((SCU_INP4 & SCU_INP4_INP_EXINT0_Msk) >>  SCU_INP4_INP_EXINT0_Pos) == EXTINT_INP_NVIC_IRQ20)

  if (((SCU->EXTCON.bit.EXTINT0IEV & (uint8)(1u << 1u)) >> 1u) == 1u)
  {
    if (SCU->EXTIS.bit.EXTINT0F == 1u)
    {
      SCU_EXTINT0_FALLING_CALLBACK();
      SCU->EXTISC.bit.EXTINT0FCLR = 1u;
#if (NVIC_IRQ20_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq20 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* EXTINT1 Rising Edge */
#if (SCU_EXTINT1_RISING_INT_EN == 1)
#if (((SCU_INP4 & SCU_INP4_INP_EXINT1_Msk) >>  SCU_INP4_INP_EXINT1_Pos) == EXTINT_INP_NVIC_IRQ20)

  if ((SCU->EXTCON.bit.EXTINT1IEV & (uint8)(1u << 0u)) == 1u)
  {
    if (SCU->EXTIS.bit.EXTINT1R == 1u)
    {
      SCU_EXTINT1_RISING_CALLBACK();
      SCU->EXTISC.bit.EXTINT1RCLR = 1u;
#if (NVIC_IRQ20_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq20 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* EXTINT1 Falling Edge */
#if (SCU_EXTINT1_FALLING_INT_EN == 1)
#if (((SCU_INP4 & SCU_INP4_INP_EXINT1_Msk) >>  SCU_INP4_INP_EXINT1_Pos) == EXTINT_INP_NVIC_IRQ20)

  if (((SCU->EXTCON.bit.EXTINT1IEV & (uint8)(1u << 1u)) >> 1u) == 1u)
  {
    if (SCU->EXTIS.bit.EXTINT1F == 1u)
    {
      SCU_EXTINT1_FALLING_CALLBACK();
      SCU->EXTISC.bit.EXTINT1FCLR = 1u;
#if (NVIC_IRQ20_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq20 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* EXTINT2 Rising Edge */
#if (SCU_EXTINT2_RISING_INT_EN == 1)
#if (((SCU_INP4 & SCU_INP4_INP_EXINT2_Msk) >>  SCU_INP4_INP_EXINT2_Pos) == EXTINT_INP_NVIC_IRQ20)

  if ((SCU->EXTCON.bit.EXTINT2IEV & (uint8)(1u << 0u)) == 1u)
  {
    if (SCU->EXTIS.bit.EXTINT2R == 1u)
    {
      SCU_EXTINT2_RISING_CALLBACK();
      SCU->EXTISC.bit.EXTINT2RCLR = 1u;
#if (NVIC_IRQ20_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq20 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* EXTINT2 Falling Edge */
#if (SCU_EXTINT2_FALLING_INT_EN == 1)
#if (((SCU_INP4 & SCU_INP4_INP_EXINT2_Msk) >>  SCU_INP4_INP_EXINT2_Pos) == EXTINT_INP_NVIC_IRQ20)

  if (((SCU->EXTCON.bit.EXTINT2IEV & (uint8)(1u << 1u)) >> 1u) == 1u)
  {
    if (SCU->EXTIS.bit.EXTINT2F == 1u)
    {
      SCU_EXTINT2_FALLING_CALLBACK();
      SCU->EXTISC.bit.EXTINT2FCLR = 1u;
#if (NVIC_IRQ20_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq20 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* EXTINT3 Rising Edge */
#if (SCU_EXTINT3_RISING_INT_EN == 1)
#if (((SCU_INP4 & SCU_INP4_INP_EXINT3_Msk) >>  SCU_INP4_INP_EXINT3_Pos) == EXTINT_INP_NVIC_IRQ20)

  if ((SCU->EXTCON.bit.EXTINT3IEV & (uint8)(1u << 0u)) == 1u)
  {
    if (SCU->EXTIS.bit.EXTINT3R == 1u)
    {
      SCU_EXTINT3_RISING_CALLBACK();
      SCU->EXTISC.bit.EXTINT3RCLR = 1u;
#if (NVIC_IRQ20_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq20 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* EXTINT3 Falling Edge */
#if (SCU_EXTINT3_FALLING_INT_EN == 1)
#if (((SCU_INP4 & SCU_INP4_INP_EXINT3_Msk) >>  SCU_INP4_INP_EXINT3_Pos) == EXTINT_INP_NVIC_IRQ20)

  if (((SCU->EXTCON.bit.EXTINT3IEV & (uint8)(1u << 1u)) >> 1u) == 1u)
  {
    if (SCU->EXTIS.bit.EXTINT3F == 1u)
    {
      SCU_EXTINT3_FALLING_CALLBACK();
      SCU->EXTISC.bit.EXTINT3FCLR = 1u;
#if (NVIC_IRQ20_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq20 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
}
#endif /* ((CPU_NVIC_ISER & CPU_NVIC_ISER_IRQEN20_Msk) == 1u) */
