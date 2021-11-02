#include "signupscreen.h"
#include "ui_signupscreen.h"

signupscreen::signupscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signupscreen)
{
    ui->setupUi(this);
}

signupscreen::~signupscreen()
{
    delete ui;
}
