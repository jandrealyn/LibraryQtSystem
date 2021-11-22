#include "adminoverdue.h"
#include "ui_adminoverdue.h"
#include "SystemFiles.h"
#include <QDebug>
#include <QDate>
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

//Laras Code :)

adminoverdue::adminoverdue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminoverdue)
{
    QStringList booksData = SystemFiles::GetFileData(CSVFiles::_CheckedOutBooks);
    QString date = QDate::currentDate().toString("dd.MM.yyyy");
    QDate currDate = QDate::fromString(date, "dd.MM.yyyy");
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));
    ui->adminOverdue->setStyleSheet("QHeaderView::section { background-color: rgba(254, 222, 255, 0.3) }");

       for (int i = 0; i < 6; i++)
       {
          ui->adminOverdue->insertColumn(ui->adminOverdue->columnCount());
       }
       // We have headers in our CSV file, so I use them to set the labels for the table.
       ui->adminOverdue->setHorizontalHeaderLabels({booksData[0], booksData[1], booksData[2], booksData[3], booksData[4], booksData[5]});
       ui->adminOverdue->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
       ui->adminOverdue->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
       ui->adminOverdue->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
       ui->adminOverdue->setSelectionMode(QHeaderView::NoSelection);
       // Create the rows of the QTableWidget
       int i = 7;
       int rowCount = (booksData.size() / 7) - 1;
       for (int row = 0; row < rowCount; row++)
       {
           QDate bookDueDate = QDate::fromString(booksData[i + 5], "dd.MM.yyyy");
           if (currDate > bookDueDate){
            ui->adminOverdue->insertRow(ui->adminOverdue->rowCount()); //Inserting rows into the table widget
           }
           for (int col = 0; col < 7; col++)
           {
               if (currDate > bookDueDate){
                 if (col == 6){
                     i++; //Skipping push button
                    }
                    else {
                         QTableWidgetItem *item = new QTableWidgetItem(QString(booksData[i])); //Sets item from the book list into the table widget
                         ui->adminOverdue->setItem(row, col, item);
                        i++;
                     }

               }
               else {
                   i++; //Skips everything that isnt apart of an overdue book
               }

           }

       }

}

adminoverdue::~adminoverdue()
{
    delete ui;
}

void adminoverdue::on_back_clicked()
{
    close();
    emit ClosedAdminSystem(); //Reopening admin system screen on back clicked
}

