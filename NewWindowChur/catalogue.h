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
    explicit Catalogue(QWidget *parent = nullptr, QString memId = "", QString memAvatar = "", QString memName = "", QString memEmail = "", QString memPhone = "");
    ~Catalogue();

signals:
    void OpenMainMenu();

private slots:
    void on_yourAccount_logout_clicked();
    void on_searchBar_textChanged(const QString &arg1);

    void on_yourAccount_update_clicked();
    void on_home_clicked();
    void on_yourAccount_updatePic_clicked();

private:
    QString memberName, memberID;
    Ui::Catalogue *ui;
    CheckOutScreen* c_ui;

    QString _memID, _memName;
};

#endif // CATALOGUE_H
