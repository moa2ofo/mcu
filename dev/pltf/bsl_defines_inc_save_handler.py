#<checksum>2897bff166e0a65642280846ab3a2612bd6724f8c443f994cb07211b0215f480</checksum>
#                                                                                
# Copyright (c) Infineon Technologies AG
# All rights reserved.
#
# The applicable license agreement can be found at this pack's installation directory in the file
# license/IFX_SW_Licence_MOTIX_LITIX.txt
#
#
# \file     bsl_defines_inc_save_handler.py
#
# \brief    Script to generate the file bsl_defines.inc
#
# \version  V0.2.3
# \date     05. Nov 2024
#

###############################################################################
#                              Author(s) Identity                             #
#*****************************************************************************#
#  Initials     Name                                                          #
#  -------------------------------------------------------------------------- #
#  JO           Julia Ott                                                     #
#  BG           Blandine Guillot                                              #
###############################################################################

###############################################################################
#                           Revision Control History                          #
#*****************************************************************************#
#  V0.1.0: 2021-04-09, JO:   Initial version with FLASH1_CACHE_EN             #
#  V0.1.1: 2021-06-21, JO:   EP-846: Updated SECBOOT_KEY to 0xFFFFFFFF        #
#  V0.2.0: 2021-06-21, JO:   EP-847: Added generation of BSL_NAD_NAC          #
#  V0.2.1: 2021-07-12, BG:   EP-716: Added generation of two files - the .inc #
#                            file for IAR must not have an END at the end     #
#  V0.2.2: 2021-11-30, JO:   EP-937: Updated copyright and branding           #
#  V0.2.3: 2024-11-05, JO:   EP-1494: Updated license                         #
###############################################################################


def bsl_defines_inc_save_handler():
    if FLASH1_CACHE_EN.checked == False:
      FLASH1_CACHE_EN_value = '0x00000000'
    else:
      FLASH1_CACHE_EN_value = '0x00000004'
    with open('bsl_defines_ARM.inc', 'w+') as file:
        file.write('BSL_NAD_NAC     EQU     ' + hex(int(BSL_NAD_NAC_REG.text.replace('\u202c', ''))).upper().replace('X', 'x') + '\n')
        file.write('SECBOOT_KEY     EQU     0xFFFFFFFF\n')
        file.write('FLASH1_CACHE_EN EQU     ' + FLASH1_CACHE_EN_value + '\n')
        file.write('                END\n')
    with open('bsl_defines_IAR.inc', 'w+') as file:
        file.write('BSL_NAD_NAC     EQU     ' + hex(int(BSL_NAD_NAC_REG.text.replace('\u202c', ''))).upper().replace('X', 'x') + '\n')
        file.write('SECBOOT_KEY     EQU     0xFFFFFFFF\n')
        file.write('FLASH1_CACHE_EN EQU     ' + FLASH1_CACHE_EN_value + '\n')
    
  

FILE_SAVE.connect('triggered()', bsl_defines_inc_save_handler)

