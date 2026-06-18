#ifndef TEST_ADC2_GETFILTCHRESULT_H
#define TEST_ADC2_GETFILTCHRESULT_H

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

/** \brief Get the result value from the given filter channel
 *  \note This function violates [MISRA Rule 45]
 *
 * \param u8_filtCh filter channel number (0..3)
 * \param *u16p_filtDigValue filter digital value
 * \return sint8 0: success, <0: error codes
 */
sint8 ADC2_getFiltChResult(uint16 * u16p_filtDigValue, uint8 u8_filtCh);


#endif /* TEST_ADC2_GETFILTCHRESULT_H */
