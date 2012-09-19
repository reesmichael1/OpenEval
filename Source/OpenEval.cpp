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

    //Set the Employee Name and Employer Name field to display the last line in the files. (This will change.)
    updateEmployerID();
    updateEmployeeID();

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
        setFields();
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
        setFields();
        newEmployeeWindow.addEmployers();
    }
}

void OpenEval::removeEmployee()
{
}

//Set the average score box to display the average score, and save information to file.
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

//Display the next employee employed by the currently displayed employer.
void OpenEval::nextEmployeeID()
{
    //Go to field placements and find the current employee. Find the next employee with the same employer ID. Change the current
    //employee ID. Update the employee name field with the new employee ID.
    QFile fieldPlacementsFile("/Users/ladmin/Documents/OpenEval/Files/FIELDPLACEMENTS.txt");
    fieldPlacementsFile.open(QIODevice::ReadOnly | QIODevice::Text);

    QTextStream fieldPlacements(&fieldPlacementsFile);

    QString fieldPlacementsString = fieldPlacements.readLine();
    QStringList fieldPlacementsList;
    do
    {
        fieldPlacementsList = fieldPlacementsString.split(',');
        fieldPlacementsString = fieldPlacements.readLine();
    } while (fieldPlacementsList.at(0).toInt() != currentEmployeeID);

    do
    {
        if (fieldPlacementsString != "")
        {
        fieldPlacementsList = fieldPlacementsString.split(',');
        fieldPlacementsString = fieldPlacements.readLine();

        }

        else
        {
            fieldPlacementsFile.close();
            fieldPlacementsFile.open(QIODevice::Text | QIODevice::ReadOnly);
            fieldPlacementsString = fieldPlacements.readLine();
        }

        QMessageBox msgBox;
        msgBox.setText(tr("fieldPlacementsString is %1.").arg(fieldPlacementsString));
        msgBox.exec();

    } while (fieldPlacementsList.at(1).toInt() != currentEmployerID);

    currentEmployeeID = fieldPlacementsList.at(0).toInt();

    fieldPlacementsFile.close();
}

void OpenEval::previousEmployeeID()
{
}

void OpenEval::setNextEmployer()
{
    nextEmployerID();
    updateEmployerName();
}

void OpenEval::setNextEmployee()
{
    nextEmployeeID();
    updateEmployeeName();
}

void OpenEval::setPreviousEmployee()
{
    previousEmployeeID();
    updateEmployeeName();
}

//Display the next employer in EMPLOYERS.txt. If at the end of the file, display the first employer.
void OpenEval::nextEmployerID()
{
    employerDataFile->open(QIODevice::Text | QIODevice::ReadOnly);

    QString currentEmployerName = employerName->text();
    QString employerNameString;
    QStringList employerDataList;
    QString employerDataString = employerData->readLine();

    //Read to the line containing the current employer's name.
    do
    {
        if (employerDataString != "")
        {
            employerDataList = employerDataString.split(',');
            employerNameString = employerDataList.at(1);
            employerDataString = employerData->readLine();
        }
    } while (employerNameString != currentEmployerName);

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

//Display the previous employer in EMPLOYERS.txt. If at the beginning of the file, display the last employer.
void OpenEval::previousEmployerID()
{
    employerDataFile->open(QIODevice::Text | QIODevice::ReadOnly);

    QString currentEmployerName = employerName->text();
    QString employerNameString;
    QStringList employerDataList;
    QString employerDataString = employerData->readLine();

    employerDataFile->close();
    employerDataFile->open(QIODevice::Text | QIODevice::ReadOnly);

    int lineCount = 0;

    do
    {
            employerDataList = employerDataString.split(',');
            employerNameString = employerDataList.at(1);
            lineCount++;
            employerDataString = employerData->readLine();

    } while (employerNameString != currentEmployerName);

    employerDataFile->close();
    employerDataFile->open(QIODevice::Text | QIODevice::ReadOnly);

    if (lineCount == 1)
    {
        while (employerDataString != "")
        {
            employerDataList = employerDataString.split(',');
            currentEmployerID = employerDataList.at(0).toInt();
            employerDataString = employerData->readLine();
        }
    }

    else if (lineCount == 2)
    {
        employerDataList = employerDataString.split(',');
        currentEmployerID = employerDataList.at(0).toInt();
    }

    else
    {
        for (int i = 1; i <= lineCount; i++)
        {
                employerDataList = employerDataString.split(',');
                employerNameString = employerDataList.at(1);
                currentEmployerID = employerDataList.at(0).toInt();
                employerDataString = employerData->readLine();
        }
    }

    employerDataFile->close();
}

void OpenEval::setPreviousEmployer()
{
    previousEmployerID();
    updateEmployerName();
}

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
    }

    else
    {
        employerNameString = "";
    }

    employerName->setText(employerNameString);
    employerDataFile->close();
}

void OpenEval::updateEmployeeName()
{
    employeeDataFile->open(QIODevice::Text | QIODevice::ReadOnly);
    QString employeeDataString = employeeData->readLine();
    QString employeeNameString;
    QStringList employeeDataList;
    if (employeeDataString != "")
    {
        do
        {
            employeeDataList = employeeDataString.split(',');
            employeeNameString = employeeDataList.at(1) + " " + employeeDataList.at(2);
            employeeDataString = employeeData->readLine();
        } while (currentEmployeeID != employeeDataList.at(0).toInt());
    }

    else
    {
        employeeNameString = "";
    }

    employeeName->setText(employeeNameString);
    employeeDataFile->close();
}

void OpenEval::updateEmployeeID()
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

void OpenEval::updateEmployerID()
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

void OpenEval::enableEmployeeFields()
{
    reviewButton->setEnabled(true);
    editEmployeeButton->setEnabled(true);
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
