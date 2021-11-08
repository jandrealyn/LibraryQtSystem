// ------------------------------------------------------------
//
// CREATE FILES CLASS
// Written by Jakob
//
// This class is used to easily acess our system files.
// Team members can access a file they need by calling
// CreateFiles::_fileNeeded;
//
// If you need some files data, you can call
// CreateFiles::GetFileData(CSVFiles::_YourFile) into a QStringList.
//
// ------------------------------------------------------------

#include "createfiles.h"
#include <QDebug>
#include <QRandomGenerator>
#include <QDebug>
#include <QDate>

// Defining static variables
QString CreateFiles::_path = "CSVFiles/";
QFile CreateFiles::_catalogue(_path + "catalogue.csv");
QFile CreateFiles::_members(_path + "members.csv");
QFile CreateFiles::_checkedOutBooks(_path + "checkedoutbooks.csv");

CreateFiles::CreateFiles()
{
}

void CreateFiles::CreateFilesOnStartUp()
{
    // Check if the "CSVFiles" folder exists, if not then create it.
    if (!QDir(_path).exists())
    {
        // Make the directory (the CSVFiles folder)
        QDir().mkdir(_path);

        // Create all the files necessary to the directory
        _catalogue.open(QIODevice::WriteOnly | QFile::Text);
        QTextStream catalogue_output(&_catalogue);
        catalogue_output << "BOOK ID" << "," << "IMAGE" << "," << "BOOK NAME" << "," << "AUTHOR" << "," << "COPIES" << "\n";
        for (int i = 0; i < 20; i++)
        {
            if (i % 2 == 0) // Maybe change how we create a book ID
            {
                catalogue_output << QString::number(i) << "," << ":/images/blue-book.jpg" << "," << "This is a book" << "," << "Author" << "," << "10" << "\n";
            }
            else
            {
                catalogue_output << QString::number(i) << "," <<  ":/images/book-cover.png" << "," << "Cool Book" << "," << "Authorz" << "," << "10" << "\n";
            }
        }
        _catalogue.close();

        _members.open(QIODevice::WriteOnly | QFile::Text);
        QTextStream members_output(&_members);
        members_output << "ID" << "," << "PROFILE PICTURE" << "," << "FIRST NAME" << "," << "LAST NAME" << "," << "USERNAME" << "," << "PASSWORD" << "," << "EMAIL" << "," << "PHONE NUM" << "\n";
        _members.close();

        _checkedOutBooks.open(QIODevice::WriteOnly | QFile::Text);
        QTextStream checkout_output(&_checkedOutBooks);
        checkout_output << "BOOK ID" << "," << "BOOK NAME" << "," << "MEMBER ID" << "," << "MEMBER NAME" << "," << "DATE CHECKED OUT" << "," << "DATE DUE" << "\n";
        _checkedOutBooks.close();
    }
}

QStringList CreateFiles::GetFileData(enum CSVFiles file)
{
    QStringList fileData;
    switch (file)
    {
    case CSVFiles::_Catalogue:
        if (_catalogue.open(QIODevice::ReadOnly))
        {
            QTextStream in(&_catalogue);
            while(!in.atEnd())
            {
                QString line = _catalogue.readLine().replace("\r\n","");
                fileData.append(line.split(','));
            }
        }
        else
        {
            return fileData;
        }
        _catalogue.close();
        break;
    case CSVFiles::_Members:
        if (_members.open(QIODevice::ReadOnly))
        {
            QTextStream in(&_members);
            while(!in.atEnd())
            {
                QString line = _members.readLine().replace("\r\n","");
                fileData.append(line.split(','));
            }
        }
        else
        {
            return fileData;
        }
        _members.close();
        break;
    case CSVFiles::_CheckedOutBooks:
        if (_checkedOutBooks.open(QIODevice::ReadOnly))
        {
            QTextStream in(&_checkedOutBooks);
            while(!in.atEnd())
            {
                QString line = _checkedOutBooks.readLine().replace("\r\n","");
                fileData.append(line.split(','));
            }
        }
        else
        {
            return fileData;
        }
        _checkedOutBooks.close();
        break;
    default:
        qDebug() << "Could not open file.";
        fileData.append("error");
        break;
    }
    return fileData;
}

// This function is used to make the coding for other members in the team easier.
// Whoever is in charge of the login screen can use this function to pass through
// the values of the users account details and creates an account. It will also
// generate a randomised ID.
void CreateFiles::CreateMember(QString fName, QString lName, QString uName, QString pWord, QString email, QString phoneNum)
{
    // Generate the members ID
    quint32 idNum = QRandomGenerator::global()->bounded(1000, 9999);
    QString id = "Mem" + QString::number(idNum);
    QStringList membersList = GetFileData(CSVFiles::_Members);
    if (membersList.contains(id))
    {
        while (membersList.contains(id))
        {
            quint32 idNum = QRandomGenerator::global()->bounded(1000, 9999);
            QString id = "Mem" + QString::number(idNum);
        }
    }

    // Output all of the members details
    _members.open(QIODevice::WriteOnly | QFile::Append | QFile::Text);
    QTextStream in(&_members);
    in << id << "," << fName << "," << lName << "," << uName << "," << pWord << "," << email << "," << phoneNum << "\n";
    _members.close();
}

void CreateFiles::CheckOutBook(QString bookID, QString bookName, QString memID, QString memName)
{
    // Get the current date and due date
    QString currentDate = QDate::currentDate().toString("dd.MM.yyyy");
    QString dueDate = QDate::currentDate().addDays(7).toString("dd.MM.yyyy");

    _checkedOutBooks.open(QIODevice::WriteOnly | QFile::Append | QFile::Text);
    QTextStream in(&_checkedOutBooks);
    in << bookID << "," << bookName << "," << memID << "," << memName << "," << currentDate << "," << dueDate << "\n";
    _checkedOutBooks.close();
}
