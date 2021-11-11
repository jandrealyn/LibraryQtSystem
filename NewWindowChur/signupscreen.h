#ifndef SIGNUPSCREEN_H
#define SIGNUPSCREEN_H

#include <QDialog>
#include <QMainWindow>
#include "dialog.h"
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
    void on_Next_clicked(); //function - for when the user clicks "next" button
    void Signupclosed(); //function - for when the user clicks "close" button

    void on_close_clicked(); //function - for when the user clicks "close" button and what happens after

    void on_Username_textChanged(const QString &arg1);

    void on_cat_avatar_toggled(bool checked);

    void on_pup_avatar_toggled(bool checked);

    void on_jerboa_avatar_toggled(bool checked);

    void on_radioButton_toggled(bool checked);

    void checkValues();

    void on_email_textChanged(const QString &arg1);

private:
    Ui::signupscreen *ui;
    signupscreen2* _signup2;
    QString _avatar; // jakob
    bool _usernameOk; // jakob
    bool _emailOk; // jakob
    QStringList _membersList; // jakob
};

#endif // SIGNUPSCREEN_H
