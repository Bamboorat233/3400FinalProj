#ifndef HOSPITAL_BRANCH_H
#define HOSPITAL_BRANCH_H

#include <vector>
#include <unordered_map>
#include "../../Patient/header/Patient.h"
#include "../../Doctor/header/Doctor.h"
#include "../../Nurse/header/Nurse.h"

class HospitalBranch {
private:
    int branchID;  // 院区ID
    std::vector<Patient> patients;  // 最多20个患者
    std::vector<Doctor> doctors;    // 至少3名医生
    std::vector<Nurse> nurses;      // 至少5名护士
    std::unordered_map<int, double> pharmacyBills; // 药房账单记录

public:
    // 构造函数
    HospitalBranch(int id);

    // 患者管理功能
    bool admitPatient(Patient& p, int doctorID);
    bool dischargePatient(int patientID);
    bool assignDoctor(int patientID);
    bool assignNurse(int patientID);

    // 药品采购
    void purchaseMedication(int pharmacyID, double amount);

    // 床位情况
    int getAvailableBeds() const;

    // 日报
    void displayDailyReport() const;
};

#endif // HOSPITAL_BRANCH_H
