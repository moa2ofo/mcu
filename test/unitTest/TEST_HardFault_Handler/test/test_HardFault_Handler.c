/**
    * @file test/unitTest/TEST_HardFault_Handler/test/test_HardFault_Handler.c
    * @brief Unit tests for HardFault_Handler.
    *
    * @anchor UT_HardFault_Handler
    *
    * @details
    * This file contains the Unity unit test stub for the SW unit
    * HardFault_Handler.
    */
    
#include "HardFault_Handler.h"
#include "unity.h"

#include "mock_RTE_Components.h"
#include "mock_isr_defines.h"
#include "mock_pmu_defines.h"
#include "mock_scu_defines.h"
#include "mock_cmsis_compiler.h"
#include "mock_cmsis_gcc.h"
#include "mock_cmsis_misra.h"
#include "mock_cmsis_version.h"
#include "mock_core_cm3.h"
#include "mock_error_codes.h"
#include "mock_isr.h"
#include "mock_pmu.h"
#include "mock_system_tle989x.h"
#include "mock_tle989x.h"
#include "mock_tle_variants.h"
#include "mock_types.h"

void setUp(void) {}
void tearDown(void) {}

void test_HardFault_Handler(void)
{
    TEST_IGNORE_MESSAGE("Auto-generated stub test");
}
