#include "Nurse.h"
#include "../../MedicalStaff/header/MedicalStaff.h"
#include <iostream>

void testNurse() {
    std::cout << "Testing Nurse class...\n";

    // 创建护士对象
    Nurse nurse1(101, "Alice", 301);

    // 测试基础信息
    std::cout << "Nurse ID: " << nurse1.getStaffID() << ", Name: " << nurse1.getName()
              << ", Assigned Hospital: " << nurse1.getAssignedHospital() << std::endl;

    // 测试患者分配
    nurse1.assignPatient(1001);
    nurse1.assignPatient(1002);

    // 试图分配第3个患者 (应该失败)
    nurse1.assignPatient(1003);

    // 测试患者解除
    nurse1.releasePatient(1001);
    
    // 再次分配患者 (应该成功)
    nurse1.assignPatient(1003);

    // 获取当前负责的患者
    std::vector<int> patients = nurse1.getAssignedPatients();
    std::cout << "Nurse " << nurse1.getName() << " is responsible for patients: ";
    for (int id : patients) {
        std::cout << id << " ";
    }
    std::cout << std::endl;
}

int main() {
    testNurse();
    return 0;
}
