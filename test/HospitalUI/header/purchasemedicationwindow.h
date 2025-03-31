#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

#include "../HospitalSystem/header/HospitalSystem.h"


class PurchaseMedicationWindow : public QDialog {
    Q_OBJECT

public:
    explicit PurchaseMedicationWindow(HospitalSystem *hospitalSystem,
                                QWidget *parent = nullptr);

private slots:
    void onPurchaseClicked();

private:
    QLineEdit *pharmacyIdEdit;
    QLineEdit *amountEdit;
    QPushButton *purchaseButton;

    HospitalSystem *hospitalSystem;
};
