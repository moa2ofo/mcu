// CEEDLING NOTICE: This generated file only to be consumed by CMock

#ifndef _CMSIS_MISRA_H_ // Ceedling-generated include guard
#define _CMSIS_MISRA_H_

#include "types.h"
#include "error_codes.h"
#include "RTE_Components.h"
#include "core_cm3.h"
#include "cmsis_version.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"

static inline sint32 CMSIS_Irq_Dis(void);

static inline void CMSIS_Irq_En(void);

static inline void CMSIS_NOP(void);

static inline void CMSIS_WFE(void);

static inline void CMSIS_SEV(void);

static inline sint32 CMSIS_Irq_Dis(void)
{

  __disable_irq();
  return 0;
}

static inline void CMSIS_Irq_En(void)
{

  __enable_irq();
}

static inline void CMSIS_NOP(void)
{

  __asm volatile ("nop");
}

static inline void CMSIS_WFE(void)
{

  __asm volatile ("wfe":::"memory");
}

static inline void CMSIS_SEV(void)
{

  __asm volatile ("sev");
}

#endif // _CMSIS_MISRA_H_
