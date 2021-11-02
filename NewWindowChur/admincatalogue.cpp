#include "admincatalogue.h"
#include "ui_admincatalogue.h"

admincatalogue::admincatalogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admincatalogue)
{
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));
}

admincatalogue::~admincatalogue()
{
    delete ui;
}

void admincatalogue::on_back_clicked()
{
    close();
    emit ClosedAdminHome();
}

