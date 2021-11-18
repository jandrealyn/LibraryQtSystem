// ------------------------------------------------------------
//
// SystemFiles CLASS
// Written by Jakob
//
// This class is used to easily acess our system files.
// Team members can access a file they need by calling
// CreateFiles::_fileNeeded;
//
// If you need some files data, you can call
// CreateFiles::GetFileData(CSVFiles::_YourFile) into a QStringList.
//
// ------------------------------------------------------------

#include "SystemFiles.h"
#include <QRandomGenerator>
#include <QDir>
#include <QTextStream>
#include <QMessageBox>

// Defining static variables
QString SystemFiles::_path = "CSVFiles/";
QFile SystemFiles::_catalogue(_path + "catalogue.csv");
QFile SystemFiles::_members(_path + "members.csv");
QFile SystemFiles::_checkedOutBooks(_path + "checkedoutbooks.csv");
QFile SystemFiles::_reserveBook(_path + "reserveBook.csv");

void SystemFiles::CreateFilesOnStartUp()
{
    // Check if the "CSVFiles" folder exists, if not then create it.
    if (!QDir(_path).exists())
    {
        // Make the directory (the CSVFiles folder)
        QDir().mkdir(_path);
    }

    if (!_catalogue.exists())
    {
        _catalogue.open(QIODevice::WriteOnly | QFile::Text);
        QTextStream catalogue_output(&_catalogue);
        catalogue_output << "BOOK ID" << "," << "IMAGE" << "," << "BOOK NAME" << "," << "AUTHOR" << "," << "COPIES" << "," << "EDIT BOOK" << "\n";
        catalogue_output << "Book6969" << "," << ":/images/jerboa-avatar.jpg" << "," << "Jerboa Book" << "," << "Jakob Frederikson" << "," << "0" << "," << "PushButton" << "\n";
        catalogue_output << "Book0342" << "," << ":/images/blue-book.jpg" << "," << "This is a book" << "," << "Author" << "," << "10" << "," << "PushButton" << "\n";
        catalogue_output << "Book3163" << "," <<  ":/images/book-cover.png" << "," << "Cool Book" << "," << "Authorz" << "," << "10" << "," << "PushButton" << "\n";
        catalogue_output << "Book3164" << "," <<  ":/images/cat-avatar.jpg" << "," << "Swag" << "," << "Lawl" << "," << "1" << "," << "PushButton" << "\n";
        _catalogue.close();
    }

    if (!_members.exists())
    {
        _members.open(QIODevice::WriteOnly | QFile::Text);
        QTextStream members_output(&_members);
        members_output << "ID" << "," << "PROFILE PICTURE" << "," << "FIRST NAME" << "," << "LAST NAME" << "," << "USERNAME" << "," << "PASSWORD" << "," << "EMAIL" << "," << "PHONE NUM" << "\n";
        _members.close();
    }

    if (!_checkedOutBooks.exists())
    {
        _checkedOutBooks.open(QIODevice::WriteOnly | QFile::Text);
        QTextStream checkout_output(&_checkedOutBooks);
        checkout_output << "BOOK ID" << "," << "BOOK NAME" << "," << "MEMBER ID" << "," << "MEMBER NAME" << "," << "DATE CHECKED OUT" << "," << "DATE DUE" << "\n";
        _checkedOutBooks.close();
    }

    if (!_reserveBook.exists())
    {
        _reserveBook.open(QIODevice::WriteOnly | QFile::Text);
        QTextStream prebook_output(&_reserveBook);
        prebook_output << "BOOK ID" << "," << "BOOK NAME" << "," << "MEMBER ID" << "," << "MEMBER NAME" << "," << "PREBOOK DATE" << "," << "DATE DUE" << "\n";
        _reserveBook.close();
    }
}

QStringList SystemFiles::GetFileData(enum CSVFiles file)
{
    QStringList fileData;
    switch (file)
    {
    case CSVFiles::_Catalogue:
        if (_catalogue.open(QIODevice::ReadOnly))
            {
                QTextStream in(&_catalogue);
                while(!in.atEnd())
                {
                    QString line = _catalogue.readLine().replace("\r\n","");
                    fileData.append(line.split(','));
                }
            }
            else
            {
                return fileData;
            }
            _catalogue.close();
            break;
    case CSVFiles::_Members:
        if (_members.open(QIODevice::ReadOnly))
        {
            QTextStream in(&_members);
            while(!in.atEnd())
            {
                QString line = _members.readLine().replace("\r\n","");
                fileData.append(line.split(','));
            }
        }
        else
        {
            return fileData;
        }
        _members.close();
        break;
    case CSVFiles::_CheckedOutBooks:
        if (_checkedOutBooks.open(QIODevice::ReadOnly))
        {
            QTextStream in(&_checkedOutBooks);
            while(!in.atEnd())
            {
                QString line = _checkedOutBooks.readLine().replace("\r\n","");
                fileData.append(line.split(','));
            }
        }
        else
        {
            return fileData;
        }
        _checkedOutBooks.close();
        break;
    case CSVFiles::_ReservedBooks:
        if (_reserveBook.open(QIODevice::ReadOnly))
        {
            QTextStream in(&_reserveBook);
            while(!in.atEnd())
            {
                QString line = _reserveBook.readLine().replace("\r\n","");
                fileData.append(line.split(','));
            }
        }
        _reserveBook.close();
        break;
    default:
        QMessageBox::warning(NULL, "Error", "Could not get file data.");
        fileData.append("error");
        break;
    }
    return fileData;
}

