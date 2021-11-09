#include "reservebook.h"
#include "ui_reservebook.h"
#include "createfiles.h"
#include <QDate>

ReserveBook::ReserveBook(QWidget *parent, QString memName, QString memID, QString bookID, QString bookName) :
    QDialog(parent),
    ui(new Ui::ReserveBook)
{
    ui->setupUi(this);

    _membersName = memName;
    _membersID = memID;
    _bookID = bookID;
    _bookName = bookName;
    ui->calendarWidget->setMinimumDate(QDate::currentDate());
    ui->bookNameLabel->setText(_bookName);
    ui->returnDateLabel->setText("Your selected date + 7 days.");
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
    bool yesChecked = false;

    QMessageBox* confirmCheckout = new QMessageBox(nullptr);
    confirmCheckout->setWindowTitle("Checkout Confirmation");
    confirmCheckout->setText("Are you sure you want to checkout this book?");
    confirmCheckout->setStandardButtons(QMessageBox::Yes | QMessageBox::Cancel);
    confirmCheckout->setDefaultButton(QMessageBox::Yes);
    int result = confirmCheckout->exec();

    QString reserveDate = ui->calendarWidget->selectedDate().toString("dd/MM/yyyy");
    QString dueDate = ui->calendarWidget->selectedDate().addDays(7).toString("dd/MM/yyyy");

    switch(result)
    {
    case QMessageBox::Yes:
        CreateFiles::CheckOutBook(_bookID, _bookName, _membersID, _membersName, reserveDate, dueDate); //ReserveBook()
        yesChecked = true;
        break;
    case QMessageBox::Cancel:
        confirmCheckout->close();
        break;
    default: break;
    }
}

