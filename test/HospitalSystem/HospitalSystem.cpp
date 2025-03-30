#include <iostream>

#include "header/HospitalSystem.h"

int HospitalSystem::nextPatientID = 1000;

HospitalSystem::HospitalSystem() {}

// Initialization: 5 branches, 20 pharmacies
void HospitalSystem::initializeSystem() {
    for (int i = 1; i <= 5; ++i) {
        branches.emplace_back(i);
    }

    for (int i = 1; i <= 20; ++i) {
        pharmacies.emplace_back(i);
    }

    std::cout << "System initialized: 5 branches and 20 pharmacies.\n";
}

// Register a patient
int HospitalSystem::registerPatient(std::string info) {
    int id = nextPatientID++;
    Patient newPatient(id, info, 1);  // Default assigned to branch 1
    allPatients.emplace(id, std::move(newPatient));
    std::cout << "Successfully registered new patient, ID: " << id << "\n";
    return id;
}

// Transfer across branches
bool HospitalSystem::transferPatient(int patientID, int newBranch) {
    auto it = allPatients.find(patientID);
    if (it == allPatients.end()) {
        std::cout << "Patient not found.\n";
        return false;
    }
    if (newBranch < 1 || newBranch > 5) {
        std::cout << "Invalid branch number.\n";
        return false;
    }
    it->second.transferHospital(newBranch);
    std::cout << "Patient " << patientID
              << " successfully transferred to branch " << newBranch << "\n";
    return true;
}

// Add a doctor
void HospitalSystem::addDoctor(int branchID, Doctor&& doc) {
    if (branchID < 1 || branchID > branches.size()) return;
    branches[branchID - 1].addDoctor(std::move(doc));
}

// Add a nurse
void HospitalSystem::addNurse(int branchID, Nurse&& nrs) {
    if (branchID < 1 || branchID > branches.size()) return;
    branches[branchID - 1].addNurse(std::move(nrs));
}

// Register a pharmacy
void HospitalSystem::addPharmacy(Pharmacy&& pharma) {
    if (pharmacies.size() >= 20) {
        std::cout << "Maximum number of pharmacies reached.\n";
        return;
    }
    int PharmacyID = pharma.getPharmacyID();
    pharmacies.push_back(std::move(pharma));
    std::cout << "Pharmacy registered, ID: " << PharmacyID << "\n";
}

// Generate financial report
void HospitalSystem::generateFinancialReport() const {
    std::cout << "=== Hospital Financial Report ===\n";
    for (const Pharmacy& p : pharmacies) {
        std::cout << "Pharmacy ID: " << p.getPharmacyID()
                  << ", Total Amount: " << p.getTotalBill() << " yuan\n";
    }
}
void AssignDoctorToPatient(int patientID, int staffID) {}
void nurseAssignPatient(int staffID, int patientID) {}
void nurseReleasePatient(int staffID, int patientID) {}