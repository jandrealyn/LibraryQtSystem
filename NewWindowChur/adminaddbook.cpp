#include "adminaddbook.h"
#include "ui_adminaddbook.h"
#include "QCheckBox"
#include "SystemFiles.h"
#include <QWidget>
#include <QDebug>
#include <QDialog>
#include <QFile>
#include <QMessageBox>
#include <QTableWidget>
#include <QStringList>
#include <QItemSelectionModel>
#include <QFormLayout>
#include <QFrame>
#include <QInputDialog>
#include <QScrollArea>
#include <QGroupBox>
#include <QPushButton>

//Laras Code :)

adminaddbook::adminaddbook(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::adminaddbook)
{
    ui->setupUi(this);

    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(100, 100, Qt::KeepAspectRatio));

    QPixmap book1(":/images/blue-book.jpg");
    ui->book1->setPixmap(book1.scaled(150, 150, Qt::KeepAspectRatio));

    QPixmap book2(":/images/berserk.jpg");
    ui->book2->setPixmap(book2.scaled(60, 60, Qt::KeepAspectRatio));

    QPixmap book3(":/images/book-cover.png");
    ui->book3->setPixmap(book3.scaled(60, 60, Qt::KeepAspectRatio));

    connect(this, SIGNAL(UpdateAdminCatalogue()), this, SLOT(UpdateAdminCatalogueSlot()));
}

adminaddbook::~adminaddbook()
{
    delete ui;
}

void adminaddbook::on_confirmadd_clicked()
{
    if (!ui->book_name_label->text().isEmpty() && !ui->book_author_label->text().isEmpty() && !ui->book_copies_label->text().isEmpty() && !bookimg.isEmpty()){
        QMessageBox msgBox;
        msgBox.setWindowTitle(tr("Edit Book"));
        msgBox.setText(tr("Proceed with adding book?"));
        QAbstractButton* add = msgBox.addButton(tr("Yes"), QMessageBox::YesRole);
        msgBox.addButton(tr("No"), QMessageBox::NoRole);
        msgBox.exec();

        if (msgBox.clickedButton()==add){
            QString title = ui->book_name_label->text();//Lastname input
            QString author = ui->book_author_label->text(); //username input
            QString copies = ui->book_copies_label->text();//password input

            SystemFiles::CreateBook(bookimg, title, author, copies);
            emit UpdateAdminCatalogue();
            close();
        }
        else {
            //if no clicked
        }
    }
    else {
        QMessageBox msgBox;
        msgBox.setWindowTitle(tr("Warning"));
        msgBox.setText(tr("Please fill out all information on the book"));
        msgBox.addButton(tr("Okay"), QMessageBox::RejectRole);
        msgBox.exec();
    }
}


void adminaddbook::on_canceladd_clicked()
{
    close();
}

void adminaddbook::on_bookone_toggled(bool checked)
{
    if (checked)
    {
        bookimg = ":/images/blue-book.jpg";
    }
}


void adminaddbook::on_booktwo_toggled(bool checked)
{
    bookimg = ":/images/berserk.jpg";
}


void adminaddbook::on_bookthree_toggled(bool checked)
{
    bookimg = ":/images/book-cover.png";
}

