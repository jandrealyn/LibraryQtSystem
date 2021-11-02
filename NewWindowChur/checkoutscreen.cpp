// ------------------------------------------------------------
//
// CHECK OUT SCREEN
// Written by Jakob
//
// This window displays the information of a specific book
// and gives the user options to check out a book, pre book
// or leave and go back to the catalogue.
//
// ------------------------------------------------------------

#include "checkoutscreen.h"
#include "ui_checkoutscreen.h"
#include "createfiles.h"

CheckOutScreen::CheckOutScreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CheckOutScreen)
{
    ui->setupUi(this);

    ui->checkoutNow->setStyleSheet("QPushButton#checkoutNow { border: 1px solid black; color: rgb(0, 0, 0); background-color: rgb(243, 243, 243);"
                                   "QPushButton:hover { background-color: #c2c2c2;}");
    //ui->checkoutNow->setStyleSheet("QPushButton:hover { background-color: #c2c2c2;}");
//    ui->prebook->setStyleSheet("QPushButton { border: 1px solid black; color: rgb(0, 0, 0); background-color: rgb(243, 243, 243);");
//    ui->prebook->setStyleSheet("QPushButton:hover { background-color: #c2c2c2;}");
//    ui->cancel->setStyleSheet("QPushButton { border: 1px solid black; color: rgb(0, 0, 0); background-color: rgb(243, 243, 243);");
//    ui->cancel->setStyleSheet("QPushButton:hover { background-color: #c2c2c2;}");
}

CheckOutScreen::~CheckOutScreen()
{
    delete ui;
}

void CheckOutScreen::on_cancel_clicked()
{
    close();
}

void CheckOutScreen::setLabels(QString bookName, QString authorName, QString copies)
{
    ui->book_name_label->setText(bookName);
    ui->book_author_label->setText(authorName);
    ui->book_copies_label->setText(copies);
}
