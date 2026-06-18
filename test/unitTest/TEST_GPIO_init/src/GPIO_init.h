#ifndef TEST_GPIO_INIT_H
#define TEST_GPIO_INIT_H

#include "RTE_Components.h"
#include "gpio_defines.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "cmsis_misra.h"
#include "cmsis_version.h"
#include "core_cm3.h"
#include "error_codes.h"
#include "gpio.h"
#include "system_tle989x.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "types.h"

/** \brief Initialize all CW registers of the GPIO module
 */
void GPIO_init(void);


#endif /* TEST_GPIO_INIT_H */
