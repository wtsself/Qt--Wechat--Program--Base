# Qt--base

> for learning

在 D 盘创建了 `cppsoft` 文件夹，里面放了不完全构建的 Boost 库和从 `jsonapp` 复制来的文件。  
`jsonapp` 文件和编译后的 Boost 文件都放进了浏览器下载目录。

在 Visual Studio 中配置好了 Boost 和 `jsonapp` 的包含目录和库目录，  
**其中 `jsonapp` 需要特别指定链接库目录。**

---

## 启动流程

1. 启动 Redis：

   ```powershell
   PS D:\cppsoft\Redis-x64-5.0.14.1> .\redis-server.exe .\redis.windows.conf
   ```

2. 启动 Node.js 服务：

   ```powershell
   PS D:\桌面\C++项目\VarifyServer> npm run serve
   ```

3. 启动各服务：

   - 启动 GateServer
   - 启动 StatusServer
   - 启动 ChatServer1，再启动 ChatServer2
   - 启动 Qt 客户端

---

## 当前存在的问题

- ~~(已解决) 1：无法实现自动负载均衡~~  
  客户端都连接 ChatServer1，问题可能与 Qt 客户端或 StatusServer 有关，  
  可通过手动修改函数 `void TcpMgr::slot_tcp_connect(ServerInfo si)` 指定 ChatServer。

- 2：在添加标签页面，**标签显示错误**，每个标签占一整行。

- 3：添加好友后，**被添加人**的联系人页面红点未能正常显示。

- 4：聊天时，**自己头像无法正常显示**。
