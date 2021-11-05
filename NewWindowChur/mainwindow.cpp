#include "mainwindow.h"
#include "adminhome.h"
#include "dialog.h"
#include "ui_mainwindow.h"
#include "catalogue.h"
#include "QMessageBox"
#include "QCheckBox"
#include <QDebug>
#include <QPushButton>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::MainMenuClosed()
{
    show();
}
