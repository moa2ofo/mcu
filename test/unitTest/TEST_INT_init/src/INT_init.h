#ifndef TEST_INT_INIT_H
#define TEST_INT_INIT_H

#include "RTE_Components.h"
#include "ccu7_defines.h"
#include "isr_defines.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "cmsis_misra.h"
#include "cmsis_version.h"
#include "core_cm3.h"
#include "error_codes.h"
#include "int.h"
#include "system_tle989x.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "types.h"

/** \brief Initialize all interrupt-related registers
 */
void INT_init(void);


#endif /* TEST_INT_INIT_H */
