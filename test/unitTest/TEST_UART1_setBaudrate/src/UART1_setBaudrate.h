#ifndef TEST_UART1_SETBAUDRATE_H
#define TEST_UART1_SETBAUDRATE_H

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

/** \brief Set the baudrate for UART1
 *
 * \param u32_baudrate baudrate
 * \return sint8 0: success, <0: error codes
 */
sint8 UART1_setBaudrate(uint32 u32_baudrate);


#endif /* TEST_UART1_SETBAUDRATE_H */
