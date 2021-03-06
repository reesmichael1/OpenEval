//Operations that define the Employee Info window.

#include <QtGui>
#include "EmployeeInfo.h"

//Draw base window for Employee Info.
EmployeeInfo::EmployeeInfo(QWidget *parent)
    : QDialog(parent)
{

    QLabel *firstNameLabel = new QLabel(tr("First Name"));
    employeeFirstName = new QLineEdit;
    employeeFirstName->setReadOnly(true);

    QLabel *lastNameLabel = new QLabel(tr("Last Name"));
    employeeLastName = new QLineEdit;
    employeeLastName->setReadOnly(true);

    QLabel *addressLabel = new QLabel(tr("Street Address"));
    employeeAddress = new QLineEdit;
    employeeAddress->setReadOnly(true);

    QLabel *cityLabel = new QLabel(tr("City"));
    employeeCity = new QLineEdit;
    employeeCity->setReadOnly(true);

    QLabel *stateLabel = new QLabel(tr("State"));
    employeeState = new QLineEdit;
    employeeState->setReadOnly(true);

    QLabel *zipLabel = new QLabel(tr("Zip Code"));
    employeeZipCode = new QLineEdit;
    employeeZipCode->setReadOnly(true);

    QLabel *phoneLabel = new QLabel(tr("Phone Number"));
    employeePhone = new QLineEdit;
    employeePhone->setReadOnly(true);

    QLabel *cellLabel = new QLabel(tr("Cell Phone"));
    employeeCell = new QLineEdit;
    employeeCell->setReadOnly(true);

    QLabel *emailLabel = new QLabel(tr("E-Mail Address"));
    employeeEMail = new QLineEdit;
    employeeEMail->setReadOnly(true);

    QLabel *employerLabel = new QLabel(tr("Employer"));
    employeeEmployer = new QLineEdit;
    employeeEmployer->setReadOnly(true);


    qualityOfWorkScore = new QSpinBox;
    qualityOfWorkScore->setRange(1, 5);
    qualityOfWorkScore->setMaximumWidth(40);
    qualityOfWorkScore->setReadOnly(true);

    workQualityComments = new QLineEdit;
    workQualityComments->setMaxLength(256);
    workQualityComments->setReadOnly(true);

    workHabitsScore = new QSpinBox;
    workHabitsScore->setRange(1, 5);
    workHabitsScore->setMaximumWidth(40);
    workHabitsScore->setReadOnly(true);

    workHabitsComments = new QLineEdit;
    workHabitsComments->setMaxLength(256);
    workHabitsComments->setReadOnly(true);

    jobKnowledgeScore = new QSpinBox;
    jobKnowledgeScore->setRange(1, 5);
    jobKnowledgeScore->setMaximumWidth(40);
    jobKnowledgeScore->setReadOnly(true);

    jobKnowledgeComments = new QLineEdit;
    jobKnowledgeComments->setMaxLength(256);
    jobKnowledgeComments->setReadOnly(true);

    behaviorScore = new QSpinBox;
    behaviorScore->setRange(1, 5);
    behaviorScore->setMaximumWidth(40);
    behaviorScore->setReadOnly(true);

    behaviorComments = new QLineEdit;
    behaviorComments->setMaxLength(256);
    behaviorComments->setReadOnly(true);

    averageScore = new QDoubleSpinBox;
    averageScore->setRange(1 , 5);
    averageScore->setReadOnly(true);
    averageScore->setMaximumWidth(55);
    averageScore->setReadOnly(true);

    overallComments = new QLineEdit;
    overallComments->setMaxLength(256);
    overallComments->setReadOnly(true);

    overallProgressScore = new QSpinBox;
    overallProgressScore->setMaximumWidth(55);
    overallProgressScore->setReadOnly(true);

    employmentRecommendation = new QLineEdit;
    employmentRecommendation->setReadOnly(true);

    previousEvaluationDate = new QCalendarWidget;
    previousEvaluationDate->setSelectionMode(QCalendarWidget::NoSelection);
    previousEvaluationDate->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    nextEvaluationDate = new QCalendarWidget;
    nextEvaluationDate->setSelectionMode(QCalendarWidget::NoSelection);
    nextEvaluationDate->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    showReviewButton = new QPushButton(tr("Employee Review Information"));
    connect(showReviewButton, SIGNAL(clicked()), this, SLOT(showReviewInfo()));

    editButton = new QPushButton(tr("Edit Employee"));
    connect(editButton, SIGNAL(clicked()), this, SLOT(editEmployee()));

    submitButton = new QPushButton(tr("Submit Edits"));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submitEdits()));
    submitButton->setVisible(false);

    okButton = new QPushButton(tr("OK"));
    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(okButton, SIGNAL(clicked()), this, SLOT(clearFields()));

    cancelButton = new QPushButton(tr("Cancel"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancelEdits()));
    cancelButton->setVisible(false);

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(showReviewButton);
    buttonLayout->addWidget(editButton);
    buttonLayout->addWidget(submitButton);
    buttonLayout->addWidget(okButton);
    buttonLayout->addWidget(cancelButton);

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
    mainLayout->addWidget(employeeCity, 3, 1, 1, 2);
    mainLayout->addWidget(stateLabel, 3, 3);
    mainLayout->addWidget(employeeState, 3, 4, 1, 1);
    mainLayout->addWidget(zipLabel, 3, 5);
    mainLayout->addWidget(employeeZipCode, 3, 6, 1, 4);
    mainLayout->addWidget(emailLabel, 4, 0);
    mainLayout->addWidget(employeeEMail, 4, 1, 1, 4);
    mainLayout->addWidget(employerLabel, 4, 5);
    mainLayout->addWidget(employeeEmployer, 4, 6, 1, 4);
    mainLayout->addLayout(buttonLayout, 5, 1, 1, 9);


    setLayout(mainLayout);
    setWindowTitle(tr("Employee Info"));
}

