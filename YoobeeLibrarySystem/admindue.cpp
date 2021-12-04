#include "admindue.h"
#include "ui_admindue.h"
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

//Laras Code :)

admindue::admindue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admindue)
{
    ui->setupUi(this);
    UpdateAdminReturnSlot(); //Calls checkedout books table
}

admindue::~admindue()
{
    delete ui;
}

void admindue::on_back_clicked()
{
    close();
    emit ClosedAdminSystem(); //Closes admin check out and reopend admin system
}


void admindue::UpdateAdminReturnSlot(){
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio)); //Sets yoobee logo
    ui->adminDue->setRowCount(0);
    ui->adminDue->setColumnCount(0); //Resets rows and columns to 0

    QStringList booksData = SystemFiles::GetFileData(CSVFiles::_CheckedOutBooks); //Gets data from the file for checked out books


    ui->adminDue->setStyleSheet("QHeaderView::section { background-color: rgba(254, 222, 255, 0.3) }"); //Setting the table to have a white background

       // Because we have 7 columns, we insert a column 7 times
       for (int i = 0; i < 7; i++)
       {
          ui->adminDue->insertColumn(ui->adminDue->columnCount());
       }

       // Headers in the file are used in the table
       ui->adminDue->setHorizontalHeaderLabels({booksData[0], booksData[1], booksData[2], booksData[3], booksData[4], booksData[5], booksData[6]});
       ui->adminDue->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
       ui->adminDue->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
       ui->adminDue->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
       ui->adminDue->setSelectionMode(QHeaderView::NoSelection);

       // Create the rows of the QTableWidget
       int i = 7;
       int rowCount = (booksData.size() / 7) - 1;
       QPushButton* push[rowCount];
       adminreturn* ret[rowCount];
       for (int row = 0; row < rowCount; row++)
       {
           ui->adminDue->insertRow(ui->adminDue->rowCount());
           for (int col = 0; col < 7; col++)
           {
               if (col == 6){
                   //Creates a push button that sends the user to a return screen
                   QWidget* item = new QWidget(ui->adminDue);
                   push[row] = new QPushButton(item);
                   push[row]->setText("Return");
                   push[row]->setGeometry(23,5,50,20); //Changes the size of the button and the placement
                   ret[row] = new adminreturn(NULL, booksData[i-6], booksData[i-5], booksData[i-3], booksData[i-4]);
                   ret[row]->setWindowTitle("Return book");
                   connect(ret[row], SIGNAL(UpdateAdminReturn()), this, SLOT(UpdateAdminReturnSlot()));
                   connect(push[row], SIGNAL(clicked()), ret[row], SLOT(exec()));
                   ui->adminDue->setCellWidget(row, col, item);
                   i++;
               }
               else {
                   //Pushes all other items into the table
                   QTableWidgetItem *item = new QTableWidgetItem(QString(booksData[i]));
                   ui->adminDue->setItem(row, col, item);
                   i++;
               }
           }
       }
}
//
