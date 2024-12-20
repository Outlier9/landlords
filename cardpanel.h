#ifndef CARDPANEL_H
#define CARDPANEL_H

#include <QWidget>
#include"card.h"
#include"player.h"

class CardPanel : public QWidget
{
    Q_OBJECT
public:
    explicit CardPanel(QWidget *parent = nullptr);

    //设置和获取图片函数
    void setImage(QPixmap &front,QPixmap &back);
    QPixmap getImage();

    //扑克牌显示的那一面
    void setFrontSide(bool flag);
    bool isFrontSide();

    //记录窗口是否被选中
    void setSelected(bool flag);
    bool isSelected();

    //扑克牌的花色以及点数
    void setCard(Card& card);
    Card getCard();

    //扑克牌的所有者
    void setOwner(Player* player);
    Player* getOwner();

    // 模拟扑克牌的点击事件
    void clicked();


protected:
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent* event);

signals:
    void cardSelected(Qt::MouseButton button);

private:
    QPixmap m_front;
    QPixmap m_back;
    bool m_isfront;
    bool m_isselected;
    Card m_card;
    Player* m_player;
    Player* m_owner;
};

#endif // CARDPANEL_H
