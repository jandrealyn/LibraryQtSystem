#ifndef ADMINEDITUSER_H
#define ADMINEDITUSER_H

#include <QDialog>

namespace Ui {
class adminedituser;
}

class adminedituser : public QDialog
{
    Q_OBJECT

public:
    explicit adminedituser(QWidget *parent = nullptr, QString id = "", QString firstname = "", QString lastname = "", QString email = "", QString phone = "");
    ~adminedituser();

signals:
    void UpdateAdminUser();

private slots:
    void on_deleteuser_clicked();

    void on_canceledit_clicked();

    void on_confimedit_clicked();

private:
    Ui::adminedituser *ui;
    QString _userid;
};

#endif // ADMINEDITUSER_H
