#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>

class AddDoctorWindow : public QDialog {
    Q_OBJECT

public:
    explicit AddDoctorWindow(QWidget *parent = nullptr);

private slots:
    void onAddClicked();

private:
    QLineEdit *nameEdit;
    QLineEdit *idEdit;
    QComboBox *branchComboBox;
    QPushButton *addButton;
};
