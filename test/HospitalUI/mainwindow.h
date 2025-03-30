#pragma once

#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include "adddoctorwindow.h"
#include "registerpatientwindow.h"
#include "transferpatientwindow.h"
#include "updateconditionwindow.h"
#include "assigndoctorwindow.h"
#include "purchasemedicationwindow.h"
#include "dailyreportwindow.h"
#include "financialreportwindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void openAddDoctorWindow();
    void openRegisterPatientWindow();
    void openTransferPatientWindow();
    void openUpdateConditionWindow();
    void openAssignDoctorWindow();
    void openPurchaseMedicationWindow();
    void openDailyReportWindow();
    void openFinancialReportWindow();

private:
    QWidget *central;
    QVBoxLayout *mainLayout;
};
