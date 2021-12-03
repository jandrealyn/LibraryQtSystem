<<<<<<< HEAD
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
#include "catalogue.h"
#include "adminhome.h"

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
    void on_login_clicked();
    void MainMenuClosed();

private:
    Ui::MainWindow *ui;
    Catalogue *_catalogueWindow;
    adminhome * _adminWindow;
};
#endif // MAINWINDOW_H
=======
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "catalogue.h"
#include "adminhome.h"
#include "loginscreen.h"

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
    void MainMenuOpen(); // - Liv
//    void MainMenuClosed();
    void on_login_clicked(); // - Liv

    void on_searchBar_textChanged(const QString &arg1); // Jakob

private:
    Ui::MainWindow *ui;
    Catalogue *_catalogueWindow; // - Liv
    adminhome * _adminWindow; // - Liv
    loginscreen *_loginWindow; // - Liv

};
#endif // MAINWINDOW_H
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
