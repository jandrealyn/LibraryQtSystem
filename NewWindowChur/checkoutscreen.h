#ifndef CHECKOUTSCREEN_H
#define CHECKOUTSCREEN_H

#include <QDialog>
<<<<<<< HEAD
=======
#include "reservebook.h"
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653

namespace Ui {
class CheckOutScreen;
}

class CheckOutScreen : public QDialog
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit CheckOutScreen(QWidget *parent = nullptr);
    ~CheckOutScreen();

private slots:
    void on_cancel_clicked();
    void get_Book_Name(QString name);

private:
    Ui::CheckOutScreen *ui;
=======
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
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
};

#endif // CHECKOUTSCREEN_H
