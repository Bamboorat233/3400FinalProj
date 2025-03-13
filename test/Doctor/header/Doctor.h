#ifndef DOCTOR_H
#define DOCTOR_H

#include "MedicalStaff.h"
#include <vector>

class Doctor : public MedicalStaff {
    private:
        std::vector<int> assignedPatients; // 负责的患者ID列表
        static const int MAX_PATIENTS = 10; // 最大接诊量
    
    public:
        // 构造函数
        Doctor(int id, std::string n, int h);
        Doctor();
        Doctor(const Doctor& doc);

        // 分配患者
        bool assignPatient(int patientID);
        
        // 解除患者关系
        void releasePatient(int patientID);
        
        // 获取当前分配的患者列表
        std::vector<int> getAssignedPatients() const;

        // 析构函数
        ~Doctor();
};

#endif // DOCTOR_H
