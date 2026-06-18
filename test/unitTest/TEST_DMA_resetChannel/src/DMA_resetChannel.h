#ifndef TEST_DMA_RESETCHANNEL_H
#define TEST_DMA_RESETCHANNEL_H

#include "RTE_Components.h"
#include "dma_defines.h"
#include "scu_defines.h"
#include "cmsis_compiler.h"
#include "cmsis_gcc.h"
#include "cmsis_misra.h"
#include "cmsis_version.h"
#include "core_cm3.h"
#include "dma.h"
#include "error_codes.h"
#include "system_tle989x.h"
#include "tle989x.h"
#include "tle_variants.h"
#include "types.h"

  #define DMA_BASE_ADDR (uint32)(&u32p_DMA_entriesForTest)

/** \brief Reset the primary structure in RAM for a given channel and rearm it
 *
 * \param u8_chIdx DMA channel to be reset
 * \param u32_transferCnt Number of transfers
 */
void DMA_resetChannel(uint8 u8_chIdx, uint32 u32_transferCnt);


#endif /* TEST_DMA_RESETCHANNEL_H */
