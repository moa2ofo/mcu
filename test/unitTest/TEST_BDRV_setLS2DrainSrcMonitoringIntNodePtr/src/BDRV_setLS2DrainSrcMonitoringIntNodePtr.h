#ifndef TEST_BDRV_SETLS2DRAINSRCMONITORINGINTNODEPTR_H
#define TEST_BDRV_SETLS2DRAINSRCMONITORINGINTNODEPTR_H

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

/** \brief Set Low Side 2 Drain-Source Monitoring Interrupt Node Pointer
 * \warning Do not change this at runtime, use the ConfigWizard to configure this feature!
 */
void BDRV_setLS2DrainSrcMonitoringIntNodePtr(void);


#endif /* TEST_BDRV_SETLS2DRAINSRCMONITORINGINTNODEPTR_H */
