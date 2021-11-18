//including modules

#include "mainwindow.h"
#include "adminhome.h"
#include "loginscreen.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "catalogue.h"
#include "QMessageBox"
#include "QCheckBox"
#include "SystemFiles.h"
#include <QDebug> //is a class that provides an output stream for debugging information
#include <QPushButton>//is a widget which executes an action when a user clicks on it.
#include <QGroupBox>
#include <QFormLayout>



/*
 * Main screen is for when a user enters the website to browse the online library without needing
 * to save their data. and can freely view the catalogue and main menu.
*/

//Livs code
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));

    // Code by Jakob
    // Setting the home screen catalogue with our current books
    // Array control
    QStringList catalogue = SystemFiles::GetFileData(CSVFiles::_Catalogue);
    const int arraySize = (catalogue.size() / 6) - 1;

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

        // Horizontal Lines
        lines1[row] = new QFrame();
        lines1[row]->setLineWidth(1);
        lines1[row]->setFrameShape(QFrame::HLine);
        lines1[row]->setFrameShadow(QFrame::Sunken);

        lines2[row] = new QFrame();
        lines2[row]->setLineWidth(1);
        lines2[row]->setFrameShape(QFrame::HLine);
        lines2[row]->setFrameShadow(QFrame::Sunken);

        t = t + 6;
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
        verticalLayout->addWidget(lines2[row]);
        formLayout->setContentsMargins(10, 5, 0, 20);
        formLayout->setVerticalSpacing(30);
    }

    ui->scrollArea->setWidget(groupBox);
    groupBox->setStyleSheet("background-color: white;");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked(){
    hide();
    _loginWindow = new loginscreen(nullptr);
    _loginWindow->setWindowFlags((windowFlags()) | Qt::WindowMinimizeButtonHint);
    _loginWindow->show();
    connect(_loginWindow, SIGNAL(OpenMainMenu()), this, SLOT(MainMenuOpen()));
}

void MainWindow::MainMenuOpen()
{
    show();
}

// Code by Jakob
void MainWindow::on_searchBar_textChanged(const QString &arg1)
{
    QStringList foundData;

    if (SystemFiles::_catalogue.open(QIODevice::ReadOnly))
    {
        QTextStream in(&SystemFiles::_catalogue);
        while(!in.atEnd())
        {
            QString line = SystemFiles::_catalogue.readLine().replace("\r\n","");
            if (line != "BOOK ID,IMAGE,BOOK NAME,AUTHOR,COPIES,EDIT BOOK") // These are the headers of the CSV file. This just skips over it.
            {
                if (line.toLower().contains(arg1.toLower()))
                {
                    foundData.append(line.split(','));
                }
            }
        }
    }
    SystemFiles::_catalogue.close();

    for (int i = 0; i < foundData.size(); i++)
    {
        qDebug() << foundData[i];
    }

    // Array control
    const int arraySize = (foundData.size() / 6);

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

    int t = 0;
    // Initalize all widgets
    for (int row = 0; row < arraySize; row++)
    {
        // Book image
        QString imagePath = foundData[t + 1];
        QPixmap p(imagePath);
        bookImage[row] = new QLabel;
        bookImage[row]->setPixmap(p.scaled(90, 120));

        // Book name
        bookName[row] = new QLabel;
        bookName[row]->setText("Book name: " + foundData[t + 2]);

        // Book authour
        bookAuthor[row] = new QLabel;
        bookAuthor[row]->setText("Author: " + foundData[t + 3]);

        // Book copies
        bookCopies[row] = new QLabel;
        bookCopies[row]->setText("Copies: " + foundData[t + 4]);

        // Horizontal Lines
        lines1[row] = new QFrame();
        lines1[row]->setLineWidth(1);
        lines1[row]->setFrameShape(QFrame::HLine);
        lines1[row]->setFrameShadow(QFrame::Sunken);

        lines2[row] = new QFrame();
        lines2[row]->setLineWidth(1);
        lines2[row]->setFrameShape(QFrame::HLine);
        lines2[row]->setFrameShadow(QFrame::Sunken);

        t = t + 6;
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
        verticalLayout->addWidget(lines2[row]);
        formLayout->setContentsMargins(10, 5, 0, 20);
        formLayout->setVerticalSpacing(30);
    }

    ui->scrollArea->setWidget(groupBox);
    groupBox->setStyleSheet("background-color: white;");
}

