#ifndef TEST_UARTX_SETBAUDRATE_H
#define TEST_UARTX_SETBAUDRATE_H

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

/** \brief Set the baudrate for UART0/UART1
 *  \brief The maximum allowed deviation is 2.5%. Otherwise return error code ERR_LOG_CODE_PARAM_OUT_OF_RANGE
 *
 * \param u32_baudrate baudrate
 * \param tp_baudrateReg baudrate pointer to baudrate configuration register
 * \return sint8 0: success, <0: error codes
 * \note The resulting SFR values might deviate from a configuration with the ConfigWizard or from User Manual examples. Some specific baudrates can be achieved with different SFR settings.
 */
sint8 UARTx_setBaudrate(uint32 u32_baudrate, volatile tUARTx_BCON * tp_baudrateReg);


#endif /* TEST_UARTX_SETBAUDRATE_H */
