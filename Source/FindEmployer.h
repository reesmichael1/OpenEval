#ifndef FINDEMPLOYER_H
#define FINDEMPLOYER_H

class QLineEdit;
class QPushButton;

class FindEmployer : public QDialog
{

public:
    FindEmployer(QDialog *parent = 0);

private:
    QLineEdit *employerName;
    QPushButton *findEmployerButton;

};

#endif // FINDEMPLOYER_H
