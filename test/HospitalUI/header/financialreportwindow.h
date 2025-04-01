#pragma once

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>

#include "../HospitalSystem/header/HospitalSystem.h"


class FinancialReportWindow : public QDialog {
    Q_OBJECT

public:
    explicit FinancialReportWindow(HospitalSystem *hospitalSystem,
                                QWidget *parent = nullptr);

private slots:
    void onGenerateClicked();

private:
    QTextEdit *reportArea;
    QPushButton *generateButton;

    HospitalSystem *hospitalSystem;
};
