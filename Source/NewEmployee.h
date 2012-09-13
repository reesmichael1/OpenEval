#ifndef NEWEMPLOYEE_H
#define NEWEMPLOYEE_H

#include <QDialog>
#include <QFile>

class QLineEdit;
class QTextStream;
class QComboBox;

class NewEmployee : public QDialog
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
    QString firstName;
    QString lastName;
    QString address;
    QString city;
    QString state;
    QString zipCode;
    QString phone;
    QString cell;
    QString eMail;
    QString employer;
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
    QFile *employeeIDDataFile;
    QFile *fieldPlacementsFile;
    QTextStream *employerData;
    QTextStream *employeeData;
    QTextStream *employeeIDData;
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
