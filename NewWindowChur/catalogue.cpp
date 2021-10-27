#include "catalogue.h"
#include "ui_catalogue.h"
#include "createfiles.h"
#include <QFile>
#include <QMessageBox>
#include <QTableWidget>
#include <QVector>

Catalogue::Catalogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Catalogue)
{
    ui->setupUi(this);

    QVector<QString> catalogueData;

    // Read the CSV file and store its data into catalogueData
    if (CreateFiles::_catalogue.open(QIODevice::ReadOnly))
    {
        QTextStream in(&CreateFiles::_catalogue);

        while (!in.atEnd())
        {
            // readLine() will also read an endl or \n, so it's important to use replace() to get rid of them.
            QString line = CreateFiles::_catalogue.readLine().replace("\r\n","");
            catalogueData.append(line.split(','));
        }
    }
    else
    {
        // Displaying an error to the user if we can't open the catalogue.csv file.
        QMessageBox::warning(this, "Can not open \'catalogue.csv\'.", CreateFiles::_catalogue.errorString());
    }
    CreateFiles::_catalogue.close();

    // Creating a style sheet for when the QTableWidget is populated with data
    ui->bookCatalogue->setStyleSheet("QHeaderView::section { background-color: rgba(254, 222, 255, 0.3) }");

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
    c_ui = new CheckOutScreen(this);
    c_ui->exec();
}

