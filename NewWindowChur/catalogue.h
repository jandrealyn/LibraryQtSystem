#ifndef CATALOGUE_H
#define CATALOGUE_H

#include <QDialog>

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

private:
    Ui::Catalogue *ui;
};

#endif // CATALOGUE_H
