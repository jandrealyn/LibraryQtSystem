#include "adminreturned.h"
#include "ui_adminreturned.h"

adminreturned::adminreturned(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminreturned)
{
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));
}

adminreturned::~adminreturned()
{
    delete ui;
}

void adminreturned::on_back_clicked()
{
    close();
    emit ClosedAdminSystem();
}

