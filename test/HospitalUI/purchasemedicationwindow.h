#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class PurchaseMedicationWindow : public QDialog {
    Q_OBJECT

public:
    explicit PurchaseMedicationWindow(QWidget *parent = nullptr);

private slots:
    void onPurchaseClicked();

private:
    QLineEdit *pharmacyIdEdit;
    QLineEdit *amountEdit;
    QPushButton *purchaseButton;
};
