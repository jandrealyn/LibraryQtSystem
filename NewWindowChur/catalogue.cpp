#include "catalogue.h"
#include "ui_catalogue.h"
#include "createfiles.h"
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
            if (catalogueData[i].contains(":/images"))
            {
                QWidget* item = new QWidget(ui->bookCatalogue);
                QString imagePath = catalogueData[i];
                QPixmap p(imagePath);
                QLabel* l = new QLabel(item);
                l->setPixmap(p.scaled(90,120));
                ui->bookCatalogue->setCellWidget(row, col, item);
            }
            else if (catalogueData[i] == "checkoutbtn")
            {
                QWidget* item = new QWidget(ui->bookCatalogue);
                QPushButton* push = new QPushButton(item);
                push->setText("button");
                connect(push, SIGNAL(clicked()), this, SLOT(mySlot()));
                ui->bookCatalogue->setCellWidget(row, col, item);
            }
            else
            {
                QTableWidgetItem *item = new QTableWidgetItem(QString(catalogueData[i]));
                ui->bookCatalogue->setItem(row, col, item);
            }
            i++;
        }
        ui->bookCatalogue->verticalHeader()->setDefaultSectionSize(120);
        ui->bookCatalogue->verticalHeader()->sectionResizeMode(QHeaderView::Fixed);
    }


    // Make the items non editable
    ui->bookCatalogue->setEditTriggers(ui->bookCatalogue->NoEditTriggers);

    // Make the headers not able to be clicked
    //ui->bookCatalogue->setSelectionModel(QItemSelectionModel::NoUpdate);

    QPixmap img(":/images/yoobee-logo.png");
    ui->yoobeeLogo->setPixmap(img);

    // Array control
    QStringList catalogueTest = CreateFiles::GetFileData("catalogueTest");
    const int arraySize = (catalogueTest.size() / 4) - 1;

    // LAYOUTS
    QGroupBox* groupBox = new QGroupBox;
    QFormLayout* formLayout = new QFormLayout();
    groupBox->setLayout(formLayout);


    QFrame* lines1[arraySize];
    QFrame* lines2[arraySize];
    QLabel* bookImage[arraySize];
    QLabel* bookName[arraySize];
    QLabel* bookAuthor[arraySize];
    QLabel* bookCopies[arraySize];
    QPushButton* checkoutButton[arraySize];

    int t = 4;
    // Initalize all widgets
    for (int row = 0; row < arraySize; row++)
    {
        // Book image
        QString imagePath = catalogueTest[t];
        QPixmap p(imagePath);
        bookImage[row] = new QLabel;
        bookImage[row]->setPixmap(p.scaled(90, 120));

        // Book name
        bookName[row] = new QLabel;
        bookName[row]->setText("Book name: " + catalogueTest[t + 1]);

        // Book authour
        bookAuthor[row] = new QLabel;
        bookAuthor[row]->setText("Author: " + catalogueTest[t + 2]);

        // Book copies
        bookCopies[row] = new QLabel;
        bookCopies[row]->setText("Copies: " + catalogueTest[t + 3]);

        // Checkout button
        const QSize btnSize = QSize(80, 25);
        checkoutButton[row] = new QPushButton;
        checkoutButton[row]->setText("Checkout");
        checkoutButton[row]->setFixedSize(btnSize);
        checkoutButton[row]->setStyleSheet("border: 1px solid black;");

        // Horizontal Lines
        lines1[row] = new QFrame();
        lines1[row]->setLineWidth(1);
        lines1[row]->setFrameShape(QFrame::HLine);
        lines1[row]->setFrameShadow(QFrame::Sunken);

        lines2[row] = new QFrame();
        lines2[row]->setLineWidth(1);
        lines2[row]->setFrameShape(QFrame::HLine);
        lines2[row]->setFrameShadow(QFrame::Sunken);

        t = t + 4;
    }

    // Add all of the widgets into the layouts
    for (int row = 0; row < arraySize; row++)
    {
        formLayout->setWidget(row, QFormLayout::LabelRole, bookImage[row]);

        QVBoxLayout* verticalLayout = new QVBoxLayout();
        formLayout->setLayout(row, QFormLayout::FieldRole, verticalLayout);

        verticalLayout->addWidget(lines1[row]);
        verticalLayout->addWidget(bookName[row]);
        verticalLayout->addWidget(bookAuthor[row]);
        verticalLayout->addWidget(bookCopies[row]);
        verticalLayout->addWidget(checkoutButton[row]);
        verticalLayout->addWidget(lines2[row]);
        formLayout->setContentsMargins(10, 5, 0, 5);
        formLayout->setVerticalSpacing(30);
    }

    ui->scrollArea->setWidget(groupBox);
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

