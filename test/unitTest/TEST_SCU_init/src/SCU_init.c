#include "SCU_init_help.h"

/* FUNCTION TO TEST */
void SCU_init(void)
{
  /* Enable CLKOUT if configured */
  SCU->CLKSEL.reg |= ((uint32)SCU_CLKSEL & SCU_CLKSEL_CLKOUTEN_Msk);
}