#pragma once

#include <QHBoxLayout>
#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

#include "adddoctorwindow.h"
#include "assigndoctorwindow.h"
#include "dailyreportwindow.h"
#include "financialreportwindow.h"
#include "purchasemedicationwindow.h"
#include "registerpatientwindow.h"
#include "transferpatientwindow.h"
#include "updateconditionwindow.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(HospitalSystem *hospitalSystem, QWidget *parent = nullptr);
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
    HospitalSystem *hospitalSystem;
};
