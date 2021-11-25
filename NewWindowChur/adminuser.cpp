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
    QStringList membersData = SystemFiles::GetFileData(CSVFiles::_Members);

    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));
    ui->adminUser->setStyleSheet("QHeaderView::section { background-color: rgba(254, 222, 255, 0.3) }");
       // Because we have 9 columns, we insert a column 9 times
       for (int i = 0; i < 9; i++)
       {
          ui->adminUser->insertColumn(ui->adminUser->columnCount());
       }
       // We have headers in our CSV file, so I use them to set the labels for the table.
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
       ui->adminUser->verticalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
       //ui->adminUser->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
       //ui->adminUser->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
       ui->adminUser->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
       ui->adminUser->verticalHeader()->setDefaultSectionSize(20);
       // Create the rows of the QTableWidget
       int i = 8;
       int rowCount = (membersData.size() / 8) - 1;
       QPushButton* push[rowCount];
       adminedituser* admineditu[rowCount];
       qDebug() << "rowCount = " << rowCount;
       for (int row = 0; row < rowCount; row++)
       {
           ui->adminUser->insertRow(ui->adminUser->rowCount());
           for (int col = 0; col < 8; col++)
           {
               if (membersData[i].contains(":/images")){
                   qDebug() << "col = " << col;
                   ui->adminUser->verticalHeader()->setSectionResizeMode(row, QHeaderView::Stretch);
                   QWidget* item = new QWidget(ui->adminUser);
                   QString imagePath = membersData[i];
                   QPixmap p(imagePath);
                   QLabel* l = new QLabel(item);
                   l->setPixmap(p.scaled(30,45));
                   ui->adminUser->setCellWidget(row, col, item);
               }
               else if (col == 7){
                   qDebug() << " col7 == " << col;
                   QTableWidgetItem *item = new QTableWidgetItem(QString(membersData[i]));
                   ui->adminUser->setItem(row, col, item);
                   col++;
                   if (col == 8)
                   {
                       qDebug() << "col8 == " << col;
                       QWidget* item = new QWidget(ui->adminUser);
                       push[row] = new QPushButton(item);
                       push[row]->setText("Edit");
                     //  push[row]->setStyleSheet("QPushButton{font-size: 12px;}");
                     //  push[row]->setGeometry(20,35,60,40); //Changes the size of the button and the placement
                       admineditu[row] = new adminedituser(NULL, membersData[i-7], membersData[i-5], membersData[i-4], membersData[i-1], membersData[i]);
                       admineditu[row]->setWindowTitle("Edit User");
                       connect(admineditu[row], SIGNAL(UpdateAdminUser()), this, SLOT(UpdateAdminUserSlot()));
                       connect(push[row], SIGNAL(clicked()), admineditu[row], SLOT(exec()));
                       ui->adminUser->setCellWidget(row, col, item);
                   }
               }
               else {
                    QTableWidgetItem *item = new QTableWidgetItem(QString(membersData[i]));
                    ui->adminUser->setItem(row, col, item);
               }
                i++;
           }
           qDebug() << row;
       }
}


adminuser::~adminuser()
{
    delete ui;
}

void adminuser::on_back_clicked()
{
    close();
    emit ClosedAdminHome();
}


void adminuser::on_adduser_clicked()
{
    _signup = new signupscreen(nullptr);
    _signup->show();
}

void adminuser::UpdateAdminUserSlot(){
    QStringList membersData = SystemFiles::GetFileData(CSVFiles::_Members);
    ui->adminUser->setRowCount(0);
    ui->adminUser->setColumnCount(0);


        ui->adminUser->setStyleSheet("QHeaderView::section { background-color: rgba(254, 222, 255, 0.3) }");
           // Because we have 9 columns, we insert a column 9 times
           for (int i = 0; i < 9; i++)
           {
              ui->adminUser->insertColumn(ui->adminUser->columnCount());
           }
           // We have headers in our CSV file, so I use them to set the labels for the table.
           ui->adminUser->setHorizontalHeaderLabels({membersData[0], membersData[1], membersData[2], membersData[3], membersData[4], membersData[5], membersData[6], membersData[7], "EDIT USER"});
           ui->adminUser->horizontalHeader()->setSectionResizeMode(0, QHeaderView::ResizeToContents);
           ui->adminUser->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
           ui->adminUser->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
           ui->adminUser->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
           ui->adminUser->horizontalHeader()->setSectionResizeMode(4, QHeaderView::Stretch);
           ui->adminUser->horizontalHeader()->setSectionResizeMode(5, QHeaderView::Stretch);
           ui->adminUser->horizontalHeader()->setSectionResizeMode(6, QHeaderView::Stretch);
           ui->adminUser->horizontalHeader()->setSectionResizeMode(7, QHeaderView::Stretch);
           ui->adminUser->horizontalHeader()->setSectionResizeMode(8, QHeaderView::Stretch);
           ui->adminUser->setSelectionMode(QHeaderView::NoSelection);
           // Create the rows of the QTableWidget
           int i = 8;
           int rowCount = (membersData.size() / 8) - 1;
           QPushButton* push[rowCount];
           adminedituser* admineditu[rowCount];
           for (int row = 0; row < rowCount; row++)
           {
               ui->adminUser->insertRow(ui->adminUser->rowCount());
               for (int col = 0; col < 8; col++)
               {
                   if (membersData[i].contains(":/images")){
                       qDebug() << "col = " << col;
                       ui->adminUser->verticalHeader()->setSectionResizeMode(row, QHeaderView::Stretch);
                       QWidget* item = new QWidget(ui->adminUser);
                       QString imagePath = membersData[i];
                       QPixmap p(imagePath);
                       QLabel* l = new QLabel(item);
                       l->setPixmap(p.scaled(30,45));
                       ui->adminUser->setCellWidget(row, col, item);
                   }
                   else if (col == 7){
                       qDebug() << " col7 == " << col;
                       QTableWidgetItem *item = new QTableWidgetItem(QString(membersData[i]));
                       ui->adminUser->setItem(row, col, item);
                       col++;
                       if (col == 8)
                       {
                           qDebug() << "col8 == " << col;
                           QWidget* item = new QWidget(ui->adminUser);
                           push[row] = new QPushButton(item);
                           push[row]->setText("Edit");
                         //  push[row]->setStyleSheet("QPushButton{font-size: 12px;}");
                         //  push[row]->setGeometry(20,35,60,40); //Changes the size of the button and the placement
                           admineditu[row] = new adminedituser(NULL, membersData[i-7], membersData[i-5], membersData[i-4], membersData[i-1], membersData[i]);
                           admineditu[row]->setWindowTitle("Edit User");
                           connect(admineditu[row], SIGNAL(UpdateAdminUser()), this, SLOT(UpdateAdminUserSlot()));
                           connect(push[row], SIGNAL(clicked()), admineditu[row], SLOT(exec()));
                           ui->adminUser->setCellWidget(row, col, item);
                       }
                   }
                   else {
                        QTableWidgetItem *item = new QTableWidgetItem(QString(membersData[i]));
                        ui->adminUser->setItem(row, col, item);
                   }
                    i++;
               }
               qDebug() << row;
           }
}
