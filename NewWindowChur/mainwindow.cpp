#include "mainwindow.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "catalogue.h"
#include "QMessageBox"
#include "QCheckBox"
#include <QDebug>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString user = ui->lineEditUser->text();
    QString pass = ui->lineEditPass->text();

    if(user == "test" && pass == "test"){
        hide();
        _catalogueWindow = new Catalogue(this);
        _catalogueWindow->show();
        connect(_catalogueWindow, SIGNAL(ClosedMainMenu()), this, SLOT(MainMenuClosed()));
    }
    else {
        QMessageBox::warning(this, "Login", "Unsucessful, try again.");
    }

   // window = new Dialog(this);
    // window->show();

}

void MainWindow::MainMenuClosed()
{
    show();
}
