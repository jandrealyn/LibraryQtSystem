#include "prebook.h"
#include "ui_prebook.h"

Prebook::Prebook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Prebook)
{
    ui->setupUi(this);
}

Prebook::~Prebook()
{
    delete ui;
}
