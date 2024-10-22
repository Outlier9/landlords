#include "player.h"

Player::Player(QObject *parent)
    : QObject{parent}
{

}

Player::Player(QString name, QObject *parent)
{
    m_name = name;
    m_score = 0; // 或其他初始化逻辑
    m_role = Farmer; // 默认角色
    m_sex = Man; // 默认性别
    m_direction = Left; // 默认方向
    m_type = User; // 默认类型
    m_isWin = false; // 默认状态
    m_prev = nullptr; // 初始化上家
    m_next = nullptr; // 初始化下家
}

void Player::setName(QString name)
{
    m_name = name;
}

QString Player::getNmae()
{
    return m_name;
}

void Player::setRole(Role role)
{
    m_role = role;
}

Player::Role Player::getRole()
{
    return m_role;
}

void Player::setSex(Sex sex)
{
    m_sex = sex;
}

Player::Sex Player::getSex()
{
    return m_sex;
}

void Player::setDirection(Direction direction)
{
    m_direction = direction;
}

Player::Direction Player::getDirection()
{
    return m_direction;
}

void Player::setType(Type type)
{
    m_type = type;
}

Player::Type Player::getType()
{
    return m_type;
}

void Player::setScore(int score)
{
    m_score = score;
}

int Player::getScore()
{
    return m_score;
}

void Player::setWin(bool flag)
{
    m_isWin = flag;
}

bool Player::isWin()
{
    return m_isWin;
}

void Player::setPrevPlayer(Player *player)
{
    m_prev = player;
}

void Player::setNextPlayer(Player *player)
{
    m_next = player;
}

Player *Player::getPrevPlayer()
{
    return m_prev;
}

Player *Player::getNextPlayer()
{
    return m_next;
}

void Player::grablordBet(int point)
{

}

void Player::storeDispatchCard(Card &card)
{
    m_cards.add(card);
}

void Player::storeDispatchCard(Cards &cards)
{
    m_cards.add(cards);
}

Cards Player::getCards()
{
    return m_cards;
}

void Player::clearCards()
{
    m_cards.clear();
}

void Player::playHand(Cards &cards)
{
    m_cards.remove(cards);
}

void Player::setPendInfo(Player* player, Cards &cards)
{
    m_pendPlayer = player;
    m_pendCards = cards;
}

Player *Player::getPendplayer()
{
    return m_pendPlayer;
}

Cards Player::getPendCards()
{
    return m_pendCards;
}

void Player::prepareCallLord()
{
    //实际处理逻辑在子类中实现
}

void Player::preparePlayHand()
{
    //实际处理逻辑在子类中实现
}