// This function is used to make the coding for other members in the team easier.
// Whoever is in charge of the login screen can use this function to pass through
// the values of the users account details and creates an account. It will also
// generate a randomised ID.
void SystemFiles::CreateMember(QString avatar, QString fName, QString lName, QString uName, QString pWord, QString email, QString phoneNum)
{
    // Generate the members ID
    quint32 idNum = QRandomGenerator::global()->bounded(1000, 9999);
    QString id = "Mem" + QString::number(idNum);
    QStringList membersList = GetFileData(CSVFiles::_Members);
    if (membersList.contains(id))
    {
        while (membersList.contains(id))
        {
            quint32 idNum = QRandomGenerator::global()->bounded(1000, 9999);
            QString id = "Mem" + QString::number(idNum);
        }
    }

    // Output all of the members details
    if (_members.open(QIODevice::WriteOnly | QFile::Append | QFile::Text))
    {
        QTextStream in(&_members);
        in << id << "," << avatar << "," << fName << "," << lName << "," << uName << "," << pWord << "," << email << "," << phoneNum << "\n";
    }
    else
    {
        QMessageBox* w = new QMessageBox;
        w->setWindowTitle("Cannot open members.csv");
        w->setText(_members.errorString() + "\n"
                   "Please try again.");
    }
    _members.close();
}

//Lara 3:)

void SystemFiles::CreateBook(QString bookimg, QString title, QString author, QString copies)
{
    // Generate the members ID
    quint32 id = QRandomGenerator::global()->bounded(1000, 9999);
    QString bookid = "Book" + QString::number(id);
    QStringList bookList = GetFileData(CSVFiles::_Catalogue);
    if (bookList.contains(bookid))
    {
        while (bookList.contains(bookid))
        {
            quint32 id = QRandomGenerator::global()->bounded(1000, 9999);
            QString bookid = "Book" + QString::number(id);
        }
    }

    // Output all of the members details
    if (_catalogue.open(QIODevice::WriteOnly | QFile::Append | QFile::Text))
    {
        QTextStream in(&_catalogue);
        in << bookid << "," << bookimg << "," << title << "," << author << "," << copies << "," << "PushButton" << "\n";
    }
    else
    {
        QMessageBox* w = new QMessageBox;
        w->setWindowTitle("Cannot open catalogue.csv");
        w->setText(_members.errorString() + "\n"
                   "Please try again.");
    }
    _catalogue.close();
}

void SystemFiles::DeleteBook(QString bookID){

    QStringList bookList = GetFileData(CSVFiles::_Catalogue);
    _catalogue.open(QIODevice::WriteOnly| QFile::Truncate | QFile::Text);
    QTextStream catalogue_output(&_catalogue);

    catalogue_output << "BOOK ID" << "," << "IMAGE" << "," << "BOOK NAME" << "," << "AUTHOR" << "," << "COPIES" << "," << "EDIT BOOK" << "\n";
    int i=6;
    int amount = (bookList.size() / 6) - 1;
    for (int row = 0; row < amount; row++){
        if (bookList[i] != bookID){
            catalogue_output << bookList[i] << "," << bookList[i+1] << "," << bookList[i+2] << "," << bookList[i+3] << "," << bookList[i+4] << "," << "PushButton" << "\n";
        }
        i = i + 6;
    }
    _catalogue.close();
}

