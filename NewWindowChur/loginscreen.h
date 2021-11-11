#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QDialog> // the base class of dialog windows
#include "dialog.h"
#include "catalogue.h"
#include "signupscreen.h"
#include "adminhome.h"

namespace Ui {class loginscreen;}

class loginscreen : public QDialog{
    Q_OBJECT

public:
    explicit loginscreen(QWidget *parent = nullptr);
    ~loginscreen();

signals:
    void OpenMainMenu();

private slots:
    void on_login_clicked(); // - Liv
    void on_Create_clicked(); // - Liv
    void on_close_clicked(); // - Liv
    void LoginScreenOpen(); // - Liv

private:
    Ui::loginscreen *ui;
    Catalogue *_catalogueWindow;//pointer to a catalogue window // - Liv
    signupscreen *_signup; //pointer to a signup window // - Liv
    adminhome * _adminWindow; //pointer to the admin window // - Liv

};

#endif // LOGINSCREEN_H
