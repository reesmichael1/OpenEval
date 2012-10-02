#include <QtGui>
#include "ReviewEmployee.h"

ReviewEmployee::ReviewEmployee(QWidget *parent)
    : QDialog(parent)
{

    evaluationResultsDataFile = new QFile("/Users/ladmin/Documents/OpenEval/Files/EVALUATIONRESULTS.txt");
    evaluationResults = new QTextStream(evaluationResultsDataFile);

    QLabel *employeeNameLabel = new QLabel(tr("Employee Name"));
    employeeName = new QLineEdit;
    employeeName->setReadOnly(true);

    QLabel *employerNameLabel = new QLabel(tr("Employer Name"));
    employerName = new QLineEdit;
    employerName->setReadOnly(true);

    QLabel *workQualityLabel = new QLabel(tr("Quality of Work:"));
    workQualityLabel->setToolTip(tr("Accuracy, neatness, timeliness, attention to detail,"
                                    "volume/quantity requirements, adherence to duties, and procedures in job description."));
    qualityOfWorkScore = new QSpinBox;
    qualityOfWorkScore->setRange(1, 5);
    qualityOfWorkScore->setMaximumWidth(40);

    workQualityComments = new QLineEdit;
    workQualityComments->setMaxLength(256);


    QLabel *workHabitsLabel = new QLabel(tr("Work Habits:"));
    workHabitsLabel->setToolTip(tr("Attendance, organization, punctuality, and time on task."));
    workHabitsScore = new QSpinBox;
    workHabitsScore->setRange(1, 5);
    workHabitsScore->setMaximumWidth(40);

    workHabitsComments = new QLineEdit;
    workHabitsComments->setMaxLength(256);

    QLabel *jobKnowledgeLabel = new QLabel(tr("Job Knowledge:"));
    jobKnowledgeLabel->setToolTip(tr("Skill/ability to perform job, and interest in learning."));
    jobKnowledgeScore = new QSpinBox;
    jobKnowledgeScore->setRange(1, 5);
    jobKnowledgeScore->setMaximumWidth(40);

    jobKnowledgeComments = new QLineEdit;
    jobKnowledgeComments->setMaxLength(256);

    QLabel *behaviorLabel = new QLabel(tr("Behavior:"));
    behaviorLabel->setToolTip(tr("Teamwork, communication, response to criticism, and adapt to change."));
    behaviorScore = new QSpinBox;
    behaviorScore->setRange(1, 5);
    behaviorScore->setMaximumWidth(40);

    behaviorComments = new QLineEdit;
    behaviorComments->setMaxLength(256);

    QLabel *averageLabel = new QLabel(tr("Average:"));
    averageLabel->setToolTip(tr("Average of scores for Quality of Work, Work Habits, Job Knowledge, and Behavior."));
    averageScore = new QDoubleSpinBox;
    averageScore->setRange(1 , 5);
    averageScore->setReadOnly(true);
    averageScore->setMaximumWidth(55);

    QLabel *currentDateLabel = new QLabel(tr("Current Date"));
    currentEvaluationDate = new QCalendarWidget;

    QLabel *nextDateLabel = new QLabel(tr("Next Evaluation"));
    nextEvaluationDate = new QCalendarWidget;

    cancelButton = new QPushButton(tr("Cancel"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));

    submitButton = new QPushButton(tr("Submit"));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(accept()));

    QGridLayout *evaluationLayout = new QGridLayout;
    evaluationLayout->addWidget(employeeNameLabel, 0, 0);
    evaluationLayout->addWidget(employeeName, 0, 2, 1, 2);
    evaluationLayout->addWidget(employerNameLabel, 0, 4);
    evaluationLayout->addWidget(employerName, 0, 5, 1, 3);
    evaluationLayout->addWidget(workQualityLabel, 1, 0);
    evaluationLayout->addWidget(qualityOfWorkScore, 1, 1);
    evaluationLayout->addWidget(workQualityComments, 1, 2, 1, 6);
    evaluationLayout->addWidget(workHabitsLabel, 2, 0);
    evaluationLayout->addWidget(workHabitsScore, 2, 1);
    evaluationLayout->addWidget(workHabitsComments, 2, 2, 1, 6);
    evaluationLayout->addWidget(jobKnowledgeLabel, 3, 0);
    evaluationLayout->addWidget(jobKnowledgeScore, 3, 1);
    evaluationLayout->addWidget(jobKnowledgeComments, 3, 2, 1, 6);
    evaluationLayout->addWidget(behaviorLabel, 4, 0);
    evaluationLayout->addWidget(behaviorScore, 4, 1);
    evaluationLayout->addWidget(behaviorComments, 4, 2, 1, 6);

    QHBoxLayout *calendarLayout = new QHBoxLayout;

    calendarLayout->addWidget(currentDateLabel);
    calendarLayout->addWidget(currentEvaluationDate);
    calendarLayout->addWidget(nextDateLabel);
    calendarLayout->addWidget(nextEvaluationDate);

    QHBoxLayout *buttonLayout = new QHBoxLayout;

    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(submitButton);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addLayout(evaluationLayout, 0, 0, 1, 2);
    mainLayout->addLayout(calendarLayout, 3, 1);
    mainLayout->addLayout(buttonLayout, 4, 1, 1, 2);

    //setEmployeeName();

    setLayout(mainLayout);
}

