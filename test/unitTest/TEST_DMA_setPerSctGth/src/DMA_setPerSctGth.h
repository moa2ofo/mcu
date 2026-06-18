#ifndef TEST_DMA_SETPERSCTGTH_H
#define TEST_DMA_SETPERSCTGTH_H

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

/** \brief Set up a channel to operate in Peripheral Scatter-Gather mode on a given task list
 *
 * \param u8_chIdx DMA channel to be set up
 * \param s_taskList Points to the task structure defined in RAM, see \link DMA_setTaskSctGth \endlink
 * \param u32_taskCnt Number of tasks in the s_taskList
 */
void DMA_setPerSctGth(uint8 u8_chIdx, tDMA_entry * s_taskList, uint32 u32_taskCnt);


#endif /* TEST_DMA_SETPERSCTGTH_H */
