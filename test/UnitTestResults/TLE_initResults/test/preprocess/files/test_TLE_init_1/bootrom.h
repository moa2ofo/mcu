// CEEDLING NOTICE: This generated file only to be consumed by CMock

#ifndef _BOOTROM_H_ // Ceedling-generated include guard
#define _BOOTROM_H_

#include "types.h"
#include "error_codes.h"
#include "RTE_Components.h"

typedef struct user_100tp_read_t
{
  uint32_t offset;
  uint8_t *data;
  uint16_t nbyte;
} user_100tp_read_t;

typedef struct user_100tp_write_t
{
  uint32_t offset;
  uint8_t *data;
  uint8_t nbyte;
  uint8_t counter;
} user_100tp_write_t;

typedef struct user_key_t
{
  uint8_t key[((0x20u))];
  uint16_t version;
  uint8_t length;
  uint8_t protection;
} user_key_t;

typedef enum user_crypto_fid_t
{
  CRYPTO_ECB_ENCRYPT = 0,
  CRYPTO_ECB_DECRYPT = 1,
  CRYPTO_CBC_ENCRYPT = 2,
  CRYPTO_CBC_DECRYPT = 3
} user_crypto_fid_t;

typedef struct user_crypto_inp_buf_t
{
  uint8_t *buffer;
  uint32_t length;
} user_crypto_inp_buf_t;

typedef struct user_crypto_out_buf_t
{
  uint8_t *buffer;
  uint32_t *length;
} user_crypto_out_buf_t;

typedef struct user_crypto_io_buf_t
{
  user_crypto_inp_buf_t inp;
  user_crypto_out_buf_t out;
} user_crypto_io_buf_t;

typedef struct user_crypto_cmac_t
{
  user_crypto_inp_buf_t inp;
  user_crypto_inp_buf_t mac;
} user_crypto_cmac_t;

typedef struct user_crypto_cbc_t
{
  void *iv;
  uint32_t iv_length;
} user_crypto_cbc_t;

typedef struct user_key_write_params_t
{
  uint8_t encrypted_key_buf[(0x40u)];
  uint16_t target_key_id;
  uint16_t encrypt_key_id;
} user_key_write_params_t;

typedef struct user_key_write_t
{
  user_key_write_params_t params;
  uint8_t signature[(0x10u)];
} user_key_write_t;

typedef struct user_key_erase_params_t
{
  uint16_t target_key_id;
  uint16_t version;
} user_key_erase_params_t;

typedef struct user_key_erase_t
{
  user_key_erase_params_t params;
  uint8_t signature[(0x10u)];
} user_key_erase_t;

typedef struct user_nvm_page_write_t
{
  uint8_t *data;
  uint32_t nbyte;
  uint32_t options;
} user_nvm_page_write_t;

typedef enum user_cache_op_t
{
  CACHE_OP_AC = 0,
  CACHE_OP_SC = 1,
  CACHE_OP_BC = 2,
  CACHE_OP_BT = 3,
  CACHE_OP_BL = 4,
  CACHE_OP_BU = 5,
  CACHE_OP_EN = 6,
  CACHE_OP_DIS = 7
} user_cache_op_t;

typedef enum user_nvm_segment_t
{
  NVM_PASSWORD_SEGMENT_BOOT = 0,
  NVM_PASSWORD_SEGMENT_CODE = 1,
  NVM_PASSWORD_SEGMENT_DATA = 2,
  NVM_PASSWORD_SEGMENT_TOTAL = 3
} user_nvm_segment_t;

#endif // _BOOTROM_H_
