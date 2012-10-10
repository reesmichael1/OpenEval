#ifndef OPENEVAL_H
#define OPENEVAL_H

#include <QtGui>
#include <QFile>
#include "NewEmployee.h"
#include "NewEmployer.h"
#include "ReviewEmployee.h"
#include "EmployerInfo.h"
#include "EmployeeInfo.h"

class OpenEval : public QWidget
{
    Q_OBJECT

public:
    OpenEval();
    int returnEmployeeID();
    int returnEmployerID();

public slots:
    void addEmployee();
    void addEmployer();
    void removeEmployee();
    void setNextEmployee();
    void setPreviousEmployee();
    void setPreviousEmployer();
    void setNextEmployer();
    void setFields();
    void reviewEmployee();
    void showEmployerInfo();
    void showEmployeeInfo();
    void editEmployer();

private:
    QLineEdit *employeeName;
    QLineEdit *employerName;
    QSpinBox *qualityOfWorkScore;
    QSpinBox *workHabitsScore;
    QSpinBox *jobKnowledgeScore;
    QSpinBox *behaviorScore;
    QPushButton *addEmployeeButton;
    QPushButton *addEmployerButton;
    QPushButton *employeeInfoButton;
    QPushButton *employerInfoButton;
    QPushButton *nextEmployeeButton;
    QPushButton *previousEmployeeButton;
    QPushButton *nextEmployerButton;
    QPushButton *previousEmployerButton;
    QPushButton *editEmployeeButton;
    QPushButton *editEmployerButton;
    QPushButton *removeEmployeeButton;
    QPushButton *removeEmployerButton;
    QPushButton *findEmployeeButton;
    QPushButton *findEmployerButton;
    QPushButton *reviewButton;
    QDoubleSpinBox *averageScore;
    QString employeeString;
    QString employerString;
    QFile *employeeDataFile;
    QFile *employerDataFile;
    QFile *employerIDDataFile;
    QTextStream *employeeData;
    QTextStream *employerData;
    QTextStream *employerIDData;
    NewEmployee newEmployeeWindow;
    NewEmployer newEmployerWindow;
    ReviewEmployee reviewEmployeeWindow;
    EmployerInfo employerInfoWindow;
    EmployeeInfo employeeInfoWindow;
    int currentEmployeeID;
    int currentEmployerID;
    bool employeeDataFileEmpty;
    bool employerDataFileEmpty;
    bool fieldPlacementsDataFileEmpty;
    void updateEmployeeName();
    void updateEmployerName();
    void nextEmployerID();
    void nextEmployeeID();
    void previousEmployerID();
    void previousEmployeeID();
    void setFirstEmployeeID();
    void setEmployeeIDForEmployer();
    void setFirstEmployerID();
    void disableEmployeeFields();
    void enableEmployeeFields();
    void disableEmployerFields();
    void enableEmployerFields();
    QVector<int> generateEmployeeIDVector();
    QVector<int> generateEmployerIDVector();
};

#endif // OPENEVAL