//The base OpenEval window passes the current employee ID and employer ID
//to Employee Info through this function.
void EmployeeInfo::setIDValues(int employeeID, int employerID)
{
    currentEmployeeID = employeeID;
    currentEmployerID = employerID;
}

//This reads the necessary information from the employee data file and sets
//the corresponding fields in the window with the information it contains.
void EmployeeInfo::setFields()
{
    QFile employeeDataFile(EMPLOYEEFILE);
    QString employeeDataString = returnDataString(&employeeDataFile, currentEmployeeID, 0);
    QStringList employeeDataList = employeeDataString.split("\",\"");


    employeeFirstName->setText(employeeDataList.at(1));
    employeeLastName->setText(employeeDataList.at(2));
    employeeEMail->setText(employeeDataList.at(3));
    employeePhone->setText(employeeDataList.at(4));
    employeeCell->setText(employeeDataList.at(5));
    employeeAddress->setText(employeeDataList.at(6));
    employeeCity->setText(employeeDataList.at(7));
    employeeState->setText(employeeDataList.at(8));
    employeeZipCode->setText(employeeDataList.at(9));

    QFile employerDataFile(EMPLOYERFILE);

    QString employerDataString = returnDataString(&employerDataFile, currentEmployerID, 0);
    QStringList employerDataList = employerDataString.split("\",\"");


    employeeEmployer->setText(employerDataList.at(1));

    QFile evaluationResultsFile(EVALUATIONRESULTSFILE);

    QString evaluationResultsString = returnDataString(&evaluationResultsFile, currentEmployeeID, 1);

    if (evaluationResultsString != "")
    {

        QStringList evaluationResultsList = evaluationResultsString.split("\",\"");

        previousEvaluationDate->setSelectedDate(QDate::fromString(evaluationResultsList.at(3)));
        nextEvaluationDate->setSelectedDate(QDate::fromString(evaluationResultsList.at(4)));
        qualityOfWorkScore->setValue(evaluationResultsList.at(5).toInt());
        workQualityComments->setText(evaluationResultsList.at(6));
        workHabitsScore->setValue(evaluationResultsList.at(7).toInt());
        workHabitsComments->setText(evaluationResultsList.at(8));
        jobKnowledgeScore->setValue(evaluationResultsList.at(9).toInt());
        jobKnowledgeComments->setText(evaluationResultsList.at(10));
        behaviorScore->setValue(evaluationResultsList.at(11).toInt());
        behaviorComments->setText(evaluationResultsList.at(12));
        averageScore->setValue(evaluationResultsList.at(13).toDouble());
        overallComments->setText(evaluationResultsList.at(14));
        overallProgressScore->setValue(evaluationResultsList.at(15).toInt());
        employmentRecommendation->setText(evaluationResultsList.at(16));
    }

}

