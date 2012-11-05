#include "EmployerInfo.h"
#include <QtGui>

EmployerInfo::EmployerInfo(QWidget *parent)
    : QDialog(parent)
{
    QLabel *nameLabel = new QLabel(tr("Name"));
    employerName = new QLineEdit;
    employerName->setReadOnly(true);

    QLabel *addressLabel = new QLabel(tr("Street Address"));
    employerAddress = new QLineEdit;
    employerAddress->setReadOnly(true);

    QLabel *cityLabel = new QLabel(tr("City"));
    employerCity = new QLineEdit;
    employerCity->setReadOnly(true);

    QLabel *stateLabel = new QLabel(tr("State"));
    employerState = new QLineEdit;
    employerState->setReadOnly(true);

    QLabel *zipLabel = new QLabel(tr("Zip Code"));
    employerZipCode = new QLineEdit;
    employerZipCode->setReadOnly(true);

    QLabel *phoneLabel = new QLabel(tr("Phone Number"));
    employerPhone = new QLineEdit;
    employerPhone->setReadOnly(true);

    QLabel *emailLabel = new QLabel(tr("E-Mail Address"));
    employerEMail = new QLineEdit;
    employerEMail->setReadOnly(true);

    QLabel *contactLabel = new QLabel(tr("Contact Person"));
    employerContact = new QLineEdit;
    employerContact->setReadOnly(true);

    editButton = new QPushButton(tr("Edit Employer"));
    connect(editButton, SIGNAL(clicked()), this, SLOT(editEmployer()));

    submitButton = new QPushButton(tr("Submit"));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submitEdits()));
    submitButton->setVisible(false);

    cancelButton = new QPushButton(tr("Cancel"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelEdits()));
    cancelButton->setVisible(false);

    okButton = new QPushButton(tr("OK"));
    okButton->setFocus();
    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(submitButton);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(nameLabel, 0, 0);
    mainLayout->addWidget(employerName, 0, 1, 1, 9);
    mainLayout->addWidget(addressLabel, 1, 0);
    mainLayout->addWidget(employerAddress, 1, 1, 1, 9);
    mainLayout->addWidget(cityLabel, 2, 0);
    mainLayout->addWidget(employerCity, 2, 1, 1, 3);
    mainLayout->addWidget(stateLabel, 2, 4);
    mainLayout->addWidget(employerState, 2, 5);
    mainLayout->addWidget(zipLabel, 2, 6);
    mainLayout->addWidget(employerZipCode, 2, 7, 1, 3);
    mainLayout->addWidget(phoneLabel, 3, 0);
    mainLayout->addWidget(employerPhone, 3, 1, 1, 5);
    mainLayout->addWidget(contactLabel, 3, 6);
    mainLayout->addWidget(employerContact, 3, 7, 1, 3);
    mainLayout->addWidget(emailLabel, 4, 0);
    mainLayout->addWidget(employerEMail, 4, 1, 1, 9);
    mainLayout->addLayout(buttonLayout, 5, 1, 1, 9);

    setLayout(mainLayout);
    setWindowTitle(tr("Employer Info"));
}

void EmployerInfo::setEmployerID(int employerID)
{
    currentEmployerID = employerID;
}

void EmployerInfo::setFields()
{
    QFile employerDataFile(EMPLOYERFILE);
    QString employerDataString = returnDataString(&employerDataFile, currentEmployerID, 0);
    QStringList employerDataList = employerDataString.split(',');

    employerName->setText(employerDataList.at(1));
    employerAddress->setText(employerDataList.at(2));
    employerCity->setText(employerDataList.at(3));
    employerState->setText(employerDataList.at(4));
    employerZipCode->setText(employerDataList.at(5));
    employerPhone->setText(employerDataList.at(6));
    employerEMail->setText(employerDataList.at(7));
    employerContact->setText(employerDataList.at(8));
}

void EmployerInfo::editEmployer()
{
    setMode(EditingMode);
}

void EmployerInfo::setMode(Mode currentMode)
{
    if (currentMode == EditingMode)
    {
        employerName->setReadOnly(false);
        employerAddress->setReadOnly(false);
        employerCity->setReadOnly(false);
        employerState->setReadOnly(false);
        employerZipCode->setReadOnly(false);
        employerPhone->setReadOnly(false);
        employerEMail->setReadOnly(false);
        employerContact->setReadOnly(false);
        editButton->setVisible(false);
        okButton->setVisible(false);
        submitButton->setVisible(true);
        cancelButton->setVisible(true);
    }

    if (currentMode == ViewingMode)
    {
        employerName->setReadOnly(true);
        employerAddress->setReadOnly(true);
        employerCity->setReadOnly(true);
        employerState->setReadOnly(true);
        employerZipCode->setReadOnly(true);
        employerPhone->setReadOnly(true);
        employerEMail->setReadOnly(true);
        employerContact->setReadOnly(true);
        submitButton->setVisible(false);
        cancelButton->setVisible(false);
        editButton->setVisible(true);
        okButton->setVisible(true);
    }
}

void EmployerInfo::submitEdits()
{
    QFile employerDataFile(EMPLOYERFILE);
    removeEntity(&employerDataFile, currentEmployerID, 0);

    QString employerDataString = QString::number(currentEmployerID) + ","
                        + employerName->text() + "," + employerAddress->text()
                        + "," + employerCity->text() + "," + employerState->text()
                        + "," + employerZipCode->text() + "," + employerPhone->text()
                        + "," + employerEMail->text() + "," + employerContact->text();

    addStringToFile(&employerDataFile, employerDataString);

    setMode(ViewingMode);
}

void EmployerInfo::cancelEdits()
{
    setMode(ViewingMode);
    setFields();
}
