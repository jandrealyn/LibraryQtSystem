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
<<<<<<< HEAD

CheckOutScreen::CheckOutScreen(QWidget *parent) :
=======
#include "SystemFiles.h"
#include "catalogue.h"
#include <QStatusBar>
#include <QDate>
#include <QMessageBox>

CheckOutScreen::CheckOutScreen(QWidget *parent, QString memName, QString memID, QString bookID, QString bookName, QString authorName, QString copies) :
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
    QDialog(parent),
    ui(new Ui::CheckOutScreen)
{
    ui->setupUi(this);
<<<<<<< HEAD

    ui->book_name_label->setText("hi");
=======
    _membersID = memID;
    _membersName = memName;
    _bookID = bookID;
    _bookName = bookName;
    _copies = copies;

    ui->book_name_label->setText(bookName);
    ui->book_author_label->setText(authorName);
    ui->book_copies_label->setText(copies);

    if (_copies.toInt() == 0) // We can't let a user checkout a book that doesn't have any copies
    {
        ui->checkoutNow->setEnabled(false);
        ui->checkoutNow->setToolTip("Checking out a book is not available while there are no copies available.");
    }
    else
    {
        ui->reserve->setEnabled(false);
        ui->reserve->setToolTip("Reserving a book is not available while there are copies remaining \n for checkout.");
    }

    connect(this, SIGNAL(UpdateCheckOutScreenSignal()), this, SLOT(UpdateCheckOutScreenSlot()));
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
}

CheckOutScreen::~CheckOutScreen()
{
    delete ui;
}

void CheckOutScreen::on_cancel_clicked()
{
    close();
}

<<<<<<< HEAD
void CheckOutScreen::get_Book_Name(QString name)
{

=======
void CheckOutScreen::on_checkoutNow_clicked()
{
    QMessageBox* confirmCheckout = new QMessageBox(nullptr);
    confirmCheckout->setWindowTitle("Yoobe Library System | Checkout Confirmation");
    confirmCheckout->setIcon(QMessageBox::Question);
    confirmCheckout->setWindowIcon(QIcon(":/images/favicon.ico"));
    confirmCheckout->setText("Are you sure you want to checkout this book?");
    confirmCheckout->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    confirmCheckout->setDefaultButton(QMessageBox::Yes);
    int result = confirmCheckout->exec();

    switch(result)
    {
    case QMessageBox::Yes:
    {
        delete(confirmCheckout);
        QString dueDate = QDate::currentDate().addDays(7).toString("dd/MM/yyyy");
        SystemFiles::CheckOutBook(_bookID, _bookName, _membersID, _membersName, dueDate);
        QMessageBox* confirmed = new QMessageBox(nullptr);
        confirmed->setWindowTitle("Yoobe Library System | Checkout Confirmed");
        confirmed->setWindowIcon(QIcon(":/images/favicon.ico"));
        confirmed->setText("You have successfully checked out " + _bookName + "!<br> "
                           "Please return by " + dueDate);
        emit UpdateUsersCurrentBooks();
        emit UpdateCatalogue();
        emit UpdateCheckOutScreenSignal();
        confirmed->exec();
    }
        close();
        break;
    case QMessageBox::Cancel:
        confirmCheckout->close();
        break;
    default: break;
    }
}

void CheckOutScreen::OpenCheckOutScreen()
{
    show();
}

void CheckOutScreen::UpdateCheckOutScreenSlot()
{
    _copies = QString::number(_copies.toInt() - 1);
    ui->book_copies_label->setText(_copies);

    if (_copies.toInt() == 0)
    {
        ui->checkoutNow->setEnabled(false);
        ui->checkoutNow->setToolTip("Checking out a book is not available while there are no copies available.");
        ui->reserve->setEnabled(true);
    }
    else
    {
        ui->reserve->setEnabled(false);
        ui->reserve->setToolTip("Reserving a book is not available while there are copies remaining \n for checkout.");
        ui->checkoutNow->setEnabled(true);
    }
}

void CheckOutScreen::Res_UpdateUsersCurrentBooks_Emitted()
{
    emit UpdateUsersCurrentBooks();
}

void CheckOutScreen::on_reserve_clicked()
{
    hide();
    _reserveBook = new ReserveBook(NULL, _membersName, _membersID, _bookID, _bookName);
    _reserveBook->setWindowTitle("Reserve a book");
    _reserveBook->showNormal();
    connect(_reserveBook, SIGNAL(ReserveScreenClosed()), this, SLOT(OpenCheckOutScreen()));
    connect(_reserveBook, SIGNAL(Res_UpdateUsersCurrentBooks()), this, SLOT(Res_UpdateUsersCurrentBooks_Emitted()));
    connect(_reserveBook, SIGNAL(CloseCheckOutScreen()), this, SLOT(on_cancel_clicked()));
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
}
