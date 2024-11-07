#include "gamecontrol.h"
#include<QRandomGenerator>
#include<QTimer>

GameControl::GameControl(QObject *parent)
    : QObject{parent}
{}

void GameControl::playerInit()
{
    //对象实例化
    m_robotLeft = new Robot("机器人A",this);
    m_robotRight = new Robot("机器人B",this);
    m_user = new UserPlayer("玩家自己",this);

    //头像的显示
    m_robotLeft->setDirection(Player::Left);
    m_robotRight->setDirection(Player::Right);
    m_user->setDirection(Player::Right);

    //性别
    Player::Sex sex;
    //生成随机数随机设定性别
    sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
    m_robotLeft->setSex(sex);

    sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
    m_robotRight->setSex(sex);

    sex = (Player::Sex)QRandomGenerator::global()->bounded(2);
    m_user->setSex(sex);

    //出牌顺序
    //user
    m_user->setPrevPlayer(m_robotLeft);
    m_user->setNextPlayer(m_robotRight);

    //left robot
    m_robotLeft->setPrevPlayer(m_robotRight);
    m_robotLeft->setNextPlayer(m_user);

    //right robot
    m_robotRight->setPrevPlayer(m_user);
    m_robotRight->setNextPlayer(m_robotLeft);

    //指定开始玩家
    m_currPlayer = m_user;

    //处理玩家发射出的信号
    connect(m_user,&UserPlayer::notifyGrabLordBet,this,&GameControl::onGrabBet);
    connect(m_robotLeft,&UserPlayer::notifyGrabLordBet,this,&GameControl::onGrabBet);
    connect(m_robotRight,&UserPlayer::notifyGrabLordBet,this,&GameControl::onGrabBet);

}

Robot *GameControl::getLeftRobot()
{
    return m_robotLeft;
}

Robot *GameControl::getRightRobot()
{
    return m_robotRight;
}

UserPlayer *GameControl::getUserPlayer()
{
    return m_user;
}

void GameControl::setCurrentPlayer(Player* player)
{
    m_currPlayer = player;
}

Player *GameControl::getCurrentPlayer()
{
    return m_currPlayer;
}

Player *GameControl::getPendPlayer()
{
    return m_pendPlayer;
}

Cards GameControl::getPendCards()
{
    return m_pendCards;
}

void GameControl::initAllCards()
{
    m_allCards.clear();
    for(int p = Card::Card_Begin+1;p<Card::Card_SJ;++p)
    {
        for(int s = Card::Suit_Begin+1;s<Card::Suit_End;++s)
        {
            Card c((Card::CardPoint)p,(Card::CardSuit)s);
            m_allCards.add(c);
        }
    }
    //大小王需要单独初始化，花色不等于上边任意一种
    m_allCards.add(Card(Card::Card_SJ,Card::Suit_Begin));
    m_allCards.add(Card(Card::Card_BJ,Card::Suit_Begin));
}

Card GameControl::takeOneCard()
{
    return m_allCards.takeRandCard();
}

Cards GameControl::getSurplusCards()
{
    return m_allCards;
}

void GameControl::resetCardData()
{
    //洗牌
    initAllCards();
    //清空所有玩家的牌
    m_robotLeft->clearCards();
    m_robotRight->clearCards();
    m_user->clearCards();
    //初始化出牌玩家和牌
    m_pendPlayer = nullptr;
    m_pendCards.clear();
}

void GameControl::startLordCard()
{
    m_currPlayer->prepareCallLord();
    emit playerStatusChanged(m_currPlayer,ThinkingForCallLord);
}

void GameControl::becomeLord(Player* player)
{
    player->setRole(Player::lord);
    player->getPrevPlayer()->setRole(Player::Farmer);
    player->getNextPlayer()->setRole(Player::Farmer);

    m_currPlayer = player;
    player->storeDispatchCard(m_allCards);

    QTimer::singleShot(1000,this,[=](){
        emit gameStatusChanged(PlayingHand);
        emit playerStatusChanged(player,ThinkForPlayHand);
        m_currPlayer->preparePlayHand();
    });

}

