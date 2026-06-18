#ifndef TEST_GPT12_SETINTERVALTIMERT6_H
#define TEST_GPT12_SETINTERVALTIMERT6_H

#include "RTE_Components.h"
#include "gpt12_defines.h"
#include "scu_defines.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "cmsis_misra.h"
#include "cmsis_version.h"
#include "core_cm3.h"
#include "error_codes.h"
#include "gpt12.h"
#include "system_tle989x.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "types.h"

/** \brief Define an interval timer with the core timer T6
 *
 * \param u32_timeInterval_us Duration of the core timer T6 in microseconds
 * \return sint8 0: success, <0: error codes
 */
sint8 GPT12_setIntervalTimerT6(uint32 u32_timeInterval_us);


#endif /* TEST_GPT12_SETINTERVALTIMERT6_H */
