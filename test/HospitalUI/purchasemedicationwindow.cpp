#include "purchasemedicationwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

PurchaseMedicationWindow::PurchaseMedicationWindow(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Purchase Medication");
    resize(300, 160);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Pharmacy ID
    QHBoxLayout *pharmacyLayout = new QHBoxLayout();
    pharmacyLayout->addWidget(new QLabel("Pharmacy ID:"));
    pharmacyIdEdit = new QLineEdit();
    pharmacyLayout->addWidget(pharmacyIdEdit);
    mainLayout->addLayout(pharmacyLayout);

    // Amount
    QHBoxLayout *amountLayout = new QHBoxLayout();
    amountLayout->addWidget(new QLabel("Amount:"));
    amountEdit = new QLineEdit();
    amountLayout->addWidget(amountEdit);
    mainLayout->addLayout(amountLayout);

    // Purchase Button
    purchaseButton = new QPushButton("Purchase");
    mainLayout->addWidget(purchaseButton);

    connect(purchaseButton, &QPushButton::clicked, this, &PurchaseMedicationWindow::onPurchaseClicked);
}

void PurchaseMedicationWindow::onPurchaseClicked() {
    QString pharmacyId = pharmacyIdEdit->text();
    QString amountStr = amountEdit->text();

    if (pharmacyId.isEmpty() || amountStr.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter both Pharmacy ID and Amount.");
        return;
    }

    QMessageBox::information(this, "Success", "Medication purchase recorded.");
    close();
}
