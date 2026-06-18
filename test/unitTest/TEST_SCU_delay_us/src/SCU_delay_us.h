#ifndef TEST_SCU_DELAY_US_H
#define TEST_SCU_DELAY_US_H

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

#define SYSTICK_DELAY_THRESHOLD 100U

/** \brief Delays the regular program execution by a given number of Microseconds
 * \brief the function returns if the given time has elapsed
 * \brief Too small delay times are being falsified by execution time
 * \brief of the function itself
 *
 * \warning Handle this function with care, as the watchdog will not be serviced during the delay time.
 * \warning The user has to take care of WDT1/WDT service by himself.
 *
 * \param u32_time_us Delay time in Microseconds
 *
 * \brief <b>Example</b><br>
 * \brief This example sets a delay of 100 us.
 * ~~~~~~~~~~~~~~~{.c}
 * void Example_Function(void)
 * {
 *     SCU_delay_us(100);
 * }
 * ~~~~~~~~~~~~~~~
 */
void SCU_delay_us(uint32 u32_time_us);


#endif /* TEST_SCU_DELAY_US_H */
