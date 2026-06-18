#include "PendSV_Handler_help.h"

/* FUNCTION TO TEST */
void PendSV_Handler(void)
{
#if (CPU_PENDSV_EN == 1)
  CPU_PENDSV_CALLBACK();
#endif /*(CPU_PENDSV_EN == 1)*/
}