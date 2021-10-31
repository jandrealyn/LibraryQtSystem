#include "checkoutscreen.h"
#include "ui_checkoutscreen.h"

CheckOutScreen::CheckOutScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckOutScreen)
{
    ui->setupUi(this);

    ui->book_name_label->setText("hi");
}

CheckOutScreen::~CheckOutScreen()
{
    delete ui;
}

void CheckOutScreen::on_cancel_clicked()
{
    close();
}

void CheckOutScreen::get_Book_Name(QString name)
{

}
