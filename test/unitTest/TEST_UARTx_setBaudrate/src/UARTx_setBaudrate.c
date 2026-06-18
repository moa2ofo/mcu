#include "UARTx_setBaudrate_help.h"

/* FUNCTION TO TEST */
sint8 UARTx_setBaudrate(uint32 u32_baudrate, volatile tUARTx_BCON *tp_baudrateReg)
{
  sint8 s8_returnCode;
  uint32 u32_maxBaudrate;
  uint8 i;
  uint8 u8_deviation;
  uint8 u8_flag;
  sint8 s8_pre;
  uint8 u8_prescaler;
  uint16 u16_reloadVal;
  uint32 u32_calcBR;
  uint32 u32_minBR;
  uint32 u32_maxBR;
  u32_maxBaudrate = 0;
  u8_deviation = 0u;
  u8_flag = 0u;
  s8_pre = (sint8)5;
  u8_prescaler = 32u;
  u16_reloadVal = 1u;
  s8_returnCode = ERR_LOG_CODE_PARAM_OUT_OF_RANGE;
  u32_maxBaudrate = (uint32)(SCU_fUART_MHz * 1000000 / 16);

  /* Check range for baudrate */
  if ((u32_baudrate <= u32_maxBaudrate) && (u32_baudrate >= 2400u))
  {
    /* While loop on prescaler value to find the reload value/fractional divider */
    /* At each iteration the prescaler is divided by 2 */
    while (u8_prescaler > 0u && u8_deviation < 250)
    {
      /* According to UM, Baudrate = fUART / (16 * prescaler * (reloadVal + fracDiv/32)) */
      u16_reloadVal = (uint16)((uint32)SCU_fUART_MHz * 1000000u / (16u * u8_prescaler * u32_baudrate));

      /* The reload value is an 11-bit value, 0 sets the timer into Bypass mode -> valid values between 1 and 2047 */
      if ((u16_reloadVal <= 2047u) && (u16_reloadVal > 0u))
      {
        /* For-loop on the fractional divider, for given prescaler and reload values */
        for (i = 0; i <= 32; i++)
        {
          //lint --e{9011}
          /* Calculated baudrate with the given prescaler, reload and fractional divider values */
          u32_calcBR = (SCU_fUART_MHz * 1000000u * 32u) / (16u * u8_prescaler * (32u * u16_reloadVal + i));
          /* Min and max baudrate values for the given deviation */
          u32_minBR = (uint32)(((uint64)u32_baudrate * (uint64)((uint64)10000u - (uint64)u8_deviation)) / 10000u);
          u32_maxBR = (uint32)(((uint64)u32_baudrate * (uint64)((uint64)10000u + (uint64)u8_deviation)) / 10000u);

          /* If the calculated baudrate is below the minimum possible baudrate, the for-loop on the fractional divider is interrupted */
          if (u32_calcBR < u32_minBR)
          {
            break;
          }
          else
          {
            /* To meet the expected deviation, the calculated baudrate should be between a min and a max baudrate */
            if ((u32_calcBR >= u32_minBR) && (u32_calcBR <= u32_maxBR))
            {
              /* In that case parameters (prescaler, fractional dividers and reload value) are found that meet the given deviation */
              /* The for-loop is interrupted and the u8_flag is set to 1 (to stop the while-loop on line 243 */
              u8_flag = 1u;
              /* Disable baudrate generator */
              tp_baudrateReg->bit.BR_R = 0u;
              /* Set prescaler, fractional divider and reload value */
              tp_baudrateReg->bit.BR_PRE = (uint8)s8_pre;

              if (i == 32)
              {
                tp_baudrateReg->bit.BG_FD_SEL = 0u;
                tp_baudrateReg->bit.BG_BR_VALUE = u16_reloadVal + 1u;
              }
              else
              {
                tp_baudrateReg->bit.BG_FD_SEL = i;
                tp_baudrateReg->bit.BG_BR_VALUE = u16_reloadVal;
              }

              /* Enable baudrate generator */
              tp_baudrateReg->bit.BR_R = 1u;
              /* Set the return code to success */
              s8_returnCode = ERR_LOG_SUCCESS;
              break;
            }
          }
        }

        if (u8_flag == 0u)
        {
          /* At each iteration the prescaler is divided by 2 */
          u8_prescaler /= 2u;
          /* At each iteration the prescaler value is decremented by 1 */
          s8_pre -= (sint8)1;

          if (s8_pre < (sint8)0)
          {
            u8_deviation += 1u;
            /* Reinitialization of variables */
            s8_pre = (sint8)5;
            u8_prescaler = 32u;
            u16_reloadVal = 0u;
          }
        }
        else
        {
          break;
        }
      }
      else
      {
        /* At each iteration the prescaler is divided by 2 */
        u8_prescaler /= 2u;
        /* At each iteration the prescaler value is decremented by 1 */
        s8_pre -= (sint8)1;
      }
    }
  }

  return s8_returnCode;
}