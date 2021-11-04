#ifndef ADMINDUE_H
#define ADMINDUE_H

#include <QDialog>

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

private:
    Ui::admindue *ui;
};

#endif // ADMINDUE_H
