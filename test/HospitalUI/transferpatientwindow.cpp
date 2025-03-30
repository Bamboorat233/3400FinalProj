#include "transferpatientwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

TransferPatientWindow::TransferPatientWindow(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Transfer Patient");
    resize(300, 150);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Patient ID
    QHBoxLayout *idLayout = new QHBoxLayout();
    idLayout->addWidget(new QLabel("Patient ID:"));
    idEdit = new QLineEdit();
    idLayout->addWidget(idEdit);
    mainLayout->addLayout(idLayout);

    // Target Branch
    QHBoxLayout *branchLayout = new QHBoxLayout();
    branchLayout->addWidget(new QLabel("Target Branch:"));
    branchEdit = new QLineEdit();
    branchLayout->addWidget(branchEdit);
    mainLayout->addLayout(branchLayout);

    // Transfer Button
    transferButton = new QPushButton("Transfer");
    mainLayout->addWidget(transferButton);

    connect(transferButton, &QPushButton::clicked, this, &TransferPatientWindow::onTransferClicked);
}

void TransferPatientWindow::onTransferClicked() {
    QString idStr = idEdit->text();
    QString branchStr = branchEdit->text();

    if (idStr.isEmpty() || branchStr.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter both Patient ID and Target Branch.");
        return;
    }

    // 模拟转院成功
    QMessageBox::information(this, "Success", "Patient transferred successfully.");
    close();
}
