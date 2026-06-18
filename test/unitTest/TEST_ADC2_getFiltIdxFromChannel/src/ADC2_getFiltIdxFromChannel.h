#ifndef TEST_ADC2_GETFILTIDXFROMCHANNEL_H
#define TEST_ADC2_GETFILTIDXFROMCHANNEL_H

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

/** \brief Get the index of the filter channel configured for a given digital channel
 *
 * \param u8_channel digital channel number(0..14)
 * \return u8_fidx index of the filter channel configured for a given digital channel
 */
uint8 ADC2_getFiltIdxFromChannel(uint8 u8_channel);


#endif /* TEST_ADC2_GETFILTIDXFROMCHANNEL_H */
