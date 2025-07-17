#ifndef CHATPAGE_H
#define CHATPAGE_H
//这里是用QWidget界面代替聊天page
#include <QWidget>
#include"picturebubble.h"
#include"textbubble.h"
#include"chatitembase.h"
#include<QTextEdit>
#include"userdata.h"
#include"tcpmgr.h"
namespace Ui {
class ChatPage;
}

class ChatPage : public QWidget
{
    Q_OBJECT

public:
    explicit ChatPage(QWidget *parent = nullptr);
    ~ChatPage();
    void SetUserInfo(std::shared_ptr<UserInfo> user_info);
    void AppendChatMsg(std::shared_ptr<TextChatData> msg);
protected:
    void paintEvent(QPaintEvent *event);

private slots:
    void on_send_btn_clicked();

private:
    Ui::ChatPage *ui;
    std::shared_ptr<UserInfo> _user_info;
signals:
    void sig_append_send_chat_msg(std::shared_ptr<TextChatData> msg);
};

#endif // CHATPAGE_H
