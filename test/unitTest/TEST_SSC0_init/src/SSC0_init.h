#ifndef TEST_SSC0_INIT_H
#define TEST_SSC0_INIT_H

#include "RTE_Components.h"
#include "scu_defines.h"
#include "ssc_defines.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "cmsis_misra.h"
#include "cmsis_version.h"
#include "core_cm3.h"
#include "error_codes.h"
#include "ssc.h"
#include "system_tle989x.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "types.h"

/** \brief Initialize all CW registers of the SSC0 module
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 SSC0_init(void);


#endif /* TEST_SSC0_INIT_H */
