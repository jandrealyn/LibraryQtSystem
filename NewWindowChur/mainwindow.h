#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "dialog.h"
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
    void MainMenuClosed();
    void on_login_clicked();
private:
    Ui::MainWindow *ui;
    Catalogue *_catalogueWindow;
    adminhome * _adminWindow;
    loginscreen *_loginWindow;

};
#endif // MAINWINDOW_H
