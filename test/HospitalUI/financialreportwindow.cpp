#include "header/financialreportwindow.h"
#include <QVBoxLayout>
#include <QLabel>

FinancialReportWindow::FinancialReportWindow(QWidget *parent)
    : QDialog(parent)
{
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

    connect(generateButton, &QPushButton::clicked, this, &FinancialReportWindow::onGenerateClicked);
}

void FinancialReportWindow::onGenerateClicked() {
    QString report;
    report += "Pharmacy 1 - ¥1200.50\n";
    report += "Pharmacy 2 - ¥875.00\n";
    report += "Pharmacy 3 - ¥342.75\n";
    report += "Pharmacy 4 - ¥998.90\n";

    reportArea->setPlainText(report);
}
