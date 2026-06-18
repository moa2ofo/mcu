cmake_minimum_required(VERSION 3.16)

project(new C ASM)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(PROJECT_ROOT "C:/docAiGen/Manuali_SW3_SW4")
set(MCU_ROOT ${PROJECT_ROOT}/mcu/dev)

file(GLOB SOURCES
    "${MCU_ROOT}/pltf/*.c"
    "${MCU_ROOT}/cfg/*.c"
)

add_library(new STATIC ${SOURCES})

target_include_directories(new PUBLIC
    ${MCU_ROOT}/pltf
    ${MCU_ROOT}/cfg
    ${MCU_ROOT}
)

target_compile_definitions(new PRIVATE
    TLE9893_2QKW62S
)

target_compile_options(new PRIVATE
    -mcpu=cortex-m3
    -mthumb
    -w
)