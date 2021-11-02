#ifndef SIGNUPSCREEN_H
#define SIGNUPSCREEN_H

#include <QDialog>
#include <QMainWindow>
#include "dialog.h"
#include "catalogue.h"

namespace Ui {class signupscreen;}
QT_END_NAMESPACE

class signupscreen : public QDialog
{
    Q_OBJECT

public:
    explicit signupscreen(QWidget *parent = nullptr);
    ~signupscreen();

private slots:
    void on_next_clicked();

private:
    Ui::signupscreen *ui;
};

#endif // SIGNUPSCREEN_H
