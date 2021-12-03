#ifndef ADMINADDUSER_H
#define ADMINADDUSER_H

#include <QDialog>

namespace Ui {
class adminadduser;
}

class adminadduser : public QDialog
{
    Q_OBJECT

public:
    explicit adminadduser(QWidget *parent = nullptr);
    ~adminadduser();

private:
    Ui::adminadduser *ui;
};

#endif // ADMINADDUSER_H
