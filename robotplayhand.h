#ifndef ROBOTPLAYHAND_H
#define ROBOTPLAYHAND_H

#include"player.h"
#include<QThread>

class Robotplayhand : public QThread
{
    Q_OBJECT
public:
    explicit Robotplayhand(Player* player,QObject *parent = nullptr);

signals:

protected:
    void run() override;

private:
    Player* m_player;
};

#endif // ROBOTPLAYHAND_H
