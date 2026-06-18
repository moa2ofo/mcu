#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_cmsis_version.h"


static struct mock_cmsis_versionInstance
{
  unsigned char placeHolder;
} Mock;

extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_cmsis_version_Verify(void)
{
}

void mock_cmsis_version_Init(void)
{
  mock_cmsis_version_Destroy();
}

void mock_cmsis_version_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

