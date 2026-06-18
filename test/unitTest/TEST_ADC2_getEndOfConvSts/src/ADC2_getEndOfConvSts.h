#ifndef TEST_ADC2_GETENDOFCONVSTS_H
#define TEST_ADC2_GETENDOFCONVSTS_H

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

/** \brief Get End-of-Convertion status for selected sequence and slot
 *  \note This function violates [MISRA Rule 45]
 *
 * \param u8_seqIdx sequencer channel number (0..3)
 * \param u8_slotIdx slot number (0..3)
 * \return uint8 End-of-Convertion status for selected sequence and slot
 *
 * \brief <b>Example</b><br>
 * \brief This example starts sequence 0, checks slot0's EOC status and reads its result
 * ~~~~~~~~~~~~~~~{.c}
 * uint8 Example_Function(void)
 * {
 *   uint16 u16_val_mV;
 *
 *   if (ADC2_startSequence(ADC2_SEQ0) == ERR_LOG_SUCCESS)
 *   {
 *     while (ADC2_getEndOfConvSts(ADC2_SEQ0, ADC2_SEQ_SLOT0) == 0u) {}
 *
 *     ADC2_getSeqResult_mV(&u16_val_mV, ADC2_SEQ0, ADC2_SEQ_SLOT0);
 *   }
 *
 *   return u8_EOCSts;
 * }
 * ~~~~~~~~~~~~~~~
 */
uint8 ADC2_getEndOfConvSts(uint8 u8_seqIdx, uint8 u8_slotIdx);


#endif /* TEST_ADC2_GETENDOFCONVSTS_H */
