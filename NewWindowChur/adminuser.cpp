#include "adminuser.h"
#include "ui_adminuser.h"
#include "SystemFiles.h"
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

adminuser::adminuser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminuser)

{
    QStringList membersData = SystemFiles::GetFileData(CSVFiles::_Members);
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));

    ui->adminUser->setStyleSheet("QHeaderView::section { background-color: rgba(254, 222, 255, 0.3) }");
       // Because we have 5 columns, we insert a column 5 times
       for (int i = 0; i < 5; i++)
       {
          ui->adminUser->insertColumn(ui->adminUser->columnCount());
       }
       // We have headers in our CSV file, so I use them to set the labels for the table.
       ui->adminUser->setHorizontalHeaderLabels({membersData[0], membersData[1], membersData[2], membersData[3], membersData[4]});
       ui->adminUser->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
       ui->adminUser->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
       ui->adminUser->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
       ui->adminUser->setSelectionMode(QHeaderView::NoSelection);
       // Create the rows of the QTableWidget
       int i = 5;
       int rowCount = (membersData.size() / 5) - 1;
       for (int row = 0; row < rowCount; row++)
       {
           ui->adminUser->insertRow(ui->adminUser->rowCount());
           for (int col = 0; col < 5; col++)
           {
               QTableWidgetItem *item = new QTableWidgetItem(QString(membersData[i]));
               ui->adminUser->setItem(row, col, item);
               i++;
           }
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

