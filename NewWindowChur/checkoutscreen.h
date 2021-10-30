#ifndef CHECKOUTSCREEN_H
#define CHECKOUTSCREEN_H

#include <QDialog>

namespace Ui {
class CheckOutScreen;
}

class CheckOutScreen : public QDialog
{
    Q_OBJECT

public:
    explicit CheckOutScreen(QWidget *parent = nullptr);
    ~CheckOutScreen();

private slots:
    void on_cancel_clicked();
    void get_Book_Name(QString name);

private:
    Ui::CheckOutScreen *ui;
};

#endif // CHECKOUTSCREEN_H
