#ifndef SCOREPANEL_H
#define SCOREPANEL_H

#include <QWidget>

namespace Ui {
class scorepanel;
}

class scorepanel : public QWidget
{
    Q_OBJECT

public:
    explicit scorepanel(QWidget *parent = nullptr);
    ~scorepanel();

private:
    Ui::scorepanel *ui;
};

#endif // SCOREPANEL_H
