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
    //Gets data from the checked out books file
    QStringList booksData = SystemFiles::GetFileData(CSVFiles::_CheckedOutBooks);
    QString date = QDate::currentDate().toString("dd/MM/yyyy");
    QDate currDate = QDate::fromString(date, "dd/MM/yyyy");
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio)); //Sets yoobee logo image
    ui->adminOverdue->setStyleSheet("QHeaderView::section { background-color: rgba(254, 222, 255, 0.3) }"); //Sets table background as white

       for (int i = 0; i < 6; i++)
       {
          ui->adminOverdue->insertColumn(ui->adminOverdue->columnCount()); //Inserts columns into the table
       }

       // We are using the headers from the file in the table
       ui->adminOverdue->setHorizontalHeaderLabels({booksData[0], booksData[1], booksData[2], booksData[3], booksData[4], booksData[5]});
       ui->adminOverdue->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
       ui->adminOverdue->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
       ui->adminOverdue->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
       ui->adminOverdue->setSelectionMode(QHeaderView::NoSelection);

       // Create the rows of the QTableWidget
       int i = 7; //Skips the headers
       int h = 0; //Initializes h as 0, the rows
       int rowCount = (booksData.size() / 7) - 1;
       for (int row = 0; row < rowCount; row++)
       {
           QDate bookDueDate = QDate::fromString(booksData[i + 5], "dd/MM/yyyy"); //Setting our book due date as the date from the file

           if (currDate > bookDueDate){
               qDebug() << "inserting" << booksData[i+5];
            ui->adminOverdue->insertRow(ui->adminOverdue->rowCount()); //Inserting rows into the table widget if current date is greater than due date
            for (int col = 0; col < 7; col++)
            {
                  if (col == 6){
                      i++; //Skipping push button
                     }
                     else {
                          QTableWidgetItem *item = new QTableWidgetItem(QString(booksData[i])); //Sets item from the book list into the table widget
                          ui->adminOverdue->setItem((row - h), col, item);
                         i++;
                      }

                }
           }
           else {
               qDebug() << "skipping" << booksData[i+5];
               i = i + 7; //All items skipped
               h = h + 1; //Row has passed
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

