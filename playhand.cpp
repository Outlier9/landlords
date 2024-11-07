#include "playhand.h"

PlayHand::PlayHand() {}

PlayHand::PlayHand(Cards &cards)
{
    //1.对扑克牌进行分类：1张、2张、3张、4张有多少种
    classify(cards);
    //2.对牌型进行分类
    judgeCardType();
}

PlayHand::PlayHand(HandType type, Card::CardPoint pt, int extra)
{
    m_type = type;
    m_pt = pt;
    m_extra = extra;
}

void PlayHand::classify(Cards &cards)
{

}

void PlayHand::judgeCardType()
{

}

PlayHand::HandType PlayHand::getHandType()
{
    return m_type;
}

Card::CardPoint PlayHand::getCardPoint()
{
    return m_pt;
}

int PlayHand::getExtra()
{
    return m_extra;
}
