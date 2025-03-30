#pragma once

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class TransferPatientWindow : public QDialog {
    Q_OBJECT

public:
    explicit TransferPatientWindow(QWidget *parent = nullptr);

private slots:
    void onTransferClicked();

private:
    QLineEdit *idEdit;
    QLineEdit *branchEdit;
    QPushButton *transferButton;
};
