#ifndef NURSE_H
#define NURSE_H

#include <utility>
#include <vector>

#include "../../MedicalStaff/header/MedicalStaff.h"

// Nurse class inherits from MedicalStaff
// Each nurse can be assigned to a maximum of 2 patients
class Nurse : public MedicalStaff {
   private:
    std::vector<int> assignedPatients;  // List of patient IDs (max 2)

   public:
    // Default constructor
    Nurse();

    // Constructor with parameters
    Nurse(int id, std::string n, int h);

    // Copy constructor
    Nurse(const Nurse& other);

    // Move constructor
    Nurse(Nurse&& other) noexcept;

    // Move assignment operator
    Nurse& operator=(Nurse&& other) noexcept;

    // Assign a patient to this nurse (max 2 allowed)
    bool assignPatient(int patientID);

    // Release a patient from this nurse
    bool releasePatient(int patientID);

    // Get list of assigned patient IDs
    std::vector<int> getAssignedPatients() const;

    // Destructor
    ~Nurse();
};

#endif  // NURSE_H
