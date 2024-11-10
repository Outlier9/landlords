#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include"cards.h"
class Player : public QObject
{
    Q_OBJECT
public:
    enum Role{lord, Farmer}; // 角色，枚举类型
    enum Sex{Man,Woman}; // 性别
    enum Direction{Left,Right}; // 人物朝向
    enum Type{Robot,User,UnKnow}; //玩家类型
    explicit Player(QObject *parent = nullptr);
    explicit Player(QString name,QObject *parent = nullptr);


    //名字
    void setName(QString name);
    QString getNmae();

    //角色
    void setRole(Role role);
    Role getRole();

    //性别
    void setSex(Sex sex);
    Sex getSex();

    //方位
    void setDirection(Direction direction);
    Direction getDirection();

    //玩家类型
    void setType(Type type);
    Type getType();

    //玩家分数
    void setScore(int score);
    int getScore();

    //游戏结果
    void setWin(bool flag);
    bool isWin();

    //提供当前对象的上家/下家
    void setPrevPlayer(Player* player);
    void setNextPlayer(Player* player);
    Player* getPrevPlayer();
    Player* getNextPlayer();

    //叫地主/抢地主
    void grablordBet(int point);

    //存储扑克牌（发牌的时候得到）
    void storeDispatchCard(Card& card);
    void storeDispatchCard(Cards& cards);

    //得到所有的牌
    Cards getCards();

    //清空所有卡牌
    void clearCards();

    //出牌
    void playHand(Cards &cards);

    //设置出牌玩家以及待处理的扑克牌
    void setPendInfo(Player* player,Cards &cards);
    //抽象类，不能进行实例化
    Player* getPendPlayer();
    Cards getPendCards();

    //纯虚函数,用多态实现机器人和用户的不同处理方式
    virtual void prepareCallLord();
    virtual void preparePlayHand();

signals:
    //通知已经下注
    void notifyGrabLordBet(Player* player,int bet);

protected:
    int m_score;
    QString m_name;
    Role m_role;
    Sex m_sex;
    Direction m_direction;
    Type m_type;
    bool m_isWin;
    Player* m_prev;
    Player* m_next;
    Cards m_cards; // 存储多张扑克牌

    Cards m_pendCards;
    Player* m_pendPlayer;
};

#endif // PLAYER_H
