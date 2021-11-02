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

    void setLabels(QString bookName, QString authorName, QString copies);

private slots:
    void on_cancel_clicked();

private:
    QString bookID;
    Ui::CheckOutScreen *ui;
};

#endif // CHECKOUTSCREEN_H
