#ifndef ADMINSYSTEM_H
#define ADMINSYSTEM_H

#include <QDialog>

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

private:
    Ui::adminsystem *ui;
};

#endif // ADMINSYSTEM_H
