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

signals:
    void ClosedAdminHome();

private slots:
    void on_back_clicked();

    void on_adduser_clicked();

private:
    Ui::adminuser *ui;
};

#endif // ADMINUSER_H
