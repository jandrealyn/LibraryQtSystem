#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "catalogue.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_login_clicked(); //calling a function
    void MainMenuClosed(); //calling a function

private:
    Ui::MainWindow *ui;
    Catalogue *_catalogueWindow;//pointer to a catalogue window
};
#endif // MAINWINDOW_H
