#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class UpdateConditionWindow : public QDialog {
    Q_OBJECT

public:
    explicit UpdateConditionWindow(QWidget *parent = nullptr);

private slots:
    void onUpdateClicked();

private:
    QLineEdit *idEdit;
    QLineEdit *conditionEdit;
    QPushButton *updateButton;
};
