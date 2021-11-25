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
#include "SystemFiles.h"
#include "overdue.h"
#include <QDebug>
#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QStringList>
#include <QFormLayout>
#include <QFrame>
#include <QScrollArea>
#include <QGroupBox>
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
    QDialog(parent),
    ui(new Ui::Catalogue)
{
    ui->setupUi(this);

    // -----------------------------------------------------------------
    //                                                                 |
    //              SETTING PRIVATE VARIABLES AND LABELS               |
    //                                                                 |
    // -----------------------------------------------------------------
    //
    // The private variables are used later in several functions. The
    // labels are used just to display the users information on the
    // home screen and their Account screen.
    //
    _memUser = memUser;
    _memPass = memPass;
    _memfName = memfName;
    _memlName = memlName;
    _memEmail = memEmail;
    _memPhone = memPhone;
    _memID = memID;
    _memAvatar = memAvatar;

    // Set users details
    QPixmap p(memAvatar);
    ui->profile_picture->setPixmap(p.scaled(120,120));
    ui->welcomeBack->setText("Welcome back, " + _memfName);

    ui->user_name->setText(_memfName);
    ui->user_email->setText("<b>Email:</b> " + _memEmail);
    ui->user_phonenumber->setText("<b>Phone:</b> " + _memPhone);
    ui->user_id->setText("<b>Your ID:</b> " + _memID);


    // -----------------------------------------------------------------
    //                                                                 |
    //            CHECKING OVERDUE BOOKS / NEARBY DUE DATES            |
    //                                                                 |
    // -----------------------------------------------------------------
    //                                                                 |
    // Check if the user has any overdue books. If they do, write a    |
    // log of the what books are overdue. We then display a window to  |
    // to the user showing them their overdue books.                   |
    //                                                                 |
    // Afterwards, we check if the user has any books near to their    |
    // due date (if the books is 2 or less days till the due date).    |
    // If yes, a log is written of any of the books that may be near   |
    // their due date. We don't currently display a window to the user |
    // showing them their due dates.
    //                                                                 |
    // -----------------------------------------------------------------
    // Check if user has any overdue books as they login
    QStringList overdueBooks = SystemFiles::CheckUsersOverdueBooks(_memID); // we need to show them: book name, book return date, current date

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
    // -----------------------------------------------------------------
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
    ui->tableWidget_currentBooks->setHorizontalHeaderLabels({"Book Name", "Date Checked Out/Booked", "Return By", "Checkout or Reserve"});
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
                    usersCheckedOutBooks.append("Checkout");
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
                if (line.toLower().contains(arg1.toLower()))
                {
                    foundData.append(line.split(','));
                }
            }
        }
    }
    SystemFiles::_catalogue.close();

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
    QPushButton* checkoutButton[arraySize];
    CheckOutScreen* checkoutScreen[arraySize];

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

        // Checkout button
        const QSize btnSize = QSize(80, 25);
        checkoutButton[row] = new QPushButton;
        checkoutButton[row]->setText("Checkout");
        checkoutButton[row]->setFixedSize(btnSize);
        checkoutButton[row]->setStyleSheet("QPushButton { border: 1px solid black; }"
                                           "QPushButton:pressed { border-color: #e7e7e7; background-color: #f4f4f4; }");

        // Sending Book ID, Book Name, Member ID, Member Name, Date through CheckOutScreen constructor.
        checkoutScreen[row] = new CheckOutScreen(NULL, _memfName, _memID, foundData[t], foundData[t + 2], foundData[t + 3], foundData[t + 4]);
        connect(checkoutButton[row], SIGNAL(clicked()), checkoutScreen[row], SLOT(exec()));
        connect(checkoutScreen[row], SIGNAL(UpdateCatalogue()), this, SLOT(update_catalogue()));
        connect(checkoutScreen[row], SIGNAL(UpdateUsersCurrentBooks()), this, SLOT(update_usersBooks()));

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
        verticalLayout->addWidget(checkoutButton[row]);
        verticalLayout->addWidget(lines2[row]);
        formLayout->setContentsMargins(10, 5, 0, 20);
        formLayout->setVerticalSpacing(30);
    }

    ui->scrollArea->setWidget(groupBox);
    groupBox->setStyleSheet("background-color: white;");
}

void Catalogue::on_yourAccount_update_clicked()
{

    update_ui = new UpdateUserDetails(this, _memUser, _memPass, _memfName, _memlName, _memEmail, _memPhone, _memID);
    update_ui->exec();
}

// This function is used when a user updates their details or when a user checks out a book.
// It will update the entire catalogue each time either of those functions happens.
void Catalogue::update_catalogue()
{
    display_catalogue();
}

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
    QPushButton* checkoutButton[arraySize];
    CheckOutScreen* checkoutScreen[arraySize];

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
        checkoutButton[row] = new QPushButton;
        checkoutButton[row]->setText("Checkout");
        checkoutButton[row]->setFixedSize(btnSize);
        checkoutButton[row]->setStyleSheet("QPushButton { border: 1px solid black; }"
                                           "QPushButton:pressed { border-color: #e7e7e7; background-color: #f4f4f4; }");

        // Sending Book ID, Book Name, Member ID, Member Name, Date through CheckOutScreen constructor.
        checkoutScreen[row] = new CheckOutScreen(NULL, _memfName, _memID, catalogue[t], catalogue[t + 2], catalogue[t + 3], catalogue[t + 4]);
        checkoutScreen[row]->setWindowTitle("Checkout a book");
        connect(checkoutButton[row], SIGNAL(clicked()), checkoutScreen[row], SLOT(exec()));
        connect(checkoutScreen[row], SIGNAL(UpdateCatalogue()), this, SLOT(update_catalogue()));
        connect(checkoutScreen[row], SIGNAL(UpdateUsersCurrentBooks()), this, SLOT(update_usersBooks()));

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
        verticalLayout->addWidget(checkoutButton[row]);
        verticalLayout->addWidget(lines2[row]);
        formLayout->setContentsMargins(10, 5, 0, 20);
        formLayout->setVerticalSpacing(30);
    }

    ui->scrollArea->setWidget(groupBox);
    groupBox->setStyleSheet("background-color: white;");
}

