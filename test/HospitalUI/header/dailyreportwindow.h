#pragma once

#include <QDialog>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>

#include "../HospitalSystem/header/HospitalSystem.h"


class DailyReportWindow : public QDialog {
    Q_OBJECT

public:
    explicit DailyReportWindow(HospitalSystem *hospitalSystem,
                                QWidget *parent = nullptr);

private slots:
    void onGenerateClicked();

private:
    QComboBox *branchComboBox;
    QTextEdit *reportArea;
    QPushButton *generateButton;

    HospitalSystem *hospitalSystem;
};
