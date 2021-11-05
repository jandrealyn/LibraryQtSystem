#include "mainwindow.h"
#include "adminhome.h"
#include "loginscreen.h"
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

void MainWindow::on_login_clicked(){
 hide();
  _loginWindow = new loginscreen(nullptr);
  _loginWindow->setWindowFlags((windowFlags()) | Qt::WindowMinimizeButtonHint);
  _loginWindow->show();
  connect(_loginWindow, SIGNAL(OpenMainMenu()), this, SLOT(MainMenuOpen()));
}
void MainWindow::MainMenuOpen()
{
    show();
}
