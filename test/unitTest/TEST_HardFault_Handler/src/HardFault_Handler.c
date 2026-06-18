#include "HardFault_Handler_help.h"

/* FUNCTION TO TEST */
void HardFault_Handler(void)
{
#if (CPU_HARDFAULT_EN == 1)
  CPU_HARDFAULT_CALLBACK();
#endif /*(CPU_HARDFAULT_EN == 1)*/
}