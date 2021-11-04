#ifndef CREATEFILES_H
#define CREATEFILES_H
#include <QDir>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>

class CreateFiles
{
public:
    enum FileFlag
    {
        catalogue = 1,
        members = 2,
        checkedOut = 3
    };

    CreateFiles();

    static void CreateFilesOnStartUp();

    static QString _path;
    static QFile _catalogue;
    static QFile _members;
    static QFile _checkedOutBooks;

    static QStringList GetFileData(QString file);
    static void CreateMember(QString fName, QString lName, QString uName, QString pWord, QString email, QString phoneNum);
};

#endif // CREATEFILES_H
