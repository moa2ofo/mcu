#ifndef TEST_ADC2_GETCHRESULT_H
#define TEST_ADC2_GETCHRESULT_H

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

/** \brief Get the 12-bit value of the ADC2 Result Register of the selected ADC2 channel and returns the validity info
 *  \note This function violates [MISRA Rule 45]
 *
 * \param u8_channel digital channel number (0..14)
 * \param *u16p_digValue pointer to 12-bit ADC2 digital result value of the selected channel number (0..14)
 * \return sint8 0: success, <0: error codes
 *
 * \brief <b>Example</b><br>
 * \brief This example returns the ADC2 Channel 5 result.
 * ~~~~~~~~~~~~~~~{.c}
 * sint8 Example_Function(void)
 * {
 *   sint8 s8_returnCode = ERR_LOG_SUCCESS;
 *   uint16 u16_var;
 *
 *   if (ADC2_getCh5ResultValidSts() == 1u)
 *   {
 *     s8_returnCode = ADC2_getChResult(&u16_var, ADC2_DCH5);
 *   }
 *
 *   return s8_returnCode;
 * }
 * ~~~~~~~~~~~~~~~
 */
sint8 ADC2_getChResult(uint16 * u16p_digValue, uint8 u8_channel);


#endif /* TEST_ADC2_GETCHRESULT_H */
