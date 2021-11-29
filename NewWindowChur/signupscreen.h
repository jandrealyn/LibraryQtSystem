#ifndef SIGNUPSCREEN_H
#define SIGNUPSCREEN_H

#include <QDialog>
#include <QMainWindow>
#include "catalogue.h"
#include "signupscreen2.h" // jakob

//--- Livs Part --//
namespace Ui {class signupscreen;}
QT_END_NAMESPACE

class signupscreen : public QDialog
{
    Q_OBJECT

public:
    explicit signupscreen(QWidget *parent = nullptr);
    ~signupscreen();

signals:
    void OpenLoginScreen();

private slots:
    void on_Next_clicked(); //function - for when the user clicks "next" button - Liv
    void Signupclosed(); //function - for when the user clicks "close" button - Liv

    void on_close_clicked(); //function - for when the user clicks "close" button and what happens after - Liv

    void on_Username_textChanged(const QString &arg1); // --------
                                                       //        |
    void on_email_textChanged(const QString &arg1);    //        |
                                                       //        |
    void on_cat_avatar_toggled(bool checked);          //        |
                                                       //        |
    void on_pup_avatar_toggled(bool checked);          //        |  ---- Jakob's code
                                                       //        |
    void on_jerboa_avatar_toggled(bool checked);       //        |
                                                       //        |
    void on_no_avatar_toggled(bool checked);           //        |
                                                       //        |
    void checkValues();                                // --------

private:
    Ui::signupscreen *ui;
    signupscreen2* Signupscreen2; // liv
    QString _avatar; // jakob
    bool _usernameOk; // jakob
    bool _emailOk; // jakob
    bool _avatarSelected; // jakob
    QStringList _membersList; // jakob
};

#endif // SIGNUPSCREEN_H
