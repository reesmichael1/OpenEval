#ifndef NEWEMPLOYER_H
#define NEWEMPLOYER_H

#include <QDialog>
#include "FileOperations.h"

class QLineEdit;

class NewEmployer : public QDialog, private FileOperations
{
    Q_OBJECT

public:
    NewEmployer(QWidget *parent = 0);
    void clearFields();

public slots:
    void cancel();
    void submit();

private:
    int employerID;
    QLineEdit *employerName;
    QLineEdit *employerAddress;
    QLineEdit *employerCity;
    QLineEdit *employerState;
    QLineEdit *employerZipCode;
    QLineEdit *employerPhone;
    QLineEdit *employerEMail;
    QLineEdit *employerContact;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    void assignEmployerID();
    void writeEmployerData();
    void setReadOnly();
};

#endif // NEWEMPLOYER_H
