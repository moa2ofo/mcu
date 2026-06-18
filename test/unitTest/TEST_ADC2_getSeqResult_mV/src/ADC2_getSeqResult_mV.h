#ifndef TEST_ADC2_GETSEQRESULT_MV_H
#define TEST_ADC2_GETSEQRESULT_MV_H

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

/** \brief Get the 12-bit value of the ADC2 Result Register in mV of the selected slot in the sequencer and returns the validity info
 *  \note This function violates [MISRA Rule 45]
 *
 * \param u8_seqIdx sequencer channel number (0..3)
 * \param u8_slotIdx slot inside sequencer (0..3)
 * \param *u16p_digValue_mV 12-bit ADC2 digital result value in mV of the channel from the sequence and slot
 * \return sint8 0: success, <0: error codes
 *
 * \brief <b>Example</b><br>
 * \brief This example returns the ADC2 result for the channel in slot3 of sequence 2.
 * ~~~~~~~~~~~~~~~{.c}
 * sint8 Example_Function(void)
 * {
 *   sint8 s8_returnCode = ERR_LOG_SUCCESS;
 *   uint16 u16_var_mV;
 *
 *   if (ADC2_getSeqResult_mV(&u16_var_mV, ADC2_SEQ2, ADC2_SEQ_SLOT3) == ERR_LOG_SUCCESS)
 *   {
 *   }
 *
 *   return s8_returnCode;
 * }
 * ~~~~~~~~~~~~~~~
 */
sint8 ADC2_getSeqResult_mV(uint16 * u16p_digValue_mV, uint8 u8_seqIdx, uint8 u8_slotIdx);


#endif /* TEST_ADC2_GETSEQRESULT_MV_H */
