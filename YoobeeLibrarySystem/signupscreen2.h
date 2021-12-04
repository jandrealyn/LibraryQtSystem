#ifndef SIGNUPSCREEN2_H
#define SIGNUPSCREEN2_H

#include <QDialog>  // the base class of dialog windows
#include <QMainWindow>
#include "catalogue.h"


//--- Livs Part --//
namespace Ui {class signupscreen2;}
QT_END_NAMESPACE

class signupscreen2 : public QDialog
{
    Q_OBJECT

public:
    explicit signupscreen2(QWidget *parent = nullptr);
    ~signupscreen2();

signals:
    void OpenLoginScreen();

private slots:
  void on_close_clicked();//function - for when the user clicks the "close" button // - Liv
  void on_done_clicked(); //function - for when the user clicks the "done" button // - Liv
private:
    Ui::signupscreen2 *ui; // - Liv
    signupscreen2 *Signup; // - Liv
    //
};

#endif // SIGNUPSCREEN2_H
