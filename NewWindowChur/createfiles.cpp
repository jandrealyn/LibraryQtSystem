#include "createfiles.h"

// Defining static variables
QString CreateFiles::_path = "CSVFiles/";
QFile CreateFiles::_catalogue(_path + "catalogue.csv");
QFile CreateFiles::_catalogueTest(_path + "catalogueTest.csv");
QFile CreateFiles::_members(_path + "members.csv");

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
        catalogue_output << "IMAGE" << "," << "BOOK NAME" << "," << "AUTHOR" << "," << "COPIES" << "," << "CHECKOUT" << "\n";
        for (int i = 0; i < 20; i++)
        {
            if (i % 2 == 0)
            {
                catalogue_output << ":/images/blue-book.jpg" << "," << "This is a book" << "," << "Author" << "," << "10" << "," << "checkoutbtn" << "\n";
            }
            else
            {
                catalogue_output << ":/images/book-cover.png" << "," << "Cool Book" << "," << "Authorz" << "," << "10" << "," << "checkoutbtn" << "\n";
            }

        }
        _catalogue.close();

        _catalogueTest.open(QIODevice::WriteOnly | QFile::Text);
        QTextStream test_output(&_catalogueTest);
        test_output << "IMAGE" << "," << "BOOK NAME" << "," << "AUTHOR" << "," << "COPIES" << "\n";
        for (int i = 0; i < 20; i++)
        {
            if (i % 2 == 0)
            {
                test_output << ":/images/blue-book.jpg" << "," << "This is a book" << "," << "Author" << "," << "10" << "\n";
            }
            else
            {
                test_output << ":/images/book-cover.png" << "," << "Cool Book" << "," << "Authorz" << "," << "10" << "\n";
            }
        }
        _catalogueTest.close();

        _members.open(QIODevice::WriteOnly | QFile::Text);
        QTextStream members_output(&_members);
        members_output << "ID" << "," << "USERNAME" << "," << "PASSWORD" << "," << "EMAIL" << "," << "PHONE_NUM" << "\n";
        _members.close();
    }
}

QStringList CreateFiles::GetFileData(QString file)
{
    QStringList fileData;

    if (file == "catalogue")
    {
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
    }
    else if (file == "members")
    {
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
    }
    else if (file == "catalogueTest")
    {
        if (_catalogueTest.open(QIODevice::ReadOnly))
        {
            QTextStream in(&_catalogueTest);
            while(!in.atEnd())
            {
                QString line = _catalogueTest.readLine().replace("\r\n","");
                fileData.append(line.split(','));
            }
        }
        else
        {
            return fileData;
        }
        _catalogueTest.close();
    }

    return fileData;
}
