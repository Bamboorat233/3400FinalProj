#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

#include "../HospitalSystem/header/HospitalSystem.h"

class TransferPatientWindow : public QDialog {
    Q_OBJECT

public:
    explicit TransferPatientWindow(HospitalSystem *hospitalSystem,
                                    QWidget *parent = nullptr);

private slots:
    void onTransferClicked();

private:
    QLineEdit *idEdit;
    QLineEdit *branchEdit;
    QPushButton *transferButton;

    HospitalSystem *hospitalSystem;
};
