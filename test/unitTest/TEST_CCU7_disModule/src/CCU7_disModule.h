#ifndef TEST_CCU7_DISMODULE_H
#define TEST_CCU7_DISMODULE_H

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

/** \brief Disable the CCU7 module by performing the following steps:
 *  stop T12
 *  stop T13, T14, T15, T16
 *  programming the passive states to LOW
 *  switching all CCU7 outputs to passive state
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 CCU7_disModule(void);


#endif /* TEST_CCU7_DISMODULE_H */
