#include "adminoverdue.h"
#include "ui_adminoverdue.h"

//Laras Code :)

adminoverdue::adminoverdue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminoverdue)
{
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));
}

adminoverdue::~adminoverdue()
{
    delete ui;
}

void adminoverdue::on_back_clicked()
{
    close();
    emit ClosedAdminSystem();
}

