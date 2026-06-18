#include "Mcu_Initialize_help.h"

/* FUNCTION TO TEST */
void Mcu_Initialize(void)
{
  /* Clear watchdog fail status */
  PMU_clrFailSafeWatchdogFailSts();
  
  /* Initialization of hardware modules based on Config Wizard configuration */
  (void)TLE_init();

  /* Release safe shutdown mechanism */
  ClearFailSafeRegisters();
}