#ifndef OVERDUE_H
#define OVERDUE_H

#include <QDialog>

namespace Ui {
class Overdue;
}

class Overdue : public QDialog
{
    Q_OBJECT

public:
    explicit Overdue(QWidget *parent = nullptr, QStringList overdueBooks = {""});
    ~Overdue();

private slots:
    void on_pushButton_gotIt_clicked();

private:
    Ui::Overdue *ui;
    //
};

#endif // OVERDUE_H
