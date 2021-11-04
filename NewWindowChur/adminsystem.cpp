#include "adminsystem.h"
#include "ui_adminsystem.h"

adminsystem::adminsystem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminsystem)
{
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));
}

adminsystem::~adminsystem()
{
    delete ui;
}

void adminsystem::on_back_clicked()
{
    close();
    emit ClosedAdminHome();
}

