#include "UsageFault_Handler_help.h"

/* FUNCTION TO TEST */
void UsageFault_Handler(void)
{
#if (CPU_USAGEFAULT_EN == 1)
  CPU_USAGEFAULT_CALLBACK();
#endif /*(CPU_USAGEFAULT_EN == 1)*/
}