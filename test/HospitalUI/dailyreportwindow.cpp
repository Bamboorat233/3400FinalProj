#include "header/dailyreportwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>

DailyReportWindow::DailyReportWindow(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("Daily Report");
    resize(400, 300);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    // 分院选择
    QHBoxLayout *branchLayout = new QHBoxLayout();
    branchLayout->addWidget(new QLabel("Select Branch:"));
    branchComboBox = new QComboBox();
    for (int i = 1; i <= 5; ++i)
        branchComboBox->addItem(QString("Branch %1").arg(i));
    branchLayout->addWidget(branchComboBox);
    mainLayout->addLayout(branchLayout);

    // 报告区域
    reportArea = new QTextEdit();
    reportArea->setReadOnly(true);
    mainLayout->addWidget(reportArea);

    // 按钮
    generateButton = new QPushButton("Generate Report");
    mainLayout->addWidget(generateButton);

    connect(generateButton, &QPushButton::clicked, this, &DailyReportWindow::onGenerateClicked);
}

void DailyReportWindow::onGenerateClicked() {
    int branch = branchComboBox->currentIndex() + 1;

    // 模拟日报表内容（真实数据将在数据库版本加入）
    QString report;
    report += QString("=== Daily Report: Branch %1 ===\n").arg(branch);
    report += "Patients: 12\nDoctors: 5\nNurses: 6\nAvailable Beds: 8\n";
    report += "Pharmacy Bills: \n  Pharmacy 1: 1200.50 yuan\n  Pharmacy 2: 875.00 yuan";

    reportArea->setPlainText(report);
}
