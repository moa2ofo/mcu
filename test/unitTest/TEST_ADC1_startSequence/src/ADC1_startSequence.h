#ifndef TEST_ADC1_STARTSEQUENCE_H
#define TEST_ADC1_STARTSEQUENCE_H

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

/** \brief Start the conversion of a sequence by software.
 *  \note A sequence can only be started by software if the trigger selection is set to software trigger.
 *  \note This function violates [MISRA Rule 45]
 *
 * \param u8_seqIdx sequencer channel number (0..3)
 * \return sint8 0: success, <0: error codes
 *
 * \brief <b>Example</b><br>
 * \brief This example starts sequence 0
 * ~~~~~~~~~~~~~~~{.c}
 * sint8 Example_Function(void)
 * {
 *   sint8 s8_returnCode = ERR_LOG_SUCCESS;
 *
 *   if (ADC1_startSequence(ADC1_SEQ0) == ERR_LOG_SUCCESS)
 *   {
 *     //sequence successfully started
 *   }
 *
 *   return s8_returnCode;
 * }
 * ~~~~~~~~~~~~~~~
 */
sint8 ADC1_startSequence(uint8 u8_seqIdx);


#endif /* TEST_ADC1_STARTSEQUENCE_H */
