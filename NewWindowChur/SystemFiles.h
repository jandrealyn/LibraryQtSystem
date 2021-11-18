#ifndef SYSTEMFILES_H
#define SYSTEMFILES_H
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

enum CSVFiles
{
    _Catalogue,
    _Members,
    _CheckedOutBooks,
    _ReservedBooks
};

//enum MyEnum
//{
//    CSVFiles = _Catalogue | _Members,
//    Test,
//    One
//};

class SystemFiles
{
public:
    SystemFiles();

    static void CreateFilesOnStartUp();
    static QStringList GetFileData(enum CSVFiles);
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

    static QString _path;
    static QFile _catalogue;
    static QFile _members;
    static QFile _checkedOutBooks;
    static QFile _reserveBook;
};

#endif // SYSTEMFILES_H
