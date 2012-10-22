#include <QtGui>
#include "FileOperations.h"

QString FileOperations::returnDataString(QFile *file, int currentID, int IDPosition)
{

    QTextStream dataStream(file);

    file->open(QIODevice::Text | QIODevice::ReadOnly);

    QString dataString = dataStream.readLine();
    QStringList employeeDataList = dataString.split(',');

    while (employeeDataList.at(IDPosition).toInt() != currentID)
    {
        dataString = dataStream.readLine();
        employeeDataList = dataString.split(',');
    }

    file->close();

    return dataString;
}

void FileOperations::removeEntity(QFile *file, int currentID, int IDPosition)
{

    QFile fileBackup(FILEBACKUP);
    QTextStream backupStream(&fileBackup);
    QTextStream originalStream(file);

    fileBackup.open(QIODevice::Text | QIODevice::ReadWrite);
    file->open(QIODevice::Text | QIODevice::ReadOnly);

    QString dataString = originalStream.readLine();
    QStringList dataList = dataString.split(',');

    if (dataString != "")
    {
        do
        {
            if (dataList.at(IDPosition).toInt() != currentID)
            {
                backupStream << dataString << endl;
            }

            dataString = originalStream.readLine();
            dataList = dataString.split(',');
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

    /*if (backupStream.readLine().isNull())
    {
        fileBackup.close();
        fileBackup.remove();
        QFile newFile(fileName);
        newFile.open(QIODevice::Text | QIODevice::WriteOnly);
        newFile.close();
    }

    else
    {
        fileBackup.close();
    }*/

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
        fieldPlacementsList = fieldPlacementsString.split(',');
        if (fieldPlacementsList.at(1).toInt() == currentEmployerID)
        {
            employeeIDVector.append(fieldPlacementsList.at(0).toInt());
        }
        fieldPlacementsString = fieldPlacements.readLine();
    }

    fieldPlacementsFile.close();

    return employeeIDVector;
}

QVector<int> FileOperations::generateEmployerIDVector()
{
    QVector<int> employerIDVector;

    QFile employerDataFile(EMPLOYERFILE);
    QTextStream employerData(&employerDataFile);

    employerDataFile.open(QIODevice::Text | QIODevice::ReadOnly);

    QString employerDataString = employerData.readLine();
    QStringList employerDataList;

    while (employerDataString != "")
    {
        employerDataList = employerDataString.split(',');
        employerIDVector.append(employerDataList.at(0).toInt());
        employerDataString = employerData.readLine();
    }

    employerDataFile.close();

    return employerIDVector;
}
