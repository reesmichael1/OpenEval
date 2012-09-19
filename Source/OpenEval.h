#ifndef OPENEVAL_H
#define OPENEVAL_H

#include <QtGui>
#include <QFile>
#include "NewEmployee.h"
#include "NewEmployer.h"

class OpenEval : public QWidget
{
    Q_OBJECT

public:
    OpenEval();

public slots:
    void submitEmployee();
    void addEmployee();
    void addEmployer();
    void removeEmployee();
    void setNextEmployee();
    void setPreviousEmployee();
    void setPreviousEmployer();
    void setNextEmployer();
    void setFields();

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
    int currentEmployeeID;
    int currentEmployerID;
    void updateEmployeeName();
    void updateEmployerName();
    void nextEmployerID();
    void nextEmployeeID();
    void previousEmployerID();
    void previousEmployeeID();
    void updateEmployeeID();
    void updateEmployerID();
    void disableEmployeeFields();
    void enableEmployeeFields();
    void disableEmployerFields();
    void enableEmployerFields();
};

#endif // OPENEVAL
