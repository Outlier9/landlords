#include "buttongroup.h"
#include "ui_buttongroup.h"
#include"mybutton.h"

ButtonGroup::ButtonGroup(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ButtonGroup)
{
    ui->setupUi(this);
}

ButtonGroup::~ButtonGroup()
{
    delete ui;
}

void ButtonGroup::initButtons()
{
    // 开始游戏
    ui->start->setImage(":/images/start-1.png", ":/images/start-3.png", ":/images/start-2.png");
    // 出牌
    ui->playcard->setImage(":/images/chupai_btn-1.png", ":/images/chupai_btn-3.png", ":/images/chupai_btn-2.png");
    ui->playcard1->setImage(":/images/chupai_btn-1.png", ":/images/chupai_btn-3.png", ":/images/chupai_btn-2.png");

    // 不要
    ui->pass->setImage(":/images/pass_btn-1.png", ":/images/pass_btn-3.png", ":/images/pass_btn-2.png");
    // 不抢
    ui->giveup->setImage(":/images/buqiang-1.png", ":/images/buqiang-3.png", ":/images/buqiang-2.png");
    // 1,2,3分
    ui->oneScore->setImage(":/images/1fen-1.png", ":/images/1fen-3.png", ":/images/1fen-2.png");
    ui->twoScore->setImage(":/images/2fen-1.png", ":/images/2fen-3.png", ":/images/2fen-2.png");
    ui->threeScore->setImage(":/images/3fen-1.png", ":/images/3fen-3.png", ":/images/3fen-2.png");
    //设置按钮大小
    QVector<MyButton*> btns;
    btns << ui->start << ui->playcard << ui->playcard1 << ui->pass << ui->giveup
         << ui->oneScore << ui->twoScore << ui->threeScore;
    for(int i = 0;i<btns.size();++i)
    {
        btns[i]->setFixedSize(90,45);
    }

    connect(ui->start,&MyButton::clicked,this,&ButtonGroup::startGame);
    connect(ui->playcard,&MyButton::clicked,this,&ButtonGroup::playHand);
    connect(ui->playcard1,&MyButton::clicked,this,&ButtonGroup::playHand);
    connect(ui->pass,&MyButton::clicked,this,&ButtonGroup::pass);
    connect(ui->giveup,&MyButton::clicked,this,[=]()
    {
        emit betPoint(0);
    });
    connect(ui->oneScore,&MyButton::clicked,this,[=]()
            {
                emit betPoint(1);
            });
    connect(ui->twoScore,&MyButton::clicked,this,[=]()
            {
                emit betPoint(2);
            });
    connect(ui->threeScore,&MyButton::clicked,this,[=]()
            {
                emit betPoint(3);
            });
}

void ButtonGroup::selectPanel(Panel type)
{
    ui->stackedWidget->setCurrentIndex(type);
}
