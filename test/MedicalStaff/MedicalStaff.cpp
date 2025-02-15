#include "header/MedicalStaff.h"
#include <iostream>

// 带参数的构造函数实现
MedicalStaff::MedicalStaff(int id, std::string n, int h) : staffID(id), name(n), assignedHospital(h) {}

// 默认构造函数实现
MedicalStaff::MedicalStaff() : staffID(0), name(""), assignedHospital(0) {}

// 拷贝构造函数实现
MedicalStaff::MedicalStaff(const MedicalStaff& staff) : staffID(staff.staffID), name(staff.name), assignedHospital(staff.assignedHospital) {}

// 设置分配医院
void MedicalStaff::setAssignedHospital(int h) {
    assignedHospital = h;
}

// 获取分配医院
int MedicalStaff::getAssignedHospital() const {
    return assignedHospital;
}

// 设置员工ID
void MedicalStaff::setStaffID(int id) {
    staffID = id;
}

// 获取员工ID
int MedicalStaff::getStaffID() const {
    return staffID;
}

// 获取姓名
std::string MedicalStaff::getName() const {
    return name;
}

// 设置姓名
void MedicalStaff::setName(std::string n) {
    name = n;
}

// 析构函数
MedicalStaff::~MedicalStaff() {
    std::cout << "MedicalStaff " << staffID << " is destroyed." << std::endl;
}
