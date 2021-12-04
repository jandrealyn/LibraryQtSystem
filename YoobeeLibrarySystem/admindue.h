#ifndef ADMINDUE_H
#define ADMINDUE_H

#include <QDialog>
#include "adminreturn.h"

namespace Ui {
class admindue;
}

class admindue : public QDialog
{
    Q_OBJECT

public:
    explicit admindue(QWidget *parent = nullptr);
    ~admindue();

signals:
    void ClosedAdminSystem();

private slots:
    void on_back_clicked();
    void UpdateAdminReturnSlot();

private:
    Ui::admindue *ui;
    adminreturn* ret;
    QString _id;
    //
};

#endif // ADMINDUE_H
