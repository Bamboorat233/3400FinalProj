#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QDateEdit>
#include <QPushButton>

#include "../HospitalSystem/header/HospitalSystem.h"


class RegisterPatientWindow : public QDialog {
    Q_OBJECT

public:
    explicit RegisterPatientWindow(HospitalSystem *hospitalSystem,
                                QWidget *parent = nullptr);

private slots:
    void onRegisterClicked();

private:
    QLineEdit *nameEdit;
    QLineEdit *idEdit;
    QDateEdit *dobEdit;
    QComboBox *genderComboBox;
    QLineEdit *conditionEdit;
    QPushButton *registerButton;

    HospitalSystem *hospitalSystem;
};
