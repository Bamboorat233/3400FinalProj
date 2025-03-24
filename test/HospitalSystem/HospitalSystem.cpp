#include "header/HospitalSystem.h"
#include <iostream>

int HospitalSystem::nextPatientID = 1000;

HospitalSystem::HospitalSystem() {}

// 初始化：5个院区，20个药房
void HospitalSystem::initializeSystem() {
    for (int i = 1; i <= 5; ++i) {
        branches.emplace_back(i);
    }

    for (int i = 1; i <= 20; ++i) {
        pharmacies.emplace_back(i);
    }

    std::cout << "系统初始化完成：5个院区，20个药房。\n";
}

// 登记患者
int HospitalSystem::registerPatient(std::string info) {
    int id = nextPatientID++;
    Patient newPatient(id, info, 1); // 默认分配到1号院区
    allPatients[id] = newPatient;
    std::cout << "成功登记新患者，ID: " << id << "\n";
    return id;
}

// 跨院区转移
bool HospitalSystem::transferPatient(int patientID, int newBranch) {
    if (allPatients.find(patientID) == allPatients.end()) {
        std::cout << "无此患者。\n";
        return false;
    }
    if (newBranch < 1 || newBranch > 5) {
        std::cout << "无效院区编号。\n";
        return false;
    }
    allPatients[patientID].transferHospital(newBranch);
    std::cout << "患者 " << patientID << " 成功转移至院区 " << newBranch << "\n";
    return true;
}

// 添加医生
void HospitalSystem::addDoctor(int branchID, Doctor doc) {
    if (branchID < 1 || branchID > branches.size()) return;
    branches[branchID - 1].addDoctor(doc);
}

// 添加护士
void HospitalSystem::addNurse(int branchID, Nurse nrs) {
    if (branchID < 1 || branchID > branches.size()) return;
    branches[branchID - 1].addNurse(nrs);
}

// 注册药房
void HospitalSystem::addPharmacy(Pharmacy pharma) {
    pharmacies.push_back(pharma);
    std::cout << "已注册药房 ID: " << pharma.getPharmacyID() << "\n";
}

// 生成财务报告
void HospitalSystem::generateFinancialReport() const {
    std::cout << "=== 医院财务报告 ===\n";
    for (const Pharmacy& p : pharmacies) {
        std::cout << "药房ID: " << p.getPharmacyID()
                  << "，总金额: " << p.getTotalBill() << " 元\n";
    }
}
