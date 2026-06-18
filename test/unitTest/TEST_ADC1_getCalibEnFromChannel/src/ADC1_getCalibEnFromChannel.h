#ifndef TEST_ADC1_GETCALIBENFROMCHANNEL_H
#define TEST_ADC1_GETCALIBENFROMCHANNEL_H

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

/** \brief Get the calibration enable bit from the analog input used by the given digital channel
 *
 * \param u8_channel digital channel number(0..19)
 * \return u8_res calibration enable bit from the analog input used by the given digital channel
 */
uint8 ADC1_getCalibEnFromChannel(uint8 u8_channel);


#endif /* TEST_ADC1_GETCALIBENFROMCHANNEL_H */
