#ifndef PATIENT_H
#define PATIENT_H

#include <string>
#include <vector>

// Class representing a hospital patient
class Patient {
   private:
    int patientID;                   // Unique ID for patient
    int currentHospitalID;          // Current hospital branch ID
    int patientFee;                 // Daily hospitalization fee
    int healingDays;                // Total healing days
    int attendingDoctorID;         // Assigned primary doctor
    std::string personalInfo;      // Basic personal information
    std::string medicalCondition;  // Current medical condition
    std::vector<std::string> treatments;       // List of treatments
    std::vector<int> consultingDoctors;        // IDs of consulting doctors
    bool medicalCertificate;       // Flag indicating discharge eligibility

   public:
    // Constructor
    Patient(int id, std::string info, int hospitalID);

    // Copy constructor & assignment (default)
    Patient(const Patient& other) = default;
    Patient& operator=(const Patient& other) = default;

    // Move constructor & assignment
    Patient(Patient&& other) noexcept;
    Patient& operator=(Patient&& other) noexcept;

    // Destructor
    ~Patient();

    // Getters
    int getID() const;
    bool getmedicalCertificate() const;
    int getCurrentHospitalID() const;
    int getAttendingDoctorID() const;
    std::string getPersonalInfo() const;
    std::string getMedicalCondition() const;

    // Setters and modifiers
    void updateCondition(std::string condition);
    void addTreatment(std::string treatment);
    void transferHospital(int newHospitalID);
    void setAttendingDoctor(int doctorID);
    void addConsultingDoctor(int doctorID);
    void removeConsultingDoctor(int doctorID);

    // Other operations
    void displayInfo() const;
    int calculateFee();       // patientFee * healingDays
    bool isHealed();          // Mark patient as healed
};

#endif  // PATIENT_H
