#include "updateuserpicture.h"
#include "ui_updateuserpicture.h"

UpdateUserPicture::UpdateUserPicture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateUserPicture)
{
    ui->setupUi(this);
}

UpdateUserPicture::~UpdateUserPicture()
{
    delete ui;
}
