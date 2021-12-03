<<<<<<< HEAD
#include "adminuser.h"
#include "ui_adminuser.h"

adminuser::adminuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminuser)
{
    ui->setupUi(this);
}

adminuser::~adminuser()
{
    delete ui;
}
=======
#include "adminuser.h"
#include "ui_adminuser.h"
#include "SystemFiles.h"
#include "adminedituser.h"
#include "signupscreen.h"
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
#include <QScrollBar>
//Laras Code :)
adminuser::adminuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminuser)
{
    ui->setupUi(this);
    UpdateAdminUserSlot(); //Calling user information table
}
adminuser::~adminuser()
{
    delete ui;
}
void adminuser::on_back_clicked()
{
    close();
    emit ClosedAdminHome(); //Closes admin user and reopens admin home
}
void adminuser::on_adduser_clicked()
{
    _signup = new signupscreen(nullptr); //When ad user is clicked will send admin to signup screen
    _signup->show();
    if (_signup->isVisible()){

    }
    else {
        UpdateAdminUserSlot(); //Updates the users once sign up is closed
    }
}
void adminuser::UpdateAdminUserSlot(){

    QPixmap Img(":/images/YoobeeLibraries.png"); //Setting the yoobee logo
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));

    ui->adminUser->setRowCount(0); //Resetting the row and column counts to 0
    ui->adminUser->setColumnCount(0);

    QStringList membersData = SystemFiles::GetFileData(CSVFiles::_Members); //Getting member data from csv
    ui->adminUser->setStyleSheet("QHeaderView::section { background-color: rgba(254, 222, 255, 0.3) }");

       // Because we have 9 columns, we insert a column 9 times
       for (int i = 0; i < 9; i++)
       {
          ui->adminUser->insertColumn(ui->adminUser->columnCount());
       }

       // Headers from the file are used in the table
       ui->adminUser->setHorizontalHeaderLabels({membersData[0], membersData[1], membersData[2], membersData[3], membersData[4], membersData[5], membersData[6], membersData[7], "EDIT USER"});
       ui->adminUser->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
       ui->adminUser->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
       ui->adminUser->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
       ui->adminUser->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
       ui->adminUser->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
       ui->adminUser->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Stretch);
       ui->adminUser->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);
       ui->adminUser->horizontalHeader()->setSectionResizeMode(7, QHeaderView::Stretch);
       ui->adminUser->horizontalHeader()->setSectionResizeMode(8, QHeaderView::ResizeToContents);
       ui->adminUser->setSelectionMode(QHeaderView::NoSelection);

       int i = 8;
       int rowCount = (membersData.size() / 8) - 1;
       QPushButton* push[rowCount];
       adminedituser* admineditu[rowCount];
       for (int row = 0; row < rowCount; row++)
       {
           // Create the rows of the QTableWidget
           ui->adminUser->insertRow(ui->adminUser->rowCount());
           for (int col = 0; col < 8; col++)
           {
               //If image is found in the file it will set as image in table
               if (membersData[i].contains(":/images")){
                   ui->adminUser->verticalHeader()->setSectionResizeMode(row, QHeaderView::Stretch);
                   QWidget* item = new QWidget(ui->adminUser);
                   QString imagePath = membersData[i];
                   QPixmap p(imagePath);
                   QLabel* l = new QLabel(item);
                   l->setPixmap(p.scaled(30,45));
                   ui->adminUser->setCellWidget(row, col, item);
               }
               //Sets column 7 in the table and automatically skips to column 8 to create push button
               else if (col == 7){
                   QTableWidgetItem *item = new QTableWidgetItem(QString(membersData[i]));
                   ui->adminUser->setItem(row, col, item);
                   col++;
                   if (col == 8)
                   {
                       //Push buttons are made for edit user screen
                       QWidget* item = new QWidget(ui->adminUser);
                       push[row] = new QPushButton(item);
                       push[row]->setText("Edit");
                       push[row]->setStyleSheet("QPushButton{font-size: 12px;}");
                       push[row]->setGeometry(5,5,50,40); //Changes the size of the button and the placement
                       admineditu[row] = new adminedituser(NULL, membersData[i-7], membersData[i-5], membersData[i-4], membersData[i-1], membersData[i]);
                       admineditu[row]->setWindowTitle("Edit User");
                       connect(admineditu[row], SIGNAL(UpdateAdminUser()), this, SLOT(UpdateAdminUserSlot()));
                       connect(push[row], SIGNAL(clicked()), admineditu[row], SLOT(exec()));
                       ui->adminUser->setCellWidget(row, col, item);
                   }
               }
               else {
                   //All other items are added to the table
                    QTableWidgetItem *item = new QTableWidgetItem(QString(membersData[i]));
                    ui->adminUser->setItem(row, col, item);
               }
                i++;
           }
           ui->adminUser->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
           ui->adminUser->verticalHeader()->setDefaultSectionSize(60);
       }
}
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
