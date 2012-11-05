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
    QString returnFirstString(QFile *file);
    QString returnLineWithString(QFile *file, QString string, int stringPosition);
    int returnLastID(QFile *file, int IDPosition);
    QVector<int> generateEmployeeIDVector(int currentEmployerID);
    //QVector<int> generateEmployeeIDVector();
    //QVector<int> generateEmployerIDVector();
    QVector<int> generateIDVector(QFile *file, int IDPosition);
    int returnMaxValue(QVector<int> IDVector);
    void addStringToFile(QFile *file, QString string);
    void removeEntity(QFile *file, int currentID, int IDPosition);
};

#endif // FILEOPERATIONS_H
