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

#include "cantrx.h"

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

/** \brief Initialize all CW registers of the cantrx module
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 CANTRX_init(void)
{
  sint8 s8_returnCode;
  s8_returnCode = ERR_LOG_CODE_MODULE_DISABLED_IN_CW;
#if ((CANTRX_CTRL & CANTRX_CTRL_EN_Msk) == CANTRX_CTRL_EN_Msk)
  s8_returnCode = ERR_LOG_SUCCESS;
  CANTRX->CTRL.reg = (uint32)CANTRX_CTRL;
#endif
  return s8_returnCode;
}

/*******************************************************************************
**                       Deprecated Function Definitions                      **
*******************************************************************************/

void CANTRX_setCANTRXIntNodePtr(void)
{
  /* Do not change this at runtime, use the ConfigWizard to configure this feature! */
}

