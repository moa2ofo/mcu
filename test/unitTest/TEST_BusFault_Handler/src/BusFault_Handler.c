#include "BusFault_Handler_help.h"

/* FUNCTION TO TEST */
void BusFault_Handler(void)
{
#if (CPU_BUSFAULT_EN == 1)
  CPU_BUSFAULT_CALLBACK();
#endif /*(CPU_BUSFAULT_EN == 1)*/
}