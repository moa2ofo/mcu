#include "NVIC_IRQ12_Handler_help.h"

/* FUNCTION TO TEST */
void NVIC_IRQ12_Handler(void)
{
#if (NVIC_IRQ12_HANDLER_INT_CHECK == 1)
  u8_interrupt_cnt_irq12 = 0;
#endif
  /* MON1 R */
#if (MON_MON1_R_INT_EN == 1)
#if (((SCU_INP2 & SCU_INP2_INP_MON1_Msk) >>  SCU_INP2_INP_MON1_Pos) == MON_INP_NVIC_IRQ12)

  if (SCU->MONIEN.bit.MON1EN == 1u)
  {
    if (SCU->MONIS.bit.MON1R == 1u)
    {
      MON_MON1_R_CALLBACK();
      SCU->MONISC.bit.MON1RCLR = 1u;
#if (NVIC_IRQ12_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq12 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* MON1 F */
#if (MON_MON1_F_INT_EN == 1)
#if (((SCU_INP2 & SCU_INP2_INP_MON1_Msk) >>  SCU_INP2_INP_MON1_Pos) == MON_INP_NVIC_IRQ12)

  if (SCU->MONIEN.bit.MON1EN == 1u)
  {
    if (SCU->MONIS.bit.MON1F == 1u)
    {
      MON_MON1_F_CALLBACK();
      SCU->MONISC.bit.MON1FCLR = 1u;
#if (NVIC_IRQ12_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq12 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* MON2 R */
#if (MON_MON2_R_INT_EN == 1)
#if (((SCU_INP2 & SCU_INP2_INP_MON2_Msk) >>  SCU_INP2_INP_MON2_Pos) == MON_INP_NVIC_IRQ12)

  if (SCU->MONIEN.bit.MON2EN == 1u)
  {
    if (SCU->MONIS.bit.MON2R == 1u)
    {
      MON_MON2_R_CALLBACK();
      SCU->MONISC.bit.MON2RCLR = 1u;
#if (NVIC_IRQ12_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq12 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* MON2 F */
#if (MON_MON2_F_INT_EN == 1)
#if (((SCU_INP2 & SCU_INP2_INP_MON2_Msk) >>  SCU_INP2_INP_MON2_Pos) == MON_INP_NVIC_IRQ12)

  if (SCU->MONIEN.bit.MON2EN == 1u)
  {
    if (SCU->MONIS.bit.MON2F == 1u)
    {
      MON_MON2_F_CALLBACK();
      SCU->MONISC.bit.MON2FCLR = 1u;
#if (NVIC_IRQ12_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq12 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* MON3 R */
#if (MON_MON3_R_INT_EN == 1)
#if (((SCU_INP2 & SCU_INP2_INP_MON3_Msk) >>  SCU_INP2_INP_MON3_Pos) == MON_INP_NVIC_IRQ12)

  if (SCU->MONIEN.bit.MON3EN == 1u)
  {
    if (SCU->MONIS.bit.MON3R == 1u)
    {
      MON_MON3_R_CALLBACK();
      SCU->MONISC.bit.MON3RCLR = 1u;
#if (NVIC_IRQ12_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq12 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
  /* MON3 F */
#if (MON_MON3_F_INT_EN == 1)
#if (((SCU_INP2 & SCU_INP2_INP_MON3_Msk) >>  SCU_INP2_INP_MON3_Pos) == MON_INP_NVIC_IRQ12)

  if (SCU->MONIEN.bit.MON3EN == 1u)
  {
    if (SCU->MONIS.bit.MON3F == 1u)
    {
      MON_MON3_F_CALLBACK();
      SCU->MONISC.bit.MON3FCLR = 1u;
#if (NVIC_IRQ12_HANDLER_INT_CHECK == 1)
      u8_interrupt_cnt_irq12 += 1u;
#endif
    }
  }

#endif /* Interrupt assigned to this node */
#endif /* Interrupt enabled */
}