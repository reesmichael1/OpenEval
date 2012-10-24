#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#define EMPLOYERFILE "EMPLOYERS.txt"
#define EMPLOYEEFILE "EMPLOYEES.txt"
#define EVALUATIONRESULTSFILE "EVALUATIONRESULTS.txt"
#define FIELDPLACEMENTSFILE "FIELDPLACEMENTS.txt"
#define FILEBACKUP "FileBackup.txt"

#include <QFile>
#include <QDialog>

class FileOperations
{

protected:
    QString returnDataString(QFile *file, int currentID, int IDPosition);
    void removeEntity(QFile *file, int currentID, int IDPosition);
    QVector<int> generateEmployeeIDVector(int currentEmployerID);
    QVector<int> generateEmployeeIDVector();
    QVector<int> generateIDVector(QFile *file);
    int returnMaxValue(QVector<int> IDVector);
};

#endif // FILEOPERATIONS_H
