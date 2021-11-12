#include "admineditbook.h"
#include "ui_admineditbook.h"
#include "createfiles.h"
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

admineditbook::admineditbook(QWidget *parent, QString bookID, QString bookName, QString authorName, QString copies) :
    QDialog(parent),
    ui(new Ui::admineditbook)
{
    ui->setupUi(this);
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
            QStringList booksData = CreateFiles::GetFileData(CSVFiles::_Catalogue);
            const int arraySize = (booksData.size() / 6) - 1;
            int rowCount = (booksData.size() / 6) - 1;
            for (int row = 0; row < rowCount; row++)
            {
                for (int col = 0; col < 6; col++)
                {
                    if (booksData[row][col] == _bookID){
                        //booksData[row][2] = book_name_label::text();
                        //booksData[row][3] = book_author_label::text();
                        //booksData[row][4] = book_copies_label::text();
                    }
                }
            }
            //CreateFiles::EditBook(booksData[arraySize]);
        }

    else {
    //if no clicked
    }


}



