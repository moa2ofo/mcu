#include "CCU7_disModule_help.h"

/* FUNCTION TO TEST */
sint8 CCU7_disModule(void)
{
  /* Stop T12 */
  CCU7_stopT12();
  /* Stop T13, T14, T15, T16 */
  CCU7_stopT13();
  CCU7_stopT14();
  CCU7_stopT15();
  CCU7_stopT16();
  /* Program the passive states to LOW */
  CCU7->PSLR.bit.PSL_CC70 = 0;
  CCU7->PSLR.bit.PSL_COUT70 = 0;
  CCU7->PSLR.bit.PSL_CC71 = 0;
  CCU7->PSLR.bit.PSL_COUT71 = 0;
  CCU7->PSLR.bit.PSL_CC72 = 0;
  CCU7->PSLR.bit.PSL_COUT72 = 0;
  /* Switch all CCU7 outputs to passive state/disable any modulation */
  CCU7->MODCTR.bit.T12MODEN_CC70 = 0;
  CCU7->MODCTR.bit.T12MODEN_COUT70 = 0;
  CCU7->MODCTR.bit.T12MODEN_CC71 = 0;
  CCU7->MODCTR.bit.T12MODEN_COUT71 = 0;
  CCU7->MODCTR.bit.T12MODEN_CC72 = 0;
  CCU7->MODCTR.bit.T12MODEN_COUT72 = 0;
  CCU7->MODCTR.bit.T13MODEN_CC70 = 0;
  CCU7->MODCTR.bit.T13MODEN_COUT70 = 0;
  CCU7->MODCTR.bit.T13MODEN_CC71 = 0;
  CCU7->MODCTR.bit.T13MODEN_COUT71 = 0;
  CCU7->MODCTR.bit.T13MODEN_CC72 = 0;
  CCU7->MODCTR.bit.T13MODEN_COUT72 = 0;
  return ERR_LOG_SUCCESS;
}