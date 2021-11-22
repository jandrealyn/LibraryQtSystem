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
    explicit admineditbook(QWidget *parent = nullptr, QString bookID = "", QString bookName = "", QString authorName = "", QString copies = "");
    ~admineditbook();

signals:
    void UpdateAdminCatalogue();

private slots:
    void on_canceledit_clicked();

    void on_confimedit_clicked();

    void on_deletebook_clicked();

private:
    Ui::admineditbook *ui;
    QString _bookID, _bookName;
};

#endif // ADMINEDITBOOK_H
