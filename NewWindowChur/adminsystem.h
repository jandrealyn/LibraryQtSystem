#ifndef ADMINSYSTEM_H
#define ADMINSYSTEM_H

#include <QDialog>
#include "admindue.h"
#include "adminoverdue.h"

namespace Ui {
class adminsystem;
}

class adminsystem : public QDialog
{
    Q_OBJECT

public:
    explicit adminsystem(QWidget *parent = nullptr);
    ~adminsystem();

signals:
    void ClosedAdminHome();

private slots:
    void on_back_clicked();

    void AdminSystemClosed();

    void on_admin_due_btn_clicked();

    void on_admin_overdue_btn_clicked();

private:
    Ui::adminsystem *ui;
    admindue* admin_due;
    adminoverdue* admin_overdue;

};

#endif // ADMINSYSTEM_H
