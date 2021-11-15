#ifndef ADMINCATALOGUE_H
#define ADMINCATALOGUE_H
#include "admineditbook.h"
#include "adminaddbook.h"

#include <QDialog>

namespace Ui {
class admincatalogue;
}

class admincatalogue : public QDialog
{
    Q_OBJECT

public:
    explicit admincatalogue(QWidget *parent = nullptr);
    ~admincatalogue();

signals:
    void ClosedAdminHome();

private slots:
    void on_back_clicked();

    void admincatalogueUpdate();

    void on_addbook_clicked();

private:
    Ui::admincatalogue *ui;
    admineditbook *adminedit;
    adminaddbook *adminadd;
};

#endif // ADMINCATALOGUE_H
