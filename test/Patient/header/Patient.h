#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>

class Patient {
private:
    int patientID;
    int currentHospitalID;
    std::string personalInfo;
    std::string medicalCondition;
    std::vector<std::string> treatments;
    int attendingDoctorID;
    std::vector<int> consultingDoctors;

public:
    // 构造函数
    Patient(int id, std::string info, int hospitalID);

    // 更新病情
    void updateCondition(std::string condition);

    // 添加治疗方案
    void addTreatment(std::string treatment);

    // 转移院区
    void transferHospital(int newHospitalID);

    // 设置主治医生
    void setAttendingDoctor(int doctorID);

    // 添加会诊医生
    void addConsultingDoctor(int doctorID);

    // 移除会诊医生
    void removeConsultingDoctor(int doctorID);

    // 显示患者信息
    void displayInfo() const;
};

#endif // PATIENT_H
