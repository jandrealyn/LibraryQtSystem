#ifndef ADMINCATALOGUE_H
#define ADMINCATALOGUE_H
#include "admineditbook.h"

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

    void on_verticalScrollBar_sliderMoved(int position);

    void admincatalogueUpdate();

private:
    Ui::admincatalogue *ui;
    admineditbook *adminedit;
};

#endif // ADMINCATALOGUE_H
