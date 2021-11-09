#include "updateuserdetails.h"
#include "ui_updateuserdetails.h"

UpdateUserDetails::UpdateUserDetails(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UpdateUserDetails)
{
    ui->setupUi(this);
}

UpdateUserDetails::~UpdateUserDetails()
{
    delete ui;
}
