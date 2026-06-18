#ifndef TEST_ADC1_GETCHFILTRESULT_MV_H
#define TEST_ADC1_GETCHFILTRESULT_MV_H

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

#include <stddef.h>
#include <string.h>

/** \brief Get the value of the ADC1 Filter Result Register of the selected ADC1 channel in millivolt (mV) and returns the validity info
 *  \note This function violates [MISRA Rule 45]
 *
 * \param u8_channel digital channel number(0..19)
 * \param u16p_filtDigValue_mV pointer to ADC1 Filter Result Register value of the selected channel number converted to millivolt (mV)
 * \return sint8 0: success, <0: error codes
 *
 * \brief <b>Example</b><br>
 * \brief This example returns the ADC1 Channel 5 result in Millivolt (mV).
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
sint8 ADC1_getChFiltResult_mV(uint16 * u16p_filtDigValue_mV, uint8 u8_channel);

const uint16* get_cu16_ADC1_analogInput_Att_ptr(void);
size_t get_cu16_ADC1_analogInput_Att_size(void);
void set_cu16_ADC1_analogInput_Att(const const uint16* src, size_t n);

#endif /* TEST_ADC1_GETCHFILTRESULT_MV_H */
