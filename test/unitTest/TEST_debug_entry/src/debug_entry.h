#ifndef TEST_DEBUG_ENTRY_H
#define TEST_DEBUG_ENTRY_H

#include "RTE_Components.h"
#include "bsl_defines.h"
#include "scu_defines.h"
#include "bootrom.h"
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

#define SCU_BOOT_CFG_LATCH_ADDR 0x480040BC
#define SCU_BOOT_CFG_LATCH_TMS_MASK 0x00000001
#define SCU_BOOT_CFG_LATCH_P00_MASK 0x00000002
#define CPU_DHCSR_ADDR 0xE000EDF0
#define CPU_DHCSR_C_DEBUGEN_MASK 0x00000001

void debug_entry(void);


#endif /* TEST_DEBUG_ENTRY_H */
