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
    explicit CheckOutScreen(QWidget *parent = nullptr, QString memName = "", QString memID = "", QString bookID = "", QString bookName = "", QString authorName = "", QString copies = "");
    ~CheckOutScreen();

    void setVariables(QString memName, QString memID, QString bookID, QString bookName, QString authorName, QString copies);

private slots:
    void on_cancel_clicked();

    void on_checkoutNow_clicked();

private:
    QString _membersID, _membersName, _bookID, _bookName;
    Ui::CheckOutScreen *ui;
};

#endif // CHECKOUTSCREEN_H
