#include "header/MedicalStaff.h"
#include <iostream>

void testMedicalStaff() {
    std::cout << "Testing MedicalStaff class..." << std::endl;

    // 测试默认构造函数
    MedicalStaff defaultStaff;
    std::cout << "Default Staff ID: " << defaultStaff.getStaffID() << ", Name: " << defaultStaff.getName() << ", Assigned Hospital: " << defaultStaff.getAssignedHospital() << std::endl;

    // 测试带参数构造函数
    MedicalStaff staff1(101, "Dr. Smith", 301);
    std::cout << "Staff1 ID: " << staff1.getStaffID() << ", Name: " << staff1.getName() << ", Assigned Hospital: " << staff1.getAssignedHospital() << std::endl;

    // 测试设置 ID
    staff1.setStaffID(202);
    std::cout << "Updated Staff1 ID: " << staff1.getStaffID() << std::endl;

    // 测试设置姓名
    staff1.setName("Dr. Johnson");
    std::cout << "Updated Staff1 Name: " << staff1.getName() << std::endl;

    // 测试设置分配医院
    staff1.setAssignedHospital(505);
    std::cout << "Updated Staff1 Assigned Hospital: " << staff1.getAssignedHospital() << std::endl;

    // 测试拷贝构造函数
    MedicalStaff staff2(staff1);
    std::cout << "Staff2 (copied from Staff1) ID: " << staff2.getStaffID() << ", Name: " << staff2.getName() << ", Assigned Hospital: " << staff2.getAssignedHospital() << std::endl;

    // 修改 staff2 的分配医院，确保不会影响 staff1
    staff2.setAssignedHospital(909);
    std::cout << "Staff2 Updated Assigned Hospital: " << staff2.getAssignedHospital() << std::endl;
    std::cout << "Staff1 Assigned Hospital should remain unchanged: " << staff1.getAssignedHospital() << std::endl;
}

int main() {
    testMedicalStaff();
    return 0;
}
