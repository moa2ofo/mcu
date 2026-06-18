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
/**
 * \file     tle_device.h
 *
 * \brief    SDK initialization
 *
 * \version  V0.4.0
 * \date     05. Nov 2024
 *
 * \note
 */

/*******************************************************************************
**                             Author(s) Identity                             **
********************************************************************************
** Initials     Name                                                          **
** ---------------------------------------------------------------------------**
** DM           Daniel Mysliwitz                                              **
** BG           Blandine Guillot                                              **
** JO           Julia Ott                                                     **
** PS           Patrik Schwarz                                                **
*******************************************************************************/

/*******************************************************************************
**                          Revision Control History                          **
********************************************************************************
** V0.1.0: 2019-10-28, DM:   Initial version                                  **
** V0.2.0: 2020-04-28, BG:   Updated revision history format                  **
** V0.2.1: 2020-09-16, DM:   BRDV_initCP() call to TLE_init() added           **
** V0.2.2: 2020-10-21, BG:   EP-537: Updated placement for interrupt init and **
**                           added placeholder for CAN                        **
** V0.2.3: 2020-10-21, BG:   EP-539: Considered return codes for TLE_init     **
** V0.2.4: 2020-10-22, JO:   EP-539: Removed dependency of the init functions **
**                           on previous error codes in TLE_init              **
** V0.2.5: 2020-10-26, BG:   EP-550: Added missing ADC2 initialization in     **
**                           TLE_init()                                       **
** V0.2.6: 2020-11-12, JO:   EP-590: Removed \param none and \return none to  **
**                           avoid doxygen warning                            **
** V0.2.7: 2020-11-20, BG:   EP-610: Corrected MISRA 2012 errors              **
**                           The following rules are globally deactivated:    **
**                           - Info 774: Boolean within 'if' always evaluates **
**                             to False/True                                  **
** V0.2.8: 2020-12-18, BG:   EP-652: Corrected name of error code variable    **
** V0.3.0: 2020-12-30, JO:   EP-659: Added missing CANTRX initialization in   **
**                           TLE_init() (function CANTRX_init)                **
** V0.3.1: 2021-02-02, BG:   EP-654: Separated CAN into CANCONTR and CANTRX   **
** V0.3.2: 2021-04-23, JO:   EP-776: Added and initialized global variables   **
**                           UC_FLASH0_UBSL_SIZE, UC_FLASH0_UDATA_START,      **
**                           UC_FLASH0_UDATA_SIZE                             **
** V0.3.3: 2021-06-08, BG:   EP-685: Activated the init function for DMA      **
** V0.3.4: 2021-11-12, JO:   EP-937: Updated copyright and branding           **
** V0.3.5: 2023-04-04, PS:   EP-1141: Correct MISRA warnings                  **
** V0.3.6: 2023-04-06, JO:   EP-1143: Added error handling for module used in **
**                           Config Wizard but not enabled in RTE/package     **
**                           manager                                          **
** V0.3.7: 2023-05-09, BG:   EP-1428: Updated calculation of UBSL region size **
**                           with FW API user_nvm_config_get(**) after SVD    **
**                           update                                           **
** V0.3.8: 2023-10-19, JO:   EP-1471: Corrected SDADC handling when using     **
**                           a device without SDADC                           **
** V0.3.9: 2023-05-06, JO:   EP-1481: Corrected calculation of                **
**                           UC_FLASH0_UBSL_SIZE                              **
** V0.4.0: 2024-11-05, JO:   EP-1494: Updated license                         **
*******************************************************************************/

#ifndef _TLE_DEVICE_H
#define _TLE_DEVICE_H

/*******************************************************************************
**                                  Includes                                  **
*******************************************************************************/

#include "tle_variants.h"
#include "RTE_Components.h"

#ifdef RTE_DEVICE_TLELIB_ADC1
  #include "adc1.h"
#endif
#ifdef RTE_DEVICE_TLELIB_ADC2
  #include "adc2.h"
#endif
#ifdef RTE_DEVICE_TLELIB_BDRV
  #include "bdrv.h"
#endif
#ifdef RTE_DEVICE_TLELIB_BOOTROM
  #include "bootrom.h"
#endif
#ifdef RTE_DEVICE_TLELIB_CANCONTR
  #include "can.h"
#endif
#ifdef RTE_DEVICE_TLELIB_CANTRX
  #include "cantrx.h"
#endif
#ifdef RTE_DEVICE_TLELIB_CCU7
  #include "ccu7.h"
#endif
#ifdef RTE_DEVICE_TLELIB_CSACSC
  #include "csacsc.h"
#endif
#ifdef RTE_DEVICE_TLELIB_DMA
  #include "dma.h"
#endif
#ifdef RTE_DEVICE_TLELIB_GPIO
  #include "gpio.h"
#endif
#ifdef RTE_DEVICE_TLELIB_GPT12
  #include "gpt12.h"
#endif
#ifdef RTE_DEVICE_TLELIB_INT
  #include "int.h"
#endif
#ifdef RTE_DEVICE_TLELIB_ISR
  #include "isr.h"
#endif
#ifdef RTE_DEVICE_TLELIB_MON
  #include "mon.h"
#endif
#ifdef RTE_DEVICE_TLELIB_PMU
  #include "pmu.h"
#endif
#ifdef RTE_DEVICE_TLELIB_SCU
  #include "scu.h"
#endif
#ifdef RTE_DEVICE_TLELIB_SDADC
  #include "sdadc.h"
#endif
#ifdef RTE_DEVICE_TLELIB_SSC
  #include "ssc.h"
#endif
#ifdef RTE_DEVICE_TLELIB_TIMER2X
  #include "timer2x.h"
#endif
#ifdef RTE_DEVICE_TLELIB_UART
  #include "uart.h"
#endif

/*******************************************************************************
**                        Global Variable Declarations                        **
*******************************************************************************/
extern uint32 UC_FLASH0_UBSL_SIZE;
extern uint32 UC_FLASH0_UDATA_START;
extern uint32 UC_FLASH0_UDATA_SIZE;


/*******************************************************************************
**                        Global Function Declarations                        **
*******************************************************************************/
/** \brief Initialize the TLE modules
 *
 * \ingroup tle_api
 */

#endif
