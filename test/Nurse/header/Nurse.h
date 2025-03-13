#ifndef NURSE_H
#define NURSE_H

#include "MedicalStaff.h"
#include <vector>

class Nurse : public MedicalStaff {
private:
    std::vector<int> assignedPatients; // 护士最多负责2个患者

public:
    // 构造函数
    Nurse(int id, std::string n, int h);

    // 分配患者
    bool assignPatient(int patientID);

    // 解除患者
    void releasePatient(int patientID);

    // 获取当前负责的患者
    std::vector<int> getAssignedPatients() const;

    // 析构函数
    ~Nurse();
};

#endif // NURSE_H
