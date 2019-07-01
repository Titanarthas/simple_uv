# simple_uv

simple_uv是基于libuv封装跨平台库，旨在降低入门门槛和提高开发效率以及降低开发者人为出错的概率。

libuv是Reactor模式，simple_uv是Proactor模式(对于上层业务开发者是Proactor模式)。

simple_uv简化了客户端与服务端的通信，客户端与服务端的所有交互消息都以某一个类的对象回调到上层业务，你不用关注客户端与服务端通信过程中消息的解析以及堆空间的申请与释放等繁琐且易出错的处理。

为了方便的进行多线程程序的开发以及多线程之间高效率的通信，simple_uv实现了一个CUVThread的线程类，类似windows上mfc中的CWinThread，可以响应其他线程发送过来的异步非阻塞消息，CUVThread提供了一个SendUvMessage的函数，可以向任意的CUVThread线程发送消息。

此外，simple_uv还提供了一个CUVThreadMng的类，管理所有的CUVThread线程，你可以在任意线程中调用CUVThreadMng::GetInstance()->SendUvMessage向指定的CUVThread发送消息。

在simple_uv中，对于客户端发到服务端的消息，服务端都有一个对应的响应函数来处理。例如客户端发送了一个CTestMsg类型的消息到服务端，服务端可以在这样一个函数中响应客户端的请求

    int CTestGateWay::OnUvMessage(const CTestMsg &msg, TcpClientCtx *pClient)
    {
    	return CUVThreadMng::GetInstance()->SendUvMessage(msg, msg.MSG_ID, SERVER_TEST_CENTER_TYPE);
    }
    
其中TcpClientCtx *pClient是客户端的socket连接句柄，服务端可以通过SendUvMessage(const TYPE& msg, size_t nMsgType, TcpClientCtx *pClient)函数向客户端回传消息。CUVThreadMng::GetInstance()->SendUvMessage可以向任意的基类为CUVThread的线程发送消息。

客户端与服务端同理。

对于Linux上，simple_uv提供了一个Makefile的模板，你只需要在模板中填写src目录，需要生成的文件名，库目录和库名，以及编译所需的特殊宏定义即可。毕竟对于几十或者上百的cpp文件时原生态写Makefile还是比较麻烦且容易出错的。

为了降低入门门槛，simple_uv还提供了一套mysql的封装，你无需懂sql语句也可以做数据库相关的开发工作，你只需要填填对应字段即可完成数据库操作。（后续提供）

simple_uv在网络发包的代码参考了phata（wqvbjhc@gmail.com）在GitHub上的开源代码https://github.com/wqvbjhc/libuv_tcp.git

对simple_uv有任何问题可以邮件gzssyxwdy@gmail.com。
