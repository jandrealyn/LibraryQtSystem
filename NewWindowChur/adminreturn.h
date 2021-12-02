#ifndef ADMINRETURN_H
#define ADMINRETURN_H

#include <QDialog>

namespace Ui {
class adminreturn;
}

class adminreturn : public QDialog
{
    Q_OBJECT

public:
    explicit adminreturn(QWidget *parent = nullptr, QString bookID = "", QString bookName = "", QString memberName = "", QString memberID = "");
    ~adminreturn();

signals:
    void UpdateAdminReturn();

private slots:
    void on_yesreturn_clicked();

    void on_noreturn_clicked();

private:
    Ui::adminreturn *ui;
    QString id, userid, bookn, usern;
};

#endif // ADMINRETURN_H
