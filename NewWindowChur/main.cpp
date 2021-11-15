#include "mainwindow.h"
#include "SystemFiles.h"
#include "catalogue.h"
#include <QApplication>
//testing github
int main(int argc, char *argv[])
{
    SystemFiles::CreateFilesOnStartUp();
    SystemFiles::CheckReservedBooks();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
