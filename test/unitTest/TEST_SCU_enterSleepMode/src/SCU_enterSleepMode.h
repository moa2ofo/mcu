#ifndef TEST_SCU_ENTERSLEEPMODE_H
#define TEST_SCU_ENTERSLEEPMODE_H

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

/** \brief Enter the Sleep mode
 * \note Before entering sleep mode, you can store data in the GPUDATAx [x=0..2] registers.
 */
void SCU_enterSleepMode(void);


#endif /* TEST_SCU_ENTERSLEEPMODE_H */
