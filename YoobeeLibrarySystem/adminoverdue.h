#ifndef ADMINOVERDUE_H
#define ADMINOVERDUE_H

#include <QDialog>

namespace Ui {
class adminoverdue;
}

class adminoverdue : public QDialog
{
    Q_OBJECT

public:
    explicit adminoverdue(QWidget *parent = nullptr);
    ~adminoverdue();

signals:
    void ClosedAdminSystem();

private slots:
    void on_back_clicked();

private:
    Ui::adminoverdue *ui;
    //
};

#endif // ADMINOVERDUE_H
