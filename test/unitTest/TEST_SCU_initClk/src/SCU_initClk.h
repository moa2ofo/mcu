#ifndef TEST_SCU_INITCLK_H
#define TEST_SCU_INITCLK_H

#include "RTE_Components.h"
#include "adc1_defines.h"
#include "bdrv_defines.h"
#include "csacsc_defines.h"
#include "isr_defines.h"
#include "pmu_defines.h"
#include "scu_defines.h"
#include "adc1.h"
#include "bdrv.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "cmsis_misra.h"
#include "cmsis_version.h"
#include "core_cm3.h"
#include "csacsc.h"
#include "error_codes.h"
#include "isr.h"
#include "pmu.h"
#include "scu.h"
#include "system_tle989x.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "types.h"

/** \brief Initialize the SCU clock
 * \brief If configured in Config Wizard, the function initializes
 * \brief - XTAL
 * \brief - PLL0
 * \brief - PLL1
 * \brief In case of an XTAL error, the XTAL error status
 * is stored in the global variable e_xtalSts
 * \brief The function always initializes
 * \brief - fSYS0 (for core and peripherals except UART, CAN)
 * \brief - fSYS1 (for UART, CAN)
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 SCU_initClk(void);


#endif /* TEST_SCU_INITCLK_H */
