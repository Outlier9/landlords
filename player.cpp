#include "player.h"

Player::Player(QObject *parent)
    : QObject{parent}
{}

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
