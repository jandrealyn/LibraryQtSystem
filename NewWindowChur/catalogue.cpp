// ------------------------------------------------------------
//
// CATALOGUE SCREEN
// Written by Jakob
//
// The "Catalogue", originally just supposed to be a screen
// to show the current books the library is holding, has
// evolved into the users home screen once they've logged in.
//
<<<<<<< HEAD
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
=======
// It holds different screens in seperate tabs (QTabWidget) for
// easy maneuverability. It includes the Home tab,
// Catalogue tab, and the Account tab. Each tab has it's
// own buttons and functionality. Most of the set up for these
// tabs are done in the Catalogue constructor.
//
// TAB DECORATION:
// The tabs are decorated on the catalogue.ui page. You can
// implement a StyleSheet for the QTabWidget itself and also
// incorporate icons that way as well.
//
// HOME TAB:
// A home screen that displays a place holder image. This was
// originally supposed to be an area where the user can see
// any newly added books or updates that a library admin may
// want to show to their users. Because of time, it may be
// left with just a placeholder image.
//
// CATALOGUE TAB:
// Displays all books in the catalogue.csv file along with
// a working search bar. Users can look for a book and click
// checkout, which will open a QDialog window from
// "checkoutscreen.h".
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
//
// YOUR ACCOUNT TAB:
// The user can view their account details, picture or logout
// from the home screen. They may also update anything to do
<<<<<<< HEAD
// with their account/
=======
// with their account, apart from their picture at the moment.
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
//
// ------------------------------------------------------------

#include "catalogue.h"
#include "ui_catalogue.h"
<<<<<<< HEAD
#include "createfiles.h"
=======
#include "SystemFiles.h"
#include "overdue.h"
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
#include <QDebug>
#include <QDialog>
#include <QFile>
#include <QMessageBox>
<<<<<<< HEAD
#include <QTableWidget>
#include <QStringList>
#include <QItemSelectionModel>
=======
#include <QStringList>
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
#include <QFormLayout>
#include <QFrame>
#include <QScrollArea>
#include <QGroupBox>
<<<<<<< HEAD

Catalogue::Catalogue(QWidget *parent) :
=======
#include <QTabWidget>
#include <QTableWidget>

