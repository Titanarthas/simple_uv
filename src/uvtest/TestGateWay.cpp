#include "TestGateWay.h"
#include "UVThreadMng.h"
#include "LogMng.h"


CTestGateWay::CTestGateWay()
	: m_nSessionID(0)
{
}


CTestGateWay::~CTestGateWay()
{
}

int CTestGateWay::OnUvMessage(const CTestMsg &msg, TcpClientCtx *pClient)
{
	CTestMsg test = msg;
	test.m_nSessionID = m_nSessionID++;

	m_mapSession[test.m_nSessionID] = pClient;

	return CUVThreadMng::GetInstance()->SendUvMessage(test, test.MSG_ID, SERVER_TEST_CENTER_TYPE);
}

void CTestGateWay::OnUvThreadMessage( CTestMsg msg, unsigned int nSrcAddr )
{
	LOGI("msg.m_nTimes = " << msg.m_nTimes);
	map<int, TcpClientCtx *>::iterator it = m_mapSession.find(msg.m_nSessionID);

	if (it != m_mapSession.end())
	{
		this->SendUvMessage(msg, msg.MSG_ID, it->second);
		// m_mapSession.erase(it);
	}
}
