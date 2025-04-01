#include <iostream>

#include "../../Doctor/header/Doctor.h"
#include "../../MedicalStaff/header/MedicalStaff.h"
#include "../../Nurse/header/Nurse.h"
#include "../../Patient/header/Patient.h"
#include "header/HospitalBranch.h"

// Constructor: initialize hospital branch with branchID
HospitalBranch::HospitalBranch(int id) : branchID(id) {}

// Admit a patient and assign doctor by doctorID
bool HospitalBranch::admitPatient(Patient& p, int doctorID) {
    if (patients.size() >= 20) {
        std::cout << "No available beds. Cannot admit patient.\n";
        return false;
    }

    bool doctorAssigned = false;
    for (Doctor& doc : doctors) {
        // Find and assign matching doctor
        if (doc.getStaffID() == doctorID) {
            if (doc.assignPatient(p.getID())) {
                doctorAssigned = true;
                break;
            }
        }
    }

    if (!doctorAssigned) {
        std::cout << "No doctor found with ID: " << doctorID << "\n";
        return false;
    }

    patients.push_back(std::move(p));
    std::cout << "Patient successfully admitted.\n";
    return true;
}

// Discharge patient and return total fee (if certificate is valid)
int HospitalBranch::dischargePatient(int patientID) {
    for (auto it = patients.begin(); it != patients.end(); ++it) {
        if (it->getID() == patientID && it->getmedicalCertificate()) {
            it->displayInfo();  // Show patient info
            int fee = it->calculateFee();
            patients.erase(it);  // Remove patient from list
            std::cout << "Patient discharged successfully.\n";
            return fee;
        } else {
            std::cout << "Patient medical certificate not valid.\n";
            return -1;
        }
    }
    std::cout << "Patient not found.\n";
    return -1;
}

// Assign any available doctor to the patient
bool HospitalBranch::assignDoctor(int patientID) {
    for (Doctor& doc : doctors) {
        if (doc.assignPatient(patientID)) {
            std::cout << "Doctor assigned to patient " << patientID << ".\n";
            return true;
        }
    }
    std::cout << "No doctor currently available.\n";
    return false;
}

// Assign any available nurse to the patient
bool HospitalBranch::assignNurse(int patientID) {
    for (Nurse& nurse : nurses) {
        if (nurse.assignPatient(patientID)) {
            std::cout << "Nurse assigned to patient " << patientID << ".\n";
            return true;
        }
    }
    std::cout << "No nurse currently available.\n";
    return false;
}

// Release a nurse from caring for a patient
bool HospitalBranch::nurseRelease(int patientID) {
    for (Nurse& nurse : nurses) {
        if (nurse.releasePatient(patientID)) {
            std::cout << "Nurse released patient " << patientID << ".\n";
            return true;
        }
    }
    std::cout << "No nurse found to release patient.\n";
    return false;
}

// Add medication purchase to pharmacy bill
void HospitalBranch::purchaseMedication(int pharmacyID, double amount) {
    pharmacyBills[pharmacyID] += amount;
    std::cout << "Medication purchased: Pharmacy " << pharmacyID
              << " added bill of " << amount << " yuan.\n";
}

// Return number of remaining beds (max 20)
int HospitalBranch::getAvailableBeds() const {
    return 20 - patients.size();
}

// Print a daily summary of the branch
void HospitalBranch::displayDailyReport() const {
    std::cout << "=== Branch Daily Report (ID: " << branchID << ") ===\n";
    std::cout << "Current number of patients: " << patients.size() << "\n";
    std::cout << "Number of doctors: " << doctors.size() << "\n";
    std::cout << "Number of nurses: " << nurses.size() << "\n";
    std::cout << "Available beds: " << getAvailableBeds() << "\n";

    std::cout << "Pharmacy billing:\n";
    for (const auto& entry : pharmacyBills) {
        std::cout << "  Pharmacy ID: " << entry.first
                  << " - Total Amount: " << entry.second << " yuan\n";
    }
}

// Add a doctor (used in system initialization)
void HospitalBranch::addDoctor(Doctor doc) {
    int id = doc.getStaffID();
    doctors.push_back(std::move(doc));
    std::cout << "Doctor added successfully, ID: " << id << "\n";
}

// Add a nurse (used in system initialization)
void HospitalBranch::addNurse(Nurse nrs) {
    int id = nrs.getStaffID();
    nurses.push_back(std::move(nrs));
    std::cout << "Nurse added successfully, ID: " << id << "\n";
}

// Get doctor by index (used internally or for advanced operations)
Doctor& HospitalBranch::getDoctor(int index) {
    return doctors.at(index);
}
