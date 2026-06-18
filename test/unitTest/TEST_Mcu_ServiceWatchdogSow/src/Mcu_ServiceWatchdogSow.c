#include "Mcu_ServiceWatchdogSow_help.h"

/* FUNCTION TO TEST */
void Mcu_ServiceWatchdogSow(void)
{
  PMU->WD_TRIG_SOW.bit.TRIG ^= 1u;
}