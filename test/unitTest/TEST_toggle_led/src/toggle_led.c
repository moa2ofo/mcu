#include "toggle_led_help.h"

/* FUNCTION TO TEST */
void toggle_led(void)
{
  GPIO_setP06State(GPIO_STATE_TOGGLE);
}