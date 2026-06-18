#ifndef TEST_BDRV_SETHSCHRGCONSTMODE_H
#define TEST_BDRV_SETHSCHRGCONSTMODE_H

#include "RTE_Components.h"
#include "adc1_defines.h"
#include "adc2_defines.h"
#include "bdrv_defines.h"
#include "csacsc_defines.h"
#include "isr_defines.h"
#include "pmu_defines.h"
#include "scu_defines.h"
#include "adc1.h"
#include "adc2.h"
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

/** \brief Set high-side charge times and currents for constant mode
 *
 * \param e_hb Selection of the half-bridge (HB1, HB2 or HB3)
 * \param s_constChrgCfg Configuration of the constant mode for charge
 * \return sint8 0: success, <0: error codes
 */
sint8 BDRV_setHSChrgConstMode(tBDRV_hb e_hb, tBDRV_constCfg s_constChrgCfg);


#endif /* TEST_BDRV_SETHSCHRGCONSTMODE_H */