void SystemFiles::CheckOutBook(QString bookID, QString bookName, QString memID, QString memName, QString dueDate)
{
    QString currentDate = QDate::currentDate().toString("dd/MM/yyyy");

    // Output the details of the checkout to checkedOutBooks file
    _checkedOutBooks.open(QIODevice::WriteOnly | QFile::Append | QFile::Text);
    QTextStream in(&_checkedOutBooks);
    in << bookID << "," << bookName << "," << memID << "," << memName << "," << currentDate << "," << dueDate << "\n";
    _checkedOutBooks.close();

    // We now need to remove a copy of the book as a user has checked it out.
    QStringList catalogueData = GetFileData(CSVFiles::_Catalogue);

    for (int i = 0; i < catalogueData.size(); i++)
    {
        if (catalogueData[i] == bookName)
        {
            catalogueData[i + 2] = QString::number(catalogueData[i + 2].toInt() - 1); // subtract the book copies by 1
            break;
        }
    }
    // Once the copy of the book is removed, we need to write it back to the catalogue file.
    _catalogue.open(QIODevice::WriteOnly | QFile::Truncate | QFile::Text);
    QTextStream catalogueIn(&_catalogue);
    int col = 0;
    for (int i = 0; i < catalogueData.size(); i++)
    {
            if (col != 5)
            {
                catalogueIn << catalogueData[i] << ",";
                col++;
            }
            else if (col == 5)
            {
                catalogueIn << catalogueData[i] << "\n";
                col = 0;
            }
    }
    _catalogue.close();

    // Now that we wrote that into the catalogue file, we need to update the catalogue page with the correct information.
    // 'Correct information' being that the copies of the book has gone down by one.

}

void SystemFiles::CheckOutBook(QString bookID, QString bookName, QString memID, QString memName, QString reserveDate, QString dueDate)
{
    _reserveBook.open(QIODevice::WriteOnly | QFile::Append | QFile::Text);
    QTextStream in(&_reserveBook);
    in << bookID << "," << bookName << "," << memID << "," << memName << "," << reserveDate << "," << dueDate << "\n";
    _reserveBook.close();
}

void SystemFiles::UpdateMemberDetails(QStringList membersData)
{
    int col = 0;
    if(_members.open(QIODevice::WriteOnly | QFile::Truncate | QFile::Text))
    {
        QTextStream in(&_members);
        for (int i = 0; i < membersData.size(); i++)
        {
            in << membersData[i];
            if (col != 7)
            {
                in << ",";
                col++;
            }
            else
            {
                in << "\n";
                col = 0;
            }
        }
        QMessageBox::information(NULL, "Update Succesful", "Details have been successfully updated."); // Displaying success message.
    }
    else
    {
        QMessageBox::warning(NULL, "Unable to open members.csv", _members.errorString()); // Displaying error message if unable to open file.
    }
    _members.close();
}

//gansa

void SystemFiles::EditBook(QStringList bookData){
    _catalogue.open(QIODevice::WriteOnly| QFile::Truncate | QFile::Text);
    QTextStream catalogue_output(&_catalogue);
    catalogue_output << "BOOK ID" << "," << "IMAGE" << "," << "BOOK NAME" << "," << "AUTHOR" << "," << "COPIES" << "," << "EDIT BOOK" << "\n";
    int i=6;
    int amount = (bookData.size() / 6) - 1;
    for (int row = 0; row < amount; row++){
            catalogue_output << bookData[i] << "," << bookData[i+1] << "," << bookData[i+2] << "," << bookData[i+3] << "," << bookData[i+4] << "," << "PushButton" << "\n";
            i = i + 6;
    }
    _catalogue.close();
}

QDate SystemFiles::FindLastReserveDate(QString bookID)
{
    // We need to check if the book exists in reserved books first
    // If it doesn't, then it means it hasn't been reserved before and that it's only just hit 0 copies from a normal checkout.
    // Therefore, we need to search the checkedOutBooks file instead.
    QStringList reservedBooks = GetFileData(CSVFiles::_ReservedBooks);

    QDate date;
    QString minimumDate;
    int bookCount1 = 0;
    int bookCount2 = 0; // Multiple people may have reserved the same book
                        // In this case, we need to find the last known spot in the CSV of the reserved book.
                        // The last known spot will be the latest reserved date. We can get that due date and set that
                        // as the minimum date a user can set their next reservation.

    for (int i = 0; i < reservedBooks.size(); i++)
    {
        if (reservedBooks[i] == bookID)
        {
            bookCount1++;
        }
    }
    if (bookCount1 != 0)
    {
        for (int i = 0; i < reservedBooks.size(); i++)
        {
            if (reservedBooks[i] == bookID)
            {
                bookCount2++;
                if (bookCount2 == bookCount1)
                {
                    date = QDate::fromString(reservedBooks[i+5], "dd/MM/yyyy");
                    break;
                }
            }
        }
    }
    else // The book doesn't exist in this file, therefore we check checkedOutBooks instead.
    {
        QStringList checkedOutBooks = GetFileData(CSVFiles::_CheckedOutBooks);

        for (int i = 0; i < checkedOutBooks.size(); i++)
        {
            if (checkedOutBooks[i] == bookID)
            {
                bookCount1++;
            }
        }
        for (int i = 0; i < checkedOutBooks.size(); i++)
        {
            if (checkedOutBooks[i] == bookID)
            {
                bookCount2++;
                if (bookCount2 == bookCount1)
                {
                    date = QDate::fromString(checkedOutBooks[i+4], "dd/MM/yyyy"); // for some reason i can't read the due date in checked out books
                    date = date.addDays(7); // so I have to do addDays(7)
                    break;
                }
            }
        }
    }

    return date;
}

