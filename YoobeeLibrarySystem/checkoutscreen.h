#ifndef CHECKOUTSCREEN_H
#define CHECKOUTSCREEN_H

#include <QDialog>
#include "reservebook.h"

namespace Ui {
class CheckOutScreen;
}

class CheckOutScreen : public QDialog
{
    Q_OBJECT

public:
    explicit CheckOutScreen(QWidget *parent = nullptr, QString memName = "", QString memID = "", QString bookID = "", QString bookName = "", QString authorName = "", QString copies = "");
    ~CheckOutScreen();

signals:
    void UpdateCatalogue();
    void UpdateCheckOutScreenSignal();
    void UpdateUsersCurrentBooks();

private slots:
    void on_cancel_clicked();

    void on_checkoutNow_clicked();

    void on_reserve_clicked();

    void OpenCheckOutScreen();

    void UpdateCheckOutScreenSlot();

    void Res_UpdateUsersCurrentBooks_Emitted();

private:
    Ui::CheckOutScreen *ui;
    QString _membersID, _membersName, _bookID, _bookName, _copies;
    ReserveBook* _reserveBook;
};

#endif // CHECKOUTSCREEN_H
