#include "animationwindow.h"
#include<QPainter>
#include <QTimer>

Animationwindow::Animationwindow(QWidget *parent)
    : QWidget{parent}
{}

void Animationwindow::showBetScore(int bet)
{
    if(bet == 1)
    {
        m_image.load(":/images/score1.png");
    }
    else if(bet == 2)
    {
        m_image.load(":/images/score2.png");
    }
    else if(bet == 3)
    {
        m_image.load(":/images/score3.png");
    }
    update();
    //设置定时器，只显示一段时间就隐藏--2s
    QTimer::singleShot(2000,this,&Animationwindow::hide);
}

void Animationwindow::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev);
    QPainter p(this);
    p.drawPixmap(0,0,m_image.width(),m_image.height(),m_image);
}

