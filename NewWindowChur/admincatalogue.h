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
