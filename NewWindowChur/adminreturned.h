#ifndef ADMINRETURNED_H
#define ADMINRETURNED_H

#include <QDialog>

namespace Ui {
class adminreturned;
}

class adminreturned : public QDialog
{
    Q_OBJECT

public:
    explicit adminreturned(QWidget *parent = nullptr);
    ~adminreturned();

signals:
    void ClosedAdminSystem();

private slots:
    void on_back_clicked();

private:
    Ui::adminreturned *ui;
};

#endif // ADMINRETURNED_H
