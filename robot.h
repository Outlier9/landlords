#ifndef ROBOT_H
#define ROBOT_H

#include <QObject>
#include "player.h"

class Robot : public Player
{
    Q_OBJECT
public:
    using Player::Player;
    explicit Robot(QObject *parent = nullptr);
    //显示父类的虚函数即可
    void prepareCallLord() override;
    void preparePlayHand() override;
};

#endif // ROBOT_H