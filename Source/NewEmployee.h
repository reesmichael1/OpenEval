#ifndef NEWEMPLOYEE_H
#define NEWEMPLOYEE_H

#include <QDialog>
#include "FileOperations.h"

class QLineEdit;
class QComboBox;

class NewEmployee : public QDialog, private FileOperations
{
    Q_OBJECT

public:
    enum Mode {AddingMode, ViewingMode};
    NewEmployee(QWidget *parent = 0);
    void addEmployers();
    void assignEmployerID(int* currentID);

public slots:
    void cancel();
    void submit();

private:
    int employeeID;
    int *employerID;
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
    QPushButton *submitButton;
    QPushButton *cancelButton;
    void employEmployee();
    void assignEmployeeID();
    void writeEmployeeData();
    void clearFields();
};

#endif // NEWEMPLOYEE_H
