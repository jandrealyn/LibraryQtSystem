// ------------------------------------------------------------
//
// RESERVE BOOK
// Written by Jakob
//
// The Reserve book screen is only accessible once a book has run
// out of available copies. This allows a user to book for the book
// in advance so that they may have first dibs once a book has been
// returned.
//
// There is a set minimum and maximum date.
// The minimum date is found through a SystemFiles function, the
// maximum date is the minimum date + 14.
//
// ------------------------------------------------------------



#include "reservebook.h"
#include "ui_reservebook.h"
#include "SystemFiles.h"
#include <QDate>
#include <QMessageBox>

ReserveBook::ReserveBook(QWidget *parent, QString memName, QString memID, QString bookID, QString bookName) :
    QDialog(parent),
    ui(new Ui::ReserveBook)
{
    ui->setupUi(this);

    // Setting information
    _membersName = memName;
    _membersID = memID;
    _bookID = bookID;
    _bookName = bookName;

    // FindLastReserveDate finds the earliest that a user is able to reserve a book.
    QDate minimumDate = SystemFiles::FindLastReserveDate(_bookID);

    // Setting the minimum and maximum date
    ui->calendarWidget->setMinimumDate(minimumDate);
    ui->calendarWidget->setMaximumDate(minimumDate.addDays(14));
    ui->bookNameLabel->setText(_bookName);
    ui->returnDateLabel->setText(minimumDate.addDays(7).toString("dd/MM/yyyy"));
}

ReserveBook::~ReserveBook()
{
    delete ui;
}

void ReserveBook::on_cancel_clicked()
{
    close();
    emit ReserveScreenClosed();
}


void ReserveBook::on_calendarWidget_clicked(const QDate &date)
{
    ui->returnDateLabel->setText(date.addDays(7).toString("dd/MM/yyyy"));
    // highlight dates somehow
}


void ReserveBook::on_confirmReserve_clicked()
{
    // Creating the message box asking the user to confirm the reservation before continuing
    QMessageBox* confirmCheckout = new QMessageBox(nullptr);
    confirmCheckout->setWindowTitle("Checkout Confirmation");
    confirmCheckout->setText("Are you sure you want to checkout this book?");
    confirmCheckout->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    confirmCheckout->setDefaultButton(QMessageBox::Yes);
    int result = confirmCheckout->exec();

    // Setting the dates
    QString reserveDate = ui->calendarWidget->selectedDate().toString("dd/MM/yyyy");
    QString dueDate = ui->calendarWidget->selectedDate().addDays(7).toString("dd/MM/yyyy");

    switch(result)
    {
    case QMessageBox::Yes:
        SystemFiles::CheckOutBook(_bookID, _bookName, _membersID, _membersName, reserveDate, dueDate); //ReserveBook()
        QMessageBox::information(this, "Reservation success", "You have successfully placed a reservation for " + _bookName + "!");
        close();
        emit ReserveScreenClosed();
        emit Res_UpdateUsersCurrentBooks();
        break;
    case QMessageBox::Cancel:
        confirmCheckout->close();
        break;
    default: break;
    }
}

