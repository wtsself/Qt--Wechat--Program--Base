#ifndef TCPMGR_H
#define TCPMGR_H
#include"singleton.h"
#include<QTcpSocket>
#include"global.h"
#include"userdata.h"
#include"usermgr.h"
class TcpMgr:public QObject,public Singleton<TcpMgr>,public std::enable_shared_from_this<TcpMgr>
{
    Q_OBJECT

public:
    ~TcpMgr();
private:
    friend class Singleton<TcpMgr>;
    TcpMgr();
    void initHandler();
    void handleMeg(ReqId id,int len,QByteArray date);
    QTcpSocket _socket;
    QString _host;
    uint16_t _port;
    QByteArray _buffer;
    bool _b_recv_pending;
    quint16 _message_id;
    quint16 _message_len;
    QMap<ReqId ,std::function<void(ReqId,int,QByteArray)>> _handlers;
    void initHandlers();
    void handleMsg(ReqId id, int len, QByteArray data);
signals:
    void sig_con_success(bool bsuccess);

    void sig_send_data(ReqId reqId, QByteArray data);
   // void sig_send_data(ReqId reqId, QByteArray data);

    void sig_login_failed(int);
    void sig_swich_chatdlg();
    void sig_user_search(std::shared_ptr<SearchInfo>);
    void sig_load_apply_list(QJsonArray json_array);
    void sig_friend_apply(std::shared_ptr<AddFriendApply>);
    void sig_add_auth_friend(std::shared_ptr<AuthInfo>);
    void sig_auth_rsp(std::shared_ptr<AuthRsp>);
    void sig_text_chat_msg(std::shared_ptr<TextChatMsg> msg);
    void sig_notify_offline();
    void sig_connection_closed();


public slots:
    void slot_tcp_connect(ServerInfo);
    void slot_send_data(ReqId reqId, QByteArray data);
};

#endif // TCPMGR_H
