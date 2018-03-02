#include "Test.h"
#include "log4z.h"


CTest::CTest()
{
}


CTest::~CTest()
{
}

int CTest::OnUvMessage(const CTestMsg &msg, TcpClientCtx *pClient)
{
	LOGI("msg.m_nTimes = " << msg.m_nTimes);
	return 0;
	return this->SendUvMessage(msg, msg.MSG_ID);
}
