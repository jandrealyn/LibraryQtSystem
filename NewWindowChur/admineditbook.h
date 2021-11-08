#ifndef ADMINEDITBOOK_H
#define ADMINEDITBOOK_H

#include <QDialog>

namespace Ui {
class admineditbook;
}

class admineditbook : public QDialog
{
    Q_OBJECT

public:
    explicit admineditbook(QWidget *parent = nullptr);
    ~admineditbook();

private:
    Ui::admineditbook *ui;
};

#endif // ADMINEDITBOOK_H
