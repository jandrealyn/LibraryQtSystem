#ifndef RESERVEBOOK_H
#define RESERVEBOOK_H

#include <QDialog>

namespace Ui {
class ReserveBook;
}

class ReserveBook : public QDialog
{
    Q_OBJECT

public:
    explicit ReserveBook(QWidget *parent = nullptr, QString memName = "", QString memID = "", QString bookID = "", QString bookName = "");
    ~ReserveBook();

signals:
    void ReserveScreenClosed();
    void Res_UpdateUsersCurrentBooks();
    void CloseCheckOutScreen();

private slots:
    void on_cancel_clicked();

    void on_calendarWidget_clicked(const QDate &date);

    void on_confirmReserve_clicked();

private:
    Ui::ReserveBook *ui;
    QString _membersID, _membersName, _bookID, _bookName;
    //
};

#endif // RESERVEBOOK_H
