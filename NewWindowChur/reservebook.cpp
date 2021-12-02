// ------------------------------------------------------------
//
// RESERVE BOOK SCREEN
// Written by Jakob
//
// The Reserve book screen is opened when a user clicks checkout
// on a book with 0 copies. The main functionality of this screen
// is through the Calendar Widget.
//
// Once a user confirms they want to confirm a book, we write
// all the necessary information into the reserveBook.csv.
//
// There is a function in main that moves reserved books into
// the checkedOutBooks file once they have met the date the user
// chose to check them out.
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

    QDate minimumDate = SystemFiles::FindLastReserveDate(_bookID);
    ui->calendarWidget->setMinimumDate(minimumDate);
    ui->calendarWidget->setMaximumDate(minimumDate.addDays(14)); // Setting maximum date to be 2 weeks infront of the minimum date
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
}

void ReserveBook::on_confirmReserve_clicked()
{
    // Creating the message box asking the user to confirm the reservation before continuing
    QMessageBox* confirmCheckout = new QMessageBox(nullptr);
    confirmCheckout->setWindowTitle("Yoobee Library System | Reservation Confirmation");
    confirmCheckout->setWindowIcon(QIcon(":/images/favicon.ico"));
    confirmCheckout->setIcon(QMessageBox::Question);
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
    {
        delete(confirmCheckout);
        SystemFiles::CheckOutBook(_bookID, _bookName, _membersID, _membersName, reserveDate, dueDate); //ReserveBook()
        QMessageBox* confirmed = new QMessageBox(nullptr);
        confirmed->setWindowTitle("Yoobee Library System | Reservation Confirmed");
        confirmed->setWindowIcon(QIcon(":/images/favicon.ico"));
        confirmed->setText("You have successfully placed a reservation for " + _bookName + "!");
        confirmed->exec();
        close();
        emit ReserveScreenClosed();
        emit Res_UpdateUsersCurrentBooks();
    }
        break;
    case QMessageBox::Cancel:
        confirmCheckout->close();
        break;
    default: break;
    }
}
