//Declarations for the Employee Info window.

#ifndef EMPLOYEEINFO_H
#define EMPLOYEEINFO_H

#include <QDialog>
#include "FileOperations.h"

class QLineEdit;
class QSpinBox;
class QDoubleSpinBox;
class QCalendarWidget;

class EmployeeInfo : public QDialog, private FileOperations
{
    Q_OBJECT

public:
    enum Mode {EditingMode, ViewingMode};
    EmployeeInfo(QWidget *parent = 0);
    void setFields();
    void setIDValues(int employeeID, int employerID);
    void updateMode(Mode currentMode);

public slots:
    void clearFields();
    void showReviewInfo();
    void editEmployee();
    void submitEdits();
    void cancelEdits();

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
    QCalendarWidget *previousEvaluationDate;
    QCalendarWidget *nextEvaluationDate;
    QPushButton *okButton;
    QPushButton *cancelButton;
    QPushButton *showReviewButton;
    QPushButton *editButton;
    QPushButton *submitButton;
    QDialog *reviewDialog;
};

#endif // EMPLOYEEINFO_H
