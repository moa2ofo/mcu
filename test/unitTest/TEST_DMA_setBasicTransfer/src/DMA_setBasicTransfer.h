#ifndef TEST_DMA_SETBASICTRANSFER_H
#define TEST_DMA_SETBASICTRANSFER_H

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

/** \brief Set up a basic transfer for the desired DMA channel in the primary structure in RAM
 *
 * \param u8_chIdx DMA channel to be set up
 * \param u32_srcAddr Address pointing to the source location
 * \param u32_dstAddr Address pointing to the destination location
 * \param u32_transferCnt Number of transfers
 * \param e_transferSize Data width for each transfer, see \link tDMA_transferSize \endlink
 * \param e_incrementMode incrementing scheme used for the transfer, see \link tDMA_incrementMode \endlink
 */
void DMA_setBasicTransfer(uint8 u8_chIdx, uint32 u32_srcAddr, uint32 u32_dstAddr, uint32 u32_transferCnt, tDMA_transferSize e_transferSize, tDMA_incrementMode e_incrementMode);


#endif /* TEST_DMA_SETBASICTRANSFER_H */