Catalogue::Catalogue(QWidget *parent,
                     QString memUser,
                     QString memPass,
                     QString memfName,
                     QString memlName,
                     QString memEmail,
                     QString memPhone,
                     QString memID,
                     QString memAvatar) :
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
    QDialog(parent),
    ui(new Ui::Catalogue)
{
    ui->setupUi(this);

<<<<<<< HEAD
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
=======
    // -----------------------------------------------------------------
    //                                                                 |
    //              SETTING PRIVATE VARIABLES AND LABELS               |
    //                                                                 |
    // -----------------------------------------------------------------
    //                                                                 |
    // The private variables are used later in several functions. The  |
    // labels are used just to display the users information on the    |
    // home screen and their Account screen.                           |
    //                                                                 |
    // -----------------------------------------------------------------
    _memUser = memUser;
    _memPass = memPass;
    _memfName = memfName;
    _memlName = memlName;
    _memEmail = memEmail;
    _memPhone = memPhone;
    _memID = memID;
    _memAvatar = memAvatar;

    // Setting users details (which are QLabels)
    QPixmap p(memAvatar);
    ui->profile_picture->setPixmap(p.scaled(120,120));
    ui->welcomeBack->setText("Welcome back, " + _memfName);

    ui->user_name->setText(_memfName);
    ui->user_email->setText("<b>Email:</b> " + _memEmail);
    ui->user_phonenumber->setText("<b>Phone:</b> " + _memPhone);
    ui->user_id->setText("<b>Your ID:</b> " + _memID);

    // -----------------------------------------------------------------
    //                                                                 |
    //           CHECKING OVERDUE BOOKS / NEARBY DUE DATES             |
    //                                                                 |
    // -----------------------------------------------------------------
    //                                                                 |
    // Checking if the user has any overdue books. If they do, then we |
    // need to write a log of what books are overdue. We then display  |
    // a window to the user showing them their overdue books.          |
    //                                                                 |
    // Afterwards, we check if the user has any books near to their    |
    // due date (if the books is 2 or less days till the due date).    |
    // If yes, a log is written of any of the books that may be near   |
    // their due date. We don't currently display a window to the user |
    // showing them their due dates.                                   |
    //                                                                 |
    // -----------------------------------------------------------------

    // Check if user has any overdue books as they login
    QStringList overdueBooks = SystemFiles::CheckUsersOverdueBooks(_memID);

    if (!overdueBooks.isEmpty())
    {
        // Logging a message of the overdue books
        SystemFiles::LogOverdueBook(_memUser, _memID, overdueBooks);

        // Displaying a window to the user showing their overdue books
        Overdue* overdueScreen = new Overdue(nullptr, overdueBooks);        
        overdueScreen->exec();
    }

    // This checks if the user has any nearby due dates. It won't log anything if their books aren't due within 2 days.
    SystemFiles::LogNearbyDueDate(_memUser, _memID);

    // -----------------------------------------------------------------
    //                                                                 |
    //                        LIBRARY CATALOGUE                        |
    //                                                                 |
    // -----------------------------------------------------------------
    //                                                                 |
    // This function displays the catalogue under the "Catalogue" tab  |
    // once a user has logged in. It uses layouts as a way to group    |
    // together the books elements and assigns a button and checkout   |
    // screen for each book displayed.                                 |
    //                                                                 |
    // I use a function for this because of how messy the code got in  |
    // this constructor and because we need to use that code twice.    |
    // Once right now, and then again whenever a user checks out a     |
    // book (copies need to -1, so we update the UI).                  |
    //                                                                 |
    // I also set the style sheet for the dynamically created          |
    // push buttons located in display_catalogue() and the search      |
    // bar function.                                                   |
    //                                                                 |
    // -----------------------------------------------------------------
    pushButtonStyleSheet = "*{ "
            "font-family: Century Gothic, sans-serif;"
            "}"

            "QPushButton{"
            "color: white;"
            "padding: 5px;"
            "background: #27a9e3;"
            "border-style: outset;"
            "border-radius: 5px;"
            "font: bold;"
            "}"
            "QPushButton::pressed{"
            "background-color: rgb(216, 150, 90);"
            "border-style: inset;"
            "}"

            "QPushButton::hover {"
            "background-color: #59c7f7;"
            "}"

            "QPushButton::disabled {"
            "color: #ebebeb;"
            "background-color: #1c7ba6;"
            "}";
    display_catalogue();

    // -----------------------------------------------------------------
    //                                                                 |
    //                     USERS CHECKED OUT BOOKS                     |
    //                                                                 |
    // -----------------------------------------------------------------
    //                                                                 |
    // The chunk of code starting under this comment is the users      |
    // checked out books section. To find it in the program, it will   |
    // be located in the "Account" tab after you log in. It checks for |
    // the users ID in the checkedOutBooks.csv and the                 |
    // reservedBook.csv. If it find the users ID, then it means that   |
    // they have a book checked out or a book reserved. It grabs that  |
    // line of information, puts it into a QStringList, then displays  |
    // the information in a QTableWidget.                              |
    //                                                                 |
    // -----------------------------------------------------------------
    QStringList checkedOutBooksData = SystemFiles::GetFileData(CSVFiles::_CheckedOutBooks);
    QStringList reservedBooksData = SystemFiles::GetFileData(CSVFiles::_ReservedBooks);
    int column = 0;
    int listIndex = 0;
    int rows = 0;

    // Settings the headers of the tableWidget in the users profile.
    ui->tableWidget_currentBooks->insertColumn(ui->tableWidget_currentBooks->columnCount());
    ui->tableWidget_currentBooks->insertColumn(ui->tableWidget_currentBooks->columnCount());
    ui->tableWidget_currentBooks->insertColumn(ui->tableWidget_currentBooks->columnCount());
    ui->tableWidget_currentBooks->insertColumn(ui->tableWidget_currentBooks->columnCount());
    ui->tableWidget_currentBooks->setHorizontalHeaderLabels({"Book Name", "Date Checked Out/Reserved", "Return By", "Checkout or Reserve"});
    ui->tableWidget_currentBooks->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->tableWidget_currentBooks->horizontalHeader()->setSectionResizeMode(1, QHeaderView::Stretch);
    ui->tableWidget_currentBooks->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->tableWidget_currentBooks->horizontalHeader()->setSectionResizeMode(3, QHeaderView::Stretch);
    ui->tableWidget_currentBooks->setSelectionMode(QHeaderView::NoSelection);

    // Quick check to see if user exists in the checked out books file. If they do, it means they have a book checked
    // out and we need to display it.
    if (checkedOutBooksData.indexOf(_memID) > 0)
    {
        QStringList usersCheckedOutBooks;
        for (int i = 0; i < checkedOutBooksData.size(); i++)
        {
            if (column == 2)
            {
                if (checkedOutBooksData[i] == _memID)
                {
                    usersCheckedOutBooks.append(checkedOutBooksData[i - 1]); // Book Name
                    usersCheckedOutBooks.append(checkedOutBooksData[i + 2]); // Book checkout date
                    usersCheckedOutBooks.append(checkedOutBooksData[i + 3]); // Book return date
                    usersCheckedOutBooks.append("Checkout");                 // Since the user currently has it checked out, we also append "Checkout".
                }
                column++;
            }
            else if (column == 6)
            {
                column = 0;
            }
            else
            {
                column++;
            }
        }

        for (int i = 0; i < usersCheckedOutBooks.size() / 4; i++)
        {
            ui->tableWidget_currentBooks->insertRow(ui->tableWidget_currentBooks->rowCount());
            rows++; // We use this in the reservedBooksData section. It allows us to set items in the correct row.
            for (int j = 0; j < 4; j++)
            {
                QTableWidgetItem *item = new QTableWidgetItem(QString(usersCheckedOutBooks[listIndex]));
                item->setFlags(item->flags() ^ Qt::ItemIsEditable); // Makes the item not editable (i know, the naming doesn't make it that obvious)
                ui->tableWidget_currentBooks->setItem(i, j, item);
                listIndex++;
            }
        }
    }

    // Quick check to see if user exists in the reserved books file. Same as before, if they exist then it means they have a reserved book on the way
    // so we need to display it.
    if (reservedBooksData.indexOf(_memID) > 0)
    {
        QStringList reservedBookDetails;
        column = 0; // resetting the column and list index
        listIndex = 0;
        for (int i = 0; i < reservedBooksData.size(); i++)
        {
            if (column == 2)
            {
                if (reservedBooksData[i] == _memID)
                {
                    reservedBookDetails.append(reservedBooksData[i - 1]); // Book Name
                    reservedBookDetails.append(reservedBooksData[i + 2]); // Book checkout date
                    reservedBookDetails.append(reservedBooksData[i + 3]); // Book return date
                    reservedBookDetails.append("Reserved");
                }
            }
            else if (column == 5)
            {
                column = 0;
            }
            else
            {
                column++;
            }
        }

        for (int i = 0; i < (reservedBookDetails.size() / 4); i++)
        {
            ui->tableWidget_currentBooks->insertRow(ui->tableWidget_currentBooks->rowCount());
            for (int j = 0; j < 4; j++)
            {
                QTableWidgetItem *item = new QTableWidgetItem(QString(reservedBookDetails[listIndex]));
                item->setFlags(item->flags() ^ Qt::ItemIsEditable); // Makes the item not editable
                ui->tableWidget_currentBooks->setItem(rows, j, item); // Here we use rows instead of i to make sure we set the item in the right row
                listIndex++;
            }
            rows++;
        }
    }
}

