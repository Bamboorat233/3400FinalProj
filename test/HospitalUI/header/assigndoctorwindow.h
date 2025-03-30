#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class AssignDoctorWindow : public QDialog {
    Q_OBJECT

public:
    explicit AssignDoctorWindow(QWidget *parent = nullptr);

private slots:
    void onAssignClicked();

private:
    QLineEdit *patientIdEdit;
    QLineEdit *doctorIdEdit;
    QPushButton *assignButton;
};
