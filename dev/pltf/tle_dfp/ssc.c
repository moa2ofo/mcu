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

#include "ssc.h"

/*******************************************************************************
**                        Private Constant Declarations                       **
*******************************************************************************/

/*******************************************************************************
**                         Private Macro Declarations                         **
*******************************************************************************/

/*******************************************************************************
**                        Private Variable Definitions                        **
*******************************************************************************/

/*******************************************************************************
**                        Private Function Declarations                       **
*******************************************************************************/

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/

/** \brief Initialize all CW registers of the SSC0 module
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 SSC0_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if ((SCU_PMCON & SCU_PMCON_SSC0_DIS_Msk) == 0u)
  s8_returnCode = ERR_LOG_SUCCESS;
  SSC0->CON.reg = (uint32)SSC0_CON;
  SSC0->INSEL.reg = (uint32)SSC0_INSEL;
  SSC0->CSTIM.reg = (uint32)SSC0_CSTIM;
  SSC0->BR.reg = (uint32)SSC0_BR;
#endif
  return s8_returnCode;
}

/** \brief Initialize all CW registers of the SSC1 module
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 SSC1_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if ((SCU_PMCON & SCU_PMCON_SSC1_DIS_Msk) == 0u)
  s8_returnCode = ERR_LOG_SUCCESS;
  SSC1->CON.reg = (uint32)SSC1_CON;
  SSC1->INSEL.reg = (uint32)SSC1_INSEL;
  SSC1->CSTIM.reg = (uint32)SSC1_CSTIM;
  SSC1->BR.reg = (uint32)SSC1_BR;
#endif
  return s8_returnCode;
}

/*******************************************************************************
**                       Deprecated Function Definitions                      **
*******************************************************************************/

void SSC0_setEmptyTXBufferIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SSC0_setEmptyRXBufferIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SSC0_setTXErrIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SSC0_setRXErrIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SSC0_setPhaseErrIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SSC0_setBaudrateErrIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SSC1_setEmptyTXBufferIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SSC1_setEmptyRXBufferIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SSC1_setTXErrIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SSC1_setRXErrIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SSC1_setPhaseErrIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SSC1_setBaudrateErrIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}
