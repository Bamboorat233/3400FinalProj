#include "updateconditionwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

UpdateConditionWindow::UpdateConditionWindow(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Update Condition");
    resize(300, 160);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Patient ID
    QHBoxLayout *idLayout = new QHBoxLayout();
    idLayout->addWidget(new QLabel("Patient ID:"));
    idEdit = new QLineEdit();
    idLayout->addWidget(idEdit);
    mainLayout->addLayout(idLayout);

    // New Condition
    QHBoxLayout *conditionLayout = new QHBoxLayout();
    conditionLayout->addWidget(new QLabel("New Condition:"));
    conditionEdit = new QLineEdit();
    conditionLayout->addWidget(conditionEdit);
    mainLayout->addLayout(conditionLayout);

    // Update Button
    updateButton = new QPushButton("Update");
    mainLayout->addWidget(updateButton);

    connect(updateButton, &QPushButton::clicked, this, &UpdateConditionWindow::onUpdateClicked);
}

void UpdateConditionWindow::onUpdateClicked() {
    QString idStr = idEdit->text();
    QString conditionStr = conditionEdit->text();

    if (idStr.isEmpty() || conditionStr.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter both Patient ID and Condition.");
        return;
    }

    QMessageBox::information(this, "Success", "Condition updated successfully.");
    close();
}
