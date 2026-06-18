#ifndef TEST_ADC1_GETCHFILTRESULT_MV_HELP_H
#define TEST_ADC1_GETCHFILTRESULT_MV_HELP_H

#include "ADC1_getChFiltResult_mV.h"
#include <stddef.h>
#include <string.h>

/* static globals (copied) */
static const uint16 cu16_ADC1_analogInput_Att[] = {ADC1_ATT_TYPE0, /* analog input 0, attenuator type 0 */
                                                   ADC1_ATT_TYPE1, /* analog input 1, attenuator type 1 */
                                                   ADC1_ATT_TYPE0, /* analog input 2, attenuator type 0 */
                                                   ADC1_ATT_TYPE1, /* analog input 3, attenuator type 1 */
                                                   ADC1_ATT_TYPE1, /* analog input 4, attenuator type 1 */
                                                   ADC1_ATT_TYPE1, /* analog input 5, attenuator type 1 */
                                                   ADC1_ATT_TYPE1, /* analog input 6, attenuator type 1 */
                                                   ADC1_ATT_TYPE1, /* analog input 7, attenuator type 1 */
                                                   ADC1_ATT_TYPE1, /* analog input 8, attenuator type 1 */
                                                   ADC1_ATT_TYPE1, /* analog input 9, attenuator type 1 */
                                                   ADC1_ATT_TYPE0, /* analog input 10, attenuator type 0 */
                                                   ADC1_ATT_TYPE1, /* analog input 11, attenuator type 1 */
                                                   ADC1_ATT_TYPE0, /* analog input 12, attenuator type 0 */
                                                   ADC1_ATT_TYPE1, /* analog input 13, attenuator type 1 */
                                                   ADC1_ATT_TYPE0, /* analog input 14, attenuator type 0 */
                                                   ADC1_ATT_TYPE1, /* analog input 15, attenuator type 1 */
                                                   ADC1_ATT_TYPE2, /* analog input 16, attenuator type 2 */
                                                   ADC1_ATT_TYPE2, /* analog input 17, attenuator type 2 */
                                                   ADC1_ATT_TYPE2, /* analog input 18, attenuator type 2 */
                                                   ADC1_ATT_TYPE2, /* analog input 19, attenuator type 2 */
                                                   ADC1_ATT_TYPE2, /* analog input 20, attenuator type 2 */
                                                   ADC1_ATT_TYPE2, /* analog input 21, attenuator type 2 */
                                                   ADC1_ATT_TYPE2, /* analog input 22, attenuator type 2 */
                                                   ADC1_ATT_TYPE2, /* analog input 23, attenuator type 2 */
                                                   ADC1_ATT_TYPE2, /* analog input 24, attenuator type 2 */
                                                   ADC1_ATT_TYPE2, /* analog input 25, attenuator type 2 */
                                                   ADC1_ATT_TYPE2  /* analog input 26, attenuator type 2 */
                                                  };
const uint16* get_cu16_ADC1_analogInput_Att_ptr(void) { return cu16_ADC1_analogInput_Att; }
size_t get_cu16_ADC1_analogInput_Att_size(void) { return (size_t)27; }
void set_cu16_ADC1_analogInput_Att(const const uint16* src, size_t n) {
    size_t m = (n < (size_t)27) ? n : (size_t)27;
    memcpy(cu16_ADC1_analogInput_Att, src, m * sizeof(const uint16));
}

#endif /* TEST_ADC1_GETCHFILTRESULT_MV_HELP_H */
