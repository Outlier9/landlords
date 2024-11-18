#ifndef ANIMATIONWINDOW_H
#define ANIMATIONWINDOW_H

#include <QWidget>

class Animationwindow : public QWidget
{
    Q_OBJECT
public:
    explicit Animationwindow(QWidget *parent = nullptr);

    //显示下注分数
    void showBetScore(int bet);


signals:

protected:
    void paintEvent(QPaintEvent *ev);

private:
    QPixmap m_image;
};

#endif // ANIMATIONWINDOW_H
