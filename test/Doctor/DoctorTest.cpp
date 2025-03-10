#include "Doctor.h"
#include <iostream>

// Doctor 类成员函数实现
bool Doctor::assignPatient(int patientID) {
    if (assignedPatients.size() >= MAX_PATIENTS) {
        return false; // 超过最大接诊量，分配失败
    }
    assignedPatients.push_back(patientID);
    return true;
}

void Doctor::releasePatient(int patientID) {
    for (auto it = assignedPatients.begin(); it != assignedPatients.end(); ++it) {
        if (*it == patientID) {
            assignedPatients.erase(it);
            return;
        }
    }
}

void Doctor::showPatients() const {
    std::cout << "Assigned Patients: ";
    for (int id : assignedPatients) {
        std::cout << id << " ";
    }
    std::cout << std::endl;
}

// 测试类
int main() {
    Doctor doctor;
    
    // 分配患者测试
    for (int i = 101; i <= 111; ++i) {
        std::cout << (doctor.assignPatient(i) ? "Assigned " + std::to_string(i) : "Assignment failed for " + std::to_string(i)) << std::endl;
    }

    doctor.showPatients();
    
    // 释放患者测试
    doctor.releasePatient(105);
    std::cout << "After releasing patient 105:" << std::endl;
    doctor.showPatients();
    
    return 0;
}
