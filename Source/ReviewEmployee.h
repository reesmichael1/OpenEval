#ifndef REVIEWEMPLOYEE_H
#define REVIEWEMPLOYEE_H

#include <QDialog>

class QPushButton;
class QLineEdit;
class QSpinBox;
class QDoubleSpinBox;
class QCalendarWidget;
class QFile;
class QTextStream;

class ReviewEmployee : public QDialog
{
    Q_OBJECT

public:
    ReviewEmployee(QWidget *parent = 0);
    void setEmployeeID(int employeeID);
    void setEmployerID(int employerID);
    void setEmployeeName();
    void setEmployerName();

public slots:
    void cancel();
    void submit();

private:
    int currentEmployeeID;
    int currentEmployerID;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QLineEdit *employeeName;
    QLineEdit *employerName;
    QLineEdit *workQualityComments;
    QLineEdit *workHabitsComments;
    QLineEdit *jobKnowledgeComments;
    QLineEdit *behaviorComments;
    QSpinBox *qualityOfWorkScore;
    QSpinBox *workHabitsScore;
    QSpinBox *jobKnowledgeScore;
    QSpinBox *behaviorScore;
    QDoubleSpinBox *averageScore;
    QFile *evaluationResultsDataFile;
    QTextStream *evaluationResults;
    QCalendarWidget *currentEvaluationDate;
    QCalendarWidget *nextEvaluationDate;
    void clearFields();
    void assignEmployerID();
    void assignEmployeeID();
};

#endif // REVIEWEMPLOYEE_H
