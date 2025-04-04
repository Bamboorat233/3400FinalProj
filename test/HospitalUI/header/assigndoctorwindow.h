#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

#include "../HospitalBranch/header/HospitalBranch.h"
#include "../HospitalSystem/header/HospitalSystem.h"


class AssignDoctorWindow : public QDialog {
    Q_OBJECT

   public:
    explicit AssignDoctorWindow(HospitalSystem *hospitalSystem,
                                QWidget *parent = nullptr);

   private slots:
    void onAssignClicked();

   private:
    QLineEdit *patientIdEdit;
    QLineEdit *doctorIdEdit;
    QPushButton *assignButton;

    HospitalSystem *hospitalSystem;  // 用于操作 HospitalSystem 的指针
};
