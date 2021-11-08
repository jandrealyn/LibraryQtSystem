//including modules

#include "signupscreen2.h"
#include "ui_signupscreen2.h"
#include "catalogue.h"
#include "QMessageBox"
#include "QCheckBox"
#include <QDebug> //is a class that provides an output stream for debugging information
#include <QPushButton> //is a widget which executes an action when a user clicks on it.
#include <QInputDialog> //is a class that provides a simple convenience dialog to get a single value from the user.
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

    // Jakob - Dsiplaying users ID and First name
    //test
    //test
    QStringList membersList = CreateFiles::GetFileData(CSVFiles::_Members); // Get the data from the members file
    int lastSpotInFile = membersList.size(); // This gets the last spot in the membersList
    QString memberID = membersList[lastSpotInFile - 7]; // The user id is 6 columns away from the last spot, so we subtract it by 7
    QString memberName = membersList[lastSpotInFile - 6]; // The user name is 5 columns away from the last spot, so we subtract it by 6
    ui->user_id->setText(memberID); // Here we are just setting the text on the the page to be the ID and name that we just got
    ui->user_name->setText(memberName);
    ui->user_id->setEnabled(false); // This makes it so a user can't edit the line
    //test
}
void on_next_clicked(){


}
signupscreen2::~signupscreen2()
{
    delete ui;
}

void signupscreen2::on_close_clicked(){ //function for - when the user clicks close
    close();
    emit OpenLoginScreen();
}

void signupscreen2::on_Next_clicked()
{

}

void signupscreen2::on_back_clicked()
{

}

void signupscreen2::on_SignUp_clicked(){
    hide();
    Signup = new signupscreen2(nullptr);
    Signup->setWindowFlags((windowFlags()) | Qt::WindowMinimizeButtonHint);
    Signup->show();
    connect(Signup, SIGNAL(OpenMainMenu()), this, SLOT(MainMenuOpen()));
}
