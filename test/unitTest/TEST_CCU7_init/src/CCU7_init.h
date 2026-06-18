#ifndef TEST_CCU7_INIT_H
#define TEST_CCU7_INIT_H

#include "RTE_Components.h"
#include "ccu7_defines.h"
#include "ccu7.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "cmsis_misra.h"
#include "cmsis_version.h"
#include "core_cm3.h"
#include "error_codes.h"
#include "system_tle989x.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "types.h"

/** \brief Initialize the CCU7 module
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 CCU7_init(void);


#endif /* TEST_CCU7_INIT_H */
