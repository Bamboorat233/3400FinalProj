#include "header/mainwindow.h"

MainWindow::MainWindow(HospitalSystem *hospitalSystem, QWidget *parent)
    : QMainWindow(parent), hospitalSystem(hospitalSystem) {
    setWindowTitle("Hospital Management System");
    resize(500, 500);

    central = new QWidget(this);
    setCentralWidget(central);

    mainLayout = new QVBoxLayout(central);

    // Title
    QLabel *title = new QLabel("🏥 Hospital Management UI", this);
    title->setAlignment(Qt::AlignCenter);
    QFont font = title->font();
    font.setPointSize(14);
    font.setBold(true);
    title->setFont(font);
    mainLayout->addWidget(title);

    // Doctor Management Section
    QLabel *doctorLabel = new QLabel("🩺 Doctor Management", this);
    mainLayout->addWidget(doctorLabel);

    QPushButton *addDoctorBtn = new QPushButton("Add Doctor", this);
    mainLayout->addWidget(addDoctorBtn);
    connect(addDoctorBtn, &QPushButton::clicked, this,
            &MainWindow::openAddDoctorWindow);

    // Patient Management Section
    QLabel *patientLabel = new QLabel("🧍 Patient Management", this);
    mainLayout->addWidget(patientLabel);

    QHBoxLayout *patientRow1 = new QHBoxLayout();
    QPushButton *registerBtn = new QPushButton("Register Patient", this);
    QPushButton *transferBtn = new QPushButton("Transfer Patient", this);
    patientRow1->addWidget(registerBtn);
    patientRow1->addWidget(transferBtn);
    mainLayout->addLayout(patientRow1);

    QHBoxLayout *patientRow2 = new QHBoxLayout();
    QPushButton *updateBtn = new QPushButton("Update Condition", this);
    QPushButton *assignBtn = new QPushButton("Assign Doctor", this);
    patientRow2->addWidget(updateBtn);
    patientRow2->addWidget(assignBtn);
    mainLayout->addLayout(patientRow2);

    connect(registerBtn, &QPushButton::clicked, this,
            &MainWindow::openRegisterPatientWindow);
    connect(transferBtn, &QPushButton::clicked, this,
            &MainWindow::openTransferPatientWindow);
    connect(updateBtn, &QPushButton::clicked, this,
            &MainWindow::openUpdateConditionWindow);
    connect(assignBtn, &QPushButton::clicked, this,
            &MainWindow::openAssignDoctorWindow);

    // Pharmacy & Reports Section
    QLabel *pharmacyLabel = new QLabel("💊 Pharmacy & Reports", this);
    mainLayout->addWidget(pharmacyLabel);

    QHBoxLayout *pharmacyRow = new QHBoxLayout();
    QPushButton *purchaseBtn = new QPushButton("Purchase Medication", this);
    QPushButton *dailyBtn = new QPushButton("Daily Report", this);
    pharmacyRow->addWidget(purchaseBtn);
    pharmacyRow->addWidget(dailyBtn);
    mainLayout->addLayout(pharmacyRow);

    QPushButton *financialBtn = new QPushButton("Financial Report", this);
    mainLayout->addWidget(financialBtn);

    connect(purchaseBtn, &QPushButton::clicked, this,
            &MainWindow::openPurchaseMedicationWindow);
    connect(dailyBtn, &QPushButton::clicked, this,
            &MainWindow::openDailyReportWindow);
    connect(financialBtn, &QPushButton::clicked, this,
            &MainWindow::openFinancialReportWindow);
}

MainWindow::~MainWindow() {}

void MainWindow::openAddDoctorWindow() {
    AddDoctorWindow *window = new AddDoctorWindow(this);
    window->exec();
}

void MainWindow::openRegisterPatientWindow() {
    RegisterPatientWindow *window = new RegisterPatientWindow(this);
    window->exec();
}

void MainWindow::openTransferPatientWindow() {
    TransferPatientWindow *window = new TransferPatientWindow(this);
    window->exec();
}

void MainWindow::openUpdateConditionWindow() {
    UpdateConditionWindow *window = new UpdateConditionWindow(this);
    window->exec();
}

void MainWindow::openAssignDoctorWindow() {
    AssignDoctorWindow *window = new AssignDoctorWindow(this);
    window->exec();
}

void MainWindow::openPurchaseMedicationWindow() {
    PurchaseMedicationWindow *window = new PurchaseMedicationWindow(this);
    window->exec();
}

void MainWindow::openDailyReportWindow() {
    DailyReportWindow *window = new DailyReportWindow(this);
    window->exec();
}

void MainWindow::openFinancialReportWindow() {
    FinancialReportWindow *window = new FinancialReportWindow(this);
    window->exec();
}
