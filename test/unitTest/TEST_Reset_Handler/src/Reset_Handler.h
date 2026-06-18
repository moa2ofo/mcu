#ifndef TEST_RESET_HANDLER_H
#define TEST_RESET_HANDLER_H

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

/**
  \brief Exception / Interrupt Handler Function Prototype
*/
typedef void(*VECTOR_TABLE_Type)(void);

extern __NO_RETURN void __PROGRAM_START(void);

#if defined(__ARMCC_VERSION)
  /* Arm Compiler V5 and V6 */
  __attribute__((noreturn)) static void debug_entry(void) __attribute__((section("sec_NVM0_DEBUG_CONNECT"), used));
#elif defined ( __GNUC__ )
  /* GCC compiler*/
  __attribute__((noreturn)) static void debug_entry(void) __attribute__((section(".sec_NVM0_DEBUG_CONNECT"), used));
#elif defined(__IAR_SYSTEMS_ICC__)
  /* IAR compiler */
  __attribute__((noreturn)) static void debug_entry(void) @ "sec_NVM0_DEBUG_CONNECT";
#elif defined(UNIT_TESTING_OCN)
  __attribute__((noreturn)) static void debug_entry(void);
#endif

/*---------------------------------------------------------------------------
  Internal References
 *---------------------------------------------------------------------------*/
__NO_RETURN void Reset_Handler  (void);
__NO_RETURN void Default_Handler(void);
__NO_RETURN static void debug_entry(void);

/*---------------------------------------------------------------------------
  Exception / Interrupt Handler
 *---------------------------------------------------------------------------*/
/* Exceptions */
void NMI_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void HardFault_Handler      (void) __attribute__ ((weak));
void MemManage_Handler      (void) __attribute__ ((weak, alias("Default_Handler")));
void BusFault_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void UsageFault_Handler     (void) __attribute__ ((weak, alias("Default_Handler")));
//void SecureFault_Handler    (void) __attribute__ ((weak, alias("Default_Handler")));
void SVC_Handler            (void) __attribute__ ((weak, alias("Default_Handler")));
void DebugMon_Handler       (void) __attribute__ ((weak, alias("Default_Handler")));
void PendSV_Handler         (void) __attribute__ ((weak, alias("Default_Handler")));
void SysTick_Handler        (void) __attribute__ ((weak, alias("Default_Handler")));

void NVIC_IRQ0_Handler(void)   __attribute__ ((weak, alias("Default_Handler"))); // 0: PMU, BDRV, CSC, ARVG
void NVIC_IRQ1_Handler(void)   __attribute__ ((weak, alias("Default_Handler"))); // 1: PMU, BDRV, CSC, ARVG
void NVIC_IRQ2_Handler(void)   __attribute__ ((weak, alias("Default_Handler"))); // 2: CCU7
void NVIC_IRQ3_Handler(void)   __attribute__ ((weak, alias("Default_Handler"))); // 3: CCU7
void NVIC_IRQ4_Handler(void)   __attribute__ ((weak, alias("Default_Handler"))); // 4: CCU7
void NVIC_IRQ5_Handler(void)   __attribute__ ((weak, alias("Default_Handler"))); // 5: CCU7
//0x000000c1 // 6: MEMCTRL
void NVIC_IRQ7_Handler(void)  __attribute__ ((weak, alias("Default_Handler"))); // 7: GPT12E
void NVIC_IRQ8_Handler(void)  __attribute__ ((weak, alias("Default_Handler"))); // 8: GPT12E
void NVIC_IRQ9_Handler (void) __attribute__ ((weak, alias("Default_Handler"))); // 9: Timer2
void NVIC_IRQ10_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 10: ADC2
void NVIC_IRQ11_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 11: ADC2
void NVIC_IRQ12_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 12: MON
void NVIC_IRQ13_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 13: MON
void NVIC_IRQ14_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 14: ADC1
void NVIC_IRQ15_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 15: ADC1
void NVIC_IRQ16_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 16: ADC1
void NVIC_IRQ17_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 17: ADC1
void NVIC_IRQ18_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 18: BEMF, SDADC
void NVIC_IRQ19_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 19: BEMF, SDADC
void NVIC_IRQ20_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 20: EXTINT
void NVIC_IRQ21_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 21: EXTINT
void NVIC_IRQ22_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 22: UART0/1, LIN
void NVIC_IRQ23_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 23: UART0/1, LIN
void NVIC_IRQ24_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 24: SSC0/1
void NVIC_IRQ25_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 25: SSC0/1
void NVIC_IRQ26_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 26: MultiCAN
void NVIC_IRQ27_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 27: MultiCAN
void NVIC_IRQ28_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 28: MultiCAN
void NVIC_IRQ29_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 29: DMA
void NVIC_IRQ30_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 30: DMA
void NVIC_IRQ31_Handler(void) __attribute__ ((weak, alias("Default_Handler"))); // 31: Timer21

