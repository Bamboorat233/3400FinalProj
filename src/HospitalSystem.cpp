#include <iostream>
#include "header/HospitalSystem.h"

int HospitalSystem::nextPatientID = 1000;

// Constructor: Connect to DB and load data
HospitalSystem::HospitalSystem()
    : db("localhost", 33060, "root", "2002", "hospitaldb") {
    try {
        std::cout << "[TEST] connecting to database..." << std::endl;
        if (!db.connect()) {
            std::cerr << "[TEST ERROR] failed to connect to database" << std::endl;
            return;
        }
        std::cout << "[TEST] connected to database" << std::endl;
    } catch (const mysqlx::Error& err) {
        std::cerr << "[TEST ERROR] " << err << std::endl;
        throw;
    }

    // Load system data from database
    allPatients = db.loadAllPatients();
    pharmacies = db.loadAllPharmacies();
    branches = db.loadAllHospitalBranches();

    std::cout << "Loaded " << allPatients.size() << " patients from database.\n";
    std::cout << "Loaded " << pharmacies.size() << " pharmacies from database.\n";
    std::cout << "Loaded " << branches.size() << " hospital branches from database.\n";
}

// Destructor: Close DB session
HospitalSystem::~HospitalSystem() {
    db.close();
}

// Register a new patient
int HospitalSystem::registerPatient(const std::string info, int hospitalID,
                                    const std::string& medicalCondition,
                                    int attendingDoctorID) {
    // Check if doctor exists
    if (!db.doctorExists(attendingDoctorID)) {
        std::cerr << "[ERROR] Doctor ID " << attendingDoctorID << " does not exist.\n";
        return -1;
    }

    // Assign next patient ID
    int id = db.queryLastPatientID() + 1;
    Patient newPatient(id, info, hospitalID);
    newPatient.updateCondition(medicalCondition);
    newPatient.setAttendingDoctor(attendingDoctorID);

    // Save to database
    db.insertPatient(id, info, hospitalID, medicalCondition, attendingDoctorID);
    allPatients.emplace(id, std::move(newPatient));

    std::cout << "Successfully registered new patient, ID: " << id << "\n";
    return id;
}

// Transfer a patient to a new hospital branch
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
    std::cout << "Patient " << patientID << " successfully transferred to branch " << newBranch << "\n";
    return true;
}

// Add a doctor to the system and specific branch
void HospitalSystem::addDoctor(int branchID, int staffID, const std::string& name) {
    if (branchID < 1 || branchID > branches.size()) return;

    db.addDoctor(staffID, name, branchID);
    Doctor doc(staffID, name, branchID);
    branches[branchID - 1].addDoctor(std::move(doc));

    std::cout << "Doctor added successfully to branch " << branchID << "\n";
}

// Add a nurse to the system and specific branch
void HospitalSystem::addNurse(int branchID, int staffID, const std::string& name) {
    if (branchID < 1 || branchID > branches.size()) return;

    db.addNurse(staffID, name, branchID);
    Nurse nrs(staffID, name, branchID);
    branches[branchID - 1].addNurse(std::move(nrs));

    std::cout << "Nurse added successfully to branch " << branchID << "\n";
}

// Add a pharmacy (max 20 allowed)
void HospitalSystem::addPharmacy(Pharmacy&& pharma) {
    if (pharmacies.size() >= 20) {
        std::cout << "Maximum number of pharmacies reached.\n";
        return;
    }

    int PharmacyID = pharma.getPharmacyID();
    pharmacies.push_back(std::move(pharma));

    std::cout << "Pharmacy registered, ID: " << PharmacyID << "\n";
}

// Print total bill from each pharmacy
void HospitalSystem::generateFinancialReport() const {
    std::cout << "=== Hospital Financial Report ===\n";
    for (const Pharmacy& p : pharmacies) {
        std::cout << "Pharmacy ID: " << p.getPharmacyID()
                  << ", Total Amount: " << p.getTotalBill() << " yuan\n";
    }
}

// Assign multiple consulting doctors to a patient
void HospitalSystem::AssignDoctorToPatient(int patientID) {
    auto it = allPatients.find(patientID);
    if (it != allPatients.end()) {
        int branchID = it->second.getCurrentHospitalID();
        HospitalBranch& HB = branches.at(branchID - 1);

        for (int i = 0; i < 3; i++) {
            it->second.addConsultingDoctor(HB.getDoctor(i).getStaffID());
        }

        std::cout << "Doctors assigned to patient successfully.\n";
    } else {
        std::cout << "PatientID not found." << std::endl;
    }
}

// Assign a nurse to a patient
void HospitalSystem::nurseAssignPatient(int patientID) {
    auto it = allPatients.find(patientID);
    if (it != allPatients.end()) {
        int branchID = it->second.getCurrentHospitalID();
        HospitalBranch& HB = branches.at(branchID - 1);
        bool assigned = false;

        for (int i = 0; i < 5; i++) {
            if (HB.assignNurse(patientID)) {
                assigned = true;
                break;
            }
        }

        if (assigned) {
            std::cout << "Nurse assigned to patient." << std::endl;
        } else {
            std::cout << "No nurse currently available." << std::endl;
        }
    } else {
        std::cout << "PatientID not found." << std::endl;
    }
}

// Release a nurse from a patient
void HospitalSystem::nurseReleasePatient(int staffID, int patientID) {
    auto it = allPatients.find(patientID);
    if (it != allPatients.end()) {
        int branchID = it->second.getCurrentHospitalID();
        HospitalBranch& HB = branches.at(branchID - 1);

        HB.nurseRelease(patientID);
        std::cout << "Nurse released from patient successfully." << std::endl;
    } else {
        std::cout << "PatientID not found." << std::endl;
    }
}

// Return a hospital branch by ID
HospitalBranch HospitalSystem::getBranch(int branchID) {
    return branches.at(branchID - 1);
}
