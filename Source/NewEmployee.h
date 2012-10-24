#ifndef NEWEMPLOYEE_H
#define NEWEMPLOYEE_H

#include <QDialog>
#include <QFile>
#include "FileOperations.h"

class QLineEdit;
class QTextStream;
class QComboBox;

class NewEmployee : public QDialog, private FileOperations
{
    Q_OBJECT

public:
    enum Mode {AddingMode, ViewingMode};
    NewEmployee(QWidget *parent = 0);
    void addEmployers();

public slots:
    void cancel();
    void submit();

private:
    int employeeID;
    QLineEdit *employeeFirstName;
    QLineEdit *employeeLastName;
    QLineEdit *employeeAddress;
    QLineEdit *employeeCity;
    QLineEdit *employeeState;
    QLineEdit *employeeZipCode;
    QLineEdit *employeePhone;
    QLineEdit *employeeCell;
    QLineEdit *employeeEMail;
    QComboBox *employeeEmployer;
    QFile *employerDataFile;
    QFile *employeeDataFile;
    QFile *fieldPlacementsFile;
    QTextStream *employerData;
    QTextStream *employeeData;
    QTextStream *fieldPlacementsData;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    int setEmployeeInfo(int currentEmployeeID);
    void employEmployee();
    void assignEmployeeID();
    void writeEmployeeData();
    void clearFields();
};

#endif // NEWEMPLOYEE_H
