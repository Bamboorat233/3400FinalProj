#include <iostream>
#include "header/Patient.h"

// Constructor with patient ID, personal info, and hospital ID
Patient::Patient(int id, std::string info, int hospitalID)
    : patientID(id),
      personalInfo(info),
      currentHospitalID(hospitalID),
      attendingDoctorID(-1) {}  // Default doctor is unset

// Get patient ID
int Patient::getID() const {
    return patientID;
}

// Get personal info
std::string Patient::getPersonalInfo() const {
    return personalInfo;
}

// Get current medical condition
std::string Patient::getMedicalCondition() const {
    return medicalCondition;
}

// Get assigned primary doctor ID
int Patient::getAttendingDoctorID() const {
    return attendingDoctorID;
}

// Move constructor
Patient::Patient(Patient&& other) noexcept
    : patientID(other.patientID),
      currentHospitalID(other.currentHospitalID),
      personalInfo(std::move(other.personalInfo)),
      medicalCondition(std::move(other.medicalCondition)),
      treatments(std::move(other.treatments)),
      attendingDoctorID(other.attendingDoctorID),
      consultingDoctors(std::move(other.consultingDoctors)) {
    // Optional: reset moved-from object
    other.patientID = -1;
    other.currentHospitalID = -1;
    other.attendingDoctorID = -1;
}

// Move assignment operator
Patient& Patient::operator=(Patient&& other) noexcept {
    if (this != &other) {
        patientID = other.patientID;
        currentHospitalID = other.currentHospitalID;
        personalInfo = std::move(other.personalInfo);
        medicalCondition = std::move(other.medicalCondition);
        treatments = std::move(other.treatments);
        attendingDoctorID = other.attendingDoctorID;
        consultingDoctors = std::move(other.consultingDoctors);

        other.patientID = -1;
        other.currentHospitalID = -1;
        other.attendingDoctorID = -1;
    }
    return *this;
}

// Update medical condition
void Patient::updateCondition(std::string condition) {
    medicalCondition = condition;
    std::cout << "Patient " << patientID
              << " condition updated to: " << condition << std::endl;
}

// Calculate total fee = fee per day * healing days
int Patient::calculateFee() {
    return this->patientFee * this->healingDays;
}

// Mark the patient as healed (returns true)
bool Patient::isHealed() {
    return this->medicalCertificate = true;
}

// Return whether discharge certificate is issued
bool Patient::getmedicalCertificate() const {
    return this->medicalCertificate;
}

// Get the current hospital branch ID
int Patient::getCurrentHospitalID() const {
    return this->currentHospitalID;
}

// Add a treatment to the list
void Patient::addTreatment(std::string treatment) {
    treatments.push_back(treatment);
    std::cout << "Treatment added for Patient " << patientID << ": "
              << treatment << std::endl;
}

// Change the patient's hospital branch
void Patient::transferHospital(int newHospitalID) {
    currentHospitalID = newHospitalID;
    std::cout << "Patient " << patientID << " transferred to hospital "
              << newHospitalID << std::endl;
}

// Assign a doctor to the patient
void Patient::setAttendingDoctor(int doctorID) {
    attendingDoctorID = doctorID;
    std::cout << "Patient " << patientID << " assigned to Doctor " << doctorID << std::endl;
}

// Add a consulting doctor to the patient
void Patient::addConsultingDoctor(int doctorID) {
    consultingDoctors.push_back(doctorID);
    std::cout << "Consulting Doctor " << doctorID << " added for Patient "
              << patientID << std::endl;
}

// Remove a consulting doctor from the patient
void Patient::removeConsultingDoctor(int doctorID) {
    for (auto it = consultingDoctors.begin(); it != consultingDoctors.end(); ++it) {
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

// Display all patient info
void Patient::displayInfo() const {
    std::cout << "Patient ID: " << patientID << "\n"
              << "Hospital ID: " << currentHospitalID << "\n"
              << "Personal Info: " << personalInfo << "\n"
              << "Medical Condition: " << medicalCondition << "\n"
              << "Attending Doctor: "
              << (attendingDoctorID != -1 ? std::to_string(attendingDoctorID) : "None")
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

// Destructor
Patient::~Patient() {
    // Optional: debug output
    // std::cout << "Patient " << patientID << " destroyed" << std::endl;
}
