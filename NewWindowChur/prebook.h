#ifndef PREBOOK_H
#define PREBOOK_H

#include <QDialog>

namespace Ui {
class Prebook;
}

class Prebook : public QDialog
{
    Q_OBJECT

public:
    explicit Prebook(QWidget *parent = nullptr);
    ~Prebook();

private:
    Ui::Prebook *ui;
};

#endif // PREBOOK_H
