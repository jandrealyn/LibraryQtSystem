#include "mainwindow.h"
#include "createfiles.h"
#include "catalogue.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    CreateFiles::CreateFilesOnStartUp();

    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
