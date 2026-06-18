#ifndef TEST_CLEARFAILSAFEREGISTERS_H
#define TEST_CLEARFAILSAFEREGISTERS_H

#include "RTE_Components.h"
#include "gpio_defines.h"
#include "isr_defines.h"
#include "pmu_defines.h"
#include "scu_defines.h"
#include "Mcu.h"
#include "bootrom.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "cmsis_misra.h"
#include "cmsis_version.h"
#include "core_cm3.h"
#include "error_codes.h"
#include "gpio.h"
#include "isr.h"
#include "pmu.h"
#include "system_tle989x.h"
#include "tle989x.h"
#include "tle_device.h"
#include "tle_variants.h"
#include "types.h"

#define FS_STS_CLR_ALL_MASK (0x00017FFFu)
#define FS_SSD_CLR_ALL_MASK (PMU_FS_SSD_CLR_SSD_STS_CLR_Msk | PMU_FS_SSD_CLR_FO_STS_CLR_Msk)

void ClearFailSafeRegisters(void);


#endif /* TEST_CLEARFAILSAFEREGISTERS_H */