// Search bar functionality
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
            if (foundData[b].contains(":/images"))
            {
                qDebug("contains :/images");

                QWidget* item = new QWidget(ui->bookCatalogue);
                QString imagePath = foundData[b];
                QPixmap p(imagePath);
                QLabel* l = new QLabel(item);
                l->setPixmap(p.scaled(90,120));
                ui->bookCatalogue->setCellWidget(row, col, item);
            }
            if (foundData[b] == "checkoutbtn")
            {
                QWidget* item = new QWidget(ui->bookCatalogue);
                QPushButton* push1 = new QPushButton(item);
                push1->setText("button");
                ui->bookCatalogue->setCellWidget(row, col, item);
            }
            else
            {
                QTableWidgetItem *item = new QTableWidgetItem(QString(foundData[b]));
                ui->bookCatalogue->setItem(row, col, item);
            }
            b++;
        }
    }
}

void Catalogue::on_addBook_clicked()
{

}

void Catalogue::mySlot()
{
    c_ui = new CheckOutScreen(this);
    c_ui->show();
    int asfd = ui->bookCatalogue->currentRow();
    int f = ui->bookCatalogue->currentColumn();
    qDebug() << "row: " << asfd << " col: " << f;
}


void Catalogue::on_lineEdit_textChanged(const QString &arg1)
{
    QStringList foundData;

    if (CreateFiles::_catalogueTest.open(QIODevice::ReadOnly))
    {
        QTextStream in(&CreateFiles::_catalogueTest);
        while(!in.atEnd())
        {
            QString line = CreateFiles::_catalogueTest.readLine().replace("\r\n","");
            if (!line.contains("IMAGE, BOOK NAME, AUTHOR, COPIES"))
            {
                if (line.toLower().contains(arg1.toLower()))
                {
                    foundData.append(line.split(','));
                }
            }
        }
    }
    CreateFiles::_catalogueTest.close();

    for (int i = 0; i < foundData.size(); i++)
    {
        qDebug() << foundData[i];
    }

    QGroupBox* groupBox = new QGroupBox;
    QFormLayout* formLayout = new QFormLayout();
    groupBox->setLayout(formLayout);

    // Array control
    const int arraySize = (foundData.size() / 4) - 1;

    QFrame* lines1[arraySize];
    QFrame* lines2[arraySize];
    QLabel* bookImage[arraySize];
    QLabel* bookName[arraySize];
    QLabel* bookAuthor[arraySize];
    QLabel* bookCopies[arraySize];
    QPushButton* checkoutButton[arraySize];

    int t = 4;
    // Initalize all widgets
    for (int row = 0; row < arraySize; row++)
    {
        // Book image
        QString imagePath = foundData[t];
        QPixmap p(imagePath);
        bookImage[row] = new QLabel;
        bookImage[row]->setPixmap(p.scaled(90, 120));

        // Book name
        bookName[row] = new QLabel;
        bookName[row]->setText("Book name: " + foundData[t + 1]);

        // Book authour
        bookAuthor[row] = new QLabel;
        bookAuthor[row]->setText("Author: " + foundData[t + 2]);

        // Book copies
        bookCopies[row] = new QLabel;
        bookCopies[row]->setText("Copies: " + foundData[t + 3]);

        // Checkout button
        const QSize btnSize = QSize(80, 25);
        checkoutButton[row] = new QPushButton;
        checkoutButton[row]->setText("Checkout");
        checkoutButton[row]->setFixedSize(btnSize);

        // Horizontal Lines
        lines1[row] = new QFrame();
        lines1[row]->setLineWidth(1);
        lines1[row]->setFrameShape(QFrame::HLine);
        lines1[row]->setFrameShadow(QFrame::Sunken);

        lines2[row] = new QFrame();
        lines2[row]->setLineWidth(1);
        lines2[row]->setFrameShape(QFrame::HLine);
        lines2[row]->setFrameShadow(QFrame::Sunken);

        t = t + 4;
    }

    // Add all of the widgets into the layouts
    for (int row = 0; row < arraySize; row++)
    {
        formLayout->setWidget(row, QFormLayout::LabelRole, bookImage[row]);

        QVBoxLayout* verticalLayout = new QVBoxLayout();
        formLayout->setLayout(row, QFormLayout::FieldRole, verticalLayout);

        verticalLayout->addWidget(lines1[row]);
        verticalLayout->addWidget(bookName[row]);
        verticalLayout->addWidget(bookAuthor[row]);
        verticalLayout->addWidget(bookCopies[row]);
        verticalLayout->addWidget(checkoutButton[row]);
        verticalLayout->addWidget(lines2[row]);
        formLayout->setContentsMargins(10, 5, 0, 5);
        formLayout->setVerticalSpacing(30);
    }

    ui->scrollArea->setWidget(groupBox);
}

