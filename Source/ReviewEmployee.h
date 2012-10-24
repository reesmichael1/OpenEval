#ifndef REVIEWEMPLOYEE_H
#define REVIEWEMPLOYEE_H

#include <QDialog>
#include "FileOperations.h"

class QPushButton;
class QLineEdit;
class QSpinBox;
class QDoubleSpinBox;
class QCalendarWidget;
class QFile;
class QTextStream;
class QComboBox;

class ReviewEmployee : public QDialog, private FileOperations
{
    Q_OBJECT

public:
    ReviewEmployee(QWidget *parent = 0);
    void setFields();
    void setIDValues(int employeeID, int employerID);

public slots:
    void cancel();
    void setAverageScore();
    void submit();

private:
    int currentEmployeeID;
    int currentEmployerID;
    int currentEvaluationID;
    QPushButton *submitButton;
    QPushButton *averageButton;
    QPushButton *cancelButton;
    QLineEdit *employeeName;
    QLineEdit *employerName;
    QLineEdit *workQualityComments;
    QLineEdit *workHabitsComments;
    QLineEdit *jobKnowledgeComments;
    QLineEdit *behaviorComments;
    QLineEdit *overallComments;
    QSpinBox *qualityOfWorkScore;
    QSpinBox *workHabitsScore;
    QSpinBox *jobKnowledgeScore;
    QSpinBox *behaviorScore;
    QSpinBox *overallProgress;
    QDoubleSpinBox *averageScore;
    QComboBox *employmentRecommendation;
    QFile *evaluationResultsDataFile;
    QTextStream *evaluationResults;
    QCalendarWidget *currentEvaluationDate;
    QCalendarWidget *nextEvaluationDate;
    void clearFields();
    void assignEmployerID();
    void assignEmployeeID();
    void assignEvaluationID();
    void setEmployeeName();
    void setEmployerName();
};

#endif // REVIEWEMPLOYEE_H
