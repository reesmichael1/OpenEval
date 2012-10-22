#ifndef FINDEMPLOYEE_H
#define FINDEMPLOYEE_H

#include <QDialog>
#include "FileOperations.h"

class QLineEdit;
class QPushButton;

class FindEmployee : public QDialog, private FileOperations
{

    Q_OBJECT

public:
    FindEmployee(QDialog *parent = 0);
    void setEmployeeID(int *employeeID, int employerID);

public slots:
    void findEmployee();

private:
    int *currentEmployeeID;
    int currentEmployerID;
    QLineEdit *employeeName;
    QPushButton *findEmployeeButton;

};

#endif // FINDEMPLOYEE_H