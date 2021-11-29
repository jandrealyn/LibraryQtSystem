#include "adminhome.h"
#include "admincatalogue.h"
#include "adminuser.h"
#include "adminsystem.h"
#include "ui_adminhome.h"

//Laras Code :)

adminhome::adminhome(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminhome)
{
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio));
}

adminhome::~adminhome()
{
    delete ui;
}

//Open admin catalogue and closes this screen
void adminhome::on_admin_catalogue_btn_clicked()
{
    hide();
    admin_cat = new admincatalogue(nullptr);
    admin_cat->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
    admin_cat->showNormal();
    connect(admin_cat, SIGNAL(ClosedAdminHome()), this, SLOT(AdminHomeClosed()));
}

//Opens admin user and closes this screen
void adminhome::on_admin_user_btn_clicked()
{
    hide();
    admin_use = new adminuser(nullptr);
    admin_use->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
    admin_use->showNormal();
    connect(admin_use, SIGNAL(ClosedAdminHome()), this, SLOT(AdminHomeClosed()));
}

//Opens admin system and closes this screen
void adminhome::on_admin_system_btn_clicked()
{
    hide();
    admin_sys = new adminsystem(nullptr);
    admin_sys->setWindowFlags(windowFlags() | Qt::WindowMinimizeButtonHint);
    admin_sys->showNormal();
    connect(admin_sys, SIGNAL(ClosedAdminHome()), this, SLOT(AdminHomeClosed()));
}

//Logs out of admin and goes back to log in
void adminhome::on_logout_clicked()
{
    close();
    emit ClosedMainMenu();
}

void adminhome::AdminHomeClosed()
{
    show();
}
