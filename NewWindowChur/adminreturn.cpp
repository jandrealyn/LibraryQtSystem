#include "adminreturn.h"
#include "ui_adminreturn.h"
#include "SystemFiles.h"
#include <QWidget>
#include <QDebug>
#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QTableWidget>
#include <QStringList>
#include <QItemSelectionModel>
#include <QFormLayout>
#include <QFrame>
#include <QScrollArea>
#include <QGroupBox>
#include <QPushButton>

adminreturn::adminreturn(QWidget *parent, QString bookID, QString bookName, QString memberName) :
    QDialog(parent),
    ui(new Ui::adminreturn)
{
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(100, 100, Qt::KeepAspectRatio));

    id = bookID; //Setting variables passed form admin checked out screen

    ui->return_name->setText(bookName);
    ui->return_member->setText(memberName);

    connect(this, SIGNAL(UpdateAdminReturn()), this, SLOT(UpdateAdminReturnSlot())); //Connects this screen with update admin return
}

adminreturn::~adminreturn()
{
    delete ui;
}

void adminreturn::on_yesreturn_clicked()
{
    SystemFiles::ReturnBook(id); //Deletes book from checked out file and adds a copy onto the catalogue file book
    emit UpdateAdminReturn();
    close();
    emit exec(); //Closes this screen
}


void adminreturn::on_noreturn_clicked()
{
    close();
    emit exec(); //Closes this screen
}

