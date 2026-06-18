#include "MemManage_Handler_help.h"

/* FUNCTION TO TEST */
void MemManage_Handler(void)
{
#if (CPU_MEMMANAGE_EN == 1)
  CPU_MEMMANAGE_CALLBACK();
#endif /*(CPU_MEMMANAGE_EN == 1)*/
}