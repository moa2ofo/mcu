#ifndef TEST_ADC2_INIT_H
#define TEST_ADC2_INIT_H

#include "RTE_Components.h"
#include "adc2_defines.h"
#include "adc2.h"
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

/** \brief Initialize all CW registers of the ADC2 module
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 ADC2_init(void);


#endif /* TEST_ADC2_INIT_H */
