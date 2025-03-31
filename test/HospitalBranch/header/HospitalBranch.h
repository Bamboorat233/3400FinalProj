#ifndef HOSPITAL_BRANCH_H
#define HOSPITAL_BRANCH_H

#include <unordered_map>
#include <vector>

#include "../../Doctor/header/Doctor.h"
#include "../../MedicalStaff/header/MedicalStaff.h"
#include "../../Nurse/header/Nurse.h"
#include "../../Patient/header/Patient.h"

class HospitalBranch {
   private:
    int branchID;                   // 院区唯一标识
    std::vector<Patient> patients;  // 当前院区的患者列表（最多20个）
    std::vector<Doctor> doctors;    // 当前院区的医生列表（至少3名）
    std::vector<Nurse> nurses;      // 当前院区的护士列表（至少5名）
    std::unordered_map<int, double> pharmacyBills;  // 药房账单记录

   public:
    // 构造函数
    HospitalBranch(int id);
    Doctor& getDoctor(int index);  // 获取医生

    // 患者相关操作
    bool admitPatient(Patient& p, int doctorID);  // 接收患者
    int dischargePatient(int patientID);          // 出院结算费用
    bool assignDoctor(int patientID);             // 分配主治医生
    bool assignNurse(int patientID);              // 分配护士
    bool nurseRelease(int patientID);             // 解除护士责任

    // 药品相关
    void purchaseMedication(int pharmacyID, double amount);  // 药品采购

    // 院区状态
    int getAvailableBeds() const;     // 获取剩余床位
    void displayDailyReport() const;  // 生成日报表

    // ✅ 为系统初始化添加医护人员（辅助函数）
    void addDoctor(Doctor doc);
    void addNurse(Nurse nrs);
};

#endif  // HOSPITAL_BRANCH_H
