#include "mainwindow.h"
<<<<<<< HEAD
#include "createfiles.h"
#include "catalogue.h"
#include <QApplication>
//testing github
int main(int argc, char *argv[])
{
    CreateFiles::CreateFilesOnStartUp();
=======
#include "SystemFiles.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    SystemFiles::CreateFilesOnStartUp();
    SystemFiles::CheckReservedBooks();
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
