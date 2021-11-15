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

    _bookID = bookID;
    _bookName = bookName;

    ui->book_name_label->setText(bookName);
    ui->book_author_label->setText(authorName);
    ui->book_copies_label->setText(copies);
}


admineditbook::~admineditbook()
{
    delete ui;
}

void admineditbook::on_canceledit_clicked()
{
    close();
    emit exec();
}


void admineditbook::on_confimedit_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Edit Book"));
    msgBox.setText(tr("Proceed with editing book?"));
    QAbstractButton* edit = msgBox.addButton(tr("Yes"), QMessageBox::YesRole);
    msgBox.addButton(tr("No"), QMessageBox::NoRole);
    msgBox.exec();

    if (msgBox.clickedButton()==edit){
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
            //CreateFiles::EditBook(booksData[arraySize+1]);
            SystemFiles::EditBook(booksData);
            close();
            emit exec();
        }

    else {
    //if no clicked
    }


}




void admineditbook::on_deletebook_clicked()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle(tr("Delete Book"));
    msgBox.setText(tr("Proceed with deleting book?"));
    QAbstractButton* edit = msgBox.addButton(tr("Yes"), QMessageBox::YesRole);
    msgBox.addButton(tr("No"), QMessageBox::NoRole);
    msgBox.exec();

    if (msgBox.clickedButton()==edit){
            SystemFiles::DeleteBook(_bookID);
            close();
            emit exec();
        }

    else {
    //if no clicked
    }
}
