#ifndef MEDICALSTAFF_H
#define MEDICALSTAFF_H

#include <string>

class MedicalStaff {
   private:
    int staffID;
    std::string name;
    int assignedHospital;

   public:
    MedicalStaff();  // 默认构造函数
    MedicalStaff(int id, const std::string& name, int hospital);  // 带参构造
    MedicalStaff(const MedicalStaff& other);                      // 拷贝构造
    MedicalStaff(MedicalStaff&& other) noexcept;  // 👈 移动构造函数

    ~MedicalStaff();

    MedicalStaff& operator=(const MedicalStaff& other);      // 拷贝赋值
    MedicalStaff& operator=(MedicalStaff&& other) noexcept;  // 👈 移动赋值

    int getStaffID() const;
    std::string getName() const;
    int getAssignedHospital() const;

    void setStaffID(int id);
    void setName(const std::string& name);
    void setAssignedHospital(int hospital);
};

#endif
