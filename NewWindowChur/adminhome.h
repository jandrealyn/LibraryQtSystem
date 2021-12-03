#ifndef ADMINHOME_H
#define ADMINHOME_H

#include <QDialog>
#include "admincatalogue.h"
#include "adminuser.h"
#include "adminsystem.h"


namespace Ui {
class adminhome;
}

class adminhome : public QDialog
{
    Q_OBJECT

public:
    explicit adminhome(QWidget *parent = nullptr);
    ~adminhome();

signals:
    void ClosedMainMenu();

private slots:


    void on_admin_catalogue_btn_clicked();

    void on_admin_user_btn_clicked();

    void on_admin_system_btn_clicked();

    void on_logout_clicked();

    void AdminHomeClosed();

private:
    Ui::adminhome *ui;
    admincatalogue *admin_cat;
    adminuser *admin_use;
    adminsystem *admin_sys;
};

#endif // ADMINHOME_H
