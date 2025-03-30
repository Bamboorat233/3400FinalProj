#include "assigndoctorwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>

AssignDoctorWindow::AssignDoctorWindow(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Assign Doctor");
    resize(300, 160);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Patient ID
    QHBoxLayout *patientLayout = new QHBoxLayout();
    patientLayout->addWidget(new QLabel("Patient ID:"));
    patientIdEdit = new QLineEdit();
    patientLayout->addWidget(patientIdEdit);
    mainLayout->addLayout(patientLayout);

    // Doctor ID
    QHBoxLayout *doctorLayout = new QHBoxLayout();
    doctorLayout->addWidget(new QLabel("Doctor ID:"));
    doctorIdEdit = new QLineEdit();
    doctorLayout->addWidget(doctorIdEdit);
    mainLayout->addLayout(doctorLayout);

    // Assign Button
    assignButton = new QPushButton("Assign");
    mainLayout->addWidget(assignButton);

    connect(assignButton, &QPushButton::clicked, this, &AssignDoctorWindow::onAssignClicked);
}

void AssignDoctorWindow::onAssignClicked() {
    QString patientId = patientIdEdit->text();
    QString doctorId = doctorIdEdit->text();

    if (patientId.isEmpty() || doctorId.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter both Patient ID and Doctor ID.");
        return;
    }

    QMessageBox::information(this, "Success", "Doctor assigned successfully.");
    close();
}
