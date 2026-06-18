#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_cantrx_defines.h"


static struct mock_cantrx_definesInstance
{
  unsigned char placeHolder;
} Mock;

extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_cantrx_defines_Verify(void)
{
}

void mock_cantrx_defines_Init(void)
{
  mock_cantrx_defines_Destroy();
}

void mock_cantrx_defines_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

