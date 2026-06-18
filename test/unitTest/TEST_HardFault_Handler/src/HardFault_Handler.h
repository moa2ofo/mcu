#ifndef TEST_HARDFAULT_HANDLER_H
#define TEST_HARDFAULT_HANDLER_H

#include "RTE_Components.h"
#include "isr_defines.h"
#include "pmu_defines.h"
#include "scu_defines.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "cmsis_misra.h"
#include "cmsis_version.h"
#include "core_cm3.h"
#include "error_codes.h"
#include "isr.h"
#include "pmu.h"
#include "system_tle989x.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "types.h"

/** \brief HardFault ISR
 */
void HardFault_Handler(void);


#endif /* TEST_HARDFAULT_HANDLER_H */
