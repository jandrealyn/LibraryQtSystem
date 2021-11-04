#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "catalogue.h"
#include "signupscreen.h"

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
    void on_login_clicked(); //calling a function from Mainwindow.cpp
    void MainMenuOpen(); //calling a function

    void on_Create_clicked(); //calling a function from signupscreen.cpp

private:
    Ui::MainWindow *ui;
    Catalogue *_catalogueWindow;//pointer to a catalogue window
    signupscreen *_signup; //pointer to a signup window
};
#endif // MAINWINDOW_H
