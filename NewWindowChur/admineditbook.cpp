#include "admineditbook.h"
#include "ui_admineditbook.h"

admineditbook::admineditbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admineditbook)
{
    ui->setupUi(this);
}

admineditbook::~admineditbook()
{
    delete ui;
}
