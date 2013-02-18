#include <QtGui>
#include "ReviewEmployee.h"

ReviewEmployee::ReviewEmployee(QWidget *parent)
    : QDialog(parent)
{

    assignEvaluationID();

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
    connect(qualityOfWorkScore, SIGNAL(valueChanged(int)), this, SLOT(setAverageScore()));

    workQualityComments = new QLineEdit;
    workQualityComments->setMaxLength(256);

    QLabel *workHabitsLabel = new QLabel(tr("Work Habits:"));
    workHabitsLabel->setToolTip(tr("Attendance, organization, punctuality, and time on task."));
    workHabitsScore = new QSpinBox;
    workHabitsScore->setRange(1, 5);
    workHabitsScore->setMaximumWidth(40);
    connect(workHabitsScore, SIGNAL(valueChanged(int)), this, SLOT(setAverageScore()));

    workHabitsComments = new QLineEdit;
    workHabitsComments->setMaxLength(256);

    QLabel *jobKnowledgeLabel = new QLabel(tr("Job Knowledge:"));
    jobKnowledgeLabel->setToolTip(tr("Skill/ability to perform job, and interest in learning."));
    jobKnowledgeScore = new QSpinBox;
    jobKnowledgeScore->setRange(1, 5);
    jobKnowledgeScore->setMaximumWidth(40);
    connect(jobKnowledgeScore, SIGNAL(valueChanged(int)), this, SLOT(setAverageScore()));

    jobKnowledgeComments = new QLineEdit;
    jobKnowledgeComments->setMaxLength(256);

    QLabel *behaviorLabel = new QLabel(tr("Behavior:"));
    behaviorLabel->setToolTip(tr("Teamwork, communication, response to criticism, and adapt to change."));
    behaviorScore = new QSpinBox;
    behaviorScore->setRange(1, 5);
    behaviorScore->setMaximumWidth(40);
    connect(behaviorScore, SIGNAL(valueChanged(int)), this, SLOT(setAverageScore()));

    behaviorComments = new QLineEdit;
    behaviorComments->setMaxLength(256);

    QLabel *averageLabel = new QLabel(tr("Average:"));
    averageLabel->setToolTip(tr("Average of scores for Quality of Work, Work Habits, Job Knowledge, and Behavior."));
    averageScore = new QDoubleSpinBox;
    averageScore->setRange(1 , 5);
    averageScore->setReadOnly(true);
    averageScore->setMaximumWidth(55);

    QLabel *overallCommentsLabel = new QLabel(tr("Overall Comments"));
    overallComments = new QLineEdit;
    overallComments->setMaxLength(256);

    QLabel *overallProgressLabel = new QLabel(tr("Overall Progress"));
    overallProgress = new QSpinBox;
    overallProgress->setMaximumWidth(55);

    QLabel *recommendationLabel = new QLabel(tr("Employment Recommendation"));
    employmentRecommendation = new QComboBox;
    employmentRecommendation->addItem("Yes");
    employmentRecommendation->addItem("No");

    QLabel *currentDateLabel = new QLabel(tr("Current Date"));
    currentEvaluationDate = new QCalendarWidget;
    currentEvaluationDate->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    QLabel *nextDateLabel = new QLabel(tr("Next Evaluation"));
    nextEvaluationDate = new QCalendarWidget;
    nextEvaluationDate->setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);

    cancelButton = new QPushButton(tr("Cancel"));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(cancel()));

    submitButton = new QPushButton(tr("Submit"));
    connect(submitButton, SIGNAL(clicked()), this, SLOT(accept()));

    connect(submitButton, SIGNAL(clicked()), this, SLOT(submit()));

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
    evaluationLayout->addWidget(averageLabel, 5, 0);
    evaluationLayout->addWidget(averageScore, 5, 1);
    evaluationLayout->addWidget(overallCommentsLabel, 5, 2);
    evaluationLayout->addWidget(overallComments, 5, 3, 1, 5);
    evaluationLayout->addWidget(overallProgressLabel, 6, 0);
    evaluationLayout->addWidget(overallProgress, 6, 1);
    evaluationLayout->addWidget(recommendationLabel, 6, 6);
    evaluationLayout->addWidget(employmentRecommendation, 6, 7);


    QGridLayout *calendarLayout = new QGridLayout;

    calendarLayout->addWidget(currentDateLabel, 0, 0);
    calendarLayout->addWidget(currentEvaluationDate, 1, 0);
    calendarLayout->addWidget(nextDateLabel, 0, 1);
    calendarLayout->addWidget(nextEvaluationDate, 1, 1);

    QHBoxLayout *buttonLayout = new QHBoxLayout;

    buttonLayout->addWidget(cancelButton);
    buttonLayout->addWidget(submitButton);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addLayout(evaluationLayout, 0, 0, 1, 2);
    mainLayout->addLayout(calendarLayout, 3, 1);
    mainLayout->addLayout(buttonLayout, 4, 1, 1, 2);

    setLayout(mainLayout);
    setWindowTitle(tr("Review Employee"));
}

