#include "adminuser.h"
#include "ui_adminuser.h"

adminuser::adminuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminuser)
{
    ui->setupUi(this);
}

adminuser::~adminuser()
{
    delete ui;
}
