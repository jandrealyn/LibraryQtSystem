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
