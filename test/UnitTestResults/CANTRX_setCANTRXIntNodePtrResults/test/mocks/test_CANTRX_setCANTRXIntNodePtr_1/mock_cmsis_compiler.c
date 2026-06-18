#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_cmsis_compiler.h"


static struct mock_cmsis_compilerInstance
{
  unsigned char placeHolder;
} Mock;

extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_cmsis_compiler_Verify(void)
{
}

void mock_cmsis_compiler_Init(void)
{
  mock_cmsis_compiler_Destroy();
}

void mock_cmsis_compiler_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

