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
