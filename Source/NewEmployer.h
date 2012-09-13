#ifndef NEWEMPLOYER_H
#define NEWEMPLOYER_H

#include <QDialog>
#include <QFile>

class QLineEdit;
class QTextStream;

class NewEmployer : public QDialog
{
    Q_OBJECT

public:
    NewEmployer(QWidget *parent = 0);
    void clearFields();

public slots:
    void cancel();
    void submit();

private:
    int employerID;
    QString name;
    QString address;
    QString city;
    QString state;
    QString zipCode;
    QString phone;
    QString eMail;
    QString contact;
    QLineEdit *employerName;
    QLineEdit *employerAddress;
    QLineEdit *employerCity;
    QLineEdit *employerState;
    QLineEdit *employerZipCode;
    QLineEdit *employerPhone;
    QLineEdit *employerEMail;
    QLineEdit *employerContact;
    QPushButton *submitButton;
    QPushButton *cancelButton;
    QFile *employerDataFile;
    QFile *employerIDDataFile;
    QTextStream *employerData;
    QTextStream *employerIDData;
    void assignEmployerID();
    void writeEmployerData();
};

#endif // NEWEMPLOYER_H
