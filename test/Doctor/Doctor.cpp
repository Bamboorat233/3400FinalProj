#include "header/Doctor.h"
#include <iostream>
#include <vector>

class Doctor {
private:
    std::vector<int> assignedPatients; // 负责的患者 ID 列表
    static const int MAX_PATIENTS = 10; // 假设医生最多接诊 10 名患者

public:
    // 分配患者
    bool assignPatient(int patientID) {
        if (assignedPatients.size() >= MAX_PATIENTS) {
            return false; // 超过最大接诊量，分配失败
        }
        assignedPatients.push_back(patientID);
        return true;
    }

    // 释放患者
    void releasePatient(int patientID) {
        for (auto it = assignedPatients.begin(); it != assignedPatients.end(); ++it) {
            if (*it == patientID) {
                assignedPatients.erase(it);
                return;
            }
        }
    }

    // 显示当前负责的患者
    void showPatients() const {
        std::cout << "Assigned Patients: ";
        for (int id : assignedPatients) {
            std::cout << id << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    Doctor doctor;
    
    // 分配患者
    for (int i = 101; i <= 111; ++i) {
        std::cout << (doctor.assignPatient(i) ? "Assigned " + std::to_string(i) : "Assignment failed for " + std::to_string(i)) << std::endl;
    }

    doctor.showPatients();
    
    // 释放患者
    doctor.releasePatient(105);
    doctor.showPatients();
    
    return 0;
}
