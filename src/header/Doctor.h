#ifndef DOCTOR_H
#define DOCTOR_H

#include <utility>  // for std::move
#include <vector>

#include "../../MedicalStaff/header/MedicalStaff.h"

// Doctor class inherits from MedicalStaff
// Represents a doctor who can be assigned to multiple patients
class Doctor : public MedicalStaff {
   private:
    std::vector<int> assignedPatients;   // List of assigned patient IDs
    static const int MAX_PATIENTS = 10;  // Max number of patients a doctor can handle

   public:
    // Default constructor
    Doctor();

    // Constructor with parameters (ID, name, hospital ID)
    Doctor(int id, std::string n, int h);

    // Copy constructor
    Doctor(const Doctor& doc);

    // Move constructor
    Doctor(Doctor&& other) noexcept;

    // Move assignment operator
    Doctor& operator=(Doctor&& other) noexcept;

    // Assign a patient to this doctor
    bool assignPatient(int patientID);

    // Release a patient from this doctor
    void releasePatient(int patientID);

    // Get a list of currently assigned patient IDs
    std::vector<int> getAssignedPatients() const;

    // Destructor
    ~Doctor();
};

#endif  // DOCTOR_H
