#ifndef UPDATEUSERDETAILS_H
#define UPDATEUSERDETAILS_H

#include <QDialog>

namespace Ui {
class UpdateUserDetails;
}

class UpdateUserDetails : public QDialog
{
    Q_OBJECT

public:
    explicit UpdateUserDetails(QWidget *parent = nullptr);
    ~UpdateUserDetails();

private:
    Ui::UpdateUserDetails *ui;
};

#endif // UPDATEUSERDETAILS_H
