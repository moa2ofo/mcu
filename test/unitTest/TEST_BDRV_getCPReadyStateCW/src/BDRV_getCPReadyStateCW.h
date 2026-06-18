#ifndef TEST_BDRV_GETCPREADYSTATECW_H
#define TEST_BDRV_GETCPREADYSTATECW_H

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

/** \brief Check if the Charge Pump needs to be ready to enable the BDRV in the Config Wizard settings
 *
 * \retval 0u, BDRV can be enabled without CP voltage reached
 * \retval 1u, BDRV can only be enabled when CP is ready
 */
uint8 BDRV_getCPReadyStateCW(void);


#endif /* TEST_BDRV_GETCPREADYSTATECW_H */
