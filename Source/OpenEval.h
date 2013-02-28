//Declarations for the base window--the
//window that is seen when OpenEval first runs.

#ifndef OPENEVAL_H
#define OPENEVAL_H

#include <QtGui>
#include "NewEmployee.h"
#include "NewEmployer.h"
#include "ReviewEmployee.h"
#include "EmployerInfo.h"
#include "EmployeeInfo.h"
#include "FindEmployee.h"
#include "FindEmployer.h"
#include "FileOperations.h"

class OpenEval : public QMainWindow, private FileOperations
{
    Q_OBJECT

public:
    OpenEval();
    int returnEmployeeID();
    int returnEmployerID();

public slots:
    void addEmployee();
    void addEmployer();
    void setNextEmployee();
    void setPreviousEmployee();
    void setPreviousEmployer();
    void setNextEmployer();
    void setFields();
    void reviewEmployee();
    void showEmployerInfo();
    void showEmployeeInfo();
    void editEmployee();
    void editEmployer();
    void findEmployee();
    void findEmployer();
    void removeEmployee();
    void removeEmployer();
    void printActionTriggered();

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
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *toolsMenu;
    QAction *printAction;
    QAction *newEmployeeAction;
    QAction *newEmployerAction;
    QAction *editEmployeeAction;
    QAction *editEmployerAction;
    QAction *removeEmployeeAction;
    QAction *removeEmployerAction;
    QAction *reviewEmployeeAction;
    QAction *findEmployeeAction;
    QAction *findEmployerAction;
    QWidget *centralWidget;
    QDialog *printerOptions;
    QCheckBox *employeeData;
    QCheckBox *employerData;
    QCheckBox *employeeDataWithEvaluation;
    QCheckBox *evaluationScores;
    NewEmployee newEmployeeWindow;
    NewEmployer newEmployerWindow;
    ReviewEmployee reviewEmployeeWindow;
    EmployerInfo employerInfoWindow;
    EmployeeInfo employeeInfoWindow;
    FindEmployee findEmployeeWindow;
    FindEmployer findEmployerWindow;
    int currentEmployeeID;
    int currentEmployerID;
    void updateEmployeeFields();
    void updateEmployerName();
    void updateReviewFields();
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
    void printEmployerData(QPainter *painter, QPrinter *printer);
    void printEmployeeData(QPainter *painter, QPrinter *printer, bool evaluationResults);
    void printEvaluationScores(QPainter *painter, QPrinter *printer);
    void createActions();
    void createMenus();
};

#endif // OPENEVAL
