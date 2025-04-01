#include "header/Nurse.h"
#include "../../MedicalStaff/header/MedicalStaff.h"

#include <algorithm>
#include <iostream>

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
    //std::cout << "Nurse " << this->getName() << " is destroyed." << std::endl;
}

// 分配患者
bool Nurse::assignPatient(int patientID) {
    if (assignedPatients.size() >= 2) return false;

    if (std::find(assignedPatients.begin(), assignedPatients.end(),
                  patientID) == assignedPatients.end()) {
        assignedPatients.push_back(patientID);
        return true;
    }
    return false;
}

// 解除患者
void Nurse::releasePatient(int patientID) {
    assignedPatients.erase(std::remove(assignedPatients.begin(),
                                       assignedPatients.end(), patientID),
                           assignedPatients.end());
}

// 获取当前负责的患者
std::vector<int> Nurse::getAssignedPatients() const { return assignedPatients; }
