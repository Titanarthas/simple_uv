#pragma once
#include "UVThread.h"
#include "../message_define/TestMessage.h"
class CTestServerCenter :
	public CUVThread
{
public:
	CTestServerCenter(void);
	virtual ~CTestServerCenter(void);

	BEGIN_UV_THREAD_BIND
		UV_THREAD_BIND(CTestMsg::MSG_ID, CTestMsg)
	END_UV_THREAD_BIND(CUVThread)

protected:
	void OnUvThreadMessage(CTestMsg msg, unsigned int nSrcAddr);
};

