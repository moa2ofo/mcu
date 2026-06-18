#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_cmsis_gcc.h"


static struct mock_cmsis_gccInstance
{
  unsigned char placeHolder;
} Mock;

extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_cmsis_gcc_Verify(void)
{
}

void mock_cmsis_gcc_Init(void)
{
  mock_cmsis_gcc_Destroy();
}

void mock_cmsis_gcc_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

