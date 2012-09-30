#include <QtGui>
#include <QFile>
#include "OpenEval.h"


//Constructor for main window. This draws the main window and calls functions to construct other windows.
OpenEval::OpenEval()
{

    //Declare data files to contain information about the employees and employers.
    employeeDataFile = new QFile("/Users/ladmin/Documents/OpenEval/Files/EMPLOYEES.txt");
    employerDataFile = new QFile("/Users/ladmin/Documents/OpenEval/Files/EMPLOYERS.txt");

    //Declare streams to read and write information about the employees and employers.
    employeeData = new QTextStream(employeeDataFile);
    employerData = new QTextStream(employerDataFile);

    //Create labels and text boxes.
    QLabel *nameLabel = new QLabel(tr("Employee"));
    employeeName = new QLineEdit;
    employeeName->setReadOnly(true);

    QLabel *employerLabel = new QLabel(tr("Employer"));
    employerName = new QLineEdit;
    employerName->setReadOnly(true);

    QLabel *workQualityLabel = new QLabel(tr("Quality of Work:"));
    workQualityLabel->setToolTip(tr("Accuracy, neatness, timeliness, attention to detail,"
                                    "volume/quantity requirements, adherence to duties, and procedures in job description."));
    qualityOfWorkScore = new QSpinBox;
    qualityOfWorkScore->setRange(1, 5);
    qualityOfWorkScore->setMaximumWidth(40);
    qualityOfWorkScore->setReadOnly(true);

    QLabel *workHabitsLabel = new QLabel(tr("Work Habits:"));
    workHabitsLabel->setToolTip(tr("Attendance, organization, punctuality, and time on task."));
    workHabitsScore = new QSpinBox;
    workHabitsScore->setRange(1, 5);
    workHabitsScore->setMaximumWidth(40);
    workHabitsScore->setReadOnly(true);

    QLabel *jobKnowledgeLabel = new QLabel(tr("Job Knowledge:"));
    jobKnowledgeLabel->setToolTip(tr("Skill/ability to perform job, and interest in learning."));
    jobKnowledgeScore = new QSpinBox;
    jobKnowledgeScore->setRange(1, 5);
    jobKnowledgeScore->setMaximumWidth(40);
    jobKnowledgeScore->setReadOnly(true);

    QLabel *behaviorLabel = new QLabel(tr("Behavior:"));
    behaviorLabel->setToolTip(tr("Teamwork, communication, response to criticism, and adapt to change."));
    behaviorScore = new QSpinBox;
    behaviorScore->setRange(1, 5);
    behaviorScore->setMaximumWidth(40);
    behaviorScore->setReadOnly(true);

    QLabel *averageLabel = new QLabel(tr("Average:"));
    averageLabel->setToolTip(tr("Average of scores for Quality of Work, Work Habits, Job Knowledge, and Behavior."));
    averageScore = new QDoubleSpinBox;
    averageScore->setRange(1 , 5);
    averageScore->setReadOnly(true);
    averageScore->setMaximumWidth(55);

    //Create button to add a new employee.
    addEmployeeButton = new QPushButton(tr("Create New Employee"));
    connect(addEmployeeButton, SIGNAL(clicked()), this, SLOT(addEmployee()));

    //Create button to add a new employer.
    addEmployerButton = new QPushButton(tr("Create New Employer"));
    connect(addEmployerButton, SIGNAL(clicked()), this, SLOT(addEmployer()));

    employeeInfoButton = new QPushButton(tr("Employee Info"));

    employerInfoButton = new QPushButton(tr("Employer Info"));

    nextEmployeeButton = new QPushButton(tr("Next Employee"));
    connect(nextEmployeeButton, SIGNAL(clicked()), this, SLOT(setNextEmployee()));

    previousEmployeeButton = new QPushButton(tr("Previous Employee"));
    connect(previousEmployeeButton, SIGNAL(clicked()), this, SLOT(setPreviousEmployee()));

    nextEmployerButton = new QPushButton(tr("Next Employer"));
    connect(nextEmployerButton, SIGNAL(clicked()), this, SLOT(setNextEmployer()));

    previousEmployerButton = new QPushButton(tr("Previous Employer"));
    connect(previousEmployerButton, SIGNAL(clicked()), this, SLOT(setPreviousEmployer()));

    editEmployeeButton = new QPushButton(tr("Edit Employee"));

    editEmployerButton = new QPushButton(tr("Edit Employer"));

    removeEmployeeButton = new QPushButton(tr("Remove Employee"));

    removeEmployerButton = new QPushButton(tr("Remove Employer"));

    findEmployeeButton = new QPushButton(tr("Find Employee"));

    findEmployerButton = new QPushButton(tr("Find Employer"));

    reviewButton = new QPushButton(tr("Review"));

    //Draw scores.
    QHBoxLayout *workQualityLayout = new QHBoxLayout;
    workQualityLayout->addWidget(workQualityLabel);
    workQualityLayout->addWidget(qualityOfWorkScore);

    QHBoxLayout *workHabitsLayout = new QHBoxLayout;
    workHabitsLayout->addWidget(workHabitsLabel);
    workHabitsLayout->addWidget(workHabitsScore);

    QHBoxLayout *jobKnowledgeLayout = new QHBoxLayout;
    jobKnowledgeLayout->addWidget(jobKnowledgeLabel);
    jobKnowledgeLayout->addWidget(jobKnowledgeScore);

    QHBoxLayout *behaviorLayout = new QHBoxLayout;
    behaviorLayout->addWidget(behaviorLabel);
    behaviorLayout->addWidget(behaviorScore);

    QHBoxLayout *averageLayout = new QHBoxLayout;
    averageLayout->addWidget(averageLabel);
    averageLayout->addWidget(averageScore);

    QVBoxLayout *scoresLayout = new QVBoxLayout;
    scoresLayout->addLayout(workQualityLayout);
    scoresLayout->addLayout(workHabitsLayout);
    scoresLayout->addLayout(jobKnowledgeLayout);
    scoresLayout->addLayout(behaviorLayout);
    scoresLayout->addLayout(averageLayout);

    //Draw name layouts.
    QHBoxLayout *employeeNameLayout = new QHBoxLayout;
    employeeNameLayout->addWidget(nameLabel);
    employeeNameLayout->addWidget(employeeName);

    QHBoxLayout *employerNameLayout = new QHBoxLayout;
    employerNameLayout->addWidget(employerLabel);
    employerNameLayout->addWidget(employerName);

    QGridLayout *infoLayout = new QGridLayout;
    infoLayout->addLayout(employeeNameLayout, 0, 0, 1, 2);
    infoLayout->addWidget(employeeInfoButton, 1, 0);
    infoLayout->addWidget(employerInfoButton, 1, 1);
    infoLayout->addLayout(employerNameLayout, 2, 0, 1, 2);
    infoLayout->addWidget(previousEmployeeButton, 3, 0);
    infoLayout->addWidget(nextEmployeeButton, 3, 1);
    infoLayout->addWidget(previousEmployerButton, 4, 0);
    infoLayout->addWidget(nextEmployerButton, 4, 1);

    QVBoxLayout *editButtonLayout = new QVBoxLayout;
    editButtonLayout->addWidget(reviewButton);
    editButtonLayout->addWidget(editEmployeeButton);
    editButtonLayout->addWidget(removeEmployeeButton);
    editButtonLayout->addWidget(editEmployerButton);
    editButtonLayout->addWidget(removeEmployerButton);

    QGridLayout *createButtonLayout = new QGridLayout;
    createButtonLayout->addWidget(addEmployeeButton, 0, 0);
    createButtonLayout->addWidget(addEmployerButton, 1, 0);
    createButtonLayout->addWidget(findEmployeeButton, 0, 1);
    createButtonLayout->addWidget(findEmployerButton, 1, 1);

    //Draw main layout.
    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addLayout(scoresLayout, 0, 0, 5, 2);
    mainLayout->addLayout(infoLayout, 0, 2, 5, 2);
    mainLayout->addLayout(editButtonLayout, 0, 4, 5, 2);
    mainLayout->addLayout(createButtonLayout, 5, 0, 1, 6);

    setLayout(mainLayout);

    //Set the Employer Name field to the first employer, and the Employee Name field to the first employee for this employer.
    //updateEmployerID();
    //setNextEmployer();
    setFirstEmployerID();
    setFirstEmployeeID();
    setFields();
}

