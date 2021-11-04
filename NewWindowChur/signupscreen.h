#ifndef SIGNUPSCREEN_H
#define SIGNUPSCREEN_H

#include <QDialog>
#include <QMainWindow>
#include "dialog.h"
#include "catalogue.h"

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
    void OpenMainMenu();

private slots:
    void on_Next_clicked(); //function - for when the user clicks "next" button
    void Signupclosed(); //function - for when the user clicks "close" button

    void on_close_clicked(); //function - for when the user clicks "close" button and what happens after

    void on_Next_clicked();

private:
    Ui::signupscreen *ui;
};

#endif // SIGNUPSCREEN_H
