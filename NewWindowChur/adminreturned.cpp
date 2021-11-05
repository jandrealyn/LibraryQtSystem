#include "adminreturned.h"
#include "ui_adminreturned.h"
#include "createfiles.h"
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

adminreturned::adminreturned(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminreturned)
{
        QStringList booksData = CreateFiles::GetFileData(CSVFiles::_Catalogue);
        ui->setupUi(this);
        QPixmap Img(":/images/YoobeeLibraries.png");
        ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));

        ui->adminReturned->setStyleSheet("QHeaderView::section { background-color: rgba(254, 222, 255, 0.3) }");
           // Because we have 5 columns, we insert a column 5 times
           for (int i = 0; i < 5; i++)
           {
              ui->adminReturned->insertColumn(ui->adminReturned->columnCount());
           }
           // We have headers in our CSV file, so I use them to set the labels for the table.
           ui->adminReturned->setHorizontalHeaderLabels({booksData[0], booksData[1], booksData[2], booksData[3], booksData[4]});
           ui->adminReturned->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
           ui->adminReturned->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
           ui->adminReturned->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
           ui->adminReturned->setSelectionMode(QHeaderView::NoSelection);
           // Create the rows of the QTableWidget
           int i = 5;
           int rowCount = (booksData.size() / 5) - 1;
           for (int row = 0; row < rowCount; row++)
           {
               ui->adminReturned->insertRow(ui->adminReturned->rowCount());
               for (int col = 0; col < 5; col++)
               {
                   QTableWidgetItem *item = new QTableWidgetItem(QString(booksData[i]));
                   ui->adminReturned->setItem(row, col, item);
                   i++;
               }
           }


}

adminreturned::~adminreturned()
{
    delete ui;
}

void adminreturned::on_back_clicked()
{
    close();
    emit ClosedAdminSystem();
}