//Add a new employee.
void OpenEval::addEmployee()
{
    //Show dialog box to add a new employee.
    newEmployeeWindow.show();

    //If the new employee was submitted...
    if (newEmployeeWindow.exec() == QDialog::Accepted)
    {

        //...then update the Employee Name field to represent the new employee.
        //Read to the end of EMPLOYEES.txt. Update currentEmployeeID to reflect the value of the last employee.
        employeeDataFile->open(QIODevice::Text | QIODevice::ReadOnly);
        QStringList employeeDataList;
        QString employeeDataString = employeeData->readLine();
        while (employeeDataString != "")
        {
            employeeDataList = employeeDataString.split(',');
            currentEmployeeID = employeeDataList.at(0).toInt();
            employeeDataString = employeeData->readLine();
        }
        employeeDataFile->close();

        //Update the Employee Name field to reflect the new employee.
        updateEmployeeName();
    }
}

//Add a new employer.
void OpenEval::addEmployer()
{
    //Show the dialog box to add a new employer.
    newEmployerWindow.show();

    //If the new employer is submitted...
    if (newEmployerWindow.exec() == QDialog::Accepted)
    {
        //Set the Employer Name field to represent the new employer.
        //Read to the end of EMPLOYERS.txt. Update currentEmployerID to reflect the value of the last employer.
        employerDataFile->open(QIODevice::Text | QIODevice::ReadOnly);
        QStringList employerDataList;
        QString employerDataString = employerData->readLine();
        while (employerDataString != "")
        {
            employerDataList = employerDataString.split(',');
            currentEmployerID = employerDataList.at(0).toInt();
            employerDataString = employerData->readLine();
        }
        employerDataFile->close();

        //Update the Employer Name field to reflect the new employer.
        setEmployeeIDForEmployer();
        updateEmployeeName();
        updateEmployerName();

        //Add the new employer to the New Employee dialog box.
        newEmployeeWindow.addEmployers();
    }
}

