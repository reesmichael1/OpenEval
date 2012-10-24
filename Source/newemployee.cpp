#include "NewEmployee.h"
#include <QtGui>

NewEmployee::NewEmployee(QWidget *parent)
    : QDialog(parent)
{

    employerDataFile = new QFile(EMPLOYERFILE);
    employeeDataFile = new QFile(EMPLOYEEFILE);
    fieldPlacementsFile = new QFile(FIELDPLACEMENTSFILE);
    employerData = new QTextStream(employerDataFile);
    employeeData = new QTextStream(employeeDataFile);
    fieldPlacementsData = new QTextStream(fieldPlacementsFile);

    assignEmployeeID();

    QLabel *firstNameLabel = new QLabel(tr("First Name"));
    employeeFirstName = new QLineEdit;

    QLabel *lastNameLabel = new QLabel(tr("Last Name"));
    employeeLastName = new QLineEdit;

    QLabel *addressLabel = new QLabel(tr("Street Address"));
    employeeAddress = new QLineEdit;

    QLabel *cityLabel = new QLabel(tr("City"));
    employeeCity = new QLineEdit;

    QLabel *stateLabel = new QLabel(tr("State"));
    employeeState = new QLineEdit;

    QLabel *zipLabel = new QLabel(tr("Zip Code"));
    employeeZipCode = new QLineEdit;

    QLabel *phoneLabel = new QLabel(tr("Phone Number"));
    employeePhone = new QLineEdit;

    QLabel *cellLabel = new QLabel(tr("Cell Phone"));
    employeeCell = new QLineEdit;

    QLabel *emailLabel = new QLabel(tr("E-Mail Address"));
    employeeEMail = new QLineEdit;

    QLabel *employerLabel = new QLabel(tr("Employer"));
    employeeEmployer = new QComboBox;

    submitButton = new QPushButton(tr("Submit"));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(accept()));

    cancelButton = new QPushButton(tr("Cancel"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(submitButton);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(firstNameLabel, 0, 0);
    mainLayout->addWidget(employeeFirstName, 0, 1, 1, 4);
    mainLayout->addWidget(lastNameLabel, 0, 5, 1, 1, Qt::AlignRight);
    mainLayout->addWidget(employeeLastName, 0, 6, 1, 4);
    mainLayout->addWidget(phoneLabel, 1, 0);
    mainLayout->addWidget(employeePhone, 1, 1, 1, 4);
    mainLayout->addWidget(cellLabel, 1, 5, 1, 1, Qt::AlignRight);
    mainLayout->addWidget(employeeCell, 1, 6, 1, 4);
    mainLayout->addWidget(addressLabel, 2, 0);
    mainLayout->addWidget(employeeAddress, 2, 1, 1, 9);
    mainLayout->addWidget(cityLabel, 3, 0);
    mainLayout->addWidget(employeeCity, 3, 1, 1, 3);
    mainLayout->addWidget(stateLabel, 3, 4);
    mainLayout->addWidget(employeeState, 3, 5);
    mainLayout->addWidget(zipLabel, 3, 6);
    mainLayout->addWidget(employeeZipCode, 3, 7, 1, 3);
    mainLayout->addWidget(emailLabel, 4, 0);
    mainLayout->addWidget(employeeEMail, 4, 1, 1, 5);
    mainLayout->addWidget(employerLabel, 4, 6);
    mainLayout->addWidget(employeeEmployer, 4, 7, 1, 3);
    mainLayout->addLayout(buttonLayout, 5, 0, 1, 10);

    setLayout(mainLayout);
    setWindowTitle(tr("New Employee"));
    addEmployers();
}

void NewEmployee::cancel()
{
    hide();
    clearFields();
}

void NewEmployee::submit()
{
    assignEmployeeID();
    writeEmployeeData();
    clearFields();
}

void NewEmployee::addEmployers()
{

    employeeEmployer->clear();

    employerDataFile->open(QIODevice::Text | QIODevice::ReadOnly);
    QString employerDataString = employerDataFile->readLine();

    while(employerDataString != "")
    {
        QStringList employerDataList = employerDataString.split(',');
        QString employerNameString = employerDataList.at(1);
        employeeEmployer->addItem(employerNameString);
        employerDataString = employerData->readLine();
    }

    employerDataFile->close();

}

void NewEmployee::assignEmployeeID()
{

    QVector<int> employeeIDVector = generateEmployeeIDVector();
    employeeID = returnMaxValue(employeeIDVector);

/*
    if (employeeIDVector.size() == 0)
    {
        employeeID = 1;
    }

    else
    {
        int largestEmployeeID = 1;

        for (int i = 0; i < employeeIDVector.size(); i++)
        {
            if (employeeIDVector.at(i) > largestEmployeeID)
            {
                largestEmployeeID = employeeIDVector.at(i);
            }
        }

        largestEmployeeID++;
        employeeID = largestEmployeeID;
    }*/
}

int NewEmployee::setEmployeeInfo(int currentEmployeeID)
{
    //Someday this function will do something. I promise.
    return currentEmployeeID;
}

void NewEmployee::writeEmployeeData()
{

    employeeDataFile->open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append);
    employeeData->operator <<(employeeID) << "," << employeeFirstName->text() << "," << employeeLastName->text()
                            << "," << employeeEMail->text() << "," << employeePhone->text()
                            << "," << employeeCell->text() << "," << employeeAddress->text()
                            << "," << employeeCity->text() << "," << employeeState->text()
                            << "," << employeeZipCode->text() << endl;

    employeeDataFile->close();

    employEmployee();
}

void NewEmployee::employEmployee()
{
    QString employer = employeeEmployer->currentText();
    employerDataFile->open(QIODevice::Text | QIODevice::ReadOnly);
    QString employerNameString = employerDataFile->readLine();
    QStringList employerDataList = employerNameString.split(',');
    while(employerDataList.at(1) != employer)
    {
        employerNameString = employerDataFile->readLine();
        employerDataList = employerNameString.split(',');
    }

    employerDataFile->close();

    int employerID = employerDataList.at(0).toInt();

    fieldPlacementsFile->open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append);
    fieldPlacementsData->operator <<(employeeID) << "," << employerID << endl;
    fieldPlacementsFile->close();
}

void NewEmployee::clearFields()
{
    employeeFirstName->setText("");
    employeeLastName->setText("");
    employeeAddress->setText("");
    employeeCity->setText("");
    employeeState->setText("");
    employeeZipCode->setText("");
    employeePhone->setText("");
    employeeCell->setText("");
    employeeEMail->setText("");

    employeeFirstName->setFocus();
}
