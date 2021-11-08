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
    _CheckedOutBooks
};

class CreateFiles
{
public:
    CreateFiles();

    static void CreateFilesOnStartUp();
    static QStringList GetFileData(enum CSVFiles);
    static void CreateMember(QString avatar, QString fName, QString lName, QString uName, QString pWord, QString email, QString phoneNum);
    static void CheckOutBook(QString bookID, QString bookName, QString memID, QString memName);

    static QString _path;
    static QFile _catalogue;
    static QFile _members;
    static QFile _checkedOutBooks;
};

#endif // CREATEFILES_H