void OpenEval::removeEmployee()
{
}

//Set the average score box to display the average score. This needs to be implemented someday, but probably in a very different form.
void OpenEval::submitEmployee()
{
    int nWorkQuality = qualityOfWorkScore->value();
    int nWorkHabits = workHabitsScore->value();
    int nJobKnowledge = jobKnowledgeScore->value();
    int nBehavior = behaviorScore->value();

    double dTotal = (nWorkQuality + nWorkHabits + nJobKnowledge + nBehavior);
    double dAverage = dTotal/4;

    averageScore->setValue(dAverage);
}

QVector<int> OpenEval::generateEmployeeIDVector()
{
    QVector<int> employeeIDVector;
    QFile fieldPlacementsFile("/Users/ladmin/Documents/OpenEval/Files/FIELDPLACEMENTS.txt");
    fieldPlacementsFile.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream fieldPlacements(&fieldPlacementsFile);

    QString fieldPlacementsString = fieldPlacements.readLine();
    QStringList fieldPlacementsList;

    while (fieldPlacementsString != "")
    {
        fieldPlacementsList = fieldPlacementsString.split(',');
        if (fieldPlacementsList.at(1).toInt() == currentEmployerID)
        {
            employeeIDVector.append(fieldPlacementsList.at(0).toInt());
        }
        fieldPlacementsString = fieldPlacements.readLine();
    }

    fieldPlacementsFile.close();

    return employeeIDVector;
}

//Display the next employee employed by the currently displayed employer.
void OpenEval::nextEmployeeID()
{

    //Go to field placements and find the current employee. Find the next employee with the same employer ID. Change the current
    //employee ID. Update the employee name field with the new employee ID.

    QVector<int> employeeIDVector;

    employeeIDVector = generateEmployeeIDVector();

    int i = 0;
    int nextEmployeeID;

    if (currentEmployeeID == employeeIDVector.last())
    {
        nextEmployeeID = employeeIDVector.at(0);
    }

    else
    {
        while (employeeIDVector.at(i) != currentEmployeeID)
        {
            i++;
        }
        i++;
        nextEmployeeID = employeeIDVector.at(i);
    }

    currentEmployeeID = nextEmployeeID;
}

void OpenEval::previousEmployeeID()
{
    QVector<int> employeeIDVector;

    employeeIDVector = generateEmployeeIDVector();

    int i = 0;
    int previousEmployeeID;

    if (employeeIDVector.at(i) == currentEmployeeID)
    {
        previousEmployeeID = employeeIDVector.last();
    }
    else
    {
        while (employeeIDVector.at(i) != currentEmployeeID)
        {
            if (employeeIDVector.at(i) != currentEmployeeID)
            {
                previousEmployeeID = employeeIDVector.at(i);
                i++;
            }
        }
    }

    currentEmployeeID = previousEmployeeID;
}

