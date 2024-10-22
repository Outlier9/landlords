#include "scorepanel.h"
#include "ui_scorepanel.h"

scorepanel::scorepanel(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::scorepanel)
{
    ui->setupUi(this);
}

scorepanel::~scorepanel()
{
    delete ui;
}
