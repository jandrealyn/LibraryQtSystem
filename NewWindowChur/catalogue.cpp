#include "catalogue.h"
#include "ui_catalogue.h"
#include "createfiles.h"
#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QTableWidget>
#include <QStringList>
#include <QItemSelectionModel>

Catalogue::Catalogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Catalogue)
{
    ui->setupUi(this);

    // Creating a style sheet for when the QTableWidget is populated with data
    ui->bookCatalogue->setStyleSheet("QHeaderView::section { background-color: rgba(254, 222, 255, 0.3) }");

    // Get data from the catalogue file
    QStringList catalogueData = CreateFiles::GetFileData("catalogue");
    if (catalogueData.empty())
    {
        QMessageBox::warning(this, "Can not open \'catalogue.csv\'.", CreateFiles::_catalogue.errorString());
    }

    // Because we have 5 columns, we insert a column 5 times
    for (int i = 0; i < 5; i++)
    {   
       ui->bookCatalogue->insertColumn(ui->bookCatalogue->columnCount());
    }

    // We have headers in our CSV file, so I use them to set the labels for the table.
    ui->bookCatalogue->setHorizontalHeaderLabels({catalogueData[0], catalogueData[1], catalogueData[2], catalogueData[3], catalogueData[4]});
    ui->bookCatalogue->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
    ui->bookCatalogue->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->bookCatalogue->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->bookCatalogue->setSelectionMode(QHeaderView::NoSelection);

    // Create the rows of the QTableWidget
    int i = 5;
    int rowCount = (catalogueData.size() / 5) - 1;
    for (int row = 0; row < rowCount; row++)
    {
        ui->bookCatalogue->insertRow(ui->bookCatalogue->rowCount());
        for (int col = 0; col < 5; col++)
        {
            QTableWidgetItem *item = new QTableWidgetItem(QString(catalogueData[i]));
            ui->bookCatalogue->setItem(row, col, item);
            i++;
        }
    }

    // Make the items non editable
    ui->bookCatalogue->setEditTriggers(ui->bookCatalogue->NoEditTriggers);

    // Make the headers not able to be clicked
    //ui->bookCatalogue->setSelectionModel(QItemSelectionModel::NoUpdate);

    QPixmap img(":/images/yoobee-logo.png");
    ui->yoobeeLogo->setPixmap(img);


    // TEST
    // horizontal layout
    ui->scrollArea->setWidgetResizable(true);
    QHBoxLayout *const layout(new QHBoxLayout(ui->scrollArea));
    for (int i = 0; i < 3; i++)
    {
        QLabel* l = new QLabel(this);
        layout->addWidget(l);
        ui->scrollArea->addScrollBarWidget(l, Qt::Alignment(Qt::AlignLeft));
    }
}

Catalogue::~Catalogue()
{
    delete ui;
}

void Catalogue::on_yourAccount_logout_clicked()
{
    close();
    emit ClosedMainMenu();
}


void Catalogue::on_checkOutButton_clicked()
{
    c_ui = new CheckOutScreen(nullptr);
    c_ui->exec();
}


void Catalogue::on_searchBar_textChanged(const QString &arg1)
{
    QStringList catalogueData = CreateFiles::GetFileData("catalogue");

    int i = 5;
    int rowCount = (catalogueData.size() / 5) - 1;
    for (int row = 0; row < rowCount; row++)
    {
        ui->bookCatalogue->insertRow(ui->bookCatalogue->rowCount());
        for (int col = 0; col < 5; col++)
        {
            QTableWidgetItem *item = new QTableWidgetItem(QString(catalogueData[i]));
            ui->bookCatalogue->setItem(row, col, item);
            i++;
        }
    }
}

