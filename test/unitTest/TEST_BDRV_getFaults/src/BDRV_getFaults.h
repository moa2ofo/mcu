#ifndef TEST_BDRV_GETFAULTS_H
#define TEST_BDRV_GETFAULTS_H

#include "RTE_Components.h"
#include "adc1_defines.h"
#include "adc2_defines.h"
#include "bdrv_defines.h"
#include "csacsc_defines.h"
#include "isr_defines.h"
#include "pmu_defines.h"
#include "scu_defines.h"
#include "adc1.h"
#include "adc2.h"
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

/** \brief Read the fault information related to bridge driver and charge pump and provides them encoded in the return value
 *
 * \return uint8 Fault information related to bridge driver and charge pump
 * \return Bit0: Over Current LS1
 * \return Bit1: Over Current HS1
 * \return Bit2: Over Current LS2
 * \return Bit3: Over Current HS2
 * \return Bit4: Over Current LS3
 * \return Bit5: Over Current HS3
 * \return Bit6: Under Voltage Charge Pump (incl. VSD and VCP)
 * \return Bit7: Over Voltage Charge Pump (incl. VSD and VCP)
 */
uint8 BDRV_getFaults(void);


#endif /* TEST_BDRV_GETFAULTS_H */
