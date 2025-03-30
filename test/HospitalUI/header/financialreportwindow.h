#pragma once

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>

class FinancialReportWindow : public QDialog {
    Q_OBJECT

public:
    explicit FinancialReportWindow(QWidget *parent = nullptr);

private slots:
    void onGenerateClicked();

private:
    QTextEdit *reportArea;
    QPushButton *generateButton;
};
