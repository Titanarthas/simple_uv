#ifndef TEST_MESSAGE_H_4358943
#define TEST_MESSAGE_H_4358943

enum 
{
	SERVER_TEST_CENTER_TYPE = 1000,

};

enum 
{
	TEST_MSG = BASE_MSG_BEGIN + 1000
};

class CTestMsg
{
public:
	enum
	{
		MSG_ID = TEST_MSG
	};

	CTestMsg()
		: m_nSessionID(0)
		, m_nTimes(0)
	{

	}

	int m_nSessionID;
	int m_nTimes;
};
#endif

