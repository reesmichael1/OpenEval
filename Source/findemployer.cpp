//Operations that define the Find Employer window.

#include <QtGui>
#include "FindEmployer.h"

//Draw the main Find Employer window.
FindEmployer::FindEmployer(QDialog * parent)
    : QDialog(parent)
{
    QLabel *employerNameLabel = new QLabel(tr("Employer Name"));
    employerName = new QLineEdit;
    employerName->setMinimumWidth(300);

    findEmployerButton = new QPushButton(tr("Find Employer"));
    connect(findEmployerButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(findEmployerButton, SIGNAL(clicked()), this, SLOT(findEmployer()));

    cancelButton = new QPushButton(tr("Cancel"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(hide()));

    QHBoxLayout *mainLayout = new QHBoxLayout;

    mainLayout->addWidget(employerNameLabel);
    mainLayout->addWidget(employerName);
    mainLayout->addWidget(findEmployerButton);
    mainLayout->addWidget(cancelButton);

    setLayout(mainLayout);
    setWindowTitle(tr("Find Employer"));

}

//This function takes a pointer to the employer ID
//within OpenEval to be updated as needed.
void FindEmployer::setEmployerID(int *employerID)
{
    currentEmployerID = employerID;
}

//This searches the employer data file for an employer with
//a certain name. If the employer cannot be found, the function
//provides a notification that says so. Otherwise, the pointer
//to the employer ID within the main OpenEval window is updated.
void FindEmployer::findEmployer()
{
    QFile employerDataFile(EMPLOYERFILE);
    QVector<int> employerIDVector = generateIDVector(&employerDataFile, 0);
    QString employerDataString;

    bool employerFound = false;

    for (int i = 0; i < employerIDVector.size(); i++)
    {
        employerDataString = returnDataString(&employerDataFile, employerIDVector.at(i), 0);
        if (employerDataString.contains(employerName->text()))
        {
            QStringList employerDataList = employerDataString.split("\",\"");
            *currentEmployerID = employerDataList.at(0).toInt();
            employerFound = true;
        }
    }

    if (!employerFound)
    {
        QMessageBox employerNotFoundBox;
        employerNotFoundBox.setText(tr("Sorry, %1 is not an employer saved within OpenEval.")
            .arg(employerName->text()));
        employerNotFoundBox.setWindowTitle(tr("Employer Not Found"));
        employerNotFoundBox.exec();
    }

}

//This resets the Find Employer window to its base state.
void FindEmployer::cancel()
{
    employerName->setText("");
}
