#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include"global.h"
#include"statewidget.h"
#include"userdata.h"
#include<QListWidgetItem>
namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();

    void ShowSearch(bool bsearch);
    void AddLBGroup(StateWidget *lb);
    void ClearLabelState(StateWidget *lb);
protected:
    bool eventFilter(QObject *watched, QEvent *event) override ;
    void handleGlobalMousePress(QMouseEvent *event);
    void SetSelectChatItem(int uid=0);
    void SetSelectChatPage(int uid=0);
    void loadMoreChatUser();
    void loadMoreConUser();
    void UpdateChatMsg(std::vector<std::shared_ptr<TextChatData> > msgdata);

public slots:
    void slot_loading_chat_user();
    void slot_loading_contact_user();

    void slot_side_chat();
    void slot_side_contact();
    void slot_text_changed(const QString & str);
    void slot_apply_friend(std::shared_ptr<AddFriendApply> apply);
    void slot_jump_chat_item(std::shared_ptr<SearchInfo> si);
    void slot_friend_info_page(std::shared_ptr<UserInfo> user_info);
    void slot_switch_apply_friend_page();
    void slot_jump_chat_item_from_infopage(std::shared_ptr<UserInfo> user_info);
    void slot_item_clicked(QListWidgetItem *item);
    void slot_append_send_chat_msg(std::shared_ptr<TextChatData> msgdata);
    void slot_text_chat_msg(std::shared_ptr<TextChatMsg> msg);

private:
    Ui::ChatDialog *ui;
    ChatUIMode _mode;
    ChatUIMode _state;
    bool _b_loading;
    void addChatUserList();
    QList<StateWidget*> _lb_list;
    QWidget* _last_widget;
    QMap<int, QListWidgetItem*> _chat_items_added;
    int _cur_chat_uid;
};

#endif // CHATDIALOG_H
