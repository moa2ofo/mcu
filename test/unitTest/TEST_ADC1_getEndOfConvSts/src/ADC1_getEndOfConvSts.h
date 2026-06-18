#ifndef TEST_ADC1_GETENDOFCONVSTS_H
#define TEST_ADC1_GETENDOFCONVSTS_H

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
 *   if (ADC1_startSequence(ADC1_SEQ0) == ERR_LOG_SUCCESS)
 *   {
 *     while (ADC1_getEndOfConvSts(ADC1_SEQ0, ADC1_SEQ_SLOT0) == 0u) {}
 *
 *     ADC1_getSeqResult_mV(&u16_val_mV, ADC1_SEQ0, ADC1_SEQ_SLOT0);
 *   }
 *
 *   return EOC_sts;
 * }
 * ~~~~~~~~~~~~~~~
 */
uint8 ADC1_getEndOfConvSts(uint8 u8_seqIdx, uint8 u8_slotIdx);


#endif /* TEST_ADC1_GETENDOFCONVSTS_H */
