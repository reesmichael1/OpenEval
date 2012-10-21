#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#define EMPLOYERFILE "/Users/ladmin/Documents/OpenEval/Files/EMPLOYERS.txt"
#define EMPLOYEEFILE "/Users/ladmin/Documents/OpenEval/Files/EMPLOYEES.txt"
#define EMPLOYEEIDFILE "/Users/ladmin/Documents/OpenEval/Files/EMPLOYEEID.txt"
#define EMPLOYERIDFILE "/Users/ladmin/Documents/OpenEval/Files/EMPLOYERID.txt"
#define EVALUATIONRESULTSFILE "/Users/ladmin/Documents/OpenEval/Files/EVALUATIONRESULTS.txt"
#define FIELDPLACEMENTSFILE "/Users/ladmin/Documents/OpenEval/Files/FIELDPLACEMENTS.txt"
#define EVALUATIONIDFILE "/Users/ladmin/Documents/OpenEval/Files/EVALUATIONID.txt"
#define FILEBACKUP "/Users/ladmin/Documents/OpenEval/Files/FileBackup.txt"

#include <QFile>
#include <QDialog>

class FileOperations
{

protected:
    QString returnDataString(QFile *file, int currentID);
    void removeEntity(QFile *file, int currentID, int IDPosition);
    QVector<int> generateEmployeeIDVector(int currentEmployerID);
    QVector<int> generateEmployerIDVector();
};

#endif // FILEOPERATIONS_H
