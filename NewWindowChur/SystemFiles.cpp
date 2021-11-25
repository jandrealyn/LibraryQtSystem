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
#include <QDebug>
#include <QTime>

// Defining static variables
QString SystemFiles::_path = "CSVFiles/";
QFile SystemFiles::_catalogue(_path + "catalogue.csv");
QFile SystemFiles::_members(_path + "members.csv");
QFile SystemFiles::_checkedOutBooks(_path + "checkedoutbooks.csv");
QFile SystemFiles::_reserveBook(_path + "reserveBook.csv");

QString SystemFiles::_logsPath = "SystemLogs/";
QFile SystemFiles::_nearbyDueDatesLog(_logsPath + "NearbyDueDatesLog.txt");
QFile SystemFiles::_overdueBooksLog(_logsPath + "OverdueBooksLog.txt");
QFile SystemFiles::_returnedBooksLog(_logsPath + "ReturnedBooksLog.txt");

void SystemFiles::CreateFilesOnStartUp()
{
    // Check if the "CSVFiles" folder exists, if not then create it.
    if (!QDir(_path).exists())
    {
        // Make the directory (the CSVFiles folder)
        QDir().mkdir(_path);
    }

    if (!QDir(_logsPath).exists())
    {
        QDir().mkdir(_logsPath);
    }

    // Checking and creating .csv files
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
        checkout_output << "BOOK ID" << "," << "BOOK NAME" << "," << "MEMBER ID" << "," << "MEMBER NAME" << "," << "DATE CHECKED OUT" << "," << "DATE DUE" << "," << "RETURN" << "\n";
        _checkedOutBooks.close();
    }

    if (!_reserveBook.exists())
    {
        _reserveBook.open(QIODevice::WriteOnly | QFile::Text);
        QTextStream prebook_output(&_reserveBook);
        prebook_output << "BOOK ID" << "," << "BOOK NAME" << "," << "MEMBER ID" << "," << "MEMBER NAME" << "," << "PREBOOK DATE" << "," << "DATE DUE" << "\n";
        _reserveBook.close();
    }

    // Checking and creating .txt files
    if (!_overdueBooksLog.exists())
    {
        _overdueBooksLog.open(QIODevice::WriteOnly);
        _overdueBooksLog.close();
    }

    if (!_nearbyDueDatesLog.exists())
    {
        _nearbyDueDatesLog.open(QIODevice::WriteOnly);
        _nearbyDueDatesLog.close();
    }

    if (!_returnedBooksLog.exists())
    {
        _returnedBooksLog.open(QIODevice::WriteOnly);
        _returnedBooksLog.close();
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
        in << id << "," << avatar << "," << fName << "," << lName << "," << uName << "," << pWord << "," << email << "," << phoneNum  << "\n";
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

//lARA cODE :))))

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

void SystemFiles::DeleteUser(QString userID){

    QStringList userList = GetFileData(CSVFiles::_Members);
    _members.open(QIODevice::WriteOnly| QFile::Truncate | QFile::Text);
    QTextStream member_output(&_members);

    member_output << "ID" << "," << "PROFILE PICTURE" << "," << "FIRST NAME" << "," << "LAST NAME" << "," << "USERNAME" << "," << "PASSWORD" << "," << "EMAIL" << "," << "PHONE NUM" << "\n";
    int i=8;
    int amount = (userList.size() / 8) - 1;
    for (int row = 0; row < amount; row++){
        if (userList[i] != userID){
            member_output << userList[i] << "," << userList[i+1] << "," << userList[i+2] << "," << userList[i+3] << "," << userList[i+4] << ","<< userList[i+5] << ","<< userList[i+6] << ","<< userList[i+7] << "\n";
        }
        i = i + 8;
    }
    _members.close();
}

void SystemFiles::CheckOutBook(QString bookID, QString bookName, QString memID, QString memName, QString dueDate)
{
    QString currentDate = QDate::currentDate().toString("dd/MM/yyyy");

    // Output the details of the checkout to checkedOutBooks file
    _checkedOutBooks.open(QIODevice::WriteOnly | QFile::Append | QFile::Text);
    QTextStream in(&_checkedOutBooks);
    in << bookID << "," << bookName << "," << memID << "," << memName << "," << currentDate << "," << dueDate << "," << "PushButton" << "\n";
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

// Overloaded function for reserving a book
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

void SystemFiles::EditUser(QStringList userData){
    _members.open(QIODevice::WriteOnly| QFile::Truncate | QFile::Text);
    QTextStream member_output(&_members);
    member_output << "ID" << "," << "PROFILE PICTURE" << "," << "FIRST NAME" << "," << "LAST NAME" << "," << "USERNAME" << "," << "PASSWORD" << "," << "EMAIL" << "," << "PHONE NUM" << "\n";
    int i=8;
    int amount = (userData.size() / 8) - 1;
    for (int row = 0; row < amount; row++){
            member_output << userData[i] << "," << userData[i+1] << "," << userData[i+2] << "," << userData[i+3] << "," << userData[i+4] << ","<< userData[i+5] << ","<< userData[i+6] << ","<< userData[i+7] << "\n";
            i = i + 8;
    }
    _members.close();
}

// Find the last reserve date for a book. This makes sure a user doesn't reserve a book during someone elses reserve date.
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
                    date = QDate::fromString(checkedOutBooks[i+5], "dd/MM/yyyy");
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
    QDate currDate = QDate::fromString(date, "dd/MM/yyyy");

    int column = 0;
    for (int i = 6; i < reservedBooks.size(); i++) // loop starts at 6 to skip the headers in the CSV file
    {
        if (column == 5)
        {
            column = 0;
            QDate bookDate = QDate::fromString(reservedBooks[i], "dd/MM/yyyy");
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
            int column = 0;

            // Outputting headers into the reserve book csv
            in << reservedBooks[0] << "," << reservedBooks[1] << "," << reservedBooks[2] << "," << reservedBooks[3] << "," << reservedBooks[4] << "," << reservedBooks[5] << "\n";

            // Finding the books that weren't added to booksForCheckOut and writing them to the file again.
            for (int i = 0; i < reservedBooks.size(); i++)
            {
                if (column == 5)
                {
                    QDate bookDate = QDate::fromString(reservedBooks[i], "dd/MM/yyyy");
                    if (currDate < bookDate)
                    {
                        in << reservedBooks[i - 5] << "," << reservedBooks[i - 4] << "," << reservedBooks[i - 3] << "," << reservedBooks[i - 2] << "," << reservedBooks[i - 1] << "," << reservedBooks[i] << "\n";
                    }
                    column = 0;
                }
                else
                {
                    column++;
                }
            }
        }
        _reserveBook.close();

        // Now we are adding the books that have met or gone over their due date into the checkedOutBooks file
        if (_checkedOutBooks.open(QIODevice::WriteOnly | QFile::Append | QFile::Text))
        {
            QTextStream in(&_checkedOutBooks);
            int column = 0;
            for (int i = 0; i < booksForCheckOut.size(); i++)
            {
                if (column == 5)
                {
                    in << booksForCheckOut[i] << "," << "PushButton" << "\n"; // this used to be [ in << booksForCheckOut[i] << "\n"; but has been changed to PushButton for laras code
                    column = 0;
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
// We do not need to check reserveBook.csv. If a book has met it's overdue date in that file, it would have already
// been moved to checkedoutbooks.csv
QStringList SystemFiles::CheckUsersOverdueBooks(QString memID)
{
    QStringList checkedOutBooksData = GetFileData(CSVFiles::_CheckedOutBooks);
    QStringList overdueBooks;

    QString date = QDate::currentDate().toString("dd/MM/yyyy");
    QDate currDate = QDate::fromString(date, "dd/MM/yyyy");

    if (checkedOutBooksData.indexOf(memID) > 0) // If the members ID exists in the the checkedOutBooks file
    {
        for (int i = 0; i < checkedOutBooksData.size(); i++)
        {
            if (checkedOutBooksData[i] == memID) // Find members ID on the line
            {
                QDate bookDueDate = QDate::fromString(checkedOutBooksData[i + 3], "dd/MM/yyyy"); // Convert books due date to a QDate from a string
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

void SystemFiles::ReturnBook(QString bookid){
    QStringList catalogueData = GetFileData(CSVFiles::_Catalogue);

    for (int i = 0; i < catalogueData.size(); i++)
    {
        if (catalogueData[i] == bookid)
        {
            catalogueData[i + 4] = QString::number(catalogueData[i + 4].toInt() + 1); // add 1 to book copies
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

    QStringList bookList = GetFileData(CSVFiles::_CheckedOutBooks);
    _checkedOutBooks.open(QIODevice::WriteOnly| QFile::Truncate | QFile::Text);
    QTextStream checkout_output(&_checkedOutBooks);

    checkout_output << "BOOK ID" << "," << "BOOK NAME" << "," << "MEMBER ID" << "," << "MEMBER NAME" << "," << "DATE CHECKED OUT" << "," << "DATE DUE" << "," << "RETURN" << "\n";
    int i=7;
    bool h = false;
    int amount = (bookList.size() / 7) - 1;
    for (int row = 0; row < amount; row++){
        if (bookList[i] != bookid){
            checkout_output << bookList[i] << "," << bookList[i+1] << "," << bookList[i+2] << "," << bookList[i+3] << "," << bookList[i+4] << "," << bookList[i+5] << "," << "PushButton" << "\n";
        }
        else if(bookList[i] == bookid) {
            if (h == true){
                checkout_output << bookList[i] << "," << bookList[i+1] << "," << bookList[i+2] << "," << bookList[i+3] << "," << bookList[i+4] << "," << bookList[i+5] << "," << "PushButton" << "\n";
            }
            h = true;
        }
        i = i + 7;
    }
    _checkedOutBooks.close();

    QMessageBox msgBox;
    msgBox.setWindowTitle("Return");
    msgBox.setText("Book Returned Successfully");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.exec();

}

// Function is called in the constructor of catalogue.
void SystemFiles::LogNearbyDueDate(QString memUser, QString memID)
{
    // check for user in checkedOutBooks
    // check if that book is due within 2 days
    // if yes, check this hasn't already been logged
    // if it hasn't, log it
    // " LOG:2:20pm:22/11/2021: 'USERNAME, ID' has book 'BOOK NAME' due in 'DAYS AMOUNT' "

    QString date = QDate::currentDate().toString("dd/MM/yyyy");
    QDate currDate = QDate::fromString(date, "dd/MM/yyyy");

    QStringList checkedOutBooksData = GetFileData(CSVFiles::_CheckedOutBooks);
    QStringList reservedBooksData = GetFileData(CSVFiles::_ReservedBooks);
    QStringList nearbyDueDatesLogData;
    QStringList validLogOutput;

    if (_nearbyDueDatesLog.open(QIODevice::ReadOnly))
        {
            QTextStream in(&_nearbyDueDatesLog);
            while(!in.atEnd())
            {
                QString line = _nearbyDueDatesLog.readLine().replace("\r\n","");
                nearbyDueDatesLogData.append(line);
            }
        }
    else
    {
        QMessageBox::warning(NULL, "Overdue Books Log Fail", _nearbyDueDatesLog.errorString());
    }
     _nearbyDueDatesLog.close();

    // data for checkedOutBooks
    for (int i = 0; i < checkedOutBooksData.size(); i++)
    {
        if (checkedOutBooksData[i] == memID)
        {
            QDate bookDueDate = QDate::fromString(checkedOutBooksData[i + 3], "dd/MM/yyyy");
            if (bookDueDate > currDate)
            {
                int daysTo = currDate.daysTo(bookDueDate);
                if (daysTo < 3) // 'nearby due date' should only include books that are due in 2 days or less
                {
                    QString line = "LOG: " + QDate::currentDate().toString() + " - " + QTime::currentTime().toString() + ": USER \"" + memUser + "\" ID \"" + memID + "\": has book \"" + checkedOutBooksData[i - 1] + "\" due in " + QString::number(daysTo) + " days.";
                    if (!nearbyDueDatesLogData.contains(line))
                    {
                        validLogOutput.append(line);
                    }
                }
            }
        }
    }

    //data for reserved books
    for (int i = 0; i < reservedBooksData.size(); i++)
    {
        if (reservedBooksData[i] == memID)
        {
            QDate bookDueDate = QDate::fromString(reservedBooksData[i + 3], "dd/MM/yyyy");
            if (bookDueDate > currDate)
            {
                int daysTo = currDate.daysTo(bookDueDate);
                if (daysTo < 3)
                {

                    QString line = "LOG: " + QDate::currentDate().toString() + " - " + QTime::currentTime().toString() + ": USER \"" + memUser + "\" ID \"" + memID + "\": has book \"" + reservedBooksData[i - 1] + "\" due in " + QString::number(daysTo) + " days.";
                    if (!nearbyDueDatesLogData.contains(line))
                    {
                        validLogOutput.append(line);
                    }
                }
            }
        }
    }

    if (!validLogOutput.empty())
    {
        if(_nearbyDueDatesLog.open(QIODevice::WriteOnly | QIODevice::Append | QFile::Text))
        {
            QTextStream in(&_nearbyDueDatesLog);
            for (int i = 0; i < validLogOutput.size(); i++)
            {
                in << validLogOutput[i] << "\n";
            }
        }
        else
        {
            QMessageBox::warning(NULL, "Nearby Due Dates Fail", _nearbyDueDatesLog.errorString());
        }
        _nearbyDueDatesLog.close();
    }
}

void SystemFiles::LogOverdueBook(QString memUser, QString memID, QStringList overdueBooks)
{
    // check for user in checkedOutBooks
    // check if that books duedate is less than the current date
    // if yes, check this hasn't already been logged
    // if it hasn't, log it
    // " LOG:2:20pm:22/11/2021: 'USERNAME, ID' has book 'BOOK NAME' overdue by 'DAYS AMOUNT' "

    QString date = QDate::currentDate().toString("dd/MM/yyyy");
    QDate currDate = QDate::fromString(date, "dd/MM/yyyy");

    QStringList overdueBooksLogData;
    if (_overdueBooksLog.open(QIODevice::ReadOnly))
        {
            QTextStream in(&_overdueBooksLog);
            while(!in.atEnd())
            {
                QString line = _overdueBooksLog.readLine().replace("\r\n","");
                overdueBooksLogData.append(line);
            }
        }
    else
    {
        QMessageBox::warning(NULL, "Overdue Books Log Fail", _overdueBooksLog.errorString());
    }
     _overdueBooksLog.close();

     if (_overdueBooksLog.open(QIODevice::WriteOnly | QFile::Append | QFile::Text))
     {
         QTextStream in(&_overdueBooksLog);
         for (int i = 0; i < overdueBooks.size();)
         {
             QDate bookDueDate = QDate::fromString(overdueBooks[i + 1], "dd/MM/yyyy");
             int daysDiff = bookDueDate.daysTo(currDate);

             QString content = "LOG: " + QTime::currentTime().toString() + " - " + QDate::currentDate().toString() + ": USER \"" + memUser + "\" ID \"" + memID + "\": has book \"" + overdueBooks[i] + "\" overdue by " + QString::number(daysDiff) + " days.";
             if (!overdueBooksLogData.contains(content))
             {
                in << content << "\n";
             }
             i = i + 2;
         }
     }
     else
     {
         QMessageBox::warning(NULL, "Overdue Books Log Fail", _overdueBooksLog.errorString());
     }
     _overdueBooksLog.close();
}

void SystemFiles::LogReturnedBook()
{
    // once a book has been returned, log the Date, Time, Book ID, User ID, "
    // " LOG:2:20pm:22/11/2021: 'USERNAME, ID' has returned 'BOOK NAME'. "
}
