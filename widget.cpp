#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::changeMoney(int diff)
{
    money += diff;
    ui->lcdNumber->display(money);
}

int Widget::returnMoney(int bill)
{
    int cnt = money / bill;
    money -= bill * cnt;
    ui->lcdNumber->display(money);
    return cnt;
}

void Widget::on_pbCoin10_clicked()
{
    changeMoney(10);
}

void Widget::on_pbCoin50_clicked()
{
    changeMoney(50);
}

void Widget::on_pbCoin100_clicked()
{
    changeMoney(100);
}

void Widget::on_pbCoin500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}

void Widget::on_pbReset_clicked()
{
    QMessageBox msgBox;
    QString msg = "here's change... \n";
    msg += QString("total: %1\n").arg(money);
    msg += QString("- 500 * %1\n").arg(returnMoney(500));
    msg += QString("- 100 * %1\n").arg(returnMoney(100));
    msg += QString("- 50 * %1\n").arg(returnMoney(50));
    msg += QString("- 10 * %1\n").arg(returnMoney(10));
    msgBox.setText(msg);
    msgBox.exec();
}

