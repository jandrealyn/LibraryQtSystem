// ------------------------------------------------------------
//
// OVERDUE SCREEN
// Written by Jakob
//
// This screen is displayed after a check in the Catalogue
// constructor. If we found the user has any overdue books,
// we send that data through with this screens constructor.
// We then output the lists contents into a QTableWidget and
// let the user know that they have overdue books.
//
// ------------------------------------------------------------

#include "overdue.h"
#include "ui_overdue.h"

Overdue::Overdue(QWidget *parent, QStringList overdueBooks) :
    QDialog(parent),
    ui(new Ui::Overdue)
{
    ui->setupUi(this);

    ui->tableWidget_overdueBooks->insertColumn(ui->tableWidget_overdueBooks->columnCount());
    ui->tableWidget_overdueBooks->insertColumn(ui->tableWidget_overdueBooks->columnCount()); // We need 2 columns which is why this line appears twice
    ui->tableWidget_overdueBooks->setHorizontalHeaderLabels({"Book Name", "Due Date"});
    ui->tableWidget_overdueBooks->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget_overdueBooks->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget_overdueBooks->setSelectionMode(QHeaderView::NoSelection);

    int listIndex = 0;
    for (int i = 0; i < overdueBooks.size() / 2; i++)
    {
        ui->tableWidget_overdueBooks->insertRow(ui->tableWidget_overdueBooks->rowCount());
        for (int j = 0; j < 2; j++)
        {
            QTableWidgetItem *item = new QTableWidgetItem(QString(overdueBooks[listIndex]));
            item->setFlags(item->flags() ^ Qt::ItemIsEditable);
            ui->tableWidget_overdueBooks->setItem(i, j, item);
            listIndex++;
        }
    }
}

Overdue::~Overdue()
{
    delete ui;
}

void Overdue::on_pushButton_gotIt_clicked()
{
    close();
}

