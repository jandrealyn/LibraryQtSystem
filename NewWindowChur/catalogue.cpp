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

    // Get the data from the catalogue file
    QVector<QString> catalogueData;

    if (CreateFiles::_catalogue.open(QIODevice::ReadOnly))
    {
        QTextStream in(&CreateFiles::_catalogue);

        while (!in.atEnd())
        {
            QString line = CreateFiles::_catalogue.readLine().replace("\r\n","");
            catalogueData.append(line.split(','));
        }
    }
    else
    {
        QMessageBox::warning(this, "Can not open \'catalogue.csv\'.", CreateFiles::_catalogue.errorString());
    }
    CreateFiles::_catalogue.close();

    // Create the columns of the QTableWidget

    // CHANGE COLOUR OF TABLE HEADERS
    ui->bookCatalogue->setStyleSheet("QHeaderView::section { background-color: rgba(254, 222, 255, 0.3) }");

    QStringList colHeaders = {catalogueData[0], catalogueData[1], catalogueData[2], catalogueData[3], catalogueData[4]};
    for (int i = 0; i < 5; i++)
    {
       ui->bookCatalogue->insertColumn(ui->bookCatalogue->columnCount());
    }
    ui->bookCatalogue->setHorizontalHeaderLabels(colHeaders);

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

