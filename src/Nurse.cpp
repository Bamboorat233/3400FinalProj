#include <algorithm>
#include <iostream>

#include "../../MedicalStaff/header/MedicalStaff.h"
#include "header/Nurse.h"

// Default constructor
Nurse::Nurse() : MedicalStaff() {}

// Constructor with parameters
Nurse::Nurse(int id, std::string n, int h) : MedicalStaff(id, n, h) {}

// Copy constructor
Nurse::Nurse(const Nurse& other)
    : MedicalStaff(other), assignedPatients(other.assignedPatients) {}

// Move constructor
Nurse::Nurse(Nurse&& other) noexcept
    : MedicalStaff(std::move(other)),
      assignedPatients(std::move(other.assignedPatients)) {}

// Move assignment operator
Nurse& Nurse::operator=(Nurse&& other) noexcept {
    if (this != &other) {
        MedicalStaff::operator=(std::move(other));
        assignedPatients = std::move(other.assignedPatients);
    }
    return *this;
}

// Destructor
Nurse::~Nurse() {
    // Optional: debug output
    // std::cout << "Nurse " << this->getName() << " is destroyed." << std::endl;
}

// Assign a patient to this nurse
bool Nurse::assignPatient(int patientID) {
    // Check max limit
    if (assignedPatients.size() >= 2) return false;

    // Avoid duplicates
    if (std::find(assignedPatients.begin(), assignedPatients.end(), patientID) ==
        assignedPatients.end()) {
        assignedPatients.push_back(patientID);
        return true;
    }

    return false;
}

// Release a patient from this nurse
bool Nurse::releasePatient(int patientID) {
    for (auto it = assignedPatients.begin(); it != assignedPatients.end(); ++it) {
        if (*it == patientID) {
            assignedPatients.erase(it);
            std::cout << "Patient " << patientID << " released from nurse.\n";
            return true;  // Successfully released
        }
    }
    return false;  // Patient not found
}

// Return current list of assigned patient IDs
std::vector<int> Nurse::getAssignedPatients() const {
    return assignedPatients;
}
