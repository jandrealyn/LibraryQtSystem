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
