#include "SCU_checkXTALDiagnosis_help.h"

/* FUNCTION TO TEST */
sint8 SCU_checkXTALDiagnosis(void)
{
  sint8 s8_returnCode;
  uint32 u32_gpioP2Pud;
  uint32 u32_gpioP2Indis;
  s8_returnCode = ERR_LOG_SUCCESS;
  /* Store register values */
  u32_gpioP2Pud = GPIO->P2_PUD.reg;
  u32_gpioP2Indis = GPIO->P2_INDIS.reg;
  GPIO->P2_PUD.bit.PUDEN0 = 1u;
  GPIO->P2_INDIS.bit.INDIS0 = 0u;
  GPIO->P2_PUD.bit.PUDSEL0 = 1u;
  SCU_delay_us(5);

  if (GPIO->P2_IN.bit.PI0 == 0u)
  {
    s8_returnCode = ERR_LOG_ERROR;
  }

  GPIO->P2_PUD.bit.PUDSEL0 = 0u;
  SCU_delay_us(5);

  if (GPIO->P2_IN.bit.PI0 == 1u)
  {
    s8_returnCode = ERR_LOG_ERROR;
  }

  GPIO->P2_PUD.bit.PUDEN0 = 0u;
  GPIO->P2_INDIS.bit.INDIS0 = 1u;
  GPIO->P2_PUD.bit.PUDEN1 = 1u;
  GPIO->P2_INDIS.bit.INDIS1 = 0u;
  GPIO->P2_PUD.bit.PUDSEL1 = 1u;
  SCU_delay_us(5);

  if (GPIO->P2_IN.bit.PI1 == 0u)
  {
    s8_returnCode = ERR_LOG_ERROR;
  }

  GPIO->P2_PUD.bit.PUDSEL1 = 0u;
  SCU_delay_us(5);

  if (GPIO->P2_IN.bit.PI1 == 1u)
  {
    s8_returnCode = ERR_LOG_ERROR;
  }

  GPIO->P2_PUD.bit.PUDEN1 = 0u;
  GPIO->P2_INDIS.bit.INDIS1 = 1u;
  /* Restore register values */
  GPIO->P2_PUD.reg = u32_gpioP2Pud;
  GPIO->P2_INDIS.reg = u32_gpioP2Indis;
  return s8_returnCode;
}