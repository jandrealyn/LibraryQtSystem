#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "checkoutscreen.h"
<<<<<<< HEAD
=======
#include "updateuserdetails.h"
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653

namespace Ui {
class Catalogue;
}

class Catalogue : public QDialog
{
    Q_OBJECT

public:
<<<<<<< HEAD
    explicit Catalogue(QWidget *parent = nullptr);
    ~Catalogue();

    //static void CreateCatalogue();

signals:
    void ClosedMainMenu();

private slots:
    void on_yourAccount_logout_clicked();

    void on_checkOutButton_clicked();

    void on_searchBar_textChanged(const QString &arg1);

    void on_addBook_clicked();

    void mySlot();

    void on_lineEdit_textChanged(const QString &arg1);

private:
    Ui::Catalogue *ui;
    CheckOutScreen* c_ui;
=======
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
    //void on_home_clicked(); // liv

    //void update_catalogue();
    void display_catalogue();

    void update_usersBooks();

private:    
    Ui::Catalogue *ui;
    QString pushButtonStyleSheet;
    CheckOutScreen* c_ui;
    UpdateUserDetails* update_ui;
    QString _memUser, _memPass, _memfName, _memlName, _memEmail, _memPhone, _memID, _memAvatar;

>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653

};

#endif // CATALOGUE_H
