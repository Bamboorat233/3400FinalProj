#ifndef NURSE_H
#define NURSE_H

#include <utility>
#include <vector>

#include "../../MedicalStaff/header/MedicalStaff.h"

class Nurse : public MedicalStaff {
   private:
    std::vector<int> assignedPatients;  // 护士最多负责2个患者

   public:
    // 构造函数
    Nurse();
    Nurse(int id, std::string n, int h);
    Nurse(const Nurse& other);                 // 拷贝构造函数
    Nurse(Nurse&& other) noexcept;             // ✅ 移动构造函数
    Nurse& operator=(Nurse&& other) noexcept;  // ✅ 移动赋值运算符

    // 分配患者
    bool assignPatient(int patientID);

    // 解除患者
    bool releasePatient(int patientID);

    // 获取当前负责的患者
    std::vector<int> getAssignedPatients() const;

    // 析构函数
    ~Nurse();
};

#endif  // NURSE_H
