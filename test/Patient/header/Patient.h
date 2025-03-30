#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>

class Patient {
   private:
    int patientID;
    int currentHospitalID;
    int patientFee;
    int healingDays;
    int attendingDoctorID;
    std::string personalInfo;
    std::string medicalCondition;
    std::vector<std::string> treatments;
    std::vector<int> consultingDoctors;
    bool medicalCertificate;

   public:
    // 构造函数
    Patient(int id, std::string info, int hospitalID);

    // 拷贝构造和赋值（如有需要）
    Patient(const Patient& other) = default;
    Patient& operator=(const Patient& other) = default;

    // ✅ 移动构造函数和赋值运算符
    Patient(Patient&& other) noexcept;
    Patient& operator=(Patient&& other) noexcept;

    // 析构函数
    ~Patient();

    int getID() const;

    void updateCondition(std::string condition);
    void addTreatment(std::string treatment);
    void transferHospital(int newHospitalID);
    void setAttendingDoctor(int doctorID);
    void addConsultingDoctor(int doctorID);
    void removeConsultingDoctor(int doctorID);
    void displayInfo() const;
    int calculateFee();
    bool isHealed();
};

#endif  // PATIENT_H
