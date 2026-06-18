#ifndef TEST_DMA_SETTASKSCTGTH_H
#define TEST_DMA_SETTASKSCTGTH_H

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

/** \brief Set up a task to be used in the scatter-gather mode
 *
 * \param s_entry pointer to the task structure \link tDMA_entry \endlink
 * \param e_cycleType defines the type of DMA transfer to be performed, see \link tDMA_cycleType \endlink
 * \param u8_Rpower Arbitration rate, defines after how many DMA transfers (2^u8_Rpower) the controller rearbitrates
 * \param u32_srcAddr Address pointing to the source location
 * \param u32_dstAddr Address pointing to the destination location
 * \param u32_transferCnt Number of transfers
 * \param e_transferSize Data width for each transfer, see \link tDMA_transferSize \endlink
 * \param e_incrementMode Incrementing scheme used for the transfer, see \link tDMA_incrementMode \endlink
 *
 * \return Pointer to the task
 */
tDMA_entry * DMA_setTaskSctGth(tDMA_entry * s_entry, tDMA_cycleType e_cycleType, uint8 u8_Rpower, uint32 u32_srcAddr, uint32 u32_dstAddr, uint32 u32_transferCnt, tDMA_transferSize e_transferSize, tDMA_incrementMode e_incrementMode);


#endif /* TEST_DMA_SETTASKSCTGTH_H */
