#ifndef FINDEMPLOYEE_H
#define FINDEMPLOYEE_H

class QLineEdit;
class QPushButton;

class FindEmployee : public QDialog
{

public:
    FindEmployee(QDialog *parent = 0);

private:
    QLineEdit *employeeName;
    QPushButton *findEmployeeButton;

};

#endif // FINDEMPLOYEE_H
