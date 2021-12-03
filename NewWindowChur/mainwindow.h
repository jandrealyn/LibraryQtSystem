#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
<<<<<<< HEAD
#include "catalogue.h"
#include "adminhome.h"
#include "loginscreen.h"
=======
#include "dialog.h"
>>>>>>> parent of bb486ec... Add files via upload

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
<<<<<<< HEAD
    void MainMenuOpen(); // - Liv
//    void MainMenuClosed();
    void on_login_clicked(); // - Liv

    void on_searchBar_textChanged(const QString &arg1); // Jakob

private:
    Ui::MainWindow *ui;
    Catalogue *_catalogueWindow; // - Liv
    adminhome * _adminWindow; // - Liv
    loginscreen *_loginWindow; // - Liv

=======
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Dialog *window;
>>>>>>> parent of bb486ec... Add files via upload
};
#endif // MAINWINDOW_H
