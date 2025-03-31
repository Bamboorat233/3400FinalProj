#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>

#include "header/registerpatientwindow.h"

RegisterPatientWindow::RegisterPatientWindow(QWidget *parent,
                                             HospitalSystem *hospitalSystem)
    : QDialog(parent), hospitalSystem(hospitalSystem) {
    setWindowTitle("Register Patient");
    resize(350, 250);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Patient Name
    QHBoxLayout *nameLayout = new QHBoxLayout();
    nameLayout->addWidget(new QLabel("Name:"));
    nameEdit = new QLineEdit();
    nameLayout->addWidget(nameEdit);
    mainLayout->addLayout(nameLayout);

    // Patient ID
    QHBoxLayout *idLayout = new QHBoxLayout();
    idLayout->addWidget(new QLabel("Patient ID:"));
    idEdit = new QLineEdit();
    idLayout->addWidget(idEdit);
    mainLayout->addLayout(idLayout);

    // Date of Birth
    QHBoxLayout *dobLayout = new QHBoxLayout();
    dobLayout->addWidget(new QLabel("Date of Birth:"));
    dobEdit = new QDateEdit();
    dobEdit->setCalendarPopup(true);
    dobLayout->addWidget(dobEdit);
    mainLayout->addLayout(dobLayout);

    // Gender
    QHBoxLayout *genderLayout = new QHBoxLayout();
    genderLayout->addWidget(new QLabel("Gender:"));
    genderComboBox = new QComboBox();
    genderComboBox->addItems({"Male", "Female", "Other"});
    genderLayout->addWidget(genderComboBox);
    mainLayout->addLayout(genderLayout);

    // Initial Condition
    QHBoxLayout *conditionLayout = new QHBoxLayout();
    conditionLayout->addWidget(new QLabel("Initial Condition:"));
    conditionEdit = new QLineEdit();
    conditionLayout->addWidget(conditionEdit);
    mainLayout->addLayout(conditionLayout);

    // Register Button
    registerButton = new QPushButton("Register");
    mainLayout->addWidget(registerButton);

    connect(registerButton, &QPushButton::clicked, this,
            &RegisterPatientWindow::onRegisterClicked);
}

void RegisterPatientWindow::onRegisterClicked() {
    QString info = nameEdit->text();
    QString id = idEdit->text();
    QString condition = conditionEdit->text();

    if (name.isEmpty() || id.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter both name and ID.");
        return;
    }
    int PID = hospitalSystem->registerPatient();
    QMessageBox::information(this, "Success",
                             "Patient registered successfully.");
    close();
}
