#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

#include "../HospitalSystem/header/HospitalSystem.h"


class UpdateConditionWindow : public QDialog {
    Q_OBJECT

public:
    explicit UpdateConditionWindow(HospitalSystem *hospitalSystem,
                                QWidget *parent = nullptr);

private slots:
    void onUpdateClicked();

private:
    QLineEdit *idEdit;
    QLineEdit *conditionEdit;
    QPushButton *updateButton;

    HospitalSystem *hospitalSystem;
};
