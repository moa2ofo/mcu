#ifndef TEST_NVIC_IRQ2_HANDLER_H
#define TEST_NVIC_IRQ2_HANDLER_H

#include "RTE_Components.h"
#include "ccu7_defines.h"
#include "isr_defines.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "cmsis_misra.h"
#include "cmsis_version.h"
#include "core_cm3.h"
#include "error_codes.h"
#include "isr.h"
#include "system_tle989x.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "types.h"

/*******************************************************************************
**                         Global Function Definitions                        **
*******************************************************************************/
void NVIC_IRQ2_Handler(void);


#endif /* TEST_NVIC_IRQ2_HANDLER_H */
