#ifndef FINDEMPLOYER_H
#define FINDEMPLOYER_H

#include <QDialog>
#include "FileOperations.h"

class QLineEdit;
class QPushButton;

class FindEmployer : public QDialog, private FileOperations
{

    Q_OBJECT

public:
    FindEmployer(QDialog *parent = 0);
    void setEmployerID(int *employerID);

public slots:
    void findEmployer();

private:
    int *currentEmployerID;
    QLineEdit *employerName;
    QPushButton *findEmployerButton;

};

#endif // FINDEMPLOYER_H
