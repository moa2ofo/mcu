#ifndef TEST_CSACSC_STARTCALIBRATION_H
#define TEST_CSACSC_STARTCALIBRATION_H

#include "RTE_Components.h"
#include "adc1_defines.h"
#include "bdrv_defines.h"
#include "csacsc_defines.h"
#include "isr_defines.h"
#include "pmu_defines.h"
#include "scu_defines.h"
#include "adc1.h"
#include "bdrv.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "cmsis_misra.h"
#include "cmsis_version.h"
#include "core_cm3.h"
#include "csacsc.h"
#include "error_codes.h"
#include "isr.h"
#include "pmu.h"
#include "scu.h"
#include "system_tle989x.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "types.h"

/** \brief Perform the calibration of the CSA
 * \brief For this purpose the channel 19 / sequence 3 are reconfigured to perform a CSA measurement.
 * \brief The ADC1 configuration will be restored after the measurement is done.
 * \note Ensure that no current (0A) is flowing through the shunt for the calibration step.
 *
 * \param u16p_Val_mV pointer to the ADC1 result value
 * \return sint8 0: success, <0: error codes
 */
sint8 CSACSC_startCalibration(uint16 * u16p_Val_mV);


#endif /* TEST_CSACSC_STARTCALIBRATION_H */