//This draws the Review Employee window and sets the necessary information.
//The window is displayed when the corresponding button is clicked.
void EmployeeInfo::showReviewInfo()
{
    QLabel *workQualityLabel = new QLabel(tr("Quality of Work:"));
    workQualityLabel->setToolTip(tr("Accuracy, neatness, timeliness, attention to detail,"
                                    "volume/quantity requirements, adherence to duties, and procedures in job description."));

    QLabel *workHabitsLabel = new QLabel(tr("Work Habits:"));
    workHabitsLabel->setToolTip(tr("Attendance, organization, punctuality, and time on task."));

    QLabel *jobKnowledgeLabel = new QLabel(tr("Job Knowledge:"));
    jobKnowledgeLabel->setToolTip(tr("Skill/ability to perform job, and interest in learning."));

    QLabel *behaviorLabel = new QLabel(tr("Behavior:"));
    behaviorLabel->setToolTip(tr("Teamwork, communication, response to criticism, and adapt to change."));

    QLabel *averageLabel = new QLabel(tr("Average:"));
    averageLabel->setToolTip(tr("Average of scores for Quality of Work, Work Habits, Job Knowledge, and Behavior."));

    QLabel *previousDateLabel = new QLabel(tr("Previous Evaluation"));
    QLabel *nextDateLabel = new QLabel(tr("Next Evaluation"));

    QLabel *overallCommentsLabel = new QLabel(tr("Overall Comments"));
    QLabel *overallProgressLabel = new QLabel(tr("Overall Progress"));
    QLabel *recommendationLabel = new QLabel(tr("Employment Recommendation"));

    QGridLayout *calendarLayout = new QGridLayout;

    calendarLayout->addWidget(previousDateLabel, 0, 0);
    calendarLayout->addWidget(previousEvaluationDate, 1, 0);
    calendarLayout->addWidget(nextDateLabel, 0, 1);
    calendarLayout->addWidget(nextEvaluationDate, 1, 1);

    reviewDialog = new QDialog();

    QGridLayout *reviewLayout = new QGridLayout(reviewDialog);
    reviewLayout->addWidget(workQualityLabel, 5, 0);
    reviewLayout->addWidget(qualityOfWorkScore, 5, 1);
    reviewLayout->addWidget(workQualityComments, 5, 2, 1, 8);
    reviewLayout->addWidget(workHabitsLabel, 6, 0);
    reviewLayout->addWidget(workHabitsScore, 6, 1);
    reviewLayout->addWidget(workHabitsComments, 6, 2, 1, 8);
    reviewLayout->addWidget(jobKnowledgeLabel, 7, 0);
    reviewLayout->addWidget(jobKnowledgeScore, 7, 1);
    reviewLayout->addWidget(jobKnowledgeComments, 7, 2, 1, 8);
    reviewLayout->addWidget(behaviorLabel, 8, 0);
    reviewLayout->addWidget(behaviorScore, 8, 1);
    reviewLayout->addWidget(behaviorComments, 8, 2, 1, 8);
    reviewLayout->addWidget(averageLabel, 9, 0);
    reviewLayout->addWidget(averageScore, 9, 1);
    reviewLayout->addWidget(overallCommentsLabel, 9, 2);
    reviewLayout->addWidget(overallComments, 9, 3, 1, 7);
    reviewLayout->addWidget(overallProgressLabel, 10, 0);
    reviewLayout->addWidget(overallProgressScore, 10, 1);
    reviewLayout->addWidget(recommendationLabel, 10, 8);
    reviewLayout->addWidget(employmentRecommendation, 10, 9);
    reviewLayout->addLayout(calendarLayout, 11, 0, 1, 10);

    reviewDialog->show();
}

