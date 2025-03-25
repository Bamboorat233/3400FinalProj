#include "header/Patient.h"

#include <iostream>

// 构造函数
Patient::Patient(int id, std::string info, int hospitalID)
    : patientID(id),
      personalInfo(info),
      currentHospitalID(hospitalID),
      attendingDoctorID(-1) {}

// 获取病人ID
int Patient::getID() const { return patientID; }

// ✅ 移动构造函数
Patient::Patient(Patient&& other) noexcept
    : patientID(other.patientID),
      currentHospitalID(other.currentHospitalID),
      personalInfo(std::move(other.personalInfo)),
      medicalCondition(std::move(other.medicalCondition)),
      treatments(std::move(other.treatments)),
      attendingDoctorID(other.attendingDoctorID),
      consultingDoctors(std::move(other.consultingDoctors)) {
    // 可选：清空原对象
    other.patientID = -1;
    other.currentHospitalID = -1;
    other.attendingDoctorID = -1;
}

// ✅ 移动赋值运算符
Patient& Patient::operator=(Patient&& other) noexcept {
    if (this != &other) {
        patientID = other.patientID;
        currentHospitalID = other.currentHospitalID;
        personalInfo = std::move(other.personalInfo);
        medicalCondition = std::move(other.medicalCondition);
        treatments = std::move(other.treatments);
        attendingDoctorID = other.attendingDoctorID;
        consultingDoctors = std::move(other.consultingDoctors);

        // 可选：清空原对象
        other.patientID = -1;
        other.currentHospitalID = -1;
        other.attendingDoctorID = -1;
    }
    return *this;
}

// 更新病情
void Patient::updateCondition(std::string condition) {
    medicalCondition = condition;
    std::cout << "Patient " << patientID
              << " condition updated to: " << condition << std::endl;
}

// 添加治疗方案
void Patient::addTreatment(std::string treatment) {
    treatments.push_back(treatment);
    std::cout << "Treatment added for Patient " << patientID << ": "
              << treatment << std::endl;
}

// 转移院区
void Patient::transferHospital(int newHospitalID) {
    currentHospitalID = newHospitalID;
    std::cout << "Patient " << patientID << " transferred to hospital "
              << newHospitalID << std::endl;
}

// 设置主治医生
void Patient::setAttendingDoctor(int doctorID) {
    attendingDoctorID = doctorID;
    std::cout << "Patient " << patientID << " assigned to Doctor " << doctorID
              << std::endl;
}

// 添加会诊医生
void Patient::addConsultingDoctor(int doctorID) {
    consultingDoctors.push_back(doctorID);
    std::cout << "Consulting Doctor " << doctorID << " added for Patient "
              << patientID << std::endl;
}

// 移除会诊医生
void Patient::removeConsultingDoctor(int doctorID) {
    for (auto it = consultingDoctors.begin(); it != consultingDoctors.end();
         ++it) {
        if (*it == doctorID) {
            consultingDoctors.erase(it);
            std::cout << "Consulting Doctor " << doctorID
                      << " removed for Patient " << patientID << std::endl;
            return;
        }
    }
    std::cout << "Consulting Doctor " << doctorID << " not found for Patient "
              << patientID << std::endl;
}

// 显示患者信息
void Patient::displayInfo() const {
    std::cout << "Patient ID: " << patientID << "\n"
              << "Hospital ID: " << currentHospitalID << "\n"
              << "Personal Info: " << personalInfo << "\n"
              << "Medical Condition: " << medicalCondition << "\n"
              << "Attending Doctor: "
              << (attendingDoctorID != -1 ? std::to_string(attendingDoctorID)
                                          : "None")
              << "\n"
              << "Consulting Doctors: ";
    for (int doc : consultingDoctors) {
        std::cout << doc << " ";
    }
    std::cout << "\nTreatments: ";
    for (const auto& treat : treatments) {
        std::cout << treat << " ";
    }
    std::cout << std::endl;
}

Patient::~Patient() {
    //std::cout << "Patient " << patientID << " destroyed" << std::endl;
}
