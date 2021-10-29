#include "catalogue.h"
#include "ui_catalogue.h"
#include "createfiles.h"
#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QTableWidget>
#include <QStringList>
#include <QItemSelectionModel>
#include <QFormLayout>
#include <QLine>

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
    QWidget* testTab = new QWidget(ui->Test);

    QVBoxLayout *rootLayout = new QVBoxLayout(testTab);
    QHBoxLayout *subLayout1 = new QHBoxLayout();
    QHBoxLayout *subLayout2 = new QHBoxLayout();

    rootLayout->addLayout(subLayout1);
    rootLayout->addLayout(subLayout2);

    QPixmap p(":/images/book-cover.png");
    QLabel* l = new QLabel;
    l->setPixmap(p.scaled(90, 120));

    QPixmap x(":/images/blue-book.jpg");
    QLabel* a = new QLabel;
    a->setPixmap(x.scaled(90, 120));

    QLabel* t = new QLabel;
    t->setText("my new label");
    QLabel* b = new QLabel;
    b->setText("the second label");

    QPushButton* push1 = new QPushButton;
    push1->setText("this is a push button");

    QPushButton* push2 = new QPushButton;
    push2->setText("this is a 2nd push button");

    subLayout1->addWidget(l);
    subLayout1->addWidget(t);
    subLayout1->addWidget(push1);
    subLayout1->setContentsMargins(10, 0, 0, 40);

    subLayout2->addWidget(a);
    subLayout2->addWidget(b);
    subLayout2->addWidget(push2);
    subLayout2->setContentsMargins(10, 0, 0, 40);
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
    QStringList foundData;

    if (CreateFiles::_catalogue.open(QIODevice::ReadOnly))
    {
        QTextStream in(&CreateFiles::_catalogue);
        while(!in.atEnd())
        {
            QString line = CreateFiles::_catalogue.readLine().replace("\r\n","");
            if (!line.contains("BOOK"))
            {
                if (line.toLower().contains(arg1.toLower()))
                {
                    foundData.append(line.split(','));
                }
            }
        }
    }
    CreateFiles::_catalogue.close();

    for (int i = 0; i < foundData.size(); i++)
    {
        qDebug() << foundData[i];
    }

    ui->bookCatalogue->setRowCount(0);

    int b = 0;
    int rowCount = (foundData.size() / 5);
    for (int row = 0; row < rowCount; row++)
    {
        ui->bookCatalogue->insertRow(ui->bookCatalogue->rowCount());
        for (int col = 0; col < 5; col++)
        {
            QTableWidgetItem *item = new QTableWidgetItem(QString(foundData[b]));
            ui->bookCatalogue->setItem(row, col, item);
            b++;
        }
    }
}

void Catalogue::on_addBook_clicked()
{

}

