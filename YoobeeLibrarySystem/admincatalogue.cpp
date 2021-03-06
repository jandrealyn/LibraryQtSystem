#include "admincatalogue.h"
#include "ui_admincatalogue.h"
#include "SystemFiles.h"
#include "admineditbook.h"
#include "adminaddbook.h"
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

admincatalogue::admincatalogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admincatalogue)
{
    ui->setupUi(this);

    UpdateAdminCatalogueSlot(); //Calls the admin catalogue function
}

admincatalogue::~admincatalogue()
{
    delete ui;
}

void admincatalogue::on_back_clicked()
{
    //Once back is clicked will open admin home and close admin catalogue
    close();
    emit ClosedAdminHome();
}


void admincatalogue::on_addbook_clicked()
{
    //Opens add book window
    adminaddbook* adminadd;
    adminadd = new adminaddbook;
    connect(adminadd, SIGNAL(UpdateAdminCatalogue()), this, SLOT(UpdateAdminCatalogueSlot()));
    adminadd->setWindowTitle("Add book");
    adminadd->show();
}

void admincatalogue::UpdateAdminCatalogueSlot() {
    //Creates the catalogue
    QPixmap Img(":/images/YoobeeLibraries.png"); //Setting the yoobee logo
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));
    ui->adminCatalogue->setRowCount(0);
    ui->adminCatalogue->setColumnCount(0);

    QStringList booksData = SystemFiles::GetFileData(CSVFiles::_Catalogue); //Getting the catalogue data from the file

    ui->adminCatalogue->setStyleSheet("QHeaderView::section { background-color: rgba(254, 222, 255, 0.3) }"); //Designing our table widget with a white background

    // Creating our array size from the catalogue data size
    const int arraySize = (booksData.size() / 6) - 1;
    QPushButton* push[arraySize];
    admineditbook* adminedit[arraySize];
    for (int i = 0; i < 6; i++)
    {
       ui->adminCatalogue->insertColumn(ui->adminCatalogue->columnCount()); //Inserting columns into the table widget
    }

    // Headers in the file are used for the table
    ui->adminCatalogue->setHorizontalHeaderLabels({booksData[0], booksData[1], booksData[2], booksData[3], booksData[4], booksData[5]});
    ui->adminCatalogue->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
    ui->adminCatalogue->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->adminCatalogue->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->adminCatalogue->setSelectionMode(QHeaderView::NoSelection);

    // Create the rows of the QTableWidget
    int i = 6;
    int rowCount = (booksData.size() / 6) - 1;
    for (int row = 0; row < rowCount; row++)
    {
        ui->adminCatalogue->insertRow(ui->adminCatalogue->rowCount());
        for (int col = 0; col < 6; col++)
        {
            //Setting the image if one is found in the data
            if (booksData[i].contains(":/images")){
                ui->adminCatalogue->verticalHeader()->setSectionResizeMode(row, QHeaderView::Stretch);
                QWidget* item = new QWidget(ui->adminCatalogue);
                QString imagePath = booksData[i];
                QPixmap p(imagePath);
                QLabel* l = new QLabel(item);
                l->setPixmap(p.scaled(60,90));
                ui->adminCatalogue->setCellWidget(row, col, item);
            }
            //Creating a push button for each book and connecting them to admin edit screen
            else if (col == 5){
                QWidget* item = new QWidget(ui->adminCatalogue);
                push[row] = new QPushButton(item);
                push[row]->setText("Edit");
                push[row]->setGeometry(20,25,60,40); //Changes the size of the button and the placement
                adminedit[row] = new admineditbook(NULL, booksData[i-5], booksData[i-3], booksData[i-2], booksData[i-1]);
                adminedit[row]->setWindowTitle("Edit book");
                connect(adminedit[row], SIGNAL(UpdateAdminCatalogue()), this, SLOT(UpdateAdminCatalogueSlot()));
                connect(push[row], SIGNAL(clicked()), adminedit[row], SLOT(exec()));
                ui->adminCatalogue->setCellWidget(row, col, item);
            }
            //Pushing all other data into the table
            else {
             QTableWidgetItem *item = new QTableWidgetItem(QString(booksData[i]));
             ui->adminCatalogue->setItem(row, col, item);
            }
            i++;
        }
        ui->adminCatalogue->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
        ui->adminCatalogue->verticalHeader()->setDefaultSectionSize(90);
    }

}

