#ifndef ADMINADDBOOK_H
#define ADMINADDBOOK_H

#include <QDialog>

namespace Ui {
class adminaddbook;
}

class adminaddbook : public QDialog
{
    Q_OBJECT

public:
    explicit adminaddbook(QWidget *parent = nullptr);
    ~adminaddbook();

private slots:
    void on_confirmadd_clicked();

    void on_canceladd_clicked();



    void on_bookone_toggled(bool checked);

    void on_booktwo_toggled(bool checked);

    void on_bookthree_toggled(bool checked);

private:
    Ui::adminaddbook *ui;
    QString bookimg; // jakob // jakob
    bool bookadded;
};

#endif // ADMINADDBOOK_H
