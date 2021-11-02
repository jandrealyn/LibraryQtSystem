// ------------------------------------------------------------
//
// CATALOGUE SCREEN
// Written by Jakob
//
// The "Catalogue", originally just supposed to be a screen
// to show the current books the library is holding, has
// evolved into the users home screen once they've logged in.
//
// It holds different screens in seperate tabs for easy
// maneuverability. It includes the Home tab, Catalogue tab,
// and Your account tab. Each tab has it's own buttons and
// functionality.
//
// HOME TAB:
// A home screen that displays any new books recently added
// within the last two days. It may also hold any updates
// an admin wants to write for every user to see.
//
// CATALOGUE TAB:
// Displays all books with a search bar. User can look for
// a book and click checkout, which will open a dialog window
// from "checkoutscreen.cpp".
//
// YOUR ACCOUNT TAB:
// The user can view their account details, picture or logout
// from the home screen. They may also update anything to do
// with their account/
//
// ------------------------------------------------------------

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

    //QPixmap img(":/images/yoobee-logo.png");
    //ui->yoobeeLogo->setPixmap(img);

    // Array control
    QStringList catalogue = CreateFiles::GetFileData("catalogue");
    const int arraySize = (catalogue.size() / 5) - 1;

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
    CheckOutScreen* checkoutScreen[arraySize];

    int t = 5;
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
        checkoutButton[row] = new QPushButton;
        checkoutButton[row]->setText("Checkout");
        checkoutButton[row]->setFixedSize(btnSize);
        checkoutButton[row]->setStyleSheet("QPushButton { border: 1px solid black; }"
                                           "QPushButton:pressed { border-color: #e7e7e7; background-color: #f4f4f4; }");

        checkoutScreen[row] = new CheckOutScreen;

        connect(checkoutButton[row], SIGNAL(clicked()), checkoutScreen[row], SLOT(exec()));
        checkoutScreen[row]->setLabels(catalogue[t + 2], catalogue[t + 3], catalogue[t + 4]);

        // Horizontal Lines
        lines1[row] = new QFrame();
        lines1[row]->setLineWidth(1);
        lines1[row]->setFrameShape(QFrame::HLine);
        lines1[row]->setFrameShadow(QFrame::Sunken);

        lines2[row] = new QFrame();
        lines2[row]->setLineWidth(1);
        lines2[row]->setFrameShape(QFrame::HLine);
        lines2[row]->setFrameShadow(QFrame::Sunken);

        t = t + 5;
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
        formLayout->setContentsMargins(10, 5, 0, 20);
        formLayout->setVerticalSpacing(30);
    }

    ui->scrollArea->setWidget(groupBox);
    groupBox->setStyleSheet("background-color: white;");
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
            if (!line.contains("IMAGE, BOOK NAME, AUTHOR, COPIES"))
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