Catalogue::~Catalogue()
{
    delete ui;
}

//Liv Tried to figure out how to add the same imagery from " main window " - Yet to figure it out..s
//Catalogue::Home()
//    QDialog(parent),
//    ui(new Ui::Catalogue)
//{
//    ui->setupUi(this);
//    QPixmap Img(":/images/YoobeeLibraries.png");
//    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));
//}

void Catalogue::on_yourAccount_logout_clicked()
{
    close();
    emit OpenMainMenu();
}

// Search bar functionality
void Catalogue::on_searchBar_textChanged(const QString &arg1)
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
                if (line.contains(arg1, Qt::CaseInsensitive))
                {
                    foundData.append(line.split(','));
                }
            }
        }
    }
    SystemFiles::_catalogue.close();

    // Array control
    const int arraySize = (foundData.size() / 6);
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653

    // LAYOUTS
    QGroupBox* groupBox = new QGroupBox;
    QFormLayout* formLayout = new QFormLayout();
    groupBox->setLayout(formLayout);

<<<<<<< HEAD

=======
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
    QFrame* lines1[arraySize];
    QFrame* lines2[arraySize];
    QLabel* bookImage[arraySize];
    QLabel* bookName[arraySize];
    QLabel* bookAuthor[arraySize];
    QLabel* bookCopies[arraySize];
    QPushButton* checkoutButton[arraySize];