//Set the employer ID to the next employer. Set the employee ID to match. Set the Employee Name and Employer Name fields accordingly.
void OpenEval::setNextEmployer()
{
    nextEmployerID();
    setEmployeeIDForEmployer();
    setFields();
}

//Set the employee ID to the next employee for the employer. Update the Employee Name field accordingly.
void OpenEval::setNextEmployee()
{
    nextEmployeeID();
    updateEmployeeName();
}

//Set the employeeID to the previous employee for the employer. Update the Employee Name field accordingly.
void OpenEval::setPreviousEmployee()
{
    previousEmployeeID();
    updateEmployeeName();
}

//Set the employer ID to the next employer in EMPLOYERS.txt. If at the end of the file, display the first employer.
void OpenEval::nextEmployerID()
{
    employerDataFile->open(QIODevice::Text | QIODevice::ReadOnly);

    QStringList employerDataList;
    QString employerDataString = employerData->readLine();

    //Read to the line containing the current employer's name.
    if (employerDataString != "")
    {
        do
        {
            if (employerDataString != "")
            {
                employerDataList = employerDataString.split(',');
                employerDataString = employerData->readLine();
            }
        } while (employerDataList.at(0).toInt() != currentEmployerID);

        //Read the next line and set the employer name, or, if it is empty...
        if (employerDataString != "")
        {
            employerDataList = employerDataString.split(',');
            currentEmployerID = employerDataList.at(0).toInt();
        }

        //...read the first line and set the first employer's name.
        else
        {
            employerDataFile->close();
            employerDataFile->open(QIODevice::Text | QIODevice::ReadOnly);
            employerDataString = employerData->readLine();
            employerDataList = employerDataString.split(',');
            currentEmployerID = employerDataList.at(0).toInt();
        }

        employerDataFile->close();
    }

    /*
    else
    {
        currentEmployerID = 0;
    }
    */
}

//Set the employer ID to the previous employer in EMPLOYERS.txt. If at the beginning of the file, display the last employer.
void OpenEval::previousEmployerID()
{

    employerDataFile->open(QIODevice::Text | QIODevice::ReadOnly);

    int previousEmployerID;
    QString employerDataString = employerData->readLine();
    QStringList employerDataList = employerDataString.split(',');

    while (employerDataList.at(0).toInt() != currentEmployerID)
    {
        employerDataList = employerDataString.split(',');
        employerDataString = employerData->readLine();
        if (employerDataList.at(0).toInt() != currentEmployerID)
        {
            previousEmployerID = employerDataList.at(0).toInt();
        }
    }
    currentEmployerID = previousEmployerID;

    employerDataFile->close();
}

//Set the employer ID to the previous employer in EMPLOYERS.txt. Set the employee ID to this employer's first employee. Set the fields.
void OpenEval::setPreviousEmployer()
{
    previousEmployerID();
    setEmployeeIDForEmployer();
    setFields();
}

//Set the Employer Name field to display the current employer's name.
void OpenEval::updateEmployerName()
{
    employerDataFile->open(QIODevice::Text | QIODevice::ReadOnly);
    QString employerDataString = employerData->readLine();
    QString employerNameString;
    QStringList employerDataList;

    if (employerDataString != "")
    {
        do
        {
            employerDataList = employerDataString.split(',');
            employerNameString = employerDataList.at(1);
            employerDataString = employerData->readLine();
        } while (currentEmployerID != employerDataList.at(0).toInt());
    enableEmployerFields();
    }

    else
    {
        employerNameString = "";
    }

    employerName->setText(employerNameString);
    employerDataFile->close();
}

//Set the Employee Name field to display the current employee's name.
void OpenEval::updateEmployeeName()
{
    employeeDataFile->open(QIODevice::Text | QIODevice::ReadOnly);
    QString employeeDataString = employeeData->readLine();
    QString employeeNameString;
    QStringList employeeDataList;

    if (currentEmployeeID == 0)
    {
        employeeNameString = "";
    }

    else if (employeeDataString != "")
    {
        do
        {
            employeeDataList = employeeDataString.split(',');
            employeeNameString = employeeDataList.at(1) + " " + employeeDataList.at(2);
            employeeDataString = employeeData->readLine();
        } while (currentEmployeeID != employeeDataList.at(0).toInt());
        enableEmployeeFields();
    }

    else
    {
        employeeNameString = "";
    }

    employeeName->setText(employeeNameString);
    employeeDataFile->close();
}

