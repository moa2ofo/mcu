#ifndef TEST_MON_INIT_H
#define TEST_MON_INIT_H

#include "RTE_Components.h"
#include "pmu_defines.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "cmsis_misra.h"
#include "cmsis_version.h"
#include "core_cm3.h"
#include "error_codes.h"
#include "mon.h"
#include "system_tle989x.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "types.h"

/** \brief Initialize all CW registers of the MON module
 *
 */
void MON_init(void);


#endif /* TEST_MON_INIT_H */
