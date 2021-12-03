#include "adminedituser.h"
#include "ui_adminedituser.h"
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

adminedituser::adminedituser(QWidget *parent, QString id, QString fn, QString ln, QString email, QString phn) :
    QDialog(parent),
    ui(new Ui::adminedituser)
{
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(100, 100, Qt::KeepAspectRatio));


    _userid = id; //Sets our variables that were passed from admin user screen
    ui->admin_first_user->setText(fn);
    ui->admin_last_user->setText(ln);
    ui->admin_email_user->setText(email);
    ui->admin_phone_user->setText(phn);

    connect(this, SIGNAL(UpdateAdminUser()), this, SLOT(UpdateAdminUserSlot())); //Connects this screen with update admin user
}

adminedituser::~adminedituser()
{
    delete ui;
}

void adminedituser::on_deleteuser_clicked()
{
    QMessageBox msgBox; //Checks if admin would like to delete
    msgBox.setWindowTitle(tr("Delete User"));
    msgBox.setText(tr("Proceed with deleting user?"));
    QAbstractButton* edit = msgBox.addButton(tr("Yes"), QMessageBox::YesRole);
    msgBox.addButton(tr("No"), QMessageBox::NoRole);
    msgBox.exec();

    if (msgBox.clickedButton()==edit){
            SystemFiles::DeleteUser(_userid); //Replaces all users in file except this user
            emit UpdateAdminUser(); //Updates admin user table
            close();
            emit exec();
        }

    else {
    //if no clicked
    }
}


void adminedituser::on_canceledit_clicked()
{
    close();
    emit exec(); //Closes window
}


void adminedituser::on_confimedit_clicked()
{
    QMessageBox msgBox; //Checks if admin would like to continue
    msgBox.setWindowTitle(tr("Edit User"));
    msgBox.setText(tr("Proceed with editing User?"));
    QAbstractButton* edit = msgBox.addButton(tr("Yes"), QMessageBox::YesRole);
    msgBox.addButton(tr("No"), QMessageBox::NoRole);
    msgBox.exec();

    if (msgBox.clickedButton()==edit){
            QStringList userData = SystemFiles::GetFileData(CSVFiles::_Members);
            int rowCount = (userData.size() / 8) - 1;
            int i = 8;
            for (int row = 0; row < rowCount; row++)
            {
                for (int col = 0; col < 8; col++)
                {
                    if (userData[i] == _userid){
                        QString firstn = ui->admin_first_user->text();
                        QString lastn = ui->admin_last_user->text();
                        QString email = ui->admin_email_user->text();
                        QString phone = ui->admin_phone_user->text();
                        userData[i+2] = firstn;
                        userData[i+3] = lastn;
                        userData[i+6] = email;
                        userData[i+7] = phone;
                    }
                    i++;
                }
            }
            SystemFiles::EditUser(userData); //Replaces all data with the new row
            emit UpdateAdminUser(); //Updates admin user table
            close();
            emit exec();
        }

    else {
    //if no clicked
    }
}

