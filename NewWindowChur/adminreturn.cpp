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

    id = bookID;

    ui->return_name->setText(bookName);
    ui->return_member->setText(memberName);

    connect(this, SIGNAL(UpdateAdminReturn()), this, SLOT(UpdateAdminReturnSlot()));
}

adminreturn::~adminreturn()
{
    delete ui;
}

void adminreturn::on_yesreturn_clicked()
{
    SystemFiles::ReturnBook(id);
    emit UpdateAdminReturn();
    close();
    emit exec();
}


void adminreturn::on_noreturn_clicked()
{
    close();
    emit exec();
}

