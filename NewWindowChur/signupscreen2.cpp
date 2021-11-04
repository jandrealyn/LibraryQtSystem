#include "signupscreen2.h"
#include "ui_signupscreen2.h"
#include "catalogue.h"
#include "QMessageBox"
#include "QCheckBox"
#include <QDebug>
#include <QPushButton>
#include <QInputDialog>
#include "createfiles.h"
using namespace std;

// - liv (Worked on Login/Signup/Menu Screens)

//--- Livs Part --//

signupscreen2::signupscreen2(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signupscreen2)
{
    ui->setupUi(this);
    QPixmap Img(":/images/YoobeeLibraries.png"); // - liv
    ui->img->setPixmap(Img.scaled(150, 150, Qt::KeepAspectRatio)); // - liv
}
void on_next_clicked(){


}
signupscreen2::~signupscreen2()
{
    delete ui;
}

void signupscreen2::on_close_clicked(){ //function for - when the user clicks close
    close();
    emit OpenMainMenu();
}

void signupscreen2::on_Next_clicked()
{

}

void signupscreen2::on_back_clicked()
{

}
