#ifndef CATALOGUE_H
#define CATALOGUE_H

#include "checkoutscreen.h"

namespace Ui {
class Catalogue;
}

class Catalogue : public QDialog
{
    Q_OBJECT

public:
    explicit Catalogue(QWidget *parent = nullptr);
    ~Catalogue();

    //static void CreateCatalogue();

signals:
    void ClosedMainMenu();

private slots:
    void on_yourAccount_logout_clicked();

    void on_checkOutButton_clicked();

private:
    Ui::Catalogue *ui;
    CheckOutScreen* c_ui;
};

#endif // CATALOGUE_H
