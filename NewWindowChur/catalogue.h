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
//    static void BookNameSignal(QString bookName);
//    static void BookAuthorSignal(QString bookAuthor);
//    static void BookCopiesSignal(QString bookCopies);

private slots:
    void on_yourAccount_logout_clicked();
    void on_searchBar_textChanged(const QString &arg1);

private:
    Ui::Catalogue *ui;
    CheckOutScreen* c_ui;
};

#endif // CATALOGUE_H
