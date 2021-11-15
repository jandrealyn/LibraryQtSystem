#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "checkoutscreen.h"
#include "updateuserdetails.h"

namespace Ui {
class Catalogue;
}

class Catalogue : public QDialog
{
    Q_OBJECT

public:
    explicit Catalogue(QWidget *parent = nullptr,
                       QString memUser = "",
                       QString memPass = "",
                       QString memfName = "",
                       QString memlName = "",
                       QString memEmail = "",
                       QString memPhone = "",
                       QString memID = "",
                       QString memAvatar = "");

    ~Catalogue();

signals:
    void OpenMainMenu();

private slots:
    void on_yourAccount_logout_clicked();
    void on_searchBar_textChanged(const QString &arg1);

    void on_yourAccount_update_clicked();
    //void on_home_clicked();

    void on_yourAccount_updatePic_clicked();

    void update_catalogue();

private:
    QString _memUser, _memPass, _memfName, _memlName, _memEmail, _memPhone, _memID, _memAvatar;
    Ui::Catalogue *ui;
    CheckOutScreen* c_ui;
    UpdateUserDetails* update_ui;
};

#endif // CATALOGUE_H
