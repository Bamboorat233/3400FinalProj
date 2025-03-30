#pragma once

#include <QComboBox>
#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

#include "../HospitalSystem/header/HospitalSystem.h"


class AddDoctorWindow : public QDialog {
    Q_OBJECT

   public:
    explicit AddDoctorWindow(HospitalSystem *hospitalSystem,
                             QWidget *parent = nullptr);

   private slots:
    void onAddClicked();

   private:
    QLineEdit *nameEdit;
    QLineEdit *idEdit;
    QComboBox *branchComboBox;
    QPushButton *addButton;

    HospitalSystem *hospitalSystem;  // 指向 HospitalSystem 的指针
};