/*----------------------------------------------------------------------------
  Exception / Interrupt Vector table
 *----------------------------------------------------------------------------*/

#if defined ( __GNUC__ )
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wpedantic"
#endif

#if defined(__ARMCC_VERSION )
  /* Arm Compiler V5 and V6 */
  static const uint32 u32_flash0_page0[11] __attribute__((section("sec_NVM0_BOOTCFG"), used)) =
#elif defined ( __GNUC__ )
  /* GCC compiler */
  static const uint32 u32_flash0_page0[11] __attribute__((section(".sec_NVM0_BOOTCFG"), used)) =
#elif defined(__IAR_SYSTEMS_ICC__)
  /* IAR compiler */
  __root const uint32 u32_flash0_page0[11] @ "sec_NVM0_BOOTCFG" =
#elif defined(UNIT_TESTING_OCN)
  const uint32 u32_flash0_page0[11] =
#endif
{
  (uint32)BSL_NAD_NAC,   /* 0x00: NAC,NAD */
  0xFFFFFFFF,            /* 0x04: reserved */
  0xFFFFFFFF,            /* 0x08: Secure Boot Hash */
  0xFFFFFFFF,            /* 0x0C: Secure Boot Hash */
  0xFFFFFFFF,            /* 0x10: Secure Boot Hash */
  0xFFFFFFFF,            /* 0x14: Secure Boot Hash */
  0xFFFFFFFF,            /* 0x18: reserved */
  0xFFFFFFFF,            /* 0x1C: reserved */
  0xFFFFFFFF,            /* 0x20: reserved */
  0xFFFFFFFF,            /* 0x24: User BSL Code Size */
  0xFFFFFFFF,            /* 0x28: Secure Key ID */
};

#if defined(__ARMCC_VERSION)
  /* Arm Compiler V5 and V6 */
  static const VECTOR_TABLE_Type vt_vectab_deprecated[2] __attribute__((section("sec_NVM0_VECTAB_DEPRECATED"), used)) =
#elif defined ( __GNUC__ )
  /* GCC compiler */
  static const VECTOR_TABLE_Type vt_vectab_deprecated[2] __attribute__((section(".sec_NVM0_VECTAB_DEPRECATED"), used)) =
#elif defined(__IAR_SYSTEMS_ICC__)
  /* IAR compiler: __root needed so that the variable is not optimized away */
  __root const VECTOR_TABLE_Type vt_vectab_deprecated[2] @ "sec_NVM0_VECTAB_DEPRECATED" =
#elif defined(UNIT_TESTING_OCN)
  static const VECTOR_TABLE_Type vt_vectab_deprecated[2] =
#endif
{
  (VECTOR_TABLE_Type)(&__INITIAL_SP),  /*     Initial Stack Pointer */
  debug_entry,                         /*     Reset Handler */
};

__attribute__((noreturn)) static void debug_entry(void)
{
#define SCU_BOOT_CFG_LATCH_ADDR 0x480040BC
#define SCU_BOOT_CFG_LATCH_TMS_MASK 0x00000001
#define SCU_BOOT_CFG_LATCH_P00_MASK 0x00000002
#define CPU_DHCSR_ADDR 0xE000EDF0
#define CPU_DHCSR_C_DEBUGEN_MASK 0x00000001
  uint32 u32_boot_cfg_latch;
  uint32 u32_dhcsr_c_debugen;
  u32_boot_cfg_latch = *(uint32 *)SCU_BOOT_CFG_LATCH_ADDR;

  if ((u32_boot_cfg_latch & (SCU_BOOT_CFG_LATCH_TMS_MASK | SCU_BOOT_CFG_LATCH_P00_MASK)) == (SCU_BOOT_CFG_LATCH_TMS_MASK | SCU_BOOT_CFG_LATCH_P00_MASK))
  {
    do
    {
      u32_dhcsr_c_debugen = (*(uint32 *)CPU_DHCSR_ADDR) & CPU_DHCSR_C_DEBUGEN_MASK;
    }
    while (u32_dhcsr_c_debugen == 0);
  }

  Reset_Handler();
}

