#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

#include <QDialog>

class QLineEdit;
class QSpinBox;
class QDoubleSpinBox;
class QCalendarWidget;

class EmployeeInfo : public QDialog
{
    Q_OBJECT

public:
    EmployeeInfo(QWidget *parent = 0);
    void setFields();
    void setIDValues(int employeeID, int employerID);

public slots:
    void showReviewDates();

private:
    int currentEmployeeID;
    int currentEmployerID;
    QLineEdit *employeeFirstName;
    QLineEdit *employeeLastName;
    QLineEdit *employeeAddress;
    QLineEdit *employeeCity;
    QLineEdit *employeeState;
    QLineEdit *employeeZipCode;
    QLineEdit *employeePhone;
    QLineEdit *employeeCell;
    QLineEdit *employeeEMail;
    QLineEdit *employeeEmployer;
    QLineEdit *workQualityComments;
    QLineEdit *workHabitsComments;
    QLineEdit *jobKnowledgeComments;
    QLineEdit *behaviorComments;
    QLineEdit *overallComments;
    QLineEdit *employmentRecommendation;
    QSpinBox *qualityOfWorkScore;
    QSpinBox *workHabitsScore;
    QSpinBox *jobKnowledgeScore;
    QSpinBox *behaviorScore;
    QSpinBox *overallProgressScore;
    QDoubleSpinBox *averageScore;
    QCalendarWidget *currentEvaluationDate;
    QCalendarWidget *nextEvaluationDate;
    QPushButton *okButton;
    QPushButton *reviewDatesButton;
    QPushButton *editButton;
    QDialog *reviewDatesDialog;
};

#endif // EMPLOYEEINFO_H
