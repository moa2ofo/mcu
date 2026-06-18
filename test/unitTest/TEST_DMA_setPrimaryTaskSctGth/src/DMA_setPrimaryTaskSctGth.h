#ifndef TEST_DMA_SETPRIMARYTASKSCTGTH_H
#define TEST_DMA_SETPRIMARYTASKSCTGTH_H

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

/** \brief Set up the primary task to configure the scatter-gather mode
 * \brief The DMA scather-gather mode can be used to perform multiple but different DMA transfers initiated with one trigger.
 * \brief The last task can be used to self-arm this scatter-gather transfer again.
 *
 * \param s_primEntry Pointer to the task
 * \param u8_chIdx DMA channel for with the task is setup
 * \param s_taskList Pointer to the task list to be executed with this DMA transfer
 * \param u32_taskCnt Number of tasks defined in the task list
 *
 * \return Pointer to the task
 */
tDMA_entry * DMA_setPrimaryTaskSctGth(tDMA_entry * s_primEntry, uint8 u8_chIdx, tDMA_entry * s_taskList, uint32 u32_taskCnt);


#endif /* TEST_DMA_SETPRIMARYTASKSCTGTH_H */
