#include "adminsystem.h"
#include "ui_adminsystem.h"

//Laras Code :)

adminsystem::adminsystem(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminsystem)
{
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));
}

adminsystem::~adminsystem()
{
    delete ui;
}

void adminsystem::on_back_clicked()
{
    close();
    emit ClosedAdminHome(); //Closes this screen, re-opens home
}

//Opens admin checked out books and closes this screen
void adminsystem::on_admin_due_btn_clicked()
{
    hide();
    admin_due = new admindue(nullptr);
    admin_due->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
    admin_due->showNormal();
    connect(admin_due, SIGNAL(ClosedAdminSystem()), this, SLOT(AdminSystemClosed()));
}

//Opens admin overdue books and closes this screen
void adminsystem::on_admin_overdue_btn_clicked()
{
    hide();
    admin_overdue = new adminoverdue(nullptr);
    admin_overdue->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
    admin_overdue->showNormal();
    connect(admin_overdue, SIGNAL(ClosedAdminSystem()), this, SLOT(AdminSystemClosed()));
}

void adminsystem::AdminSystemClosed()
{
    show();
}