<<<<<<< HEAD

    int t = 4;
=======
    CheckOutScreen* checkoutScreen[arraySize];

    int t = 0;
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
    // Initalize all widgets
    for (int row = 0; row < arraySize; row++)
    {
        // Book image
<<<<<<< HEAD
        QString imagePath = catalogueTest[t];
=======
        QString imagePath = foundData[t + 1];
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
        QPixmap p(imagePath);
        bookImage[row] = new QLabel;
        bookImage[row]->setPixmap(p.scaled(90, 120));

        // Book name
        bookName[row] = new QLabel;
<<<<<<< HEAD
        bookName[row]->setText("Book name: " + catalogueTest[t + 1]);

        // Book authour
        bookAuthor[row] = new QLabel;
        bookAuthor[row]->setText("Author: " + catalogueTest[t + 2]);

        // Book copies
        bookCopies[row] = new QLabel;
        bookCopies[row]->setText("Copies: " + catalogueTest[t + 3]);
=======
        bookName[row]->setText("Book name: " + foundData[t + 2]);

        // Book authour
        bookAuthor[row] = new QLabel;
        bookAuthor[row]->setText("Author: " + foundData[t + 3]);

        // Book copies
        bookCopies[row] = new QLabel;
        bookCopies[row]->setText("Copies: " + foundData[t + 4]);
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653

        // Checkout button
        const QSize btnSize = QSize(80, 25);
        checkoutButton[row] = new QPushButton;
        checkoutButton[row]->setText("Checkout");
        checkoutButton[row]->setFixedSize(btnSize);
<<<<<<< HEAD
        checkoutButton[row]->setStyleSheet("border: 1px solid black;");
=======
        checkoutButton[row]->setStyleSheet(pushButtonStyleSheet);

        // Sending Book ID, Book Name, Member ID, Member Name, Date through CheckOutScreen constructor.
        checkoutScreen[row] = new CheckOutScreen(NULL, _memfName, _memID, foundData[t], foundData[t + 2], foundData[t + 3], foundData[t + 4]);
        connect(checkoutButton[row], SIGNAL(clicked()), checkoutScreen[row], SLOT(exec()));
        connect(checkoutScreen[row], SIGNAL(UpdateCatalogue()), this, SLOT(display_catalogue()));
        connect(checkoutScreen[row], SIGNAL(UpdateUsersCurrentBooks()), this, SLOT(update_usersBooks()));
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653

        // Horizontal Lines
        lines1[row] = new QFrame();
        lines1[row]->setLineWidth(1);
        lines1[row]->setFrameShape(QFrame::HLine);
        lines1[row]->setFrameShadow(QFrame::Sunken);

        lines2[row] = new QFrame();
        lines2[row]->setLineWidth(1);
        lines2[row]->setFrameShape(QFrame::HLine);
        lines2[row]->setFrameShadow(QFrame::Sunken);

<<<<<<< HEAD
        t = t + 4;
=======
        t = t + 6;
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
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
<<<<<<< HEAD
        formLayout->setContentsMargins(10, 5, 0, 5);
=======
        formLayout->setContentsMargins(10, 5, 0, 20);
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
        formLayout->setVerticalSpacing(30);
    }

    ui->scrollArea->setWidget(groupBox);
