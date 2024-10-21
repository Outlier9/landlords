#ifndef USERPLAYER_H
#define USERPLAYER_H

#include <QObject>
#include "player.h"

class UserPlayer : public Player
{
    Q_OBJECT
public:
    using Player::Player;
    explicit UserPlayer(QObject *parent = nullptr);

    //显示父类的虚函数即可
    void prepareCallLord() override;
    void preparePlayHand() override;
};

#endif // USERPLAYER_H
