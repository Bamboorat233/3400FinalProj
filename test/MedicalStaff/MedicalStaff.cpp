#include "header/MedicalStaff.h"

#include <utility>

// 默认构造
MedicalStaff::MedicalStaff() : staffID(0), name(""), assignedHospital(0) {}

// 带参数构造
MedicalStaff::MedicalStaff(int id, const std::string& name, int hospital)
    : staffID(id), name(name), assignedHospital(hospital) {}

// 拷贝构造函数
MedicalStaff::MedicalStaff(const MedicalStaff& other)
    : staffID(other.staffID),
      name(other.name),
      assignedHospital(other.assignedHospital) {}

// ✅ 移动构造函数
MedicalStaff::MedicalStaff(MedicalStaff&& other) noexcept
    : staffID(other.staffID),
      name(std::move(other.name)),
      assignedHospital(other.assignedHospital) {
    // 可选：清理源对象
    other.staffID = 0;
    other.assignedHospital = 0;
}

// 析构函数
MedicalStaff::~MedicalStaff() {}

// 拷贝赋值运算符
MedicalStaff& MedicalStaff::operator=(const MedicalStaff& other) {
    if (this != &other) {
        staffID = other.staffID;
        name = other.name;
        assignedHospital = other.assignedHospital;
    }
    return *this;
}

// ✅ 移动赋值运算符
MedicalStaff& MedicalStaff::operator=(MedicalStaff&& other) noexcept {
    if (this != &other) {
        staffID = other.staffID;
        name = std::move(other.name);
        assignedHospital = other.assignedHospital;

        // 可选：清理源对象
        other.staffID = 0;
        other.assignedHospital = 0;
    }
    return *this;
}

// Getter 和 Setter 实现
int MedicalStaff::getStaffID() const { return this->staffID; }

std::string MedicalStaff::getName() const { return this->name; }

int MedicalStaff::getAssignedHospital() const { return this->assignedHospital; }

void MedicalStaff::setStaffID(int id) { staffID = id; }

void MedicalStaff::setName(const std::string& name) { this->name = name; }

void MedicalStaff::setAssignedHospital(int hospital) {
    assignedHospital = hospital;
}
