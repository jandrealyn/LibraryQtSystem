#include "createfiles.h"

// Defining static variables
QString CreateFiles::_path = "CSVFiles/";
QFile CreateFiles::_catalogue(_path + "catalogue.csv");
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
        catalogue_output << "BOOK_ID" << "," << "BOOK_NAME" << "," << "AUTHOR" << "," << "COPIES" << "," << "OVERDUE" << "\n";
        for (int i = 0; i < 20; i++)
        {
            catalogue_output << QString::number(i + 1) << "," << "This is a book" << "," << "Author" << "," << "20" << "," << "No" << "\n";
        }
        _catalogue.close();

        _members.open(QIODevice::WriteOnly | QFile::Text);
        QTextStream members_output(&_members);
        members_output << "ID" << "," << "USERNAME" << "," << "PASSWORD" << "," << "EMAIL" << "," << "PHONE_NUM" << "\n";
        _members.close();
    }
}

//QFile CreateFiles::GetCatalogueData()
//{
//    QStringList* catalogueData;
//    // Read the CSV file and store its data into catalogueData
//    if (CreateFiles::_catalogue.open(QIODevice::ReadOnly))
//    {
//        QTextStream in(&CreateFiles::_catalogue);

//        while (!in.atEnd())
//        {
//            // readLine() will also read an endl or \n, so it's important to use replace() to get rid of them.
//            QString line = CreateFiles::_catalogue.readLine().replace("\r\n","");
//            catalogueData->append(line.split(','));
//        }
//    }
//    else
//    {
//        // Displaying an error to the user if we can't open the catalogue.csv file.
//        QMessageBox::warning(this, "Can not open \'catalogue.csv\'.", CreateFiles::_catalogue.errorString());
//    }
//    CreateFiles::_catalogue.close();
//}

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

    return fileData;
}
