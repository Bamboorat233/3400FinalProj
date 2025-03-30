#pragma once

#include <QDialog>
#include <QComboBox>
#include <QTextEdit>
#include <QPushButton>

class DailyReportWindow : public QDialog {
    Q_OBJECT

public:
    explicit DailyReportWindow(QWidget *parent = nullptr);

private slots:
    void onGenerateClicked();

private:
    QComboBox *branchComboBox;
    QTextEdit *reportArea;
    QPushButton *generateButton;
};
