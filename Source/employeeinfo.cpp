#include <QtGui>
#include "EmployeeInfo.h"

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

    QLabel *workQualityLabel = new QLabel(tr("Quality of Work:"));
    workQualityLabel->setToolTip(tr("Accuracy, neatness, timeliness, attention to detail,"
                                    "volume/quantity requirements, adherence to duties, and procedures in job description."));
    qualityOfWorkScore = new QSpinBox;
    qualityOfWorkScore->setRange(1, 5);
    qualityOfWorkScore->setMaximumWidth(40);
    qualityOfWorkScore->setReadOnly(true);

    workQualityComments = new QLineEdit;
    workQualityComments->setMaxLength(256);
    workQualityComments->setReadOnly(true);


    QLabel *workHabitsLabel = new QLabel(tr("Work Habits:"));
    workHabitsLabel->setToolTip(tr("Attendance, organization, punctuality, and time on task."));
    workHabitsScore = new QSpinBox;
    workHabitsScore->setRange(1, 5);
    workHabitsScore->setMaximumWidth(40);
    workHabitsScore->setReadOnly(true);

    workHabitsComments = new QLineEdit;
    workHabitsComments->setMaxLength(256);
    workHabitsComments->setReadOnly(true);

    QLabel *jobKnowledgeLabel = new QLabel(tr("Job Knowledge:"));
    jobKnowledgeLabel->setToolTip(tr("Skill/ability to perform job, and interest in learning."));
    jobKnowledgeScore = new QSpinBox;
    jobKnowledgeScore->setRange(1, 5);
    jobKnowledgeScore->setMaximumWidth(40);
    jobKnowledgeScore->setReadOnly(true);

    jobKnowledgeComments = new QLineEdit;
    jobKnowledgeComments->setMaxLength(256);
    jobKnowledgeComments->setReadOnly(true);

    QLabel *behaviorLabel = new QLabel(tr("Behavior:"));
    behaviorLabel->setToolTip(tr("Teamwork, communication, response to criticism, and adapt to change."));
    behaviorScore = new QSpinBox;
    behaviorScore->setRange(1, 5);
    behaviorScore->setMaximumWidth(40);
    behaviorScore->setReadOnly(true);

    behaviorComments = new QLineEdit;
    behaviorComments->setMaxLength(256);
    behaviorComments->setReadOnly(true);

    QLabel *averageLabel = new QLabel(tr("Average:"));
    averageLabel->setToolTip(tr("Average of scores for Quality of Work, Work Habits, Job Knowledge, and Behavior."));
    averageScore = new QDoubleSpinBox;
    averageScore->setRange(1 , 5);
    averageScore->setReadOnly(true);
    averageScore->setMaximumWidth(55);
    averageScore->setReadOnly(true);

    QLabel *overallCommentsLabel = new QLabel(tr("Overall Comments"));
    overallComments = new QLineEdit;
    overallComments->setMaxLength(256);
    overallComments->setReadOnly(true);

    QLabel *overallProgressLabel = new QLabel(tr("Overall Progress"));
    overallProgress = new QSpinBox;
    overallProgress->setMaximumWidth(55);
    overallProgress->setReadOnly(true);

    QLabel *recommendationLabel = new QLabel(tr("Employment Recommendation"));
    employmentRecommendation = new QLineEdit;
    employmentRecommendation->setReadOnly(true);

    QLabel *currentDateLabel = new QLabel(tr("Previous Evaluation"));
    currentEvaluationDate = new QCalendarWidget;
    currentEvaluationDate->setEnabled(false);
    currentEvaluationDate->setDateEditEnabled(false);

    QLabel *nextDateLabel = new QLabel(tr("Next Evaluation"));
    nextEvaluationDate = new QCalendarWidget;
    nextEvaluationDate->setEnabled(false);
    nextEvaluationDate->setDateEditEnabled(false);

    reviewDatesButton = new QPushButton(tr("Dates for Employee Reviews"));
    connect(reviewDatesButton, SIGNAL(clicked()), this, SLOT(showReviewDates()));

    reviewDatesDialog = new QDialog();

    QHBoxLayout *reviewDatesLayout = new QHBoxLayout(reviewDatesDialog);
    reviewDatesLayout->addWidget(currentDateLabel);
    reviewDatesLayout->addWidget(currentEvaluationDate);
    reviewDatesLayout->addWidget(nextDateLabel);
    reviewDatesLayout->addWidget(nextEvaluationDate);

/*
    QHBoxLayout *calendarLayout = new QHBoxLayout;
    calendarLayout->addWidget(currentDateLabel);
    calendarLayout->addWidget(currentEvaluationDate);
    calendarLayout->addWidget(nextDateLabel);
    calendarLayout->addWidget(nextEvaluationDate);*/

    QHBoxLayout *buttonLayout = new QHBoxLayout;
    buttonLayout->addWidget(reviewDatesButton);

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
    mainLayout->addWidget(workQualityLabel, 5, 0);
    mainLayout->addWidget(qualityOfWorkScore, 5, 1);
    mainLayout->addWidget(workQualityComments, 5, 2, 1, 8);
    mainLayout->addWidget(workHabitsLabel, 6, 0);
    mainLayout->addWidget(workHabitsScore, 6, 1);
    mainLayout->addWidget(workHabitsComments, 6, 2, 1, 8);
    mainLayout->addWidget(jobKnowledgeLabel, 7, 0);
    mainLayout->addWidget(jobKnowledgeScore, 7, 1);
    mainLayout->addWidget(jobKnowledgeComments, 7, 2, 1, 8);
    mainLayout->addWidget(behaviorLabel, 8, 0);
    mainLayout->addWidget(behaviorScore, 8, 1);
    mainLayout->addWidget(behaviorComments, 8, 2, 1, 8);
    mainLayout->addWidget(averageLabel, 9, 0);
    mainLayout->addWidget(averageScore, 9, 1);
    mainLayout->addWidget(overallCommentsLabel, 9, 2);
    mainLayout->addWidget(overallComments, 9, 3, 1, 7);
    mainLayout->addWidget(overallProgressLabel, 10, 0);
    mainLayout->addWidget(overallProgress, 10, 1);
    mainLayout->addWidget(recommendationLabel, 10, 7);
    mainLayout->addWidget(employmentRecommendation, 10, 8);
    mainLayout->addLayout(buttonLayout, 11, 1, 1, 9);
    //mainLayout->addLayout(calendarLayout, 11, 1, 1, 7);

    setLayout(mainLayout);
}

void EmployeeInfo::setIDValues(int employeeID, int employerID)
{
    currentEmployeeID = employeeID;
    currentEmployerID = employerID;
}

void EmployeeInfo::setFields()
{
    QFile employeeDataFile("/Users/ladmin/Documents/OpenEval/Files/EMPLOYEES.txt");
    QTextStream employeeData(&employeeDataFile);
}

void EmployeeInfo::showReviewDates()
{
    reviewDatesDialog->show();
}