<<<<<<< HEAD
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

=======
    groupBox->setStyleSheet("background-color: white;");
}

// This button is located in the Account page.
void Catalogue::on_yourAccount_update_clicked()
{
    update_ui = new UpdateUserDetails(this, _memUser, _memPass, _memfName, _memlName, _memEmail, _memPhone, _memID);
    update_ui->exec();
}

//// This function is used when a user updates their details or when a user checks out a book.
//// It will update the entire catalogue each time either of those functions happens.
//void Catalogue::update_catalogue()
//{
//    display_catalogue();
//}

void Catalogue::update_usersBooks()
{
    ui->tableWidget_currentBooks->setRowCount(0);
    // Users checked out books section
    QStringList checkedOutBooksData = SystemFiles::GetFileData(CSVFiles::_CheckedOutBooks);
    QStringList reservedBooksData = SystemFiles::GetFileData(CSVFiles::_ReservedBooks);
    int column = 0;
    int listIndex = 0;
    int rows = 0;

    // Quick check to see if user exists in the checked out books file
    if (checkedOutBooksData.indexOf(_memID) > 0)
    {
        QStringList checkOutBookDetails;
        for (int i = 0; i < checkedOutBooksData.size(); i++)
        {
            if (column == 2)
            {
                if (checkedOutBooksData[i] == _memID)
                {
                    checkOutBookDetails.append(checkedOutBooksData[i - 1]); // Book Name
                    checkOutBookDetails.append(checkedOutBooksData[i + 2]); // Book checkout date
                    checkOutBookDetails.append(checkedOutBooksData[i + 3]); // Book return date
                    checkOutBookDetails.append("Checkout");
                }
                column++;
            }
            else if (column == 6)
            {
                column = 0;
            }
            else
            {
                column++;
            }
        }

        for (int i = 0; i < checkOutBookDetails.size() / 4; i++)
        {
            ui->tableWidget_currentBooks->insertRow(ui->tableWidget_currentBooks->rowCount());
            rows++; // We use this in the reservedBooksData section. It allows us to set items in the correct row.
            for (int j = 0; j < 4; j++)
            {
                QTableWidgetItem *item = new QTableWidgetItem(QString(checkOutBookDetails[listIndex]));
                item->setFlags(item->flags() ^ Qt::ItemIsEditable); // Makes the item not editable
                ui->tableWidget_currentBooks->setItem(i, j, item);
                listIndex++;
            }
        }
    }

    // Quick check to see if user exists in the reserved books file
    if (reservedBooksData.indexOf(_memID) > 0)
    {
        QStringList reservedBookDetails;
        column = 0; // resetting the column and list index
        listIndex = 0;
        for (int i = 0; i < reservedBooksData.size(); i++)
        {
            if (column == 2)
            {
                if (reservedBooksData[i] == _memID)
                {
                    reservedBookDetails.append(reservedBooksData[i - 1]); // Book Name
                    reservedBookDetails.append(reservedBooksData[i + 2]); // Book checkout date
                    reservedBookDetails.append(reservedBooksData[i + 3]); // Book return date
                    reservedBookDetails.append("Reserved");
                }
            }
            else if (column == 5)
            {
                column = 0;
            }
            else
            {
                column++;
            }
        }

        for (int i = 0; i < (reservedBookDetails.size() / 4); i++)
        {
            ui->tableWidget_currentBooks->insertRow(ui->tableWidget_currentBooks->rowCount());
            for (int j = 0; j < 4; j++)
            {
                QTableWidgetItem *item = new QTableWidgetItem(QString(reservedBookDetails[listIndex]));
                item->setFlags(item->flags() ^ Qt::ItemIsEditable); // Makes the item not editable
                ui->tableWidget_currentBooks->setItem(rows, j, item); // Here we use rows instead of i to make sure we set the item in the right row
                listIndex++;
            }
            rows++;
        }
    }
}

