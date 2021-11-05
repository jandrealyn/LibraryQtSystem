#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "checkoutscreen.h"

namespace Ui {
class Catalogue;
}

class Catalogue : public QDialog
{
    Q_OBJECT

public:
    explicit Catalogue(QWidget *parent = nullptr, QString memName = "", QString memID = "");
    ~Catalogue();

signals:
    void OpenMainMenu();

private slots:
    void on_yourAccount_logout_clicked();
    void on_searchBar_textChanged(const QString &arg1);

private:
    QString memberName, memberID;
    Ui::Catalogue *ui;
    CheckOutScreen* c_ui;
};

#endif // CATALOGUE_H
