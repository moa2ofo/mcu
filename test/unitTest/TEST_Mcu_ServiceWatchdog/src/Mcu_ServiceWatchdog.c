#include "Mcu_ServiceWatchdog_help.h"

/* FUNCTION TO TEST */
void Mcu_ServiceWatchdog(void)
{
  /* Service watchdog by toggling bit PMU->WD_TRIG.bit.TRIG */
  PMU->WD_TRIG.bit.TRIG ^= 1u;
}