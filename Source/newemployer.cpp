//Operations that define the New Employer window.

#include "NewEmployer.h"
#include <QtGui>

//Draw the main New Employer window.
NewEmployer::NewEmployer(QWidget *parent)
    : QDialog(parent)
{

    assignEmployerID();

    QLabel *nameLabel = new QLabel(tr("Name"));
    employerName = new QLineEdit;

    QLabel *addressLabel = new QLabel(tr("Street Address"));
    employerAddress = new QLineEdit;

    QLabel *cityLabel = new QLabel(tr("City"));
    employerCity = new QLineEdit;

    QLabel *stateLabel = new QLabel(tr("State"));
    employerState = new QLineEdit;

    QLabel *zipLabel = new QLabel(tr("Zip Code"));
    employerZipCode = new QLineEdit;

    QLabel *phoneLabel = new QLabel(tr("Phone Number"));
    employerPhone = new QLineEdit;

    QLabel *emailLabel = new QLabel(tr("E-Mail Address"));
    employerEMail = new QLineEdit;

    QLabel *contactLabel = new QLabel(tr("Contact Person"));
    employerContact = new QLineEdit;

    submitButton = new QPushButton(tr("Submit"));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(accept()));

    cancelButton = new QPushButton(tr("Cancel"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(cancelButton);
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
    mainLayout->addLayout(buttonLayout, 5, 0, 1, 10);

    setLayout(mainLayout);
    setWindowTitle(tr("New Employer"));
}

//This resets the New Employer window to its base state
//and hides it.
void NewEmployer::cancel()
{
    hide();
    clearFields();
}

//This writes all of the necessary data to the necessary files,
//resets New Employer to its base state, and hides the window.
void NewEmployer::submit()
{
    assignEmployerID();
    writeEmployerData();
    clearFields();
}

//This writes all of the employer information
//to the employer data file.
void NewEmployer::writeEmployerData()
{
    QFile employerDataFile(EMPLOYERFILE);

    QString employerDataString = QString::number(employerID) + "\",\"" + employerName->text() + "\",\""
                        + employerAddress->text() + "\",\"" + employerCity->text()
                        + "\",\"" + employerState->text() + "\",\"" + employerZipCode->text()
                        + "\",\"" + employerPhone->text() + "\",\"" + employerEMail->text() + "\",\""
                        + employerContact->text();

    addStringToFile(&employerDataFile, employerDataString);
}

//This assigns the employer ID of the new employer to one
//higher than the previously highest employer ID.
void NewEmployer::assignEmployerID()
{
    QFile employerDataFile(EMPLOYERFILE);
    QVector<int> employerIDVector = generateIDVector(&employerDataFile, 0);
    employerID = returnOneHigherThanMaxValue(employerIDVector);
}

//This resets all of the editable fields in the New Employer window.
void NewEmployer::clearFields()
{
    employerName->setText("");
    employerAddress->setText("");
    employerCity->setText("");
    employerState->setText("");
    employerZipCode->setText("");
    employerPhone->setText("");
    employerEMail->setText("");
    employerContact->setText("");

    employerName->setFocus();
}
