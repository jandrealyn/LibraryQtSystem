#ifndef UPDATEUSERPICTURE_H
#define UPDATEUSERPICTURE_H

#include <QDialog>

namespace Ui {
class UpdateUserPicture;
}

class UpdateUserPicture : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateUserPicture(QWidget *parent = nullptr);
    ~UpdateUserPicture();

private:
    Ui::UpdateUserPicture *ui;
};

#endif // UPDATEUSERPICTURE_H
