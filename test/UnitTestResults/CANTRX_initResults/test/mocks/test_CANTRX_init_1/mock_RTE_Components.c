#include <string.h>
#include <stdlib.h>
#include <setjmp.h>
#include "cmock.h"
#include "mock_RTE_Components.h"


static struct mock_RTE_ComponentsInstance
{
  unsigned char placeHolder;
} Mock;

extern int GlobalExpectCount;
extern int GlobalVerifyOrder;

void mock_RTE_Components_Verify(void)
{
}

void mock_RTE_Components_Init(void)
{
  mock_RTE_Components_Destroy();
}

void mock_RTE_Components_Destroy(void)
{
  CMock_Guts_MemFreeAll();
  memset(&Mock, 0, sizeof(Mock));
  GlobalExpectCount = 0;
  GlobalVerifyOrder = 0;
}

