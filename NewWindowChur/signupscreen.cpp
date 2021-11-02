#include "signupscreen.h"
#include "ui_signupscreen.h"
#include "catalogue.h"
#include "QMessageBox"
#include "QCheckBox"
#include <QDebug>
#include <QPushButton>

 // - liv (Worked on Login/Signup/Menu Screens)

signupscreen::signupscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::signupscreen)
{
    ui->setupUi(this);
}

signupscreen::~signupscreen()
{
    delete ui;
}

void signupscreen::on_next_clicked(){

}
