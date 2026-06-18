#ifndef TEST_UART1_GETBAUDRATE_H
#define TEST_UART1_GETBAUDRATE_H

#include "RTE_Components.h"
#include "isr_defines.h"
#include "pmu_defines.h"
#include "scu_defines.h"
#include "uart_defines.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "cmsis_misra.h"
#include "cmsis_version.h"
#include "core_cm3.h"
#include "error_codes.h"
#include "pmu.h"
#include "system_tle989x.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "types.h"
#include "uart.h"

/** \brief Get the baudrate for UART1
 * Transform equation
 *   (SCU_fUART_MHz * 1000000 / (16 * (1U << (uint8)UART1->BCON.bit.BR_PRE) * (UART1->BCON.bit.BG_BR_VALUE + (UART1->BCON.bit.BG_FD_SEL / 32))))
 * to
 *   ((SCU_fUART_MHz * 1000000 * 2 )  / ((1U << (uint8)UART1->BCON.bit.BR_PRE) * (32 * UART1->BCON.bit.BG_BR_VALUE + (UART1->BCON.bit.BG_FD_SEL))))
 *
 * \return uint32 UART1 baudrate
 */
uint32 UART1_getBaudrate(void);


#endif /* TEST_UART1_GETBAUDRATE_H */
