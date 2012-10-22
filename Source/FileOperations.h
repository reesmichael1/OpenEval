#ifndef FILEOPERATIONS_H
#define FILEOPERATIONS_H

#define EMPLOYERFILE "\\EMPLOYERS.txt"
#define EMPLOYEEFILE "\\EMPLOYEES.txt"
#define EMPLOYEEIDFILE "\\EMPLOYEEID.txt"
#define EMPLOYERIDFILE "\\EMPLOYERID.txt"
#define EVALUATIONRESULTSFILE "\\EVALUATIONRESULTS.txt"
#define FIELDPLACEMENTSFILE "\\FIELDPLACEMENTS.txt"
#define EVALUATIONIDFILE "\\EVALUATIONID.txt"
#define FILEBACKUP "\\FileBackup.txt"

#include <QFile>
#include <QDialog>

class FileOperations
{

protected:
    QString returnDataString(QFile *file, int currentID, int IDPosition);
    void removeEntity(QFile *file, int currentID, int IDPosition);
    QVector<int> generateEmployeeIDVector(int currentEmployerID);
    QVector<int> generateEmployerIDVector();
};

#endif // FILEOPERATIONS_H
