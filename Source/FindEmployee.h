//Declarations for the Find Employee window.

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
    void cancel();

private:
    int *currentEmployeeID;
    int currentEmployerID;
    QLineEdit *employeeName;
    QPushButton *findEmployeeButton;
    QPushButton *cancelButton;

};

#endif // FINDEMPLOYEE_H
