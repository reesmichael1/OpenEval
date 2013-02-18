#include <QtGui>
#include "OpenEval.h"

//Constructor for main window. This draws the main window and calls functions to construct other windows.
OpenEval::OpenEval()
{

    //Draw main window.
    QLabel *nameLabel = new QLabel(tr("Employee"));
    employeeName = new QLineEdit;
    employeeName->setReadOnly(true);

    QLabel *employerLabel = new QLabel(tr("Employer"));
    employerName = new QLineEdit;
    employerName->setReadOnly(true);

    QLabel *workQualityLabel = new QLabel(tr("Quality of Work:"));
    workQualityLabel->setToolTip(tr("Accuracy, neatness, timeliness, attention to detail, "
                                    "volume/quantity requirements, adherence to duties, "
                                    "and procedures in job description."));
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
    averageLabel->setToolTip(tr("Average of scores for Quality of Work, "
     "Work Habits, Job Knowledge, and Behavior."));
    averageScore = new QDoubleSpinBox;
    averageScore->setRange(1 , 5);
    averageScore->setReadOnly(true);
    averageScore->setMaximumWidth(55);

    addEmployeeButton = new QPushButton(tr("Create New Employee"));
    connect(addEmployeeButton, SIGNAL(clicked()), this, SLOT(addEmployee()));

    addEmployerButton = new QPushButton(tr("Create New Employer"));
    connect(addEmployerButton, SIGNAL(clicked()), this, SLOT(addEmployer()));

    employeeInfoButton = new QPushButton(tr("Employee Info"));
    connect(employeeInfoButton, SIGNAL(clicked()), this, SLOT(showEmployeeInfo()));

    employerInfoButton = new QPushButton(tr("Employer Info"));
    connect(employerInfoButton, SIGNAL(clicked()), this, SLOT(showEmployerInfo()));

    nextEmployeeButton = new QPushButton(tr("Next Employee"));
    connect(nextEmployeeButton, SIGNAL(clicked()), this, SLOT(setNextEmployee()));

    previousEmployeeButton = new QPushButton(tr("Previous Employee"));
    connect(previousEmployeeButton, SIGNAL(clicked()), this, SLOT(setPreviousEmployee()));

    nextEmployerButton = new QPushButton(tr("Next Employer"));
    connect(nextEmployerButton, SIGNAL(clicked()), this, SLOT(setNextEmployer()));

    previousEmployerButton = new QPushButton(tr("Previous Employer"));
    connect(previousEmployerButton, SIGNAL(clicked()), this, SLOT(setPreviousEmployer()));

    editEmployeeButton = new QPushButton(tr("Edit Employee"));
    connect(editEmployeeButton, SIGNAL(clicked()), this, SLOT(editEmployee()));

    editEmployerButton = new QPushButton(tr("Edit Employer"));
    connect(editEmployerButton, SIGNAL(clicked()), this, SLOT(editEmployer()));

    removeEmployeeButton = new QPushButton(tr("Remove Employee"));
    connect(removeEmployeeButton, SIGNAL(clicked()), this, SLOT(removeEmployee()));

    removeEmployerButton = new QPushButton(tr("Remove Employer"));
    connect(removeEmployerButton, SIGNAL(clicked()), this, SLOT(removeEmployer()));

    findEmployeeButton = new QPushButton(tr("Find Employee"));
    connect(findEmployeeButton, SIGNAL(clicked()), this, SLOT(findEmployee()));

    findEmployerButton = new QPushButton(tr("Find Employer"));
    connect(findEmployerButton, SIGNAL(clicked()), this, SLOT(findEmployer()));

    reviewButton = new QPushButton(tr("Review"));
    connect(reviewButton, SIGNAL(clicked()), this, SLOT(reviewEmployee()));

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

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addLayout(scoresLayout, 0, 0, 5, 2);
    mainLayout->addLayout(infoLayout, 0, 2, 5, 2);
    mainLayout->addLayout(editButtonLayout, 0, 4, 5, 2);
    mainLayout->addLayout(createButtonLayout, 5, 0, 1, 6);

    //Assign keyboard shortcuts and add entries to the menu bars.
    createActions();
    createMenus();

    centralWidget = new QWidget;
    centralWidget->setLayout(mainLayout);

    setCentralWidget(centralWidget);

    setWindowTitle(tr("OpenEval"));

    //Set the Employer Name field to the first employer in EMPLOYERS.txt,
    //and the Employee Name field to the first employee for this employer.
    setFirstEmployerID();
    setEmployeeIDForEmployer();
    setFields();
}

