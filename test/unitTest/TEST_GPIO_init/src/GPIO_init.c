#include "GPIO_init_help.h"

/* FUNCTION TO TEST */
void GPIO_init(void)
{
  /* P0.x*/
  GPIO->P0_DIR.reg = (uint32)GPIO_P0_DIR;
  GPIO->P0_OD.reg = (uint32)GPIO_P0_OD;
  GPIO->P0_PUD.reg = (uint32)GPIO_P0_PUD;
  GPIO->P0_POCON.reg = (uint32)GPIO_P0_POCON;
  GPIO->P0_ALTSEL0.reg = (uint32)GPIO_P0_ALTSEL0;
  GPIO->P0_ALTSEL1.reg = (uint32)GPIO_P0_ALTSEL1;
  GPIO->P0_OUT.reg = (uint32)GPIO_P0_OUT;
  /* P1.x */
  GPIO->P1_DIR.reg = (uint32)GPIO_P1_DIR;
  GPIO->P1_OD.reg = (uint32)GPIO_P1_OD;
  GPIO->P1_PUD.reg = (uint32)GPIO_P1_PUD;
  GPIO->P1_POCON.reg = (uint32)GPIO_P1_POCON;
  GPIO->P1_ALTSEL0.reg = (uint32)GPIO_P1_ALTSEL0;
  GPIO->P1_OUT.reg = (uint32)GPIO_P1_OUT;
  /* P2.x */
  GPIO->P2_INDIS.reg = (uint32)GPIO_P2_INDIS;
  GPIO->P2_PUD.reg = (uint32)GPIO_P2_PUD;
}