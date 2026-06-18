#include "Reset_Handler_help.h"

/* FUNCTION TO TEST */
__NO_RETURN void Reset_Handler(void)
{
  __set_PSP((uint32_t)(&__INITIAL_SP));
#if defined (__ARM_FEATURE_CMSE) && (__ARM_FEATURE_CMSE == 3U)
  __TZ_set_STACKSEAL_S((uint32_t *)(&__STACK_SEAL));
#endif

  /* Enable Flash1 caching according to CW setting */
  if (FLASH1_CACHE_EN == 1)
  {
    user_cache_operation(CACHE_OP_EN, UC_FLASH1_START);
  }

  SystemInit();                    /* CMSIS System Initialization */
  __PROGRAM_START();               /* Enter PreMain (C library entry point) */
}