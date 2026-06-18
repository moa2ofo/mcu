#include "SCU_enterDeepSleepMode_help.h"

/* FUNCTION TO TEST */
void SCU_enterDeepSleepMode(void)
{
  /* Free up the pipeline */
  CMSIS_NOP();
  CMSIS_NOP();
  CMSIS_NOP();
  /* Set send event */
  CMSIS_SEV();
  /* Clear send event */
  CMSIS_WFE();
  /* Enter CPU Deep Sleep */
  CMSIS_WFE();
}