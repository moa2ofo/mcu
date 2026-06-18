#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_cmsis_misra.h"


static struct mock_cmsis_misraInstance
{
  unsigned char placeHolder;
} Mock;

extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_cmsis_misra_Verify(void)
{
}

void mock_cmsis_misra_Init(void)
{
  mock_cmsis_misra_Destroy();
}

void mock_cmsis_misra_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

