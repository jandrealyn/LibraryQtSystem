#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QDialog>
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
    void on_login_clicked();
    void MainMenuOpen();
    void on_Create_clicked();
    void on_close_clicked();

private:
    Ui::loginscreen *ui;
    Catalogue *_catalogueWindow;//pointer to a catalogue window
    signupscreen *_signup; //pointer to a signup window
    adminhome * _adminWindow; //pointer to the admin window


};

#endif // LOGINSCREEN_H
