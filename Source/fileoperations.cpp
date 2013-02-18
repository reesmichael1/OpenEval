//This defines all of the interactions with files that
//are used by OpenEval.

#include <QtGui>
#include "FileOperations.h"

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

QString FileOperations::returnFirstString(QFile *file)
{
    QTextStream dataStream(file);

    file->open(QIODevice::Text | QIODevice::ReadOnly);
    QString dataString = dataStream.readLine();
    file->close();

    return dataString;

}

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

void FileOperations::addStringToFile(QFile *file, QString string)
{
    QTextStream dataStream(file);

    file->open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append);

    dataStream << string << endl;

    file->close();
}

void FileOperations::removeEntity(QFile *file, int currentID, int IDPosition)
{

    QFile fileBackup(FILEBACKUP);
    QTextStream backupStream(&fileBackup);
    QTextStream originalStream(file);

    fileBackup.open(QIODevice::Text | QIODevice::ReadWrite);
    file->open(QIODevice::Text | QIODevice::ReadOnly);

    QString dataString = originalStream.readLine();
    QStringList dataList = dataString.split("\",\"");

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

    //If the file starts with an empty line (because the last line of the file
    //was removed and left behind an empty line), then remove it.
    //Otherwise, OpenEval only reads to the null line (the start line) and does
    //not see the data in the rest of the file. This can be done because this
    //extra line is only added when the last line is removed and the file
    //becomes empty.


    fileBackup.close();
    file->close();

    QString fileName = file->fileName();

    file->remove();
    fileBackup.rename(fileName);

    fileBackup.open(QIODevice::Text | QIODevice::ReadOnly);
}

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

int FileOperations::returnMaxValue(QVector<int> IDVector)
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
