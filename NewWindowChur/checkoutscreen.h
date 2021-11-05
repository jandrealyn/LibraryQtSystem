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

    void setVariables(QString memID, QString bookName, QString authorName, QString copies);

private slots:
    void on_cancel_clicked();

    void on_checkoutNow_clicked();

private:
    QString membersID;
    Ui::CheckOutScreen *ui;
};

#endif // CHECKOUTSCREEN_H
