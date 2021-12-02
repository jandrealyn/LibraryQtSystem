#ifndef SYSTEMFILES_H
#define SYSTEMFILES_H

#include <QString>
#include <QDate>
#include <QFile>

// Enum used in GetFileData function
enum CSVFiles
{
    _Catalogue = 0,
    _Members,
    _CheckedOutBooks,
    _ReservedBooks
};

class SystemFiles
{
public:
    static void CreateFilesOnStartUp();
    static QStringList GetFileData(enum CSVFiles file);
    static void CreateMember(QString avatar, QString fName, QString lName, QString uName, QString pWord, QString email, QString phoneNum);
    static void CreateBook(QString bookimg, QString title, QString author, QString copies);
    static void DeleteBook(QString bookID);
    static void DeleteUser(QString userID);
    static void CheckOutBook(QString bookID, QString bookName, QString memID, QString memName, QString dueDate);
    static void CheckOutBook(QString bookID, QString bookName, QString memID, QString memName, QString reserveDate, QString dueDate);
    static void EditBook(QStringList bookData);
    static void EditUser(QStringList userData);
    static void UpdateMemberDetails(QStringList membersData);
    static QDate FindLastReserveDate(QString bookID);
    static void CheckReservedBooks();
    static QStringList CheckUsersOverdueBooks(QString memID);
    static void ReturnBook(QString bookid);
    static void LogNearbyDueDate(QString memUser, QString memID);
    static void LogOverdueBook(QString memUser, QString memID, QStringList overdueBooks);
    static void LogReturnedBook(QString bookID, QString bookN, QString userID, QString userN);

    // Functional files (used for reading and writing data, all .csv files)
    static QString _path;
    static QFile _catalogue;
    static QFile _members;
    static QFile _checkedOutBooks;
    static QFile _reserveBook;

    // Log files (used for checking information on the system, all .txt files)
    static QString _logsPath;  // Logs will be kept in this folder.
    static QFile _nearbyDueDatesLog;  // System should log messages in a "due-date" file whenever the due date of their loaned books is nearby.
    static QFile _overdueBooksLog;  // System should log messages in an "overdue" file whenever a book is overdue.
    static QFile _returnedBooksLog; // System should log messages in the "return" file whenever a book is returned.

};

#endif // SYSTEMFILES_H
