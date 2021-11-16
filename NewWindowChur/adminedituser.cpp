#include "adminedituser.h"
#include "ui_adminedituser.h"

adminedituser::adminedituser(QWidget *parent, QString fn, QString ln, QString email, QString phn) :
    QDialog(parent),
    ui(new Ui::adminedituser)
{
    ui->setupUi(this);
}

adminedituser::~adminedituser()
{
    delete ui;
}

void adminedituser::on_deleteuser_clicked()
{

}


void adminedituser::on_canceledit_clicked()
{
    close();
    emit exec();
}

