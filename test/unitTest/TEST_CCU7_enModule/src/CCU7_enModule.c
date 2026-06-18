#include "CCU7_enModule_help.h"

/* FUNCTION TO TEST */
sint8 CCU7_enModule(void)
{
  sint8 s8_returnCode;
  s8_returnCode = CCU7_init();
  return s8_returnCode;
}