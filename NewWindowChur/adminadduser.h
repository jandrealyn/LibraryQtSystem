<<<<<<< HEAD:NewWindowChur/adminadduser.h
#ifndef ADMINADDUSER_H
#define ADMINADDUSER_H
=======
#ifndef DIALOG_H
#define DIALOG_H
>>>>>>> parent of bb486ec... Add files via upload:NewWindowChur/dialog.h

#include <QDialog>

namespace Ui {
<<<<<<< HEAD:NewWindowChur/adminadduser.h
class adminadduser;
}

class adminadduser : public QDialog
=======
class Dialog;
}

class Dialog : public QDialog
>>>>>>> parent of bb486ec... Add files via upload:NewWindowChur/dialog.h
{
    Q_OBJECT

public:
<<<<<<< HEAD:NewWindowChur/adminadduser.h
    explicit adminadduser(QWidget *parent = nullptr);
    ~adminadduser();

private:
    Ui::adminadduser *ui;
};

#endif // ADMINADDUSER_H
=======
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
>>>>>>> parent of bb486ec... Add files via upload:NewWindowChur/dialog.h
