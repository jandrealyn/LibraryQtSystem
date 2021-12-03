<<<<<<< HEAD
#ifndef ADMINCATALOGUE_H
#define ADMINCATALOGUE_H

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

private:
    Ui::admincatalogue *ui;
};

#endif // ADMINCATALOGUE_H
=======
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

    void on_addbook_clicked();

    void UpdateAdminCatalogueSlot();

private:
    Ui::admincatalogue *ui;
    admineditbook *adminedit;
    adminaddbook *adminadd;
};

#endif // ADMINCATALOGUE_H
>>>>>>> 80cf8e3d315ab6dd1b1f1dcc9d041668d3846653
