########################################################
# MCU SOURCE FILES, INCLUDES, AND DEFINITIONS
########################################################

#component root alias for simpler reference
set(MCU_ROOT    ${PROJECT_ROOT}/swcs/mcu/dev)

target_compile_definitions(${TARGET_NAME} PRIVATE
  TLE9893_2QKW62S
)

target_sources(${TARGET_NAME} PRIVATE
  ${MCU_ROOT}/pltf/tle_dfp/adc1.c
  ${MCU_ROOT}/pltf/tle_dfp/adc2.c
  ${MCU_ROOT}/pltf/tle_dfp/bdrv.c
  ${MCU_ROOT}/pltf/tle_dfp/bootrom.c
  ${MCU_ROOT}/pltf/tle_dfp/can.c
  ${MCU_ROOT}/pltf/tle_dfp/cantrx.c
  ${MCU_ROOT}/pltf/tle_dfp/ccu7.c
  ${MCU_ROOT}/pltf/tle_dfp/csacsc.c
  ${MCU_ROOT}/pltf/tle_dfp/dma.c
  ${MCU_ROOT}/pltf/tle_dfp/gpio.c
  ${MCU_ROOT}/pltf/tle_dfp/gpt12.c
  ${MCU_ROOT}/pltf/tle_dfp/int.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_exceptions.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq0_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq1_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq2_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq3_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq4_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq5_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq7_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq8_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq9_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq10_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq11_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq12_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq13_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq14_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq15_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq16_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq17_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq18_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq19_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq20_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq21_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq22_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq23_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq24_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq25_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq26_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq27_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq28_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq29_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq30_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/isr_nvic_irq31_handler.c
  ${MCU_ROOT}/pltf/tle_dfp/mon.c
  ${MCU_ROOT}/pltf/tle_dfp/pmu.c
  ${MCU_ROOT}/pltf/tle_dfp/scu.c
  ${MCU_ROOT}/pltf/tle_dfp/sdadc.c
  ${MCU_ROOT}/pltf/tle_dfp/ssc.c
  ${MCU_ROOT}/pltf/tle_dfp/startup_tle989x.c
  ${MCU_ROOT}/pltf/tle_dfp/system_tle989x.c
  ${MCU_ROOT}/pltf/tle_dfp/timer2x.c
  ${MCU_ROOT}/pltf/tle_dfp/tle_device.c
  ${MCU_ROOT}/pltf/tle_dfp/uart.c
  ${MCU_ROOT}/pltf/Mcu.c
)

target_include_directories(${TARGET_NAME} PRIVATE
  ${MCU_ROOT}/cfg
  ${MCU_ROOT}/cfg/tle_dfp
  ${MCU_ROOT}/pltf
  ${MCU_ROOT}/pltf/cmsis
  ${MCU_ROOT}/pltf/tle_dfp
)