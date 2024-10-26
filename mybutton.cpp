#include "mybutton.h"
#include<QMouseEvent>
#include<QPainter>

MyButton::MyButton(QWidget *parent)
    : QPushButton{parent}
{}

void MyButton::setImage(QString normal, QString hover, QString pressed)
{
    m_normal = normal;
    m_hover = hover;
    m_pressed = pressed;
    m_pixmap.load(m_normal);
    update();
}

void MyButton::mousePressEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        m_pixmap.load(m_pressed);
        update();
    }
    //重写了mousePressEvent函数，该函数的父类是会自动发送mousePressEvent的
    //所以需要在子类的重写中也再调用一遍,下边mouseReleaseEvent同理
    QPushButton::mousePressEvent(ev);
}

void MyButton::mouseReleaseEvent(QMouseEvent *ev)
{
    if(ev->button() == Qt::LeftButton)
    {
        m_pixmap.load(m_normal);
        update();
    }
    QPushButton::mouseReleaseEvent(ev);
}

void MyButton::enterEvent(QEvent *ev)
{
    Q_UNUSED(ev);
    m_pixmap.load(m_hover);
    update();

}

void MyButton::leaveEvent(QEvent *ev)
{
    Q_UNUSED(ev);
    m_pixmap.load(m_normal);
    update();
}




void MyButton::paintEvent(QPaintEvent *ev)
{
    Q_UNUSED(ev);
    QPainter p(this);

    // 绘制当前状态下的 pixmap
    p.drawPixmap(rect(), m_pixmap);
}











