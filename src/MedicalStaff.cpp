#include "header/MedicalStaff.h"
#include <utility>

// Default constructor: initializes with default values
MedicalStaff::MedicalStaff() : staffID(0), name(""), assignedHospital(0) {}

// Parameterized constructor
MedicalStaff::MedicalStaff(int id, const std::string& name, int hospital)
    : staffID(id), name(name), assignedHospital(hospital) {}

// Copy constructor
MedicalStaff::MedicalStaff(const MedicalStaff& other)
    : staffID(other.staffID),
      name(other.name),
      assignedHospital(other.assignedHospital) {}

// Move constructor
MedicalStaff::MedicalStaff(MedicalStaff&& other) noexcept
    : staffID(other.staffID),
      name(std::move(other.name)),
      assignedHospital(other.assignedHospital) {
    // Optionally reset the moved-from object
    other.staffID = 0;
    other.assignedHospital = 0;
}

// Destructor
MedicalStaff::~MedicalStaff() {}

// Copy assignment operator
MedicalStaff& MedicalStaff::operator=(const MedicalStaff& other) {
    if (this != &other) {
        staffID = other.staffID;
        name = other.name;
        assignedHospital = other.assignedHospital;
    }
    return *this;
}

// Move assignment operator
MedicalStaff& MedicalStaff::operator=(MedicalStaff&& other) noexcept {
    if (this != &other) {
        staffID = other.staffID;
        name = std::move(other.name);
        assignedHospital = other.assignedHospital;

        // Optionally reset the moved-from object
        other.staffID = 0;
        other.assignedHospital = 0;
    }
    return *this;
}

// Getters
int MedicalStaff::getStaffID() const {
    return this->staffID;
}

std::string MedicalStaff::getName() const {
    return this->name;
}

int MedicalStaff::getAssignedHospital() const {
    return this->assignedHospital;
}

// Setters
void MedicalStaff::setStaffID(int id) {
    staffID = id;
}

void MedicalStaff::setName(const std::string& name) {
    this->name = name;
}

void MedicalStaff::setAssignedHospital(int hospital) {
    assignedHospital = hospital;
}
