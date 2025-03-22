#include "header/Nurse.h"
#include "../../MedicalStaff/header/MedicalStaff.h"
#include <iostream>

// 构造函数
Nurse::Nurse(int id, std::string n, int h) : MedicalStaff(id, n, h) {}

// 分配患者
bool Nurse::assignPatient(int patientID) {
    if (assignedPatients.size() >= 2) {
        std::cout << "Nurse " << getName() << " already has 2 patients.\n";
        return false;
    }
    assignedPatients.push_back(patientID);
    std::cout << "Nurse " << getName() << " assigned to patient " << patientID << ".\n";
    return true;
}

// 解除患者
void Nurse::releasePatient(int patientID) {
    for (auto it = assignedPatients.begin(); it != assignedPatients.end(); ++it) {
        if (*it == patientID) {
            assignedPatients.erase(it);
            std::cout << "Patient " << patientID << " removed from Nurse " << getName() << ".\n";
            return;
        }
    }
    std::cout << "Patient " << patientID << " not found for Nurse " << getName() << ".\n";
}

// 获取当前负责的患者
std::vector<int> Nurse::getAssignedPatients() const {
    return assignedPatients;
}

// 析构函数
Nurse::~Nurse() {
    std::cout << "Nurse " << getName() << " (ID: " << getStaffID() << ") is removed.\n";
}
