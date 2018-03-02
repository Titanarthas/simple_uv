//


#include <iostream>
#include <string>
#include "Test.h"
#include "UVThread.h"
#include "LogMng.h"
using namespace std;

std::string serverip;
int call_time = 0;
bool is_exist = false;


void OnInstanceExit()
{
	CLogMng::GetInstance()->StopLog();
}

int main(int argc, char** argv)
{
	::atexit(OnInstanceExit);

	CLogMng::GetInstance();

	if (argc != 3) {
		fprintf(stdout, "usage: %s server_ip_address clientcount\neg.%s 192.168.1.1 50\n", argv[0], argv[0]);
		return 0;
	}
	serverip = argv[1];

	CTest pClients;

	if (!pClients.Connect(serverip.c_str(), 12345)) {
		fprintf(stdout, "connect error:%s\n", pClients.GetLastErrMsg());
	} else {
		fprintf(stdout, "client(%p) connect succeed.\n", &pClients);
	}

	CTestMsg msg;
	msg.m_nSessionID = 1000;
	pClients.SendUvMessage(msg, msg.MSG_ID);
	while (!is_exist) {
		uv_thread_sleep(10);
	}
	return 0;
}

