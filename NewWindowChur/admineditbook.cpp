#include "admineditbook.h"
#include "ui_admineditbook.h"

admineditbook::admineditbook(QWidget *parent, QString bookID, QString bookName, QString authorName, QString copies) :
    QDialog(parent),
    ui(new Ui::admineditbook)
{
    ui->setupUi(this);
    _bookID = bookID;
    ui->book_name_label->setText(bookName);
    ui->book_author_label->setText(authorName);
    ui->book_copies_label->setText(copies);
}

admineditbook::~admineditbook()
{
    delete ui;
}
