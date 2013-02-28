//Declarations for the Employer Info window.

#ifndef EMPLOYERINFO_H
#define EMPLOYERINFO_H

#include <QDialog>
#include "FileOperations.h"

class QLineEdit;
class QDataList;
class QPushButton;

class EmployerInfo : public QDialog, private FileOperations
{

    Q_OBJECT

public:
    EmployerInfo(QWidget *parent = 0);
    enum Mode {ViewingMode, EditingMode};
    void setEmployerID(int employerID);
    void setFields();
    void setMode(Mode currentMode);

public slots:
    void editEmployer();
    void cancelEdits();
    void submitEdits();

private:
    int currentEmployerID;
    QString name;
    QString address;
    QString city;
    QString state;
    QString zipCode;
    QString phone;
    QString eMail;
    QString contact;
    QLineEdit *employerName;
    QLineEdit *employerAddress;
    QLineEdit *employerCity;
    QLineEdit *employerState;
    QLineEdit *employerZipCode;
    QLineEdit *employerPhone;
    QLineEdit *employerEMail;
    QLineEdit *employerContact;
    QPushButton *okButton;
    QPushButton *editButton;
    QPushButton *submitButton;
    QPushButton *cancelButton;
};

#endif // EMPLOYERINFO_H