void ReviewEmployee::submit()
{
    assignEvaluationID();

    QFile evaluationResultsFile(EVALUATIONRESULTSFILE);
    removeEntity(&evaluationResultsFile, currentEmployeeID, 1);

    QString evaluationResultsString = QString::number(currentEvaluationID) + "\",\""
                    + QString::number(currentEmployeeID) + "\",\""
                    + QString::number(currentEmployerID) + "\",\""
                    + currentEvaluationDate->selectedDate().toString() + "\",\""
                    + nextEvaluationDate->selectedDate().toString() + "\",\""
                    + QString::number(qualityOfWorkScore->value())
                    + "\",\"" + workQualityComments->text() + "\",\""
                    + QString::number(workHabitsScore->value()) + "\",\""
                    + workHabitsComments->text() + "\",\""
                    + QString::number(jobKnowledgeScore->value()) + "\",\""
                    + jobKnowledgeComments->text() + "\",\""
                    + QString::number(behaviorScore->value())
                    + "\",\"" + behaviorComments->text() + "\",\""
                    + QString::number(averageScore->value()) + "\",\""
                    + overallComments->text() + "\",\""
                    + QString::number(overallProgress->value())
                    + "\",\"" + employmentRecommendation->currentText();

    addStringToFile(&evaluationResultsFile, evaluationResultsString);
    clearFields();
}

void ReviewEmployee::cancel()
{
    hide();
    clearFields();
}

void ReviewEmployee::assignEvaluationID()
{

    QFile evaluationResultsFile(EVALUATIONRESULTSFILE);
    QVector<int> evaluationIDVector = generateIDVector(&evaluationResultsFile, 0);
    currentEvaluationID = returnMaxValue(evaluationIDVector);

}

void ReviewEmployee::clearFields()
{
    workQualityComments->setText("");
    workHabitsComments->setText("");
    jobKnowledgeComments->setText("");
    behaviorComments->setText("");
    overallComments->setText("");

    qualityOfWorkScore->setValue(1);
    workHabitsScore->setValue(1);
    jobKnowledgeScore->setValue(1);
    behaviorScore->setValue(1);

    qualityOfWorkScore->setFocus();

}

void ReviewEmployee::setIDValues(int employeeID, int employerID)
{
    currentEmployeeID = employeeID;
    currentEmployerID = employerID;
}

void ReviewEmployee::setFields()
{
    setEmployeeName();
    setEmployerName();
}

void ReviewEmployee::setEmployeeName()
{

    QFile employeeDataFile(EMPLOYEEFILE);

    QString employeeDataString = returnDataString(&employeeDataFile, currentEmployeeID, 0);
    QStringList employeeDataList = employeeDataString.split("\",\"");
    QString employeeNameString = employeeDataList.at(1) + " " + employeeDataList.at(2);

    employeeName->setText(employeeNameString);
}

void ReviewEmployee::setEmployerName()
{
    QFile employerDataFile(EMPLOYERFILE);

    QString employerDataString = returnDataString(&employerDataFile, currentEmployerID, 0);
    QStringList employerDataList = employerDataString.split("\",\"");
    QString employerNameString = employerDataList.at(1);

    employerName->setText(employerNameString);

}

void ReviewEmployee::setAverageScore()
{
    double dTotal = (qualityOfWorkScore->value() + workHabitsScore->value()
         + jobKnowledgeScore->value() + behaviorScore->value());
    double dAverage = dTotal/4;

    averageScore->setValue(dAverage);
}
