#include "reservebook.h"
#include "ui_reservebook.h"
#include <QDate>

ReserveBook::ReserveBook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReserveBook)
{
    ui->setupUi(this);
    ui->calendarWidget->setMinimumDate(QDate::currentDate());
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

