#ifndef GAMECONTROL_H
#define GAMECONTROL_H

#include <QObject>
#include"robot.h"
#include"userplayer.h"
#include"cards.h"

class GameControl : public QObject
{
    Q_OBJECT
public:
    //游戏状态
    enum GameStatus
    {
        DispatchCard,
        Callinglord,
        PlayingHand
    };
    //玩家状态
    enum PlayerStatus
    {
        ThinkingForCallLord,
        ThinkForPlayHand,
        Winning
    };

    explicit GameControl(QObject *parent = nullptr);

    //初始化玩家
    void playerInit();

    //得到玩家的实例对象
    Robot* getLeftRoboxt();
    Robot* getRightRobot();
    UserPlayer* getUserPlayer();

    //当前玩家（会不停变化）
    void setCurrentPlayer(Player* player);
    Player* getCurrentPlayer();

    //初始化扑克牌
    void cardInit();

    //得到出牌玩家和打出的牌
    Player* getPendPlayer();
    Cards getPendCards();

    //初始化扑克牌
    void initAllCards();
    //每次发一张牌
    Card takeOneCard();
    //得到最后三张牌
    Cards getSurplusCards();
    //重置卡牌数据
    void resetCardData();


    //准备叫地主
    void startLordCard();
    //成为地主
    void becomeLord(Player* player);
    //清空分数
    void clearPlayScore();

    //处理叫地主

    //处理出牌




signals:


private:
    Robot* m_robotLeft;
    Robot* m_robotRight;
    UserPlayer* m_user;
    //最开始第一个玩家的初始化
    Player* m_currPlayer;
    //打牌的人和打出的牌
    Player* m_pendPlayer;
    Cards m_pendCards;
    //扑克牌
    Cards m_allCards;

};

#endif // GAMECONTROL_H
