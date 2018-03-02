#pragma once
#include "tcpclient.h"
#include "../message_define/TestMessage.h"
class CTest :
	public CTCPClient
{
public:
	CTest();
	virtual ~CTest();

protected:
	BEGIN_UV_BIND
		UV_BIND(CTestMsg::MSG_ID, CTestMsg)
	END_UV_BIND(CTCPClient)

	int OnUvMessage(const CTestMsg &msg, TcpClientCtx *pClient);
};

