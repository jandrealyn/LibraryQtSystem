#include "adminadduser.h"
#include "ui_adminadduser.h"

adminadduser::adminadduser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminadduser)
{
    ui->setupUi(this);
}

adminadduser::~adminadduser()
{
    delete ui;
}