// Reads catalogue.csv and displays all of its content
void Catalogue::display_catalogue()
{
    // Array control
    QStringList catalogueData = SystemFiles::GetFileData(CSVFiles::_Catalogue);
    const int arraySize = (catalogueData.size() / 6) - 1;

    // LAYOUTS
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
    QGroupBox* groupBox = new QGroupBox;
    QFormLayout* formLayout = new QFormLayout();
    groupBox->setLayout(formLayout);

<<<<<<< HEAD
    // Array control
    const int arraySize = (foundData.size() / 4) - 1;

=======
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
    QFrame* lines1[arraySize];
    QFrame* lines2[arraySize];
    QLabel* bookImage[arraySize];
    QLabel* bookName[arraySize];
    QLabel* bookAuthor[arraySize];
    QLabel* bookCopies[arraySize];
    QPushButton* checkoutButton[arraySize];
<<<<<<< HEAD

    int t = 4;
=======
    CheckOutScreen* checkoutScreen[arraySize];

    int t = 6;
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
    // Initalize all widgets
    for (int row = 0; row < arraySize; row++)
    {
        // Book image
<<<<<<< HEAD
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
=======
        QString imagePath = catalogueData[t + 1]; // Skip the first spot of the list because it's the ID
        QPixmap p(imagePath);
        bookImage[row] = new QLabel;
        bookImage[row]->setPixmap(p.scaled(90, 120, Qt::IgnoreAspectRatio, Qt::FastTransformation));

        // Book name
        bookName[row] = new QLabel;
        bookName[row]->setText("Book name: " + catalogueData[t + 2]);

        // Book author
        bookAuthor[row] = new QLabel;
        bookAuthor[row]->setText("Author: " + catalogueData[t + 3]);

        // Book copies
        bookCopies[row] = new QLabel;
        bookCopies[row]->setText("Copies: " + catalogueData[t + 4]);
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653

        // Checkout button
        const QSize btnSize = QSize(80, 25);
        checkoutButton[row] = new QPushButton;
        checkoutButton[row]->setText("Checkout");
        checkoutButton[row]->setFixedSize(btnSize);
<<<<<<< HEAD
=======
        checkoutButton[row]->setStyleSheet(pushButtonStyleSheet);

        // Sending Book ID, Book Name, Member ID, Member Name, Date through CheckOutScreen constructor.
        checkoutScreen[row] = new CheckOutScreen(NULL, _memfName, _memID, catalogueData[t], catalogueData[t + 2], catalogueData[t + 3], catalogueData[t + 4]);
        checkoutScreen[row]->setWindowTitle("Checkout a book");
        connect(checkoutButton[row], SIGNAL(clicked()), checkoutScreen[row], SLOT(exec()));
        connect(checkoutScreen[row], SIGNAL(UpdateCatalogue()), this, SLOT(display_catalogue()));
        connect(checkoutScreen[row], SIGNAL(UpdateUsersCurrentBooks()), this, SLOT(update_usersBooks()));
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653

        // Horizontal Lines
        lines1[row] = new QFrame();
        lines1[row]->setLineWidth(1);
        lines1[row]->setFrameShape(QFrame::HLine);
        lines1[row]->setFrameShadow(QFrame::Sunken);

        lines2[row] = new QFrame();
        lines2[row]->setLineWidth(1);
        lines2[row]->setFrameShape(QFrame::HLine);
        lines2[row]->setFrameShadow(QFrame::Sunken);

<<<<<<< HEAD
        t = t + 4;
=======
        t = t + 6;
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
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
<<<<<<< HEAD
        formLayout->setContentsMargins(10, 5, 0, 5);
=======
        formLayout->setContentsMargins(10, 5, 0, 20);
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
        formLayout->setVerticalSpacing(30);
    }

    ui->scrollArea->setWidget(groupBox);
<<<<<<< HEAD
=======
    groupBox->setStyleSheet("background-color: white;");
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
}

