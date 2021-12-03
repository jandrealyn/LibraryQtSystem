<<<<<<< HEAD
#include "mainwindow.h"
#include "SystemFiles.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    SystemFiles::CreateFilesOnStartUp();
    SystemFiles::CheckReservedBooks();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
=======
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
>>>>>>> parent of bb486ec... Add files via upload
