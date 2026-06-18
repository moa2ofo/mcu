#include "debug_entry_help.h"

/* FUNCTION TO TEST */
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