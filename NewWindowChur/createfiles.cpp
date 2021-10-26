#include "createfiles.h"

// Defining static variables
QString CreateFiles::_path = "CSVFiles/";
QFile CreateFiles::_catalogue(CreateFiles::_path + "catalogue.csv");
QFile CreateFiles::_members(CreateFiles::_path + "members.csv");

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
        catalogue_output << "BOOK_ID" << "," << "BOOK_NAME" << "," << "AUTHOR" << "," << "COPIES" << "," << "OVERDUE" << "\n";
        catalogue_output << "1234566" << "," << "A Game of Thrones" << "," << "R. R. Martin" << "," << "2" << "," << "No" << "\n";
        _catalogue.close();

        _members.open(QIODevice::WriteOnly | QFile::Text);
        QTextStream members_output(&_members);
        members_output << "ID" << "," << "USERNAME" << "," << "PASSWORD" << "," << "EMAIL" << "," << "PHONE_NUM" << "\n";
        _members.close();
    }
}
