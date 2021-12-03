#include "admineditbook.h"
#include "ui_admineditbook.h"
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
#include <QScrollArea>
#include <QGroupBox>
#include <QPushButton>

//Laras Code :)

admineditbook::admineditbook(QWidget *parent, QString bookID, QString bookName, QString authorName, QString copies) :
    QDialog(parent),
    ui(new Ui::admineditbook)
{
    ui->setupUi(this);

    QPixmap Img(":/images/YoobeeLibraries.png");
    ui->img->setPixmap(Img.scaled(100, 100, Qt::KeepAspectRatio));

    _bookID = bookID; //Setting our variables that were passed from admin catalogue
    _bookName = bookName;

    ui->book_name_label->setText(bookName);
    ui->book_author_label->setText(authorName);
    ui->book_copies_label->setText(copies);

    connect(this, SIGNAL(UpdateAdminCatalogue()), this, SLOT(UpdateAdminCatalogueSlot())); //Connecting update admin catalogue to this screen

}


admineditbook::~admineditbook()
{
    delete ui;
}

void admineditbook::on_canceledit_clicked()
{
    close();
    emit exec(); //Cancel edit closes the window
}


void admineditbook::on_confimedit_clicked()
{
    QMessageBox msgBox; //Sends out message box checking if the admin would like to continue
    msgBox.setWindowTitle(tr("Edit Book"));
    msgBox.setText(tr("Proceed with editing book?"));
    QAbstractButton* edit = msgBox.addButton(tr("Yes"), QMessageBox::YesRole);
    msgBox.addButton(tr("No"), QMessageBox::NoRole);
    msgBox.exec();

    if (msgBox.clickedButton()==edit){
            //
            QStringList booksData = SystemFiles::GetFileData(CSVFiles::_Catalogue);
            int rowCount = (booksData.size() / 6) - 1;
            int i = 6;
            for (int row = 0; row < rowCount; row++)
            {
                for (int col = 0; col < 6; col++)
                {
                    if (booksData[i] == _bookID){
                        QString name = ui->book_name_label->text();
                        QString author = ui->book_author_label->text();
                        QString copies = ui->book_copies_label->text();
                        booksData[i+2] = name;
                        booksData[i+3] = author;
                        booksData[i+4] = copies;
                    }
                    i++;
                }
            }
            SystemFiles::EditBook(booksData); //Book is replaced with the new edited one in system files
            emit UpdateAdminCatalogue(); //Admin catalogue is updated with new book
            close();
            emit exec(); //Closes edit screen
        }

    else {
    //if no clicked
    }


}




void admineditbook::on_deletebook_clicked()
{
    QMessageBox msgBox; //Sends out message box checking if the admin would like to continue
    msgBox.setWindowTitle(tr("Delete Book"));
    msgBox.setText(tr("Proceed with deleting book?"));
    QAbstractButton* edit = msgBox.addButton(tr("Yes"), QMessageBox::YesRole);
    msgBox.addButton(tr("No"), QMessageBox::NoRole);
    msgBox.exec();

    if (msgBox.clickedButton()==edit){
            QStringList booksData = SystemFiles::GetFileData(CSVFiles::_CheckedOutBooks);
            int rowCount = (booksData.size() / 6) - 1;
            int i = 6;
            bool checked = false;
            for (int row = 0; row < rowCount; row++)
            {
                for (int col = 0; col < 6; col++)
                {
                    if (booksData[i] == _bookID){
                        QMessageBox::warning(this, tr("Deleting Book"), tr("A user has this book checked out, cannot delete!"), QMessageBox::Close);
                        checked = true;
                    }
                    i++;
                }
            }
            if (checked == false){
                SystemFiles::DeleteBook(_bookID); //Replaces the books in the file without this book
                emit UpdateAdminCatalogue(); //Updates admin catalogue
                close();
                emit exec();
            }
        }

    else {
    //if no clicked
    }
}
