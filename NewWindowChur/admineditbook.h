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

    //void setVariables(QString bookID, QString bookName, QString authorName, QString copies);

private:
    Ui::admineditbook *ui;
    QString _bookID;
};

#endif // ADMINEDITBOOK_H
