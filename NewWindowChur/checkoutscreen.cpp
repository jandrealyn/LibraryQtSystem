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
#include <QDate>

CheckOutScreen::CheckOutScreen(QWidget *parent, QString memName, QString memID, QString bookID, QString bookName, QString authorName, QString copies) :
    QDialog(parent),
    ui(new Ui::CheckOutScreen)
{
    ui->setupUi(this);
    _membersID = memID;
    _membersName = memName;
    _bookID = bookID;
    _bookName = bookName;

    ui->book_name_label->setText(bookName);
    ui->book_author_label->setText(authorName);
    ui->book_copies_label->setText(copies);

    if (copies.toInt() == 0) // We can't let a user checkout a book that doesn't have any copies
    {
        ui->checkoutNow->setEnabled(false);
    }
}

CheckOutScreen::~CheckOutScreen()
{
    delete ui;
}

void CheckOutScreen::on_cancel_clicked()
{
    close();
}

void CheckOutScreen::on_checkoutNow_clicked()
{
    bool yesChecked = false;

    QMessageBox* confirmCheckout = new QMessageBox(nullptr);
    confirmCheckout->setWindowTitle("Checkout Confirmation");
    confirmCheckout->setText("Are you sure you want to checkout this book?");
    confirmCheckout->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    confirmCheckout->setDefaultButton(QMessageBox::Yes);
    int result = confirmCheckout->exec();

    switch(result)
    {
    case QMessageBox::Yes:
        CreateFiles::CheckOutBook(_bookID, _bookName, _membersID, _membersName);
        yesChecked = true;
        break;
    case QMessageBox::Cancel:
        confirmCheckout->close();
        break;
    default: break;
    }

    if (yesChecked)
    {
        QString dueDate = QDate::currentDate().addDays(7).toString("dd.MM.yyyy");
        QMessageBox* confirmed = new QMessageBox(nullptr);
        confirmed->setWindowTitle("Checkout Confirmed");
        confirmed->setText("You have successfully checked out " + _bookName + "!<br> "
                           "Please return by " + dueDate);
       confirmed->exec();
       this->close();
    }
}

void CheckOutScreen::OpenCheckOutScreen()
{
    show();
}

void CheckOutScreen::on_reserve_clicked()
{
    hide();
    _reserveBook = new ReserveBook(NULL, _membersName, _membersID, _bookID, _bookName);
    _reserveBook->setWindowTitle("Reserve a book");
    _reserveBook->showNormal();
    connect(_reserveBook, SIGNAL(ReserveScreenClosed()), this, SLOT(OpenCheckOutScreen()));
}



