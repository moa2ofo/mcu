#ifndef TEST_DMA_INIT_H
#define TEST_DMA_INIT_H

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

/** \brief Initialize the DMA structure in RAM and SFRs according to the ConfigWizard settings
 *
 * \return sint8 0: success, <0: error codes
 */
sint8 DMA_init(void);


#endif /* TEST_DMA_INIT_H */
