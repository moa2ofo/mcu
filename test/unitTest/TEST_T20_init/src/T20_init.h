#ifndef TEST_T20_INIT_H
#define TEST_T20_INIT_H

#include "RTE_Components.h"
#include "isr_defines.h"
#include "scu_defines.h"
#include "timer2x_defines.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "cmsis_misra.h"
#include "cmsis_version.h"
#include "core_cm3.h"
#include "error_codes.h"
#include "system_tle989x.h"
#include "timer2x.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "types.h"

/** \brief Initialize all CW registers of the timer 20
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 T20_init(void);


#endif /* TEST_T20_INIT_H */
