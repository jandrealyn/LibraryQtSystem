#ifndef CREATEFILES_H
#define CREATEFILES_H
#include <QDir>
#include <QFile>
#include <QTextStream>

class CreateFiles
{
public:
    CreateFiles();

    static void CreateFilesOnStartUp();

    static QString _path;
    static QFile _catalogue;
    static QFile _duedate;
    static QFile _overdue;
    static QFile _return;
    static QFile _members;
};

#endif // CREATEFILES_H
