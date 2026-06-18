#ifndef TEST_ADC1_GETCHFILTRESULT_H
#define TEST_ADC1_GETCHFILTRESULT_H

#include "RTE_Components.h"
#include "adc1_defines.h"
#include "adc1.h"
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

/** \brief Get the 16-bit value of the ADC1 Filter Result Register of the selected ADC1 channel and returns the validity info
 *  \note This function violates [MISRA Rule 45]
 *
 * \param u8_channel digital channel number(0..19)
 * \param u16p_filtDigValue pointer to 16-bit ADC1 digital filtered result value of the selected channel number (0..19)
 * \return sint8 0: success, <0: error codes
 *
 * \brief <b>Example</b><br>
 * \brief This example returns the ADC1 Channel 5 filtered result in Millivolt (mV).
 * ~~~~~~~~~~~~~~~{.c}
 * sint8 Example_Function(void)
 * {
 *   sint8 s8_returnCode = ERR_LOG_SUCCESS;
 *   uint16 u16_var_mV;
 *   uint16 u16_var;
 *
 *   if (ADC1_getChFiltResult(&u16_var, ADC1_DCH5) == ERR_LOG_SUCCESS)
 *   {
 *     s8_returnCode = ADC1_getChFiltResult_mV(&u16_var_mV, ADC1_DCH5);
 *   }
 *
 *   return s8_returnCode;
 * }
 * ~~~~~~~~~~~~~~~
 */
sint8 ADC1_getChFiltResult(uint16 * u16p_filtDigValue, uint8 u8_channel);


#endif /* TEST_ADC1_GETCHFILTRESULT_H */
