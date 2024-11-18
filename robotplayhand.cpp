#include "robotplayhand.h"

Robotplayhand::Robotplayhand(Player* player,QObject *parent)
    : QThread{parent}
{
    m_player = player;
}

void Robotplayhand::run()
{
    msleep(2000);
    m_player->thinkPlayHand();
}
