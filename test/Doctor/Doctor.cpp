#include "Doctor.h"

// 构造函数
Doctor::Doctor(int id, std::string n, int h) : MedicalStaff(id, n, h) {}

Doctor::Doctor() : MedicalStaff() {}

Doctor::Doctor(const Doctor& doc) : MedicalStaff(doc), assignedPatients(doc.assignedPatients) {}

// 分配患者
bool Doctor::assignPatient(int patientID) {
    if (assignedPatients.size() < MAX_PATIENTS) {
        assignedPatients.push_back(patientID);
        return true;
    }
    return false; // 超过最大接诊量
}

// 解除患者关系
void Doctor::releasePatient(int patientID) {
    for (auto it = assignedPatients.begin(); it != assignedPatients.end(); ++it) {
        if (*it == patientID) {
            assignedPatients.erase(it);
            return;
        }
    }
}

// 获取当前分配的患者列表
std::vector<int> Doctor::getAssignedPatients() const {
    return assignedPatients;
}

// 析构函数
Doctor::~Doctor() {}