extern const VECTOR_TABLE_Type __VECTOR_TABLE[48];

#if defined(__ARMCC_VERSION) || defined ( __GNUC__ )
/* Arm Compiler V5 and V6 or GCC compiler*/
const VECTOR_TABLE_Type __VECTOR_TABLE[48] __VECTOR_TABLE_ATTRIBUTE =
{
#elif defined(__IAR_SYSTEMS_ICC__)
/* IAR compiler */
const VECTOR_TABLE_Type __VECTOR_TABLE[48] @ "sec_NVM0_VECTAB" = {
#elif defined(UNIT_TESTING_OCN)
const VECTOR_TABLE_Type __VECTOR_TABLE[48] = {
#endif
  (VECTOR_TABLE_Type)(&__INITIAL_SP),  /*     Initial Stack Pointer */
  debug_entry,                         /*     Reset Handler */
  NMI_Handler,                         /* -14 NMI Handler */
  HardFault_Handler,                   /* -13 Hard Fault Handler */
  MemManage_Handler,                   /* -12 MPU Fault Handler */
  BusFault_Handler,                    /* -11 Bus Fault Handler */
  UsageFault_Handler,                  /* -10 Usage Fault Handler */
  0,                                   /*  -9 Secure Fault Handler */
  0,                                   /*     Reserved */
  0,                                   /*     Reserved */
  0,                                   /*     Reserved */
  SVC_Handler,                         /*  -5 SVCall Handler */
  DebugMon_Handler,                    /*  -4 Debug Monitor Handler */
  0,                                   /*     Reserved */
  PendSV_Handler,                      /*  -2 PendSV Handler */
  SysTick_Handler,                     /*  -1 SysTick Handler */

  /* Interrupts */
  NVIC_IRQ0_Handler,             // 0: PMU, BDRV, CSC, ARVG
  NVIC_IRQ1_Handler,             // 1: PMU, BDRV, CSC, ARVG
  NVIC_IRQ2_Handler,             // 2: CCU7
  NVIC_IRQ3_Handler,             // 3: CCU7
  NVIC_IRQ4_Handler,             // 4: CCU7
  NVIC_IRQ5_Handler,             // 5: CCU7
  (VECTOR_TABLE_Type)0x000000c1, // 6: MEMCTRL
  NVIC_IRQ7_Handler,             // 7: GPT12E
  NVIC_IRQ8_Handler,             // 8: GPT12E
  NVIC_IRQ9_Handler,             // 9: Timer2
  NVIC_IRQ10_Handler,            // 10: ADC2
  NVIC_IRQ11_Handler,            // 11: ADC2
  NVIC_IRQ12_Handler,            // 12: MON
  NVIC_IRQ13_Handler,            // 13: MON
  NVIC_IRQ14_Handler,            // 14: ADC1
  NVIC_IRQ15_Handler,            // 15: ADC1
  NVIC_IRQ16_Handler,            // 16: ADC1
  NVIC_IRQ17_Handler,            // 17: ADC1
  NVIC_IRQ18_Handler,            // 18: BEMF, SDADC
  NVIC_IRQ19_Handler,            // 19: BEMF, SDADC
  NVIC_IRQ20_Handler,            // 20: EXTINT
  NVIC_IRQ21_Handler,            // 21: EXTINT
  NVIC_IRQ22_Handler,            // 22: UART0/1, LIN
  NVIC_IRQ23_Handler,            // 23: UART0/1, LIN
  NVIC_IRQ24_Handler,            // 24: SSC0/1
  NVIC_IRQ25_Handler,            // 25: SSC0/1
  NVIC_IRQ26_Handler,            // 26: MultiCAN
  NVIC_IRQ27_Handler,            // 27: MultiCAN
  NVIC_IRQ28_Handler,            // 28: MultiCAN
  NVIC_IRQ29_Handler,            // 29: DMA
  NVIC_IRQ30_Handler,            // 30: DMA
  NVIC_IRQ31_Handler             // 31: Timer21
};

#if defined ( __GNUC__ )
#pragma GCC diagnostic pop
#endif

/*---------------------------------------------------------------------------
  Reset Handler called on controller reset
 *---------------------------------------------------------------------------*/
void Reset_Handler(void);


#endif /* TEST_RESET_HANDLER_H */
