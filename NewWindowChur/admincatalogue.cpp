#include "admincatalogue.h"
#include "ui_admincatalogue.h"
#include "createfiles.h"
#include "admineditbook.h"
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

admincatalogue::admincatalogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admincatalogue)
{
    ui->setupUi(this);

    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));

    QStringList booksData = CreateFiles::GetFileData(CSVFiles::_Catalogue);

    ui->adminCatalogue->setStyleSheet("QHeaderView::section { background-color: rgba(254, 222, 255, 0.3) }");

    // Because we have 5 columns, we insert a column 5 times
    const int arraySize = (booksData.size() / 6) - 1;
    QPushButton* push[arraySize];
    admineditbook* adminedit[arraySize];
    for (int i = 0; i < 6; i++)
    {
       ui->adminCatalogue->insertColumn(ui->adminCatalogue->columnCount());
    }
    // We have headers in our CSV file, so I use them to set the labels for the table.
    ui->adminCatalogue->setHorizontalHeaderLabels({booksData[0], booksData[1], booksData[2], booksData[3], booksData[4], booksData[5]});
    ui->adminCatalogue->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
    ui->adminCatalogue->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->adminCatalogue->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->adminCatalogue->setSelectionMode(QHeaderView::NoSelection);
    // Create the rows of the QTableWidget
    int i = 6;
    int rowCount = (booksData.size() / 6) - 1;
    for (int row = 0; row < rowCount; row++)
    {
        ui->adminCatalogue->insertRow(ui->adminCatalogue->rowCount());
        for (int col = 0; col < 6; col++)
        {
            if (booksData[i].contains(":/images")){
                ui->adminCatalogue->verticalHeader()->setSectionResizeMode(row, QHeaderView::Stretch);
                QWidget* item = new QWidget(ui->adminCatalogue);
                QString imagePath = booksData[i];
                QPixmap p(imagePath);
                QLabel* l = new QLabel(item);
                l->setPixmap(p.scaled(60,90));
                ui->adminCatalogue->setCellWidget(row, col, item);
            }
            else if (col == 5){
                QWidget* item = new QWidget(ui->adminCatalogue);
                push[row] = new QPushButton(item);
                push[row]->setText("Edit");
                push[row]->setGeometry(20,35,60,40); //Changes the size of the button and the placement
                adminedit[row] = new admineditbook(NULL, booksData[i-5], booksData[i-3], booksData[i-2], booksData[i-1]);
                adminedit[row]->setWindowTitle("Edit book");
                connect(push[row], SIGNAL(clicked()), adminedit[row], SLOT(exec()));
                ui->adminCatalogue->setCellWidget(row, col, item);
            }
            else {
             QTableWidgetItem *item = new QTableWidgetItem(QString(booksData[i]));
             ui->adminCatalogue->setItem(row, col, item);
            }
            i++;
        }
    }
}

admincatalogue::~admincatalogue()
{
    delete ui;
}

void admincatalogue::on_back_clicked()
{
    close();
    emit ClosedAdminHome();
}


void admincatalogue::on_verticalScrollBar_sliderMoved(int position)
{

}

void admincatalogue::admincatalogueUpdate(){
    QStringList booksData = CreateFiles::GetFileData(CSVFiles::_Catalogue);

    ui->adminCatalogue->setStyleSheet("QHeaderView::section { background-color: rgba(254, 222, 255, 0.3) }");

    // Because we have 5 columns, we insert a column 5 times
    const int arraySize = (booksData.size() / 6) - 1;
    QPushButton* push[arraySize];
    admineditbook* adminedit[arraySize];
    for (int i = 0; i < 6; i++)
    {
       ui->adminCatalogue->insertColumn(ui->adminCatalogue->columnCount());
    }
    // We have headers in our CSV file, so I use them to set the labels for the table.
    ui->adminCatalogue->setHorizontalHeaderLabels({booksData[0], booksData[1], booksData[2], booksData[3], booksData[4], booksData[5]});
    ui->adminCatalogue->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
    ui->adminCatalogue->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->adminCatalogue->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);
    ui->adminCatalogue->setSelectionMode(QHeaderView::NoSelection);
    // Create the rows of the QTableWidget
    int i = 6;
    int rowCount = (booksData.size() / 6) - 1;
    for (int row = 0; row < rowCount; row++)
    {
        ui->adminCatalogue->insertRow(ui->adminCatalogue->rowCount());
        for (int col = 0; col < 6; col++)
        {
            if (booksData[i].contains(":/images")){
                ui->adminCatalogue->verticalHeader()->setSectionResizeMode(row, QHeaderView::Stretch);
                QWidget* item = new QWidget(ui->adminCatalogue);
                QString imagePath = booksData[i];
                QPixmap p(imagePath);
                QLabel* l = new QLabel(item);
                l->setPixmap(p.scaled(60,90));
                ui->adminCatalogue->setCellWidget(row, col, item);
            }
            else if (col == 5){
                QWidget* item = new QWidget(ui->adminCatalogue);
                push[row] = new QPushButton(item);
                push[row]->setText("Edit");
                push[row]->setGeometry(20,35,60,40); //Changes the size of the button and the placement
                adminedit[row] = new admineditbook(NULL, booksData[i-5], booksData[i-3], booksData[i-2], booksData[i-1]);
                adminedit[row]->setWindowTitle("Edit book");
                connect(push[row], SIGNAL(clicked()), adminedit[row], SLOT(exec()));
                ui->adminCatalogue->setCellWidget(row, col, item);
            }
            else {
             QTableWidgetItem *item = new QTableWidgetItem(QString(booksData[i]));
             ui->adminCatalogue->setItem(row, col, item);
            }
            i++;
        }
    }
}