// Function performed on start up
// This checks the reserved books file to see if a book has met its checkout date.
// If it has, then we add the book to the checkedOutBooks file and remove it from reserved books.
void SystemFiles::CheckReservedBooks()
{
    QStringList reservedBooks = GetFileData(CSVFiles::_ReservedBooks);
    QStringList booksForCheckOut;

    QString date = QDate::currentDate().toString("dd/MM/yyyy");
    QDate currDate = QDate::fromString(date);

    int column = 0;
    for (int i = 6; i < reservedBooks.size(); i++) // loop starts at 6 to skip the headers in the CSV file
    {
        if (column == 5)
        {
            column = 0;
            QDate bookDate = QDate::fromString(reservedBooks[i]);
            if (currDate > bookDate)
            {
                booksForCheckOut.append(reservedBooks[i - 5]); // Book ID
                booksForCheckOut.append(reservedBooks[i - 4]); // Book name
                booksForCheckOut.append(reservedBooks[i - 3]); // Member name
                booksForCheckOut.append(reservedBooks[i - 2]); // Member ID
                booksForCheckOut.append(reservedBooks[i - 1]); // Date Checked Out
                booksForCheckOut.append(reservedBooks[i]);     // Date due
            }
        }
        else
        {
            column++;
        }
    }

    // If there were books that need to be moved to the check out file then we need to rewrite the reserved books file
    if (!booksForCheckOut.empty())
    {
        if(_reserveBook.open(QIODevice::WriteOnly | QFile::Truncate | QFile::Text)) // Rewriting the reserveBook csv with the books for check out removed.
        {
            QTextStream in(&_reserveBook);
            int column = 0; // there are 5 columns in the reserved book file

            for (int i = 0; i < reservedBooks.size() - booksForCheckOut.size(); i++)
            {
                if (reservedBooks[i] != booksForCheckOut[i])
                {
                    if (column == 5)
                    {
                        column = 0;
                        in << reservedBooks[i] << "\n";
                    }
                    else
                    {
                        in << reservedBooks[i] << ",";
                        column++;
                    }
                }
            }
        }
        _reserveBook.close();

        if (_checkedOutBooks.open(QIODevice::WriteOnly | QFile::Append | QFile::Text)) // Adding the books for check out to checkedOutBooks csv
        {
            QTextStream in(&_checkedOutBooks);
            int column = 0;
            for (int i = 0; i < booksForCheckOut.size(); i++)
            {
                if (column == 5)
                {
                    column = 0;
                    in << booksForCheckOut[i] << "\n";
                }
                else
                {
                    in << booksForCheckOut[i] << ",";
                    column++;
                }
            }
        }
        _checkedOutBooks.close();
    }
}

// This function checks whether a user has overdue books when they log in.
// It searches the checkedOutBooks csv for their ID and appends any overdue books to the overdueBooks list.
// If the user has no overdue books, then it will return an empty list.
QStringList SystemFiles::CheckUsersOverdueBooks(QString memID)
{
    QStringList checkedOutBooksData = GetFileData(CSVFiles::_CheckedOutBooks);
    QStringList overdueBooks;

    QString date = QDate::currentDate().toString("dd/MM/yyyy");
    QDate currDate = QDate::fromString(date);

    if (checkedOutBooksData.indexOf(memID) > 0) // If the members ID exists in the the checkedOutBooks file
    {
        for (int i = 0; i < checkedOutBooksData.size(); i++)
        {
            if (checkedOutBooksData[i] == memID) // Find members ID on the line
            {
                QDate bookDueDate = QDate::fromString(checkedOutBooksData[i + 3]); // Convert books due date to a QDate from a string
                if (currDate > bookDueDate) // Compare the two dates
                {
                    overdueBooks.append(checkedOutBooksData[i - 1]); // Book name
                    overdueBooks.append(checkedOutBooksData[i + 3]); // Book return date
                }
            }
        }
        return overdueBooks; // returning a list with data
    }
    else
    {
        return overdueBooks; // returning an empty list
    }
}