int GameControl::getPlayerMaxBet()
{
    return m_betRecord.bet;
}

// void GameControl::onGrabBet(Player *player, int bet)
// {
//     //1.通知主界面玩家叫地主
//     if(bet == 0 || m_betRecord.bet >= bet)
//     {
//         emit notifyGrabLordBet(player,0,false);
//     }
//     else if(bet > 0 && m_betRecord.bet == 0)
//     {
//         //第一个抢地主的玩家
//         emit notifyGrabLordBet(player,bet,true);
//     }
//     else
//     {
//         //第2,3个叫地主的玩家
//         emit notifyGrabLordBet(player,bet,false);
//     }

//     //2.判断抢地主玩家下注是不是三分，如果是抢地主结束
//     if(bet == 3)
//     {
//         //玩家成为地主
//         becomeLord(player);
//         //清空数据
//         m_betRecord.reset();
//         return;
//     }
//     //3.下注不够三分，对玩家的分数进行比较，分数高的是地主
//     if(m_betRecord.bet < bet)
//     {
//         m_betRecord.bet = bet;
//         m_betRecord.player = player;
//     }
//     m_betRecord.times ++;
//     //如果每个玩家都抢过一次地主，抢地主结束
//     if(m_betRecord.times == 3)
//     {
//         //如果都没有抢地主，重新发牌
//         if(m_betRecord.bet == 0)
//         {
//             emit gameStatusChanged(DispatchCard);
//         }
//         else
//         {
//             becomeLord(m_betRecord.player);
//         }
//         //为了对下一局游戏不进行干扰需要重置，因为游戏开始阶段还没有创建对象
//         m_betRecord.reset();
//         return;
//     }
//     //4.切换玩家，通知下一个玩家继续抢地主
//     m_currPlayer = player->getNextPlayer();
//     //发送信号给主界面，告知当前状态为抢地主
//     emit playerStatusChanged(m_currPlayer,ThinkingForCallLord);
//     m_currPlayer->prepareCallLord();
// }



void GameControl::onGrabBet(Player *player, int bet)
{
    // 1. 检查叫分情况，并根据 bet 值发送对应的信号
    if (bet == 0) {
        // 玩家选择不抢
        emit notifyGrabLordBet(player, 0, false); // 显示“不抢”图片
    }
    else if (bet == 1) {
        // 玩家叫 1 分
        emit notifyGrabLordBet(player, 1, true); // 显示“叫地主”图片
        m_betRecord.bet = 1;  // 更新最大叫分
        m_betRecord.player = player;
    }
    else if (bet == 2) {
        // 玩家叫 2 分
        emit notifyGrabLordBet(player, 2, true); // 显示“叫地主”图片
        m_betRecord.bet = 2;  // 更新最大叫分
        m_betRecord.player = player;
    }
    else if (bet == 3) {
        // 玩家叫 3 分，直接成为地主
        emit notifyGrabLordBet(player, 3, false); // 显示“抢地主”图片
        becomeLord(player); // 成为地主
        m_betRecord.reset();  // 重置记录，准备新一局
        return;
    }

    // 2. 记录叫分次数，确保每个玩家仅叫一次
    m_betRecord.times++;

    // 3. 若每个玩家都已叫过一次
    if (m_betRecord.times == 3) {
        if (m_betRecord.bet == 0) {
            // 都没有叫分，则重新发牌
            emit gameStatusChanged(DispatchCard);
        } else {
            // 最高分玩家成为地主
            becomeLord(m_betRecord.player);
        }
        m_betRecord.reset();  // 重置记录，准备新一局
        return;
    }

    // 4. 切换到下一个玩家继续叫地主
    m_currPlayer = player->getNextPlayer();
    emit playerStatusChanged(m_currPlayer, ThinkingForCallLord);  // 更新状态为“抢地主中”
    m_currPlayer->prepareCallLord();  // 下一个玩家准备叫分
}



