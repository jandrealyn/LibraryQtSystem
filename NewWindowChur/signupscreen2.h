#ifndef SIGNUPSCREEN2_H
#define SIGNUPSCREEN2_H

#include <QDialog>

#include <QMainWindow>
#include "dialog.h"
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
    void OpenMainMenu();
private slots:
  void on_close_clicked();//function - for when the user clicks the "close" button
  void on_Next_clicked(); //function - for when the user clicks the "next" button
  void on_back_clicked(); //function - for when the user clicks the "back" button
private:
    Ui::signupscreen2 *ui;
};

#endif // SIGNUPSCREEN2_H
