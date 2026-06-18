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

#include "sdadc.h"

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

/** \brief Initialize all CW registers of the SDADC module
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 SDADC_init(void) {
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if(SDADC_GLOBCONF_EN == 1u)
  s8_returnCode = ERR_LOG_SUCCESS;
  SDADC->CFG0.reg = (uint32)SDADC_CFG0;
  SDADC->CFG1.reg = (uint32)SDADC_CFG1;
  SDADC->CMP0_CTRL.reg = (uint32)SDADC_CMP0_CTRL;
  SDADC->CMP1_CTRL.reg = (uint32)SDADC_CMP1_CTRL;
  SDADC->ALTSEL.reg = (uint32)SDADC_ALTSEL;
  SDADC->INSEL.reg = (uint32)SDADC_INSEL;
  SDADC->DITHCFG.reg = (uint32)SDADC_DITHCFG;
#endif
  return s8_returnCode;
}

/*******************************************************************************
**                       Deprecated Function Definitions                      **
*******************************************************************************/

void SDADC_setCh0ResIntNodePtr(void) {
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SDADC_setCh0CmpUpIntNodePtr(void) {
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SDADC_setCh0CmpLoIntNodePtr(void) {
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SDADC_setCh1ResIntNodePtr(void) {
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SDADC_setCh1CmpUpIntNodePtr(void) {
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

void SDADC_setCh1CmpLoIntNodePtr(void) {
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}
