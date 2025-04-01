#include "header/Doctor.h"
#include "../../MedicalStaff/header/MedicalStaff.h"

#include <algorithm>
#include <iostream>

// Default constructor
Doctor::Doctor() : MedicalStaff() {}

// Parameterized constructor
Doctor::Doctor(int id, std::string n, int h) : MedicalStaff(id, n, h) {}

// Copy constructor
Doctor::Doctor(const Doctor& doc)
    : MedicalStaff(doc), assignedPatients(doc.assignedPatients) {}

// Move constructor
Doctor::Doctor(Doctor&& other) noexcept
    : MedicalStaff(std::move(other)),
      assignedPatients(std::move(other.assignedPatients)) {
    // std::move transfers ownership of vector contents
}

// Move assignment operator
Doctor& Doctor::operator=(Doctor&& other) noexcept {
    if (this != &other) {
        MedicalStaff::operator=(std::move(other));
        assignedPatients = std::move(other.assignedPatients);
    }
    return *this;
}

// Destructor
Doctor::~Doctor() {
    // Optional: print for debugging
    // std::cout << "Doctor " << this->getName() << " destructed" << std::endl;
}

// Assign a patient to this doctor
bool Doctor::assignPatient(int patientID) {
    if (assignedPatients.size() >= MAX_PATIENTS) return false;

    // Avoid duplicate assignments
    if (std::find(assignedPatients.begin(), assignedPatients.end(), patientID) ==
        assignedPatients.end()) {
        assignedPatients.push_back(patientID);
        return true;
    }

    return false;
}

// Remove a patient from this doctor
void Doctor::releasePatient(int patientID) {
    assignedPatients.erase(std::remove(assignedPatients.begin(),
                                       assignedPatients.end(), patientID),
                           assignedPatients.end());
}

// Return the list of assigned patient IDs
std::vector<int> Doctor::getAssignedPatients() const {
    return assignedPatients;
}
