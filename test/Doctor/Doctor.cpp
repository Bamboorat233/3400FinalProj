#include "header/Doctor.h"
#include "../../MedicalStaff/header/MedicalStaff.h"

#include <algorithm>
#include <iostream>

// 默认构造
Doctor::Doctor() : MedicalStaff() {}

// 带参构造
Doctor::Doctor(int id, std::string n, int h) : MedicalStaff(id, n, h) {}

// 拷贝构造
Doctor::Doctor(const Doctor& doc)
    : MedicalStaff(doc), assignedPatients(doc.assignedPatients) {}

// ✅ 移动构造函数
Doctor::Doctor(Doctor&& other) noexcept
    : MedicalStaff(std::move(other)),
      assignedPatients(std::move(other.assignedPatients)) {
    // 其他成员（无指针资源）无需特别清空，std::move会将其置于有效但未指定状态
}

// ✅ 移动赋值运算符
Doctor& Doctor::operator=(Doctor&& other) noexcept {
    if (this != &other) {
        MedicalStaff::operator=(std::move(other));
        assignedPatients = std::move(other.assignedPatients);
    }
    return *this;
}

// 析构函数
Doctor::~Doctor() {
    //std::cout << "Doctor " << this->getName() << " destructed" << std::endl;
}

// 分配患者
bool Doctor::assignPatient(int patientID) {
    if (assignedPatients.size() >= MAX_PATIENTS) return false;

    if (std::find(assignedPatients.begin(), assignedPatients.end(),
                  patientID) == assignedPatients.end()) {
        assignedPatients.push_back(patientID);
        return true;
    }
    return false;
}

// 解除患者关系
void Doctor::releasePatient(int patientID) {
    assignedPatients.erase(std::remove(assignedPatients.begin(),
                                       assignedPatients.end(), patientID),
                           assignedPatients.end());
}

// 获取当前分配的患者列表
std::vector<int> Doctor::getAssignedPatients() const {
    return assignedPatients;
}
