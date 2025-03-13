#include "Doctor.h"
#include "../../MedicalStaff/header/MedicalStaff.h"
#include <iostream>

int main() {
    // 创建医生对象
    Doctor doc(1, "Dr. Smith", 101);
    
    // 测试 assignPatient 方法
    std::cout << "Assigning patients:" << std::endl;
    for (int i = 1; i <= 12; ++i) {
        if (doc.assignPatient(i)) {
            std::cout << "Patient " << i << " assigned successfully." << std::endl;
        } else {
            std::cout << "Patient " << i << " could not be assigned (limit reached)." << std::endl;
        }
    }
    
    // 显示当前分配的患者
    std::vector<int> patients = doc.getAssignedPatients();
    std::cout << "\nCurrent assigned patients:";
    for (int id : patients) {
        std::cout << " " << id;
    }
    std::cout << std::endl;
    
    // 测试 releasePatient 方法
    std::cout << "\nReleasing patient 5..." << std::endl;
    doc.releasePatient(5);
    
    // 显示更新后的患者列表
    patients = doc.getAssignedPatients();
    std::cout << "Updated assigned patients:";
    for (int id : patients) {
        std::cout << " " << id;
    }
    std::cout << std::endl;
    
    return 0;
}
