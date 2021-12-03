<<<<<<< HEAD
#ifndef ADMINUSER_H
#define ADMINUSER_H

#include <QDialog>

namespace Ui {
class adminuser;
}

class adminuser : public QDialog
{
    Q_OBJECT

public:
    explicit adminuser(QWidget *parent = nullptr);
    ~adminuser();

private:
    Ui::adminuser *ui;
};

#endif // ADMINUSER_H
=======
#ifndef ADMINUSER_H
#define ADMINUSER_H
#include "adminedituser.h"
#include "signupscreen.h"

#include <QDialog>

namespace Ui {
class adminuser;
}

class adminuser : public QDialog
{
    Q_OBJECT

public:
    explicit adminuser(QWidget *parent = nullptr);
    ~adminuser();

signals:
    void ClosedAdminHome();

private slots:
    void on_back_clicked();

    void on_adduser_clicked();

    void UpdateAdminUserSlot();

private:
    Ui::adminuser *ui;
    adminedituser* admineditu;
    signupscreen* _signup;
};

#endif // ADMINUSER_H
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