//Add a new employee.
void OpenEval::addEmployee()
{
    //Show dialog box to add a new employee.
    int *employerID = &currentEmployerID;

    newEmployeeWindow.assignEmployerID(employerID);
    newEmployeeWindow.show();

    //If the new employee was submitted...
    if (newEmployeeWindow.exec() == QDialog::Accepted)
    {
        //...then update the Employee Name field to represent the new employee.

        QFile employeeDataFile(EMPLOYEEFILE);
        currentEmployeeID = returnLastID(&employeeDataFile, 0);

        //Update the Employee Name field to reflect the new employee.
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

        QFile employerDataFile(EMPLOYERFILE);
        currentEmployerID = returnLastID(&employerDataFile, 0);

        //Update the Employer Name field to reflect the new employer.
        setEmployeeIDForEmployer();
        updateEmployeeFields();
        updateEmployerName();

        //Add the new employer to the New Employee dialog box.
        newEmployeeWindow.addEmployers();
    }
}

//Set the employee ID to the the next employee employed
//by the currently displayed employer.
void OpenEval::nextEmployeeID()
{
    //Create vector containing all of the current employer's employee's IDs.
    QVector<int> employeeIDVector = generateEmployeeIDVector(currentEmployerID);

    //Set currentEmployeeID to the employee ID after the current employee's ID
    //in the vector of employee IDs.

    int i = 0;
    int nextEmployeeID;

    if (currentEmployeeID == 0)
    {
        nextEmployeeID = 0;
    }

    else if (currentEmployeeID == employeeIDVector.last())
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

//Set the employee ID to the previous employee employed
//by the current employer.
void OpenEval::previousEmployeeID()
{

    //Generate vector containing all of the current employer's employee's IDs.
    QVector<int> employeeIDVector = generateEmployeeIDVector(currentEmployerID);

    //Set currentEmployeeID to match the previous employee ID in the vector.
    int i = 0;
    int previousEmployeeID;

    if (employeeIDVector.size() == 0)
    {
        previousEmployeeID = 0;
    }

    else if (employeeIDVector.at(i) == currentEmployeeID)
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

//Set the employer ID to the next employer. Set the employee ID to match.
//Set the Employee Name and Employer Name fields accordingly.
void OpenEval::setNextEmployer()
{
    nextEmployerID();
    setEmployeeIDForEmployer();
    setFields();
}

//Set the employee ID to the next employee for the employer.
//Update the Employee Name field accordingly.
void OpenEval::setNextEmployee()
{
    nextEmployeeID();
    updateEmployeeFields();
}

//Set the employeeID to the previous employee for the employer.
//Update the Employee Name field accordingly.
void OpenEval::setPreviousEmployee()
{
    previousEmployeeID();
    updateEmployeeFields();
}

//Set the employer ID to the next employer in EMPLOYERS.txt.
//If at the end of the file, display the first employer.
void OpenEval::nextEmployerID()
{

    QVector<int> employerIDVector;

    QFile employerDataFile(EMPLOYERFILE);
    employerIDVector = generateIDVector(&employerDataFile, 0);

    int i = 0;
    int nextEmployerID;

    if (currentEmployerID == 0 || employerIDVector.size() == 0)
    {
        nextEmployerID = 0;
    }

    else if (currentEmployerID == employerIDVector.last())
    {
        nextEmployerID = employerIDVector.at(0);
    }

    else
    {
        while (employerIDVector.at(i) != currentEmployerID)
        {
            i++;
        }
        i++;
        nextEmployerID = employerIDVector.at(i);
    }

    currentEmployerID = nextEmployerID;

}

//Set the employer ID to the previous employer in EMPLOYERS.txt.
//If at the beginning of the file, display the last employer.
void OpenEval::previousEmployerID()
{

    //Generate vector of all of the employer IDs.
    QFile employerDataFile(EMPLOYERFILE);
    QVector<int> employerIDVector = generateIDVector(&employerDataFile, 0);

    //Set currentEmployerID to match the previous ID in the vector.
    int i = 0;
    int previousEmployerID;

    if (currentEmployerID == 0)
    {
        previousEmployerID = 0;
        disableEmployerFields();
    }

    else if (employerIDVector.at(i) == currentEmployerID)
    {
        enableEmployerFields();
        previousEmployerID = employerIDVector.last();
    }
    else
    {
        enableEmployerFields();
        while (employerIDVector.at(i) != currentEmployerID)
        {
            while (employerIDVector.at(i) != currentEmployerID)
            {
                previousEmployerID = employerIDVector.at(i);
                i++;
            }
        }
    }

    currentEmployerID = previousEmployerID;

}

//Set the employer ID to the previous employer in EMPLOYERS.txt.
//Set the employee ID to this employer's first employee. Set the name fields.
void OpenEval::setPreviousEmployer()
{
    previousEmployerID();
    setEmployeeIDForEmployer();
    setFields();
}

//Display the window to review an employee.
void OpenEval::reviewEmployee()
{

    //Prepare and display the window for reviewing an employee.
    reviewEmployeeWindow.setIDValues(currentEmployeeID, currentEmployerID);
    reviewEmployeeWindow.setFields();
    reviewEmployeeWindow.show();

    //If the employee is successfully reviewed...
    if (reviewEmployeeWindow.exec() == QDialog::Accepted)
    {
        //...then update the review fields in the main window to contain the new information.
        updateReviewFields();
    }
}

//Display the window to view the employee's information (address, phone, etc.).
void OpenEval::showEmployeeInfo()
{

    //Prepare and display the window for displaying an employee's information.
    employeeInfoWindow.setIDValues(currentEmployeeID, currentEmployerID);
    employeeInfoWindow.setFields();
    employeeInfoWindow.show();

    //When the window is closed...
    if (employeeInfoWindow.exec() == QDialog::Accepted)
    {
        //...update the fields in case edits were made.
        setFields();
    }
}

//Display the window to view the employer's information (address, phone, etc.).
void OpenEval::showEmployerInfo()
{
    //Prepare and display the window for displaying an employer's information.
    employerInfoWindow.setEmployerID(currentEmployerID);
    employerInfoWindow.setFields();
    employerInfoWindow.show();

    //When the window is closed...
    if (employerInfoWindow.exec() == QDialog::Accepted)
    {
        //update the fields in case edits were made.
        setFields();
    }
}

//Open the Employee Info window in editing mode.
void OpenEval::editEmployee()
{

    //Prepare the window by setting the necessary values.
    employeeInfoWindow.setIDValues(currentEmployeeID, currentEmployerID);
    employeeInfoWindow.setFields();

    //Set the mode to editing mode so that the fields can be changed.
    employeeInfoWindow.updateMode(EmployeeInfo::EditingMode);
    employeeInfoWindow.show();

    //When the window is closed...
    if (employeeInfoWindow.exec() == QDialog::Accepted)
    {
        //...update the fields to reflect the edits.
        setFields();
    }
}

//Open the Employer Info window in editing mode.
void OpenEval::editEmployer()
{
    //Prepare the window by setting the necessary values.
    employerInfoWindow.setEmployerID(currentEmployerID);
    employerInfoWindow.setFields();

    //Set the mode to editing mode so that the fields can be changed.
    employerInfoWindow.setMode(EmployerInfo::EditingMode);
    employerInfoWindow.show();

    //When the window is closed...
    if (employerInfoWindow.exec() == QDialog::Accepted)
    {
        //...update the fields to reflect the edits.
        setFields();
    }
}

//Set the current employee to match a name provided by the user.
void OpenEval::findEmployee()
{
    //Prepare and display the Find Employee window.
    int* employeeID = &currentEmployeeID;
    findEmployeeWindow.setEmployeeID(employeeID, currentEmployerID);
    findEmployeeWindow.show();

    //If a valid employee is submitted...
    if (findEmployeeWindow.exec() == QDialog::Accepted)
    {
        //then update the fields to represent the new employee name.
        setFields();
    }
}

//Set the current employer to match a name provided by the user.
void OpenEval::findEmployer()
{
    //Prepare and display the Find Employer window.
    int* employerID = &currentEmployerID;
    findEmployerWindow.setEmployerID(employerID);
    findEmployerWindow.show();

    //If a valid employer is submitted...
    if (findEmployerWindow.exec() == QDialog::Accepted)
    {
        //then update the fields to represent the new employer name
        //and
        setEmployeeIDForEmployer();
        setFields();
    }
}

void OpenEval::removeEmployee()
{

    int button = QMessageBox::question(this, tr("Confirm Remove"), tr("Are you sure you want to remove %1?")
                                       .arg(employeeName->text()), QMessageBox::Yes | QMessageBox::No);

    if (button == QMessageBox::Yes)
    {

        int currentID = currentEmployeeID;

        setNextEmployee();

        QFile fieldPlacementsFile(FIELDPLACEMENTSFILE);
        QFile employeeDataFile(EMPLOYEEFILE);

        removeEntity(&employeeDataFile, currentID, 0);
        removeEntity(&fieldPlacementsFile, currentID, 0);

        QVector<int> employeeIDVector = generateEmployeeIDVector(currentEmployerID);
        if (employeeIDVector.size() == 0)
        {
            disableEmployeeFields();
            currentEmployeeID = 0;
            updateEmployeeFields();
        }

        else
        {
            updateEmployeeFields();
        }

    }

}

void OpenEval::removeEmployer()
{

    int button = QMessageBox::question(this, tr("Confirm Remove"), tr("Are you sure you want to remove %1?\n"
                    "All employees will be removed as well.")
                                       .arg(employerName->text()), QMessageBox::Yes | QMessageBox::No);

    if (button == QMessageBox::Yes)
    {

        int employerID = currentEmployerID;

        QFile employerDataFile(EMPLOYERFILE);
        QVector<int> employerIDVector = generateIDVector(&employerDataFile, 0);

        if (employerIDVector.size() > 1)
        {
            setNextEmployer();
        }

        else
        {
            employeeName->setText("");
            employerName->setText("");
            currentEmployeeID = 0;
            currentEmployerID = 0;
            disableEmployerFields();
            disableEmployeeFields();
        }

        updateReviewFields();

        QFile fieldPlacementsFile(FIELDPLACEMENTSFILE);
        QFile evaluationResultsFile(EVALUATIONRESULTSFILE);

        QVector<int> employeeIDVector = generateEmployeeIDVector(employerID);

        if (employeeIDVector.size() == 0)
        {
            removeEntity(&employerDataFile, employerID, 0);
            disableEmployeeFields();
        }

        else
        {

            QFile employeeDataFile(EMPLOYEEFILE);

            for (int i = 0; i < employeeIDVector.size(); i++)
            {
                removeEntity(&fieldPlacementsFile, employeeIDVector.at(i), 0);
                removeEntity(&evaluationResultsFile, employeeIDVector.at(i), 1);
                removeEntity(&employeeDataFile, employeeIDVector.at(i), 0);
            }

            removeEntity(&employerDataFile, employerID, 0);
        }
    }

}

//Set the Employer Name field to display the current employer's name.
void OpenEval::updateEmployerName()
{

    QFile employerDataFile(EMPLOYERFILE);
    QString employerDataString = returnDataString(&employerDataFile, currentEmployerID, 0);

    if (employerDataString != "")
    {
        QStringList employerDataList = employerDataString.split("\",\"");
        QString employerNameString  = employerDataList.at(1);
        employerName->setText(employerNameString);
        enableEmployerFields();
    }

    else
    {
        employerName->setText("");
        disableEmployerFields();
    }

}

//Set the Employee Name field to display the current employee's name.
void OpenEval::updateEmployeeFields()
{

    if (currentEmployeeID != 0)
    {
        QFile employeeDataFile(EMPLOYEEFILE);
        QString employeeDataString = returnDataString(&employeeDataFile, currentEmployeeID, 0);
        QStringList employeeDataList = employeeDataString.split("\",\"");
        QString employeeNameString  = employeeDataList.at(1) + " " + employeeDataList.at(2);
        employeeName->setText(employeeNameString);
        enableEmployeeFields();
    }

    else
    {
        employeeName->setText("");
        disableEmployeeFields();
    }


    updateReviewFields();
}

void OpenEval::updateReviewFields()
{
    QFile evaluationResultsFile(EVALUATIONRESULTSFILE);

    QString evaluationResultsString = returnDataString(&evaluationResultsFile, currentEmployeeID, 1);

    if (evaluationResultsString != "")
    {
        QStringList evaluationResultsList = evaluationResultsString.split("\",\"");
        qualityOfWorkScore->setValue(evaluationResultsList.at(5).toInt());
        workHabitsScore->setValue(evaluationResultsList.at(7).toInt());
        jobKnowledgeScore->setValue(evaluationResultsList.at(9).toInt());
        behaviorScore->setValue(evaluationResultsList.at(11).toInt());
        averageScore->setValue(evaluationResultsList.at(13).toDouble());
    }

    else
    {
        qualityOfWorkScore->setValue(1);
        workHabitsScore->setValue(1);
        jobKnowledgeScore->setValue(1);
        behaviorScore->setValue(1);
        averageScore->setValue(1);
    }
}

//Set the first employee ID.
void OpenEval::setFirstEmployeeID()
{

    QFile employeeDataFile(EMPLOYEEFILE);
    QStringList employeeDataList;
    QString employeeDataString = returnFirstString(&employeeDataFile);

    if (employeeDataString != "")
    {
        employeeDataList = employeeDataString.split("\",\"");
        currentEmployeeID = employeeDataList.at(0).toInt();
        enableEmployeeFields();
    }

    else
    {
        currentEmployeeID = 0;
        disableEmployeeFields();
    }

}

//Set the first employer ID.
void OpenEval::setFirstEmployerID()
{
    QFile employerDataFile(EMPLOYERFILE);

    QStringList employerDataList;
    QString employerDataString = returnFirstString(&employerDataFile);

    if (employerDataString != "")
    {
        employerDataList = employerDataString.split("\",\"");
        currentEmployerID = employerDataList.at(0).toInt();
        enableEmployerFields();
    }

    else
    {
        disableEmployerFields();
        currentEmployerID = 0;
    }
}

//Set the employee ID to the first one that matches the current employer ID.
void OpenEval::setEmployeeIDForEmployer()
{

    QVector<int> employeeIDVector = generateEmployeeIDVector(currentEmployerID);

    if (!employeeIDVector.isEmpty())
    {
        //Open the field placements file. Find the first employee employed by this employer.
        //Set this employee ID to be the current.
        QFile fieldPlacementsFile(FIELDPLACEMENTSFILE);
        QString fieldPlacementsString = returnDataString(&fieldPlacementsFile, currentEmployerID, 1);
        QStringList fieldPlacementsList = fieldPlacementsString.split("\",\"");
        currentEmployeeID = fieldPlacementsList.at(0).toInt();
    }

    else
    {
        currentEmployeeID = 0;
    }
}

int OpenEval::returnEmployeeID()
{
    return currentEmployeeID;
}

int OpenEval::returnEmployerID()
{
    return currentEmployerID;
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
    editEmployeeAction->setEnabled(true);
    reviewEmployeeAction->setEnabled(true);
    removeEmployeeAction->setEnabled(true);
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
    newEmployeeAction->setEnabled(false);
    editEmployeeAction->setEnabled(false);
    reviewEmployeeAction->setEnabled(false);
    removeEmployeeAction->setEnabled(false);
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
    newEmployeeAction->setEnabled(true);
    editEmployerAction->setEnabled(true);
    removeEmployerAction->setEnabled(true);
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
    editEmployerAction->setEnabled(false);
    removeEmployerAction->setEnabled(false);
}

//Set the fields in the main window to reflect the new data in the files.
void OpenEval::setFields()
{
    updateEmployeeFields();
    updateEmployerName();
}

void OpenEval::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newEmployeeAction);
    fileMenu->addAction(newEmployerAction);

    editMenu = menuBar()->addMenu(tr("&Edit"));
    editMenu->addAction(editEmployeeAction);
    editMenu->addAction(editEmployerAction);
    editMenu->addAction(removeEmployeeAction);
    editMenu->addAction(removeEmployerAction);

    toolsMenu = menuBar()->addMenu(tr("&Tools"));
    toolsMenu->addAction(reviewEmployeeAction);
}