void ReviewEmployee::submit()
{
    int workQualityScore = qualityOfWorkScore->value();

    evaluationResultsDataFile->open(QIODevice::Text | QIODevice::WriteOnly | QIODevice::Append);
    evaluationResults->operator<<(workQualityScore) << "," << endl;
    evaluationResultsDataFile->close();
    clearFields();
}

void ReviewEmployee::cancel()
{
    hide();
    clearFields();
}

void ReviewEmployee::clearFields()
{
    workQualityComments->setText("");
    workHabitsComments->setText("");
    jobKnowledgeComments->setText("");
    behaviorComments->setText("");

    qualityOfWorkScore->setValue(1);
    workHabitsScore->setValue(1);
    jobKnowledgeScore->setValue(1);
    behaviorScore->setValue(1);

    qualityOfWorkScore->setFocus();

}

void ReviewEmployee::setEmployeeID(int employeeID)
{
    currentEmployeeID = employeeID;
}

void ReviewEmployee::setEmployerID(int employerID)
{
    currentEmployerID = employerID;
}

void ReviewEmployee::setEmployeeName()
{

    QFile employeeDataFile("/Users/ladmin/Documents/OpenEval/Files/EMPLOYEES.txt");
    QTextStream employeeData(&employeeDataFile);

    employeeDataFile.open(QIODevice::Text | QIODevice::ReadOnly);
    QString employeeDataString = employeeData.readLine();
    QString employeeNameString;
    QStringList employeeDataList;

    do
    {
        employeeDataList = employeeDataString.split(',');
        employeeNameString = employeeDataList.at(1) + " " + employeeDataList.at(2);
        employeeDataString = employeeData.readLine();
    } while (currentEmployeeID != employeeDataList.at(0).toInt());

    employeeName->setText(employeeNameString);
    employeeDataFile.close();
}

void ReviewEmployee::setEmployerName()
{
    QFile employerDataFile("/Users/ladmin/Documents/OpenEval/Files/EMPLOYERS.txt");
    QTextStream employerData(&employerDataFile);

    employerDataFile.open(QIODevice::Text | QIODevice::ReadOnly);
    QString employerDataString = employerData.readLine();
    QString employerNameString;
    QStringList employerDataList;

    do
    {
        employerDataList = employerDataString.split(',');
        employerNameString = employerDataList.at(1);
        employerDataString = employerData.readLine();
    } while (currentEmployerID != employerDataList.at(0).toInt());

    employerName->setText(employerNameString);
    employerDataFile.close();
}
