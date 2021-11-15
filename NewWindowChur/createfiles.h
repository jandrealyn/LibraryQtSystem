#ifndef CREATEFILES_H
#define CREATEFILES_H
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

class CreateFiles
{
public:
    CreateFiles();

    static void CreateFilesOnStartUp();
    static QStringList GetFileData(enum CSVFiles);
    static void CreateMember(QString avatar, QString fName, QString lName, QString uName, QString pWord, QString email, QString phoneNum);
    static void CheckOutBook(QString bookID, QString bookName, QString memID, QString memName, QString dueDate);
    static void CheckOutBook(QString bookID, QString bookName, QString memID, QString memName, QString reserveDate, QString dueDate);
    static void EditBook(QStringList bookData);
    static void UpdateMemberDetails(QStringList membersData);
    static QDate FindLastReserveDate(QString bookID);

    static QString _path;
    static QFile _catalogue;
    static QFile _members;
    static QFile _checkedOutBooks;
    static QFile _reserveBook;
};

#endif // CREATEFILES_H