void OpenEval::createActions()
{
    newEmployeeAction = new QAction(tr("New Employee"), this);
    newEmployeeAction->setStatusTip(tr("Create a new employee."));
    newEmployeeAction->setShortcut(QKeySequence::New);
    connect(newEmployeeAction, SIGNAL(triggered()), this, SLOT(addEmployee()));

    newEmployerAction = new QAction(tr("New Employer"), this);
    newEmployerAction->setStatusTip(tr("Create a new employer."));
    connect(newEmployerAction, SIGNAL(triggered()), this, SLOT(addEmployer()));

    editEmployeeAction = new QAction(tr("Edit Employee"), this);
    editEmployeeAction->setStatusTip(tr("Edit employee."));
    connect(editEmployeeAction, SIGNAL(triggered()), this, SLOT(editEmployee()));

    editEmployerAction = new QAction(tr("Edit Employer"), this);
    editEmployerAction->setStatusTip(tr("Edit employer."));
    connect(editEmployerAction, SIGNAL(triggered()), this, SLOT(editEmployer()));

    removeEmployeeAction = new QAction(tr("Remove Employee"), this);
    removeEmployeeAction->setStatusTip(tr("Remove the current employee."));
    connect(removeEmployeeAction, SIGNAL(triggered()), this, SLOT(removeEmployee()));

    removeEmployerAction = new QAction(tr("Remove Employer"), this);
    removeEmployerAction->setStatusTip(tr("Remove the current employer."));
    connect(removeEmployerAction, SIGNAL(triggered()), this, SLOT(removeEmployer()));

    reviewEmployeeAction = new QAction(tr("Review Employee"), this);
    reviewEmployeeAction->setStatusTip(tr("Review the current employee."));
    connect(reviewEmployeeAction, SIGNAL(triggered()), this, SLOT(reviewEmployee()));

}
