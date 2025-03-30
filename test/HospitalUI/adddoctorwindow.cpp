#include <QHBoxLayout>
#include <QLabel>
#include <QMessageBox>
#include <QVBoxLayout>

#include "header/Doctor.h"  // 引入 Doctor 类
#include "header/adddoctorwindow.h"


AddDoctorWindow::AddDoctorWindow(HospitalSystem *hospitalSystem,
                                 QWidget *parent)
    : QDialog(parent), hospitalSystem(hospitalSystem) {
    setWindowTitle("Add Doctor");
    resize(300, 200);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // Doctor Name
    QHBoxLayout *nameLayout = new QHBoxLayout();
    nameLayout->addWidget(new QLabel("Doctor Name:"));
    nameEdit = new QLineEdit();
    nameLayout->addWidget(nameEdit);
    mainLayout->addLayout(nameLayout);

    // Doctor ID
    QHBoxLayout *idLayout = new QHBoxLayout();
    idLayout->addWidget(new QLabel("Doctor ID:"));
    idEdit = new QLineEdit();
    idLayout->addWidget(idEdit);
    mainLayout->addLayout(idLayout);

    // Hospital Branch
    QHBoxLayout *branchLayout = new QHBoxLayout();
    branchLayout->addWidget(new QLabel("Hospital Branch:"));
    branchComboBox = new QComboBox();
    for (int i = 1; i <= 5; ++i) branchComboBox->addItem(QString::number(i));
    branchLayout->addWidget(branchComboBox);
    mainLayout->addLayout(branchLayout);

    // Add Button
    addButton = new QPushButton("Add Doctor");
    mainLayout->addWidget(addButton);

    connect(addButton, &QPushButton::clicked, this,
            &AddDoctorWindow::onAddClicked);
}

void AddDoctorWindow::onAddClicked() {
    QString name = nameEdit->text();
    QString idStr = idEdit->text();
    int branchID = branchComboBox->currentText().toInt();

    if (name.isEmpty() || idStr.isEmpty()) {
        QMessageBox::warning(this, "Warning", "Please enter both name and ID.");
        return;
    }

    int doctorID = idStr.toInt();

    // 创建 Doctor 对象并添加到系统中
    Doctor newDoctor(name.toStdString(), doctorID);
    hospitalSystem->addDoctor(branchID, std::move(newDoctor));

    QMessageBox::information(this, "Success", "Doctor added successfully.");
    close();
}
