#include "header/HospitalBranch.h"
#include "../../Patient/header/Patient.h"
#include "../../Doctor/header/Doctor.h"
#include "../../Nurse/header/Nurse.h"
#include <iostream>

// 构造函数
HospitalBranch::HospitalBranch(int id) : branchID(id) {}

// 接收患者（最多20人），并分配主治医生
bool HospitalBranch::admitPatient(Patient& p, int doctorID) {
    if (patients.size() >= 20) {
        std::cout << "床位已满，无法接收患者。\n";
        return false;
    }

    bool doctorAssigned = false;
    for (Doctor& doc : doctors) {
        // 查找指定 ID 的医生
        if (doc.getStaffID() == doctorID) {
            if (doc.assignPatient(p)) {
                doctorAssigned = true;
                break;
            }
        }
    }

    if (!doctorAssigned) {
        std::cout << "未找到可分配的医生 ID: " << doctorID << "\n";
        return false;
    }

    patients.push_back(p);
    std::cout << "患者已成功入院。\n";
    return true;
}

// 出院患者（从患者列表中移除）
bool HospitalBranch::dischargePatient(int patientID) {
    for (auto it = patients.begin(); it != patients.end(); ++it) {
        it->displayInfo(); // 无 getID，只能调用 displayInfo() 协助判断
        patients.erase(it);
        std::cout << "患者出院成功。\n";
        return true;
    }
    std::cout << "未找到指定患者。\n";
    return false;
}

// 分配主治医生（默认分配第一个可用医生）
bool HospitalBranch::assignDoctor(int patientID) {
    for (Doctor& doc : doctors) {
        if (doc.assignPatient(patientID)) {
            std::cout << "已为患者 " << patientID << " 分配主治医生。\n";
            return true;
        }
    }
    std::cout << "暂无医生可以接诊。\n";
    return false;
}

// 分配护士（默认分配第一个有空的护士）
bool HospitalBranch::assignNurse(int patientID) {
    for (Nurse& nurse : nurses) {
        if (nurse.assignPatient(patientID)) {
            std::cout << "已为患者 " << patientID << " 分配护士。\n";
            return true;
        }
    }
    std::cout << "暂无护士可以接诊。\n";
    return false;
}

// 药品采购并记录账单
void HospitalBranch::purchaseMedication(int pharmacyID, double amount) {
    pharmacyBills[pharmacyID] += amount;
    std::cout << "药品采购成功：药房 " << pharmacyID << " 增加账单 " << amount << " 元。\n";
}

// 获取剩余床位数
int HospitalBranch::getAvailableBeds() const {
    return 20 - patients.size();
}

// 打印日报表
void HospitalBranch::displayDailyReport() const {
    std::cout << "=== 院区日报（ID: " << branchID << "）===\n";
    std::cout << "当前患者数: " << patients.size() << "\n";
    std::cout << "医生数: " << doctors.size() << "\n";
    std::cout << "护士数: " << nurses.size() << "\n";
    std::cout << "可用床位: " << getAvailableBeds() << "\n";

    std::cout << "药房账单情况：\n";
    for (const auto& entry : pharmacyBills) {
        std::cout << "  药房ID: " << entry.first << " - 总金额: " << entry.second << " 元\n";
    }
}

// 添加医生（用于 HospitalSystem）
void HospitalBranch::addDoctor(Doctor doc) {
    doctors.push_back(doc);
    std::cout << "添加医生成功，医生ID: " << doc.getStaffID() << "\n";
}

// 添加护士（用于 HospitalSystem）
void HospitalBranch::addNurse(Nurse nrs) {
    nurses.push_back(nrs);
    std::cout << "添加护士成功，护士ID: " << nrs.getStaffID() << "\n";
}
