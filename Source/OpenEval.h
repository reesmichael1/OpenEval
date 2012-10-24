#ifndef OPENEVAL_H
#define OPENEVAL_H

#include <QtGui>
#include <QFile>
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
    QAction *newEmployeeAction;
    QAction *newEmployerAction;
    QAction *editEmployeeAction;
    QAction *editEmployerAction;
    QKeySequence *newEmployerShortcut;
    QWidget *centralWidget;
    QFile *employeeDataFile;
    QFile *employerDataFile;
    QTextStream *employeeData;
    QTextStream *employerData;
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
    void createActions();
    void createMenus();
};

#endif // OPENEVAL
