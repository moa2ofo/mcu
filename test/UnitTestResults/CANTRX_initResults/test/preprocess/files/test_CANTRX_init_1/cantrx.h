// CEEDLING NOTICE: This generated file only to be consumed by CMock

#ifndef _CANTRX_H_ // Ceedling-generated include guard
#define _CANTRX_H_

#include "types.h"
#include "error_codes.h"
#include "RTE_Components.h"
#include "tle989x.h"
#include "core_cm3.h"
#include "cmsis_version.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "system_tle989x.h"
#include "cmsis_misra.h"
#include "cantrx_defines.h"

static inline void CANTRX_enBusDominantTimeoutInt(void);
static inline void CANTRX_disBusDominantTimeoutInt(void);
static inline uint8 CANTRX_getBusDominantTimeoutIntSts(void);
static inline uint8 CANTRX_getBusDominantTimeoutSts(void);
static inline void CANTRX_clrBusDominantTimeoutIntSts(void);
static inline void CANTRX_clrBusDominantTimeoutSts(void);
static inline void CANTRX_enTXDDominantTimeoutInt(void);
static inline void CANTRX_disTXDDominantTimeoutInt(void);
static inline uint8 CANTRX_getTXDDominantTimeoutIntSts(void);
static inline uint8 CANTRX_getTXDDominantTimeoutSts(void);
static inline void CANTRX_clrTXDDominantTimeoutIntSts(void);
static inline void CANTRX_clrTXDDominantTimeoutSts(void);
static inline void CANTRX_enCANOvertempInt(void);
static inline void CANTRX_disCANOvertempInt(void);
static inline uint8 CANTRX_getCANOvertempIntSts(void);
static inline uint8 CANTRX_getCANOvertempSts(void);
static inline void CANTRX_clrCANOvertempIntSts(void);
static inline void CANTRX_clrCANOvertempSts(void);
static inline void CANTRX_enActBusWhenCANSleepInt(void);
static inline void CANTRX_disActBusWhenCANSleepInt(void);
static inline uint8 CANTRX_getActBusWhenCANSleepIntSts(void);
static inline uint8 CANTRX_getCANSupplyUndervoltageSts(void);
static inline void CANTRX_clrActBusWhenCANSleepIntSts(void);
void CANTRX_setCANTRXIntNodePtr(void) __attribute__((deprecated("Do not change this at runtime, use the ConfigWizard to configure this feature!")));

static inline void CANTRX_enBusDominantTimeoutInt(void)
{
  ((CANTRX_Type*) 0x4800C000UL)->IRQEN.bit.BUS_TO_IEN = 1u;
}

static inline void CANTRX_disBusDominantTimeoutInt(void)
{
  ((CANTRX_Type*) 0x4800C000UL)->IRQEN.bit.BUS_TO_IEN = 0u;
}

static inline uint8 CANTRX_getBusDominantTimeoutIntSts(void)
{
  return ((CANTRX_Type*) 0x4800C000UL)->IRQS.bit.BUS_TO_IS;
}

static inline uint8 CANTRX_getBusDominantTimeoutSts(void)
{
  return ((CANTRX_Type*) 0x4800C000UL)->IRQS.bit.BUS_TO_STS;
}

static inline void CANTRX_clrBusDominantTimeoutIntSts(void)
{
  ((CANTRX_Type*) 0x4800C000UL)->IRQCLR.bit.BUS_TO_ISC = 1u;
}

static inline void CANTRX_clrBusDominantTimeoutSts(void)
{
  ((CANTRX_Type*) 0x4800C000UL)->IRQCLR.bit.BUS_TO_SC = 1u;
}

static inline void CANTRX_enTXDDominantTimeoutInt(void)
{
  ((CANTRX_Type*) 0x4800C000UL)->IRQEN.bit.TXD_TO_IEN = 1u;
}

static inline void CANTRX_disTXDDominantTimeoutInt(void)
{
  ((CANTRX_Type*) 0x4800C000UL)->IRQEN.bit.TXD_TO_IEN = 0u;
}

static inline uint8 CANTRX_getTXDDominantTimeoutIntSts(void)
{
  return ((CANTRX_Type*) 0x4800C000UL)->IRQS.bit.TXD_TO_IS;
}

static inline uint8 CANTRX_getTXDDominantTimeoutSts(void)
{
  return ((CANTRX_Type*) 0x4800C000UL)->IRQS.bit.TXD_TO_STS;
}

static inline void CANTRX_clrTXDDominantTimeoutIntSts(void)
{
  ((CANTRX_Type*) 0x4800C000UL)->IRQCLR.bit.TXD_TO_ISC = 1u;
}

static inline void CANTRX_clrTXDDominantTimeoutSts(void)
{
  ((CANTRX_Type*) 0x4800C000UL)->IRQCLR.bit.TXD_TO_SC = 1u;
}

static inline void CANTRX_enCANOvertempInt(void)
{
  ((CANTRX_Type*) 0x4800C000UL)->IRQEN.bit.OT_IEN = 1u;
}

static inline void CANTRX_disCANOvertempInt(void)
{
  ((CANTRX_Type*) 0x4800C000UL)->IRQEN.bit.OT_IEN = 0u;
}

static inline uint8 CANTRX_getCANOvertempIntSts(void)
{
  return ((CANTRX_Type*) 0x4800C000UL)->IRQS.bit.OT_IS;
}

static inline uint8 CANTRX_getCANOvertempSts(void)
{
  return ((CANTRX_Type*) 0x4800C000UL)->IRQS.bit.OT_STS;
}

static inline void CANTRX_clrCANOvertempIntSts(void)
{
  ((CANTRX_Type*) 0x4800C000UL)->IRQCLR.bit.OT_ISC = 1u;
}

static inline void CANTRX_clrCANOvertempSts(void)
{
  ((CANTRX_Type*) 0x4800C000UL)->IRQCLR.bit.OT_SC = 1u;
}

static inline void CANTRX_enActBusWhenCANSleepInt(void)
{
  ((CANTRX_Type*) 0x4800C000UL)->IRQEN.bit.BUS_ACT_IEN = 1u;
}

static inline void CANTRX_disActBusWhenCANSleepInt(void)
{
  ((CANTRX_Type*) 0x4800C000UL)->IRQEN.bit.BUS_ACT_IEN = 0u;
}

static inline uint8 CANTRX_getActBusWhenCANSleepIntSts(void)
{
  return ((CANTRX_Type*) 0x4800C000UL)->IRQS.bit.BUS_ACT_IS;
}

static inline uint8 CANTRX_getCANSupplyUndervoltageSts(void)
{
  return ((CANTRX_Type*) 0x4800C000UL)->IRQS.bit.UV_STS;
}

static inline void CANTRX_clrActBusWhenCANSleepIntSts(void)
{
  ((CANTRX_Type*) 0x4800C000UL)->IRQCLR.bit.BUS_ACT_ISC = 1u;
}

#endif // _CANTRX_H_
