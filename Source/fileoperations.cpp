//This defines all of the interactions with files that
//are used by OpenEval.

#include <QtGui>
#include "FileOperations.h"

//This returns a string within a certain file that has a certain value
//at a certain position. All of these parameters are passed to the function.
QString FileOperations::returnDataString(QFile *file, int currentID, int IDPosition)
{

    QString dataString;
    QVector<int> IDVector = generateIDVector(file, IDPosition);

    if (IDVector.contains(currentID))
    {
        QTextStream dataStream(file);

        file->open(QIODevice::Text | QIODevice::ReadOnly);

        dataString = dataStream.readLine();
        QStringList employeeDataList = dataString.split("\",\"");

        while (employeeDataList.at(IDPosition).toInt() != currentID)
        {
            dataString = dataStream.readLine();
            employeeDataList = dataString.split("\",\"");
        }

    file->close();

    }

    else
    {
        dataString = "";
    }

    return dataString;
}

//Like returnDataString(), this function returns a string from a certain file.
//However, this string is specified by the position of another string within the
//line in the file.
QString FileOperations::returnLineWithString(QFile *file, QString string, int stringPosition)
{
    file->open(QIODevice::Text | QIODevice::ReadOnly);

    QTextStream dataStream(file);

    QString dataString = dataStream.readLine();
    QStringList dataStringList = dataString.split("\",\"");
    while (dataStringList.at(stringPosition) != string)
    {
        dataString = dataStream.readLine();
        dataStringList = dataString.split("\",\"");
    }

    file->close();

    return dataString;
}

//This returns the first string within a certain file,
//a pointer to which is passed whenever this function
//is called.
QString FileOperations::returnFirstString(QFile *file)
{
    QTextStream dataStream(file);

    file->open(QIODevice::Text | QIODevice::ReadOnly);
    QString dataString = dataStream.readLine();
    file->close();

    return dataString;

}

//This returns the last ID that is contained within a certain file.
int FileOperations::returnLastID(QFile *file, int IDPosition)
{

    QTextStream dataStream(file);
    file->open(QIODevice::Text | QIODevice::ReadOnly);

    QStringList dataStringList;
    QString dataString = dataStream.readLine();
    int lastID;

    while (dataString != "")
    {
        dataStringList = dataString.split("\",\"");
        lastID = dataStringList.at(IDPosition).toInt();
        dataString = dataStream.readLine();
    }


    file->close();

    return lastID;
}

//This adds a string to the end of a certain file. Both of these
//parameters are passed whenever the function is called.
void FileOperations::addStringToFile(QFile *file, QString string)
{
    QTextStream dataStream(file);

    file->open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append);

    dataStream << string << endl;

    file->close();
}

//This removes a line from a certain file that contains a certain ID at a
//certain position within the line.
void FileOperations::removeEntity(QFile *file, int currentID, int IDPosition)
{

    QFile fileBackup(FILEBACKUP);
    QTextStream backupStream(&fileBackup);
    QTextStream originalStream(file);

    fileBackup.open(QIODevice::Text | QIODevice::ReadWrite);
    file->open(QIODevice::Text | QIODevice::ReadOnly);

    QString dataString = originalStream.readLine();
    QStringList dataList = dataString.split("\",\"");

    //If the file starts with an empty line (because the last line of the file
    //was removed and left behind an empty line), then remove it.
    //Otherwise, OpenEval only reads to the null line (the start line) and does
    //not see the data in the rest of the file. This can be done because this
    //extra line is only added when the last line is removed and the file
    //becomes empty.
    if (dataString != "")
    {
        do
        {
            if (dataList.at(IDPosition).toInt() != currentID)
            {
                backupStream << dataString << endl;
            }

            dataString = originalStream.readLine();
            dataList = dataString.split("\",\"");
        } while (dataString != "");
    }

    fileBackup.close();
    file->close();

    QString fileName = file->fileName();

    file->remove();
    fileBackup.rename(fileName);

    //TEST FOR REGRESSIONS:
    //fileBackup.open(QIODevice::Text | QIODevice::ReadOnly);
}

//This returns a vector that contains all of the IDs of the employees of
//a specified employer (the ID of which is passed to the function).
QVector<int> FileOperations::generateEmployeeIDVector(int currentEmployerID)
{
    QVector<int> employeeIDVector;
    QFile fieldPlacementsFile(FIELDPLACEMENTSFILE);
    fieldPlacementsFile.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream fieldPlacements(&fieldPlacementsFile);

    QString fieldPlacementsString = fieldPlacements.readLine();
    QStringList fieldPlacementsList;

    while (fieldPlacementsString != "")
    {
        fieldPlacementsList = fieldPlacementsString.split("\",\"");
        if (fieldPlacementsList.at(1).toInt() == currentEmployerID)
        {
            employeeIDVector.append(fieldPlacementsList.at(0).toInt());
        }
        fieldPlacementsString = fieldPlacements.readLine();
    }

    fieldPlacementsFile.close();

    return employeeIDVector;
}

//This returns a vector that contains all of the IDs at a certain position
//within a certain file.
QVector<int> FileOperations::generateIDVector(QFile *file, int IDPosition)
{
    QVector<int> IDVector;

    QTextStream dataStream(file);

    file->open(QIODevice::Text | QIODevice::ReadOnly);

    QString employerDataString = dataStream.readLine();
    QStringList employerDataList;

    while (employerDataString != "")
    {
        employerDataList = employerDataString.split("\",\"");
        IDVector.append(employerDataList.at(IDPosition).toInt());
        employerDataString = dataStream.readLine();
    }

    file->close();

    return IDVector;
}

//This returns one higher than the maximum value
//of a vector that is passed to it.
int FileOperations::returnOneHigherThanMaxValue(QVector<int> IDVector)
{
    int maxID;

    if (IDVector.size() == 0)
    {
        maxID = 1;
    }

    else
    {
        maxID = 0;

        for (int i = 0; i < IDVector.size(); i++)
        {
            if (IDVector.at(i) > maxID)
            {
                maxID = IDVector.at(i);
            }
        }
        maxID++;
    }

    return maxID;
}
