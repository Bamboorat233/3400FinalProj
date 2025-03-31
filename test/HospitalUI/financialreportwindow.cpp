#include <QLabel>
#include <QVBoxLayout>

#include "header/financialreportwindow.h"

FinancialReportWindow::FinancialReportWindow(QWidget *parent,
                                             HospitalSystem *hospitalSystem)
    : QDialog(parent), hospitalSystem(hospitalSystem) {
    setWindowTitle("Financial Report");
    resize(400, 300);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *titleLabel = new QLabel("Pharmacy Financial Summary:");
    mainLayout->addWidget(titleLabel);

    reportArea = new QTextEdit();
    reportArea->setReadOnly(true);
    mainLayout->addWidget(reportArea);

    generateButton = new QPushButton("Generate Report");
    mainLayout->addWidget(generateButton);

    connect(generateButton, &QPushButton::clicked, this,
            &FinancialReportWindow::onGenerateClicked);
}

void FinancialReportWindow::onGenerateClicked() {}
