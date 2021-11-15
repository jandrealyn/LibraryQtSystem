#include "admindue.h"
#include "ui_admindue.h"

//Laras Code :)

admindue::admindue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admindue)
{
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));
}

admindue::~admindue()
{
    delete ui;
}

void admindue::on_back_clicked()
{
    close();
    emit ClosedAdminSystem();
}

