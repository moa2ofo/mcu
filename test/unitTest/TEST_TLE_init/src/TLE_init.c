#include "TLE_init_help.h"

/* FUNCTION TO TEST */
sint8 TLE_init(void)
{
  //lint --e{9027}
  sint8 s8_returnCode;
  uint32 u32_ubslNvmSize;
  uint32 u32_codeNvmSize;
  uint32 u32_dataNvmSize;
  s8_returnCode = ERR_LOG_SUCCESS;
#ifdef RTE_DEVICE_TLELIB_SCU
  SCU_init();
#endif
#ifdef RTE_DEVICE_TLELIB_PMU
  s8_returnCode |= PMU_init();
#endif
#ifdef RTE_DEVICE_TLELIB_ADC1
  s8_returnCode |= ADC1_init();
#endif
#ifdef RTE_DEVICE_TLELIB_ADC2
  s8_returnCode |= ADC2_init();
#endif
#ifdef RTE_DEVICE_TLELIB_BDRV
  s8_returnCode |= BDRV_initCP();
#endif
#ifdef RTE_DEVICE_TLELIB_CSACSC
  s8_returnCode |= CSACSC_init();
#endif
#ifdef RTE_DEVICE_TLELIB_BDRV
  s8_returnCode |= BDRV_init();
#endif
#ifdef RTE_DEVICE_TLELIB_CCU7
  s8_returnCode |= CCU7_init();
#endif
#ifdef RTE_DEVICE_TLELIB_CANTRX
  s8_returnCode |= CANTRX_init();
#endif
#ifdef RTE_DEVICE_TLELIB_DMA
  s8_returnCode |= DMA_init();
#endif
#ifdef RTE_DEVICE_TLELIB_GPIO
  GPIO_init();
#endif
#ifdef RTE_DEVICE_TLELIB_GPT12
  s8_returnCode |= GPT12_init();
#endif
#ifdef RTE_DEVICE_TLELIB_MON
  MON_init();
#endif
#ifdef RTE_DEVICE_TLELIB_SDADC
  s8_returnCode |= SDADC_init();
#endif
#ifdef RTE_DEVICE_TLELIB_SSC
  s8_returnCode |= SSC0_init();
  s8_returnCode |= SSC1_init();
#endif
#ifdef RTE_DEVICE_TLELIB_TIMER2X
  s8_returnCode |= T20_init();
  s8_returnCode |= T21_init();
#endif
#ifdef RTE_DEVICE_TLELIB_UART
  s8_returnCode |= UART0_init();
  s8_returnCode |= UART1_init();
#endif
#ifdef RTE_DEVICE_TLELIB_INT
  INT_init();
#endif
  /* Initialize variables for memory map that can be configured */
  (void)user_nvm_config_get(&u32_ubslNvmSize, &u32_codeNvmSize, &u32_dataNvmSize);
  UC_FLASH0_UBSL_SIZE = (uint32) (u32_ubslNvmSize) * UC_FLASH_SECTOR_SIZE;
  UC_FLASH0_UDATA_START = UC_FLASH0_UBSL_START + UC_FLASH0_UBSL_SIZE;
  UC_FLASH0_UDATA_SIZE = UC_FLASH0_SIZE - UC_FLASH0_UBSL_SIZE;
  return s8_returnCode;
}