//Set the first employee ID.
void OpenEval::setFirstEmployeeID()
{
    employeeDataFile->open(QIODevice::Text | QIODevice::ReadOnly);
    QStringList employeeDataList;
    QString employeeDataString = employeeData->readLine();
    if (employeeDataString != "")
    {
        employeeDataList = employeeDataString.split(',');
        currentEmployeeID = employeeDataList.at(0).toInt();
        employeeDataString = employeeData->readLine();
        enableEmployeeFields();
    }

    else
    {
        currentEmployeeID = 1;
        disableEmployeeFields();
    }
    employeeDataFile->close();
}

//Set the first employer ID.
void OpenEval::setFirstEmployerID()
{
    employerDataFile->open(QIODevice::Text | QIODevice::ReadOnly);
    QStringList employerDataList;
    QString employerDataString = employerData->readLine();
    if (employerDataString != "")
    {
        employerDataList = employerDataString.split(',');
        currentEmployerID = employerDataList.at(0).toInt();
        employerDataString = employerData->readLine();
        enableEmployerFields();
    }

    else
    {
        disableEmployerFields();
        currentEmployerID = 1;
    }
    employerDataFile->close();
}

//Set the employee ID to the first one that matches the current employer ID.
void OpenEval::setEmployeeIDForEmployer()
{

    QVector<int> employeeIDVector = generateEmployeeIDVector();

    if (!employeeIDVector.isEmpty())
    {

    //Open the field placements file. Find the first employee employed by this employer. Set this employee ID to be the current.
    QFile fieldPlacementsFile("/Users/ladmin/Documents/OpenEval/Files/FIELDPLACEMENTS.txt");
    fieldPlacementsFile.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream fieldPlacements(&fieldPlacementsFile);

    QString fieldPlacementsString = fieldPlacements.readLine();
    QStringList fieldPlacementsList;

    do
    {
        fieldPlacementsList = fieldPlacementsString.split(',');
        currentEmployeeID = fieldPlacementsList.at(0).toInt();
        fieldPlacementsString = fieldPlacements.readLine();
    } while (fieldPlacementsList.at(1).toInt() != currentEmployerID);

    fieldPlacementsFile.close();
    }

    else
    {
        currentEmployeeID = 0;
    }
}

void OpenEval::enableEmployeeFields()
{
    reviewButton->setEnabled(true); editEmployeeButton->setEnabled(true);
    removeEmployeeButton->setEnabled(true);
    findEmployeeButton->setEnabled(true);
    previousEmployeeButton->setEnabled(true);
    nextEmployeeButton->setEnabled(true);
    employeeInfoButton->setEnabled(true);
}

void OpenEval::disableEmployeeFields()
{
    reviewButton->setEnabled(false);
    editEmployeeButton->setEnabled(false);
    removeEmployeeButton->setEnabled(false);
    findEmployeeButton->setEnabled(false);
    previousEmployeeButton->setEnabled(false);
    nextEmployeeButton->setEnabled(false);
    employeeInfoButton->setEnabled(false);
}

void OpenEval::enableEmployerFields()
{
    addEmployeeButton->setEnabled(true);
    editEmployerButton->setEnabled(true);
    removeEmployerButton->setEnabled(true);
    findEmployerButton->setEnabled(true);
    previousEmployerButton->setEnabled(true);
    nextEmployerButton->setEnabled(true);
    employerInfoButton->setEnabled(true);
}

void OpenEval::disableEmployerFields()
{
    addEmployeeButton->setEnabled(false);
    editEmployerButton->setEnabled(false);
    removeEmployerButton->setEnabled(false);
    findEmployerButton->setEnabled(false);
    previousEmployerButton->setEnabled(false);
    nextEmployerButton->setEnabled(false);
    employerInfoButton->setEnabled(false);
}

//Set the fields in the main window to reflect the new data in the files.
void OpenEval::setFields()
{
    updateEmployeeName();
    updateEmployerName();
}