//This resets the Employee Info dialog to its base state.
void EmployeeInfo::clearFields()
{
    qualityOfWorkScore->setValue(1);
    workQualityComments->setText("");
    workHabitsScore->setValue(1);
    workHabitsComments->setText("");
    jobKnowledgeScore->setValue(1);
    jobKnowledgeComments->setText("");
    behaviorScore->setValue(1);
    behaviorComments->setText("");
    averageScore->setValue(1);
    overallComments->setText("");
    overallProgressScore->setValue(1);
    employmentRecommendation->setText("");
}

//This updates all of the fields so that they
//are no longer read only.
void EmployeeInfo::editEmployee()
{
    updateMode(EditingMode);
}

//This writes any changes that have been made through editing
//mode to the employee info data file so that they are stored.
void EmployeeInfo::submitEdits()
{
    updateMode(ViewingMode);

    QFile employeeDataFile(EMPLOYEEFILE);

    removeEntity(&employeeDataFile, currentEmployeeID, 0);

    QString employeeDataString = QString::number(currentEmployeeID)
                            + "\",\"" + employeeFirstName->text() + "\",\"" + employeeLastName->text()
                            + "\",\"" + employeeEMail->text() + "\",\"" + employeePhone->text()
                            + "\",\"" + employeeCell->text() + "\",\"" + employeeAddress->text()
                            + "\",\"" + employeeCity->text() + "\",\"" + employeeState->text()
                            + "\",\"" + employeeZipCode->text();

    addStringToFile(&employeeDataFile, employeeDataString);
}

//This resets the fields to be read only, and rereads the
//information from the data file to be reset.
void EmployeeInfo::cancelEdits()
{
    updateMode(ViewingMode);
    setFields();
}

//This function takes a flag and updates the fields that contain
//the information of the employee. If the flag is for editing mode,
//the fields are set to be editable. Otherwise, they become read only.
void EmployeeInfo::updateMode(Mode currentMode)
{
    if (currentMode == EditingMode)
    {
        editButton->setVisible(false);
        okButton->setVisible(false);
        employeeFirstName->setReadOnly(false);
        employeeLastName->setReadOnly(false);
        employeePhone->setReadOnly(false);
        employeeCell->setReadOnly(false);
        employeeAddress->setReadOnly(false);
        employeeCity->setReadOnly(false);
        employeeState->setReadOnly(false);
        employeeZipCode->setReadOnly(false);
        employeeEMail->setReadOnly(false);
        showReviewButton->setEnabled(false);
        cancelButton->setVisible(true);
        submitButton->setVisible(true);
    }
    else
    {
        submitButton->setVisible(false);
        cancelButton->setVisible(false);
        employeeFirstName->setReadOnly(true);
        employeeLastName->setReadOnly(true);
        employeePhone->setReadOnly(true);
        employeeCell->setReadOnly(true);
        employeeAddress->setReadOnly(true);
        employeeCity->setReadOnly(true);
        employeeState->setReadOnly(true);
        employeeZipCode->setReadOnly(true);
        employeeEMail->setReadOnly(true);
        showReviewButton->setEnabled(true);
        okButton->setVisible(true);
        editButton->setVisible(true);
    }
}
