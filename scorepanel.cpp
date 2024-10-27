#include "scorepanel.h"
#include "ui_scorepanel.h"


ScorePanel::ScorePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScorePanel)
{
    ui->setupUi(this);
}

ScorePanel::~ScorePanel()
{
    delete ui;
}

void ScorePanel::setScores(int left, int right, int user)
{
    ui->leftscore->setText(QString::number(left));
    ui->rightscore->setText(QString::number(right));
    ui->myscore->setText(QString::number(user));
}
