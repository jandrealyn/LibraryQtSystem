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

admincatalogue::admincatalogue(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admincatalogue)
{
    qDebug() << "inside constructor tesT 1";
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));

    // Array control
    QStringList catalogue = CreateFiles::GetFileData(CSVFiles::_Catalogue);
    const int arraySize = (catalogue.size() / 6) - 1;

    QStringList booksData = CreateFiles::GetFileData(CSVFiles::_Catalogue);
       ui->setupUi(this);
       QPixmap Img(":/images/YoobeeLibraries.png");
       ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));
       ui->adminCatalogue->setStyleSheet("QHeaderView::section { background-color: rgba(254, 222, 255, 0.3) }");
          // Because we have 5 columns, we insert a column 5 times
          for (int i = 0; i < 6; i++)
          {
             ui->adminCatalogue->insertColumn(ui->adminCatalogue->columnCount());
          }
          // We have headers in our CSV file, so I use them to set the labels for the table.
          ui->adminCatalogue->setHorizontalHeaderLabels({booksData[0], booksData[1], booksData[2], booksData[3], booksData[4], booksData[5]});
          ui->adminCatalogue->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Interactive);
          ui->adminCatalogue->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
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
                      QPushButton* push = new QPushButton(item);
                      push->setText("Edit");
                      push->resize(QSize(40,20));
                      connect(push, SIGNAL(clicked()), this, SLOT(mySlot()));
                      ui->adminCatalogue->setCellWidget(row, col, item);


                  }
                  else {
                   QTableWidgetItem *item = new QTableWidgetItem(QString(booksData[i]));
                   ui->adminCatalogue->setItem(row, col, item);
                  }
                  i++;
              }
          }

    QLabel* bookImage[arraySize];
    QLabel* bookName[arraySize];
    QLabel* bookAuthor[arraySize];
    QLabel* bookCopies[arraySize];
    QPushButton* editButton[arraySize];
    admineditbook* adminedit[arraySize];

    int t = 6;
    // Initalize all widgets
    for (int row = 0; row < arraySize; row++)
    {
        // Book image
        QString imagePath = catalogue[t + 1]; // Skip the first spot of the list because it's the ID
        QPixmap p(imagePath);
        bookImage[row] = new QLabel;
        bookImage[row]->setPixmap(p.scaled(90, 120));

        // Book name
        bookName[row] = new QLabel;
        bookName[row]->setText("Book name: " + catalogue[t + 2]);

        // Book author
        bookAuthor[row] = new QLabel;
        bookAuthor[row]->setText("Author: " + catalogue[t + 3]);

        // Book copies
        bookCopies[row] = new QLabel;
        bookCopies[row]->setText("Copies: " + catalogue[t + 4]);

        // Checkout button
        const QSize btnSize = QSize(80, 25);
        editButton[row] = new QPushButton;
        editButton[row]->setText("Checkout");
        editButton[row]->setFixedSize(btnSize);
        editButton[row]->setStyleSheet("QPushButton { border: 1px solid black; }"
                                           "QPushButton:pressed { border-color: #e7e7e7; background-color: #f4f4f4; }");

        adminedit[row] = new admineditbook(NULL, catalogue[t], catalogue[t + 2], catalogue[t + 3], catalogue[t + 4]);
        connect(editButton[row], SIGNAL(clicked()), adminedit[row], SLOT(exec()));
        // Book ID, Book Name, Member ID, Member Name, Date
        //adminedit[row]->setVariables(catalogue[t], catalogue[t + 2], catalogue[t + 3], catalogue[t + 4]);

        t = t + 6;
    }

    // Add all of the widgets into the layouts
    for (int row = 0; row < arraySize; row++)
    {
        formLayout->setWidget(row, QFormLayout::LabelRole, bookImage[row]);

        QVBoxLayout* verticalLayout = new QVBoxLayout();
        formLayout->setLayout(row, QFormLayout::FieldRole, verticalLayout);

        verticalLayout->addWidget(bookName[row]);
        verticalLayout->addWidget(bookAuthor[row]);
        verticalLayout->addWidget(bookCopies[row]);
        verticalLayout->addWidget(adminedit[row]);
        formLayout->setContentsMargins(10, 5, 0, 20);
        formLayout->setVerticalSpacing(30);
    }

    ui->scrollArea->setWidget(groupBox);
    groupBox->setStyleSheet("background-color: white;");
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



