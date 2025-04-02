#include <algorithm>
#include <iostream>

#include "../../MedicalStaff/header/MedicalStaff.h"
#include "header/Nurse.h"

// 默认构造
Nurse::Nurse() : MedicalStaff() {}

// 带参数构造
Nurse::Nurse(int id, std::string n, int h) : MedicalStaff(id, n, h) {}

// 拷贝构造
Nurse::Nurse(const Nurse& other)
    : MedicalStaff(other), assignedPatients(other.assignedPatients) {}

// ✅ 移动构造函数
Nurse::Nurse(Nurse&& other) noexcept
    : MedicalStaff(std::move(other)),
      assignedPatients(std::move(other.assignedPatients)) {}

// ✅ 移动赋值运算符
Nurse& Nurse::operator=(Nurse&& other) noexcept {
    if (this != &other) {
        MedicalStaff::operator=(std::move(other));
        assignedPatients = std::move(other.assignedPatients);
    }
    return *this;
}

// 析构函数
Nurse::~Nurse() {
    // std::cout << "Nurse " << this->getName() << " is destroyed." <<
    // std::endl;
}

// 分配患者
bool Nurse::assignPatient(int patientID) {
    if (assignedPatients.size() >= 2) {
        std::cout << "[WARNING] Nurse cannot handle more than 2 patients.\n";
        return false;
    }

    if (std::find(assignedPatients.begin(), assignedPatients.end(),
                  patientID) == assignedPatients.end()) {
        assignedPatients.push_back(patientID);
        std::cout << "Patient " << patientID << " assigned successfully.\n";
        return true;
    } else {
        std::cout << "[WARNING] Patient " << patientID
                  << " is already assigned to this nurse.\n";
        return false;
    }
}

// 解除患者
// Nurse.cpp
bool Nurse::releasePatient(int patientID) {
    for (auto it = assignedPatients.begin(); it != assignedPatients.end();
         ++it) {
        if (*it == patientID) {
            assignedPatients.erase(it);
            std::cout << "Patient " << patientID << " released from nurse.\n";
            return true;  // 返回true表示成功释放
        }
    }
    return false;  // 返回false表示没有找到匹配的患者
}

// 获取当前负责的患者
std::vector<int> Nurse::getAssignedPatients() const { return assignedPatients; }
