#ifndef TEST_T20_SETINTERVALTIMER_H
#define TEST_T20_SETINTERVALTIMER_H

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

/** \brief Define an interval timer with the timer T20
 *
 * \param u32_timeInterval_us Duration of the timer T20 in microseconds
 * \return sint8 0: success, <0: error codes
 */
sint8 T20_setIntervalTimer(uint32 u32_timeInterval_us);


#endif /* TEST_T20_SETINTERVALTIMER_H */
