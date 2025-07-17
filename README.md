# Qt--base-
for learning
在D盘创建了cppsoft文件，里面放了不完全构建的boost库和jsonapp复制来的文件。
jsonapp文件和编译后的boost文件都放进浏览器下载目录。
在studio中配好了boost和jsonapp的包含目录和库目录，并且jsonapp要特别的链接库目录。


先启动redis： PS D:\cppsoft\Redis-x64-5.0.14.1> .\redis-server.exe .\redis.windows.conf
再启动node.js： PS D:\桌面\C++项目\VarifyServer> npm run serve
启动GateServer，启动StatusServer
启动ChatServer1,再启动ChatServer2
启动Qt客服端



现在存在的问题：
//(已解决)1：无法实现自动负载均衡，客户端都连接chatserver1，跟qt客户端或stateserver有关，可以手动修改函数:void TcpMgr::slot_tcp_connect(ServerInfo si)指定chatserver
2：在添加标签页面标签一次占一行的显示错误
3：添加好友后，被添加人联系人页面红点未能显示
4: 在聊天时，自己头像显示不出来
