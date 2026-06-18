#include "Mcu.h"
#include "tle_device.h"

#define FS_STS_CLR_ALL_MASK (0x00017FFFu)
#define FS_SSD_CLR_ALL_MASK (PMU_FS_SSD_CLR_SSD_STS_CLR_Msk | PMU_FS_SSD_CLR_FO_STS_CLR_Msk)

static void ClearFailSafeRegisters(void);

void Mcu_Initialize(void) {
  /* Clear watchdog fail status */
  PMU_clrFailSafeWatchdogFailSts();

  /* Initialization of hardware modules based on Config Wizard configuration */
  (void)TLE_init();

  /* Release safe shutdown mechanism */
  ClearFailSafeRegisters();
}

void Mcu_ServiceWatchdog(void) {
  /* Service watchdog by toggling bit PMU->WD_TRIG.bit.TRIG */
  PMU->WD_TRIG.bit.TRIG ^= 1u;
}

void Mcu_ServiceWatchdogSow(void) {
  PMU->WD_TRIG_SOW.bit.TRIG ^= 1u;
}

void Mcu_ReloadSystick(void) {
  /* Reset the SysTick current value */
  CPU->SYSTICK_CUR.reg = 0u;

  /* Reset Mcu_GetSystemTime_u32 */
  u32_globTimestamp_ms = 0u;
}

uint32_t Mcu_GetSystemTime_u32(void) {
  return u32_globTimestamp_ms;
}

static void ClearFailSafeRegisters(void) {
  /* Clear all fail safe status bits */
  while(PMU->FS_STS.reg != 0u) {
    PMU->FS_STS_CLR.reg = FS_STS_CLR_ALL_MASK;
  }

  /* Clear all safe shutdown status bits */
  while(PMU->FS_SSD.reg != 0u) {
    PMU->FS_SSD_CLR.reg = FS_SSD_CLR_ALL_MASK;
  }
}

/************* example code *************/
void toggle_led(void) {
  GPIO_setP06State(GPIO_STATE_TOGGLE);
}
/****************************************/
