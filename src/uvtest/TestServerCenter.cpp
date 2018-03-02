#include "TestServerCenter.h"
#include "../message_define/TestMessage.h"
#include "UVThreadMng.h"
#include "LogMng.h"


CTestServerCenter::CTestServerCenter(void)
	: CUVThread(SERVER_TEST_CENTER_TYPE)
{
}


CTestServerCenter::~CTestServerCenter(void)
{
}

void CTestServerCenter::OnUvThreadMessage( CTestMsg msg, unsigned int nSrcAddr )
{
	for (int i = 0; i < 1000; i++)
	{
		msg.m_nTimes = i;
		
		CUVThreadMng::GetInstance()->SendUvMessage2Handle(msg, msg.MSG_ID, m_nThreadType);
	}
}
