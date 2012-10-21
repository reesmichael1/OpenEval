#include <QtGui>
#include "FindEmployer.h"

FindEmployer::FindEmployer(QDialog * parent)
    : QDialog(parent)
{
    QLabel *employerNameLabel = new QLabel(tr("Employer Name"));
    employerName = new QLineEdit;
    employerName->setMinimumWidth(300);

    findEmployerButton = new QPushButton(tr("Find Employer"));

    QHBoxLayout *mainLayout = new QHBoxLayout;

    mainLayout->addWidget(employerNameLabel);
    mainLayout->addWidget(employerName);
    mainLayout->addWidget(findEmployerButton);

    setLayout(mainLayout);

}
