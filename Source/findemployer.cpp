#include <QtGui>
#include "FindEmployer.h"

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

void FindEmployer::findEmployer()
{
    QFile employerDataFile(EMPLOYERFILE);
    QVector<int> employerIDVector = generateIDVector(&employerDataFile, 0);
    QString employerDataString;

    for (int i = 0; i < employerIDVector.size(); i++)
    {
        employerDataString = returnDataString(&employerDataFile, employerIDVector.at(i), 0);
        if (employerDataString.contains(employerName->text()))
        {
            QStringList employerDataList = employerDataString.split("\",\"");
            *currentEmployerID = employerDataList.at(0).toInt();
        }
    }

}

void FindEmployer::cancel()
{
    employerName->setText("");
}

void FindEmployer::setEmployerID(int *employerID)
{
    currentEmployerID = employerID;
}
