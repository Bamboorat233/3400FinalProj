#ifndef DOCTOR_H
#define DOCTOR_H

#include <vector>
#include <iostream>

class Doctor {
private:
    std::vector<int> assignedPatients; // 负责的患者 ID 列表
    static const int MAX_PATIENTS = 10; // 假设医生最多接诊 10 名患者

public:
    // 分配患者
    bool assignPatient(int patientID);

    // 释放患者
    void releasePatient(int patientID);

    // 显示当前负责的患者
    void showPatients() const;
};

#endif // DOCTOR_H
