#include "NewEmployer.h"
#include <QtGui>

NewEmployer::NewEmployer(QWidget *parent)
    : QDialog(parent)
{
    employerDataFile = new QFile("/Users/ladmin/Documents/OpenEval/Files/EMPLOYERS.txt");
    employerIDDataFile = new QFile("/Users/ladmin/Documents/OpenEval/Files/EMPLOYERID.txt");

    //Declare streams to read and write the next employer ID.
    employerIDData = new QTextStream(employerIDDataFile);
    employerData = new QTextStream(employerDataFile);

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
}

void NewEmployer::cancel()
{
    hide();
    clearFields();
}

void NewEmployer::submit()
{
    name = employerName->text();
    address = employerAddress->text();
    city = employerCity->text();
    state = employerState->text();
    zipCode = employerZipCode->text();
    phone = employerPhone->text();
    eMail = employerEMail->text();
    contact = employerContact->text();
    employerName->setFocus();
    writeEmployerData();
    clearFields();
}

void NewEmployer::writeEmployerData()
{
    employerDataFile->open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append);

    employerData->operator <<("") << employerID << "," << name << "," << address << "," << city << "," <<
                                     state << "," << zipCode << "," << phone << "," << eMail << "," << contact << endl;

    employerDataFile->close();

    //Increment the employer ID and update EMPLOYERID.txt.
    employerID++;
    employerIDDataFile->open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Truncate);
    employerIDData->operator <<(employerID);
    employerIDDataFile->close();
}

void NewEmployer::assignEmployerID()
{
    employerIDDataFile->open(QIODevice::Text | QIODevice::ReadWrite);
    QString employerIDString = employerIDData->readLine();
    if (employerIDString == "")
    {
        employerID = 1;
        employerIDData->operator <<(employerID);
    }
    else
    {
        employerID = employerIDString.toInt();
    }
    employerIDDataFile->close();

}

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
